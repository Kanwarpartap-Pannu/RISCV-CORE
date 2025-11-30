module pd5 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32
) (
    input logic clk,
    input logic reset
);

    // Pipeline register signals

    // IF stage outputs (from fetch)
    logic [AWIDTH-1:0] if_pc;
    logic [DWIDTH-1:0] if_insn;

    logic [DWIDTH-1:0] instr_mem_data;

    // IF/ID pipeline registers -> inputs to ID stage
    logic [AWIDTH-1:0] id_pc;
    logic [DWIDTH-1:0] id_insn;

    // Decode outputs (signals derived from id_insn)
    logic [6:0]  id_opcode;
    logic [4:0]  id_rd;
    logic [4:0]  id_rs1;
    logic [4:0]  id_rs2;
    logic [6:0]  id_funct7;
    logic [2:0]  id_funct3;
    logic [4:0]  id_shamt;
    logic [DWIDTH-1:0] id_imm;

    // Register file read data (ID stage)
    logic [DWIDTH-1:0] id_rs1data;
    logic [DWIDTH-1:0] id_rs2data;

    // Control outputs from control unit (in ID), to be captured into ID/EX
    logic        id_ctrl_pcsel;
    logic        id_ctrl_immsel;
    logic        id_ctrl_regwren;
    logic        id_ctrl_rs1sel;
    logic        id_ctrl_rs2sel;
    logic        id_ctrl_memren;
    logic        id_ctrl_memwren;
    logic [1:0]  id_ctrl_wbsel;
    logic [3:0]  id_ctrl_alusel;

    // ID/EX pipeline registers -> inputs to EX stage
    logic [AWIDTH-1:0] ex_pc;
    logic [DWIDTH-1:0] ex_rs1data;
    logic [DWIDTH-1:0] ex_rs2data;
    logic [DWIDTH-1:0] ex_imm;
    logic [4:0]        ex_rs1;
    logic [4:0]        ex_rs2;
    logic [4:0]        ex_rd;

    // Control signals latched into EX stage
    logic        ex_ctrl_regwren;
    logic        ex_ctrl_memren;
    logic        ex_ctrl_memwren;
    logic [1:0]  ex_ctrl_wbsel;
    logic [3:0]  ex_ctrl_alusel;

    // EX outputs (to EX/MEM)
    logic [DWIDTH-1:0] ex_alu_res;
    logic              ex_brtaken;
    logic [AWIDTH-1:0] ex_branch_target;

    // EX/MEM pipeline registers -> inputs to MEM stage
    logic [DWIDTH-1:0] mem_alu_res;
    logic [DWIDTH-1:0] mem_rs2data; // store data (after forwarding on EX stage)
    logic [4:0]        mem_rd;

    // Control signals latched into MEM stage
    logic        mem_ctrl_regwren;
    logic        mem_ctrl_memren;
    logic        mem_ctrl_memwren;
    logic [1:0]  mem_ctrl_wbsel;

    // MEM outputs (to MEM/WB)
    logic [DWIDTH-1:0] mem_read_data;

    // MEM/WB pipeline registers -> inputs to WB stage
    logic [DWIDTH-1:0] wb_mem_read_data;
    logic [DWIDTH-1:0] wb_alu_res;
    logic [4:0]        wb_rd;

    // Control signals latched into WB stage
    logic        wb_ctrl_regwren;
    logic [1:0]  wb_ctrl_wbsel;

    // writeback final value (to register file)
    logic [DWIDTH-1:0] wb_writeback_data;

    // Other signals
    logic [1:0] size_encoded; // reuse existing logic for funct3 -> size

    // Hazard / forwarding signals
    logic stall;               // detected load-use hazard
    logic if_id_write_en;      // when 0, freeze IF/ID 
    logic pc_write_en;         // when 0, freeze PC in fetch 
    logic inject_idex_bubble;  // when 1, insert NOP into ID/EX (zero control)
    logic flush_if_id;         // flush IF/ID (for branch taken)
    logic [1:0] forwardA;      // 00 = from id_ex rs1, 10 = ex_mem, 01 = mem_wb
    logic [1:0] forwardB;

    // capture opcode/funct fields into EX stage (used by ALU)
    logic [6:0] ex_opcode;
    logic [2:0] ex_funct3;
    logic [6:0] ex_funct7;

    // control bit selecting rs2 vs imm (captured into ID/EX)
    logic ex_ctrl_rs2sel;

    // NOP / control defaults 
    localparam logic [31:0] NOP_INSN = 32'h00000013; // ADDI x0,x0,0

    // FETCH
    logic [AWIDTH-1:0] fetch_branch_target_in;

    fetch #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASEADDR(32'h01000000)
    ) fetch_u (
        .clk(clk),
        .rst(reset),
        .pcsel_o(ex_brtaken),
        .alu_res(ex_alu_res),
        .pc_write_en(pc_write_en),
        .branch_target_in(fetch_branch_target_in),
        .pc_o(if_pc),
        .insn_o()
    );

    // IF/ID register 
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            id_pc   <= '0;
            id_insn <= NOP_INSN;
        end else begin
            if (!if_id_write_en) begin
                // freeze IF/ID (stall)
                id_pc   <= id_pc;
                id_insn <= id_insn;
            end else if (flush_if_id) begin
                // insert NOP on flush (branch taken)
                id_pc   <= '0;
                id_insn <= NOP_INSN;
            end else begin
                id_pc   <= if_pc;
                id_insn <= if_insn;
            end
        end
    end

    // Drive IF instruction from instruction memory output
    assign if_insn = instr_mem_data; 

    // DECODE stage
    decode #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) decode_u (
        .clk(clk),
        .rst(reset),
        .insn_i(id_insn),
        .pc_i(id_pc),
        .pc_o(/*unused*/),
        .insn_o(/*unused*/),
        .opcode_o(id_opcode),
        .rd_o(id_rd),
        .rs1_o(id_rs1),
        .rs2_o(id_rs2),
        .funct7_o(id_funct7),
        .funct3_o(id_funct3),
        .shamt_o(id_shamt),
        .imm_o(id_imm)
    );

    // Control unit 
    logic control_br_taken_dummy = 1'b0;
    control #(
        .DWIDTH(DWIDTH)
    ) control_u (
        .insn_i(id_insn),
        .opcode_i(id_opcode),
        .funct7_i(id_funct7),
        .funct3_i(id_funct3),
        .br_taken(control_br_taken_dummy),
        .pcsel_o(id_ctrl_pcsel),
        .immsel_o(id_ctrl_immsel),
        .regwren_o(id_ctrl_regwren),
        .rs1sel_o(id_ctrl_rs1sel),
        .rs2sel_o(id_ctrl_rs2sel),
        .memren_o(id_ctrl_memren),
        .memwren_o(id_ctrl_memwren),
        .wbsel_o(id_ctrl_wbsel),
        .alusel_o(id_ctrl_alusel)
    );

    // Register file (reads in ID stage)
    logic [4:0] regfile_rd_in;
    logic [DWIDTH-1:0] regfile_datawb_in;
    logic regfile_regwren_in;

    register_file #(
        .DWIDTH(DWIDTH)
    ) u_register_file (
        .clk(clk),
        .rst(reset),
        .rs1_i(id_rs1),
        .rs2_i(id_rs2),
        .rd_i(regfile_rd_in),
        .datawb_i(regfile_datawb_in),
        .regwren_i(regfile_regwren_in),
        .rs1data_o(id_rs1data),
        .rs2data_o(id_rs2data)
    );

    // Branch control
    logic id_breq, id_brlt, id_brltu;
    branch_control #(.DWIDTH(DWIDTH)) branch_control_u (
        .opcode_i(id_opcode),
        .funct3_i(id_funct3),
        .rs1_i(id_rs1data),
        .rs2_i(id_rs2data),
        .breq_o(id_breq),
        .brlt_o(id_brlt),
        .brltu_o(id_brltu)
    );

    // ID/EX pipeline registers (capture decode outputs & control into EX stage)

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            ex_pc <= '0;
            ex_rs1data <= '0;
            ex_rs2data <= '0;
            ex_imm <= '0;
            ex_rs1 <= 5'd0;
            ex_rs2 <= 5'd0;
            ex_rd <= 5'd0;
            ex_ctrl_regwren <= 1'b0;
            ex_ctrl_memren <= 1'b0;
            ex_ctrl_memwren <= 1'b0;
            ex_ctrl_wbsel <= 2'b00;
            ex_ctrl_alusel <= 4'hF;
            ex_opcode <= 7'd0;
            ex_funct3 <= 3'd0;
            ex_funct7 <= 7'd0;
            ex_ctrl_rs2sel <= 1'b0;
        end else begin
            if (inject_idex_bubble) begin
                // insert bubble/NOP into EX stage
                ex_pc <= '0;
                ex_rs1data <= '0;
                ex_rs2data <= '0;
                ex_imm <= '0;
                ex_rs1 <= 5'd0;
                ex_rs2 <= 5'd0;
                ex_rd <= 5'd0;
                ex_ctrl_regwren <= 1'b0;
                ex_ctrl_memren <= 1'b0;
                ex_ctrl_memwren <= 1'b0;
                ex_ctrl_wbsel <= 2'b00;
                ex_ctrl_alusel <= 4'hF; // NOP code per your control
                ex_opcode <= 7'd0;
                ex_funct3 <= 3'd0;
                ex_funct7 <= 7'd0;
                ex_ctrl_rs2sel <= 1'b0;
            end else begin
                // normal capture from ID stage
                ex_pc <= id_pc;
                ex_rs1data <= id_rs1data;
                ex_rs2data <= id_rs2data;
                ex_imm <= id_imm;
                ex_rs1 <= id_rs1;
                ex_rs2 <= id_rs2;
                ex_rd <= id_rd;
                // control captured
                ex_ctrl_regwren <= id_ctrl_regwren;
                ex_ctrl_memren <= id_ctrl_memren;
                ex_ctrl_memwren <= id_ctrl_memwren;
                ex_ctrl_wbsel <= id_ctrl_wbsel;
                ex_ctrl_alusel <= id_ctrl_alusel;
                // capture decoding fields for EX
                ex_opcode <= id_opcode;
                ex_funct3 <= id_funct3;
                ex_funct7 <= id_funct7;
                // capture rs2sel control (select imm vs rs2)
                ex_ctrl_rs2sel <= id_ctrl_rs2sel;
            end
        end
    end

    // Hazard detection 
    always_comb begin
        stall = 1'b0;
        if_id_write_en = 1'b1;
        pc_write_en = 1'b1;
        inject_idex_bubble = 1'b0;

        // detect load in EX stage
        
        if (ex_ctrl_memren && (ex_rd != 5'd0) &&
            ((ex_rd == id_rs1) || (ex_rd == id_rs2))) begin
            stall = 1'b1;
            if_id_write_en = 1'b0; // freeze IF/ID
            pc_write_en = 1'b0;    // freeze PC (requires fetch.sv to implement pc_write_en)
            inject_idex_bubble = 1'b1;
        end
    end

    // Forwarding unit 
    always_comb begin
        forwardA = 2'b00;
        forwardB = 2'b00;
        // EX/MEM -> EX forwarding
        if (mem_ctrl_regwren && (mem_rd != 5'd0) && (mem_rd == ex_rs1)) begin
            forwardA = 2'b10;
        end else if (wb_ctrl_regwren && (wb_rd != 5'd0) && (wb_rd == ex_rs1)) begin
            forwardA = 2'b01;
        end

        if (mem_ctrl_regwren && (mem_rd != 5'd0) && (mem_rd == ex_rs2)) begin
            forwardB = 2'b10;
        end else if (wb_ctrl_regwren && (wb_rd != 5'd0) && (wb_rd == ex_rs2)) begin
            forwardB = 2'b01;
        end
    end

    // ALU operands for EX stage after forwarding
    logic [DWIDTH-1:0] mem_forward_value;
    logic [DWIDTH-1:0] wb_forward_value;
    assign mem_forward_value = mem_alu_res;

    always_comb begin
        case (wb_ctrl_wbsel)
            2'b00: wb_forward_value = wb_alu_res;
            2'b01: wb_forward_value = wb_mem_read_data;
            2'b10: wb_forward_value = wb_alu_res; // pc+4 not available here; using ALU result fallback
            default: wb_forward_value = wb_alu_res;
        endcase
    end

    logic [DWIDTH-1:0] ex_alu_op1;
    logic [DWIDTH-1:0] ex_alu_op2;

    always_comb begin
        // op1
        unique case (forwardA)
            2'b10: ex_alu_op1 = mem_forward_value;
            2'b01: ex_alu_op1 = wb_forward_value;
            default: ex_alu_op1 = ex_rs1data;
        endcase
        // op2
        unique case (forwardB)
            2'b10: ex_alu_op2 = mem_forward_value;
            2'b01: ex_alu_op2 = wb_forward_value;
            default: ex_alu_op2 = ex_rs2data;
        endcase
    end

    // EXECUTE stage
    // compute branch condition inputs for ALU branch
    logic ex_eq, ex_lt, ex_ltu;
    assign ex_eq = (ex_alu_op1 == ex_alu_op2);
    assign ex_lt = ($signed(ex_alu_op1) < $signed(ex_alu_op2));
    assign ex_ltu = (ex_alu_op1 < ex_alu_op2);

    // ex_opcode/ex_funct3/ex_funct7/ex_ctrl_rs2sel declared above and captured into EX registers

    logic [DWIDTH-1:0] ex_op2_final;
    assign ex_op2_final = (ex_ctrl_rs2sel) ? ex_imm : ex_alu_op2;

    // Instantiate ALU with forwarded operands
    alu #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) alu_u (
        .pc_i(ex_pc),
        .rs1_i(ex_alu_op1),
        .rs2_i(ex_op2_final),
        .funct3_i(ex_funct3),
        .funct7_i(ex_funct7),
        .opcode_i(ex_opcode),
        .alusel_i(ex_ctrl_alusel),
        .eq(ex_eq),
        .lt(ex_lt),
        .ltu(ex_ltu),
        .res_o(ex_alu_res),
        .brtaken_o(ex_brtaken)
    );

    // compute branch target
    assign ex_branch_target = ex_pc + ex_imm;
    assign fetch_branch_target_in = ex_branch_target;

    // EX/MEM pipeline registers
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            mem_alu_res <= '0;
            mem_rs2data <= '0;
            mem_rd <= 5'd0;
            mem_ctrl_regwren <= 1'b0;
            mem_ctrl_memren <= 1'b0;
            mem_ctrl_memwren <= 1'b0;
            mem_ctrl_wbsel <= 2'b00;
        end else begin
            // normal flow: EX -> MEM
            mem_alu_res <= ex_alu_res;
            // store data must be forwarded value for ex_rs2 (we used ex_alu_op2 above to incorporate forwarding)
            mem_rs2data <= ex_alu_op2;
            mem_rd <= ex_rd;
            mem_ctrl_regwren <= ex_ctrl_regwren;
            mem_ctrl_memren <= ex_ctrl_memren;
            mem_ctrl_memwren <= ex_ctrl_memwren;
            mem_ctrl_wbsel <= ex_ctrl_wbsel;
        end
    end

    // MEMORY stage
    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASE_ADDR(32'h01000000)
    ) memory_u (
        .clk(clk),
        .rst(reset),
        .addr_i(if_pc),               // instruction fetch address from fetch PC
        .addr_dat(mem_alu_res),       // data memory address from ALU
        .data_i(32'b0),               // instruction mem write (unused)
        .data_dat(mem_rs2data),       // data to write to data memory
        .read_en_i(1'b1),             // instruction memory read always enabled
        .write_en_i(1'b0),            // instruction memory write disabled
        .read_en_dat(mem_ctrl_memren),
        .write_en_dat(mem_ctrl_memwren),
        .size_encoded(size_encoded),
        .data_o(instr_mem_data),
        .data_dat_o(mem_read_data)
    );

    // MEM/WB pipeline registers
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            wb_mem_read_data <= '0;
            wb_alu_res <= '0;
            wb_rd <= 5'd0;
            wb_ctrl_regwren <= 1'b0;
            wb_ctrl_wbsel <= 2'b00;
        end else begin
            wb_mem_read_data <= mem_read_data;
            wb_alu_res <= mem_alu_res;
            wb_rd <= mem_rd;
            wb_ctrl_regwren <= mem_ctrl_regwren;
            wb_ctrl_wbsel <= mem_ctrl_wbsel;
        end
    end

    // WRITEBACK stage
    writeback #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) writeback_u (
        .pc_i(ex_pc),
        .alu_res_i(wb_alu_res),
        .memory_data_i(wb_mem_read_data),
        .wbsel_i(wb_ctrl_wbsel),
        .brtaken_i(ex_brtaken),
        .writeback_data_o(wb_writeback_data),
        .next_pc_o(/*unused*/)
    );

    // drive register file write inputs from WB stage
    always_comb begin
        regfile_datawb_in = wb_writeback_data;
        regfile_rd_in = wb_rd;
        regfile_regwren_in = wb_ctrl_regwren;
    end

    // Branch handling: flush IF/ID when branch is taken in EX stage
    always_comb begin
        // default
        flush_if_id = 1'b0;
        if (ex_brtaken) begin
            flush_if_id = 1'b1;
        end
    end

    // Size encoding combinational logic
    always_comb begin
        case (id_funct3)
            3'b000, 3'b100: size_encoded = 2'b00; // word
            3'b001, 3'b101: size_encoded = 2'b01; // halfword
            3'b010:         size_encoded = 2'b10; // byte
            3'b111:         size_encoded = 2'b11; // doubleword
            default:        size_encoded = 2'b00;
        endcase
    end

    // Program termination logic (kept from PD4)
    reg is_program = 0;
    always_ff @(posedge clk) begin
        if (if_insn == 32'h00000073) $finish;  // ecall
        if (if_insn == 32'h00008067) is_program = 1;  // ret
        if (is_program && (u_register_file.regs[2] == 32'h01000000 + `MEM_DEPTH)) $finish;
    end

endmodule : pd5