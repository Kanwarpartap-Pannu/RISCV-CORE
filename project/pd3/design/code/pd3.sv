`include "constants.svh"

/*
 * Module: pd3
 *
 * Description: Top level module that will contain sub-module instantiations.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

module pd3 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32,
    parameter logic [31:0] BASEADDR = 32'h01000000
)(
    input  logic clk,
    input  logic reset
);

    // Opcode literals used in control flow decisions
    localparam [6:0]
        OP_R      = 7'b0110011,
        OP_I      = 7'b0010011,
        OP_LOAD   = 7'b0000011,
        OP_STORE  = 7'b0100011,
        OP_BRANCH = 7'b1100011,
        OP_JALR   = 7'b1100111,
        OP_JAL    = 7'b1101111,
        OP_LUI    = 7'b0110111,
        OP_AUIPC  = 7'b0010111;

    // Fetch/PC
    logic [AWIDTH-1:0] pc;
    logic [AWIDTH-1:0] next_pc;
    logic [DWIDTH-1:0] insn_f;        // instruction fetched from imem

    // Decode outputs
    logic [AWIDTH-1:0] pc_d;
    logic [DWIDTH-1:0] insn_d;
    logic [6:0]        opcode_d;
    logic [4:0]        rd_d;
    logic [4:0]        rs1_d;
    logic [4:0]        rs2_d;
    logic [6:0]        funct7_d;
    logic [2:0]        funct3_d;
    logic [4:0]        shamt_d;
    logic [DWIDTH-1:0] imm_d;

    // Register file wires
    logic [DWIDTH-1:0] rs1_data;
    logic [DWIDTH-1:0] rs2_data;

    // Control signals
    logic              pcsel_c;
    logic              immsel_c;
    logic              regwren_c;
    logic              rs1sel_c;
    logic              rs2sel_c;
    logic              memren_c;
    logic              memwren_c;
    logic [1:0]        wbsel_c;
    logic [3:0]        alusel_c;

    // ALU
    logic [DWIDTH-1:0] alu_res;
    logic              alu_brtaken;

    // Data memory
    logic [DWIDTH-1:0] dmem_rdata;

    // Branch control
    logic breq_bc;
    logic brlt_bc;
    logic take_branch;

    // write-back data
    logic [DWIDTH-1:0] datawb;

    // pc + 4 for writeback
    wire [AWIDTH-1:0] pc_plus4 = pc + 32'd4;

    // Simple PC register (top-level controls PC)
    always_ff @(posedge clk) begin
        if (reset) begin
            pc <= BASEADDR;
        end else begin
            pc <= next_pc;
        end
    end

    // Instruction memory (imem) - always read current PC
    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASE_ADDR(BASEADDR)
    ) imem (
        .clk(clk),
        .rst(reset),
        .addr_i(pc),
        .data_i('0),
        .read_en_i(1'b1),
        .write_en_i(1'b0),
        .data_o(insn_f)
    );

    // Decode stage (combinational outputs from instruction)
    decode #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_decode (
        .clk(clk),
        .rst(reset),
        .insn_i(insn_f), //Fetches the instruction output
        .pc_i(pc), //Fetches the PC
        .pc_o(pc_d),
        .insn_o(insn_d),
        .opcode_o(opcode_d),
        .rd_o(rd_d),
        .rs1_o(rs1_d),
        .rs2_o(rs2_d),
        .funct7_o(funct7_d),
        .funct3_o(funct3_d),
        .shamt_o(shamt_d),
        .imm_o(imm_d)
    );

    // Control unit
    control #(.DWIDTH(DWIDTH)) u_control (
        .insn_i(insn_d),
        .opcode_i(opcode_d),
        .funct7_i(funct7_d),
        .funct3_i(funct3_d),
        .pcsel_o(pcsel_c),
        .immsel_o(immsel_c),
        .regwren_o(regwren_c),
        .rs1sel_o(rs1sel_c),
        .rs2sel_o(rs2sel_c),
        .memren_o(memren_c),
        .memwren_o(memwren_c),
        .wbsel_o(wbsel_c),
        .alusel_o(alusel_c)
    );

    // Register file
    register_file #(
        .DWIDTH(DWIDTH),
        .SP_INIT(32'h0110_0000)   // Explicitly set stack pointer initial value to avoid error faced 
    ) u_rf (
        .clk(clk),
        .rst(reset),
        .rs1_i(rs1_d),
        .rs2_i(rs2_d),
        .rd_i(rd_d),
        .datawb_i(datawb),
        .regwren_i(regwren_c),
        .rs1data_o(rs1_data),
        .rs2data_o(rs2_data)
);

    // Operand selection: op2 = rs2 or imm depending on control.rs2sel (1 -> reg, 0 -> imm)
    logic [DWIDTH-1:0] op2;
    assign op2 = rs2sel_c ? rs2_data : imm_d;

    // ALU instance - uses funct3/funct7 coming from decode
    alu #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH)) u_alu (
        .opcode_i(opcode_d),
        .pc_i(pc),
        .rs1_i(rs1_data),
        .rs2_i(op2),
        .funct3_i(funct3_d),
        .funct7_i(funct7_d),
        .res_o(alu_res),
        .brtaken_o(alu_brtaken)
    );

    // Data memory (dmem)
    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASE_ADDR(BASEADDR)
    ) dmem (
        .clk(clk),
        .rst(reset),
        .addr_i(alu_res),
        .data_i(rs2_data),
        .read_en_i(memren_c),
        .write_en_i(memwren_c),
        .data_o(dmem_rdata)
    );

    // Branch control: compute equality and signed/unsigned lt
    branch_control #(.DWIDTH(DWIDTH)) u_branch_ctrl (
        .opcode_i(opcode_d),
        .funct3_i(funct3_d),
        .rs1_i(rs1_data),
        .rs2_i(rs2_data),
        .breq_o(breq_bc),
        .brlt_o(brlt_bc)
    );

    // Evaluate branch condition based on funct3
    always_comb begin
        take_branch = 1'b0;
        unique case (funct3_d)
            3'b000: take_branch = breq_bc;       // BEQ
            3'b001: take_branch = ~breq_bc;      // BNE
            3'b100: take_branch = brlt_bc;       // BLT
            3'b101: take_branch = ~brlt_bc;      // BGE
            3'b110: take_branch = brlt_bc;       // BLTU
            3'b111: take_branch = ~brlt_bc;      // BGEU
            default: take_branch = 1'b0;
        endcase
    end

    // Next PC computation (JAL, JALR, BRANCH, default PC+4)
    always_comb begin
        // default next PC
        next_pc = pc_plus4;

        if (opcode_d == OP_JAL) begin
            next_pc = pc + imm_d;
        end else if (opcode_d == OP_JALR) begin
            next_pc = (rs1_data + imm_d) & ~32'h1;
        end else if (opcode_d == OP_BRANCH) begin
            if (take_branch)
                next_pc = pc + imm_d;
            else
                next_pc = pc_plus4;
        end
    end

    // Write-back selection: 00 = ALU, 01 = MEM, 10 = PC+4
    always_comb begin
        unique case (wbsel_c)
            2'b00: datawb = alu_res;
            2'b01: datawb = dmem_rdata;
            2'b10: datawb = pc_plus4;
            default: datawb = alu_res;
        endcase
    end

    // Fetch
    logic [AWIDTH-1:0] f_pc;
    logic [DWIDTH-1:0] f_insn;
    assign f_pc   = pc;
    assign f_insn = insn_f;

    // Decode
    logic [AWIDTH-1:0] d_pc;
    logic [6:0]        d_opcode;
    logic [4:0]        d_rd;
    logic [2:0]        d_funct3;
    logic [4:0]        d_rs1;
    logic [4:0]        d_rs2;
    logic [6:0]        d_funct7;
    logic [DWIDTH-1:0] d_imm;
    logic [4:0]        d_shamt;
    assign d_pc     = pc_d;
    assign d_opcode = opcode_d;
    assign d_rd     = rd_d;
    assign d_funct3 = funct3_d;
    assign d_rs1    = rs1_d;
    assign d_rs2    = rs2_d;
    assign d_funct7 = funct7_d;
    assign d_imm    = imm_d;
    assign d_shamt  = shamt_d;

    // Register file probes (writes)
    logic              r_write_enable;
    logic [4:0]        r_write_dest;
    logic [DWIDTH-1:0] r_write_data;
    assign r_write_enable = regwren_c;
    assign r_write_dest   = rd_d;
    assign r_write_data   = datawb;

    // Register file probes (reads)
    logic [4:0]        r_read_rs1;
    logic [4:0]        r_read_rs2;
    logic [DWIDTH-1:0] r_read_rs1_data;
    logic [DWIDTH-1:0] r_read_rs2_data;
    assign r_read_rs1       = rs1_d;
    assign r_read_rs2       = rs2_d;
    assign r_read_rs1_data  = rs1_data;
    assign r_read_rs2_data  = rs2_data;

    // Execute
    logic [AWIDTH-1:0] e_pc;
    logic [DWIDTH-1:0] e_alu_res;
    logic               e_br_taken;
    assign e_pc       = pc;
    assign e_alu_res  = alu_res;
    assign e_br_taken = (opcode_d == `OP_BRANCH) ? take_branch : 1'b0;

    // small use to avoid unused warnings
    // synthesis translate_off
    wire __unused_probe_guard = f_pc[0] ^ f_insn[0] ^ d_opcode[0] ^ r_read_rs1_data[0] ^ e_alu_res[0];
    // synthesis translate_on

endmodule : pd3
