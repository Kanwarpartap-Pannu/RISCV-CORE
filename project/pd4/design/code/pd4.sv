/*
 * Module: pd4
 *
 * Description: Top level module that will contain sub-module instantiations.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

module pd4 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32)(
    input logic clk,
    input logic reset
);

 /*
  * Instantiate other submodules and
  * probes. To be filled by student...
  *
  */

  // DECODE stage signals
    logic [AWIDTH-1:0] d_pc;
    logic [DWIDTH-1:0] d_insn;
    logic [6:0]        d_opcode;
    logic [4:0]        d_rd;
    logic [4:0]        d_rs1;
    logic [4:0]        d_rs2;
    logic [6:0]        d_funct7;
    logic [2:0]        d_funct3;
    logic [4:0]        d_shamt;
    logic [DWIDTH-1:0] d_imm;

    // CONTROL Signals
    logic              ctrl_pcsel;
    logic              ctrl_immsel;
    logic              ctrl_regwren;
    logic              ctrl_rs1sel;
    logic              ctrl_rs2sel;
    logic              ctrl_memren;
    logic              ctrl_memwren;
    logic [1:0]        ctrl_wbsel;
    logic [3:0]        ctrl_alusel;

    // imemory signals
    logic [DWIDTH - 1:0] addr_i;
    logic [DWIDTH - 1:0] data_i;
    logic write_en;
    logic read_en;
       
    // Fetch signals
    logic [DWIDTH - 1:0] f_pc;
    logic [DWIDTH - 1:0] f_insn;

    // Alu signals
    logic [DWIDTH - 1:0] rs1_i; // not to be confused as registers
    logic [DWIDTH - 1:0] rs2_i; // simply two operand inputs
    logic [DWIDTH - 1:0] alu_res;
    logic                br_taken;

    //register file signals
    logic [DWIDTH - 1:0] datawb_i;
    logic [DWIDTH - 1:0] rs1data_o;
    logic [DWIDTH - 1:0] rs2data_o;

    //branch control signals
    logic breq_o;
    logic brlt_o;

    // Memory data Signals
    logic [1:0] size_encoded;

    // writeback signals
    logic [DWIDTH - 1:0] writeback_data_o;
    logic [DWIDTH - 1:0] next_pc_o;
    logic [DWIDTH - 1:0] memory_data_i;

    

    // Default memory signals for instruction memory
    assign read_en = 1'b1;
    assign write_en = 1'b0;

    // Fetch
    fetch #(
        .AWIDTH(32),
        .DWIDTH(32),
        .BASEADDR(32'h01000000)
    ) fetch1 (
        .clk(clk),
        .rst(reset),
        .pcsel_o(ctrl_pcsel),
        .alu_res(alu_res),
        .pc_o(f_pc),           
        .insn_o(f_insn)         
    );

    // Decode stage
    decode #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_decode (
        .clk(clk),
        .rst(reset),
        .insn_i(f_insn),
        .pc_i(f_pc),
        .pc_o(d_pc),
        .insn_o(d_insn),
        .opcode_o(d_opcode),
        .rd_o(d_rd),
        .rs1_o(d_rs1),
        .rs2_o(d_rs2),
        .funct7_o(d_funct7),
        .funct3_o(d_funct3),
        .shamt_o(d_shamt),
        .imm_o(d_imm)
    );

    // Control unit
    control #(
        .DWIDTH(DWIDTH)
    ) u_control (
        .insn_i(d_insn),
        .opcode_i(d_opcode),
        .funct7_i(d_funct7),
        .funct3_i(d_funct3),

        .pcsel_o(ctrl_pcsel),
        .immsel_o(ctrl_immsel),
        .regwren_o(ctrl_regwren),
        .rs1sel_o(ctrl_rs1sel),
        .rs2sel_o(ctrl_rs2sel),
        .memren_o(ctrl_memren),
        .memwren_o(ctrl_memwren),
        .wbsel_o(ctrl_wbsel),
        .alusel_o(ctrl_alusel)
    );

    // Select rs1 and rs2 inputs to ALU based on control signals
    assign rs1_i = (ctrl_rs1sel) ?  rs1data_o : d_pc;
    assign rs2_i = (ctrl_rs2sel) ?  rs2data_o : d_imm;
    
    // Branch control unit
    branch_control #(
        .DWIDTH(DWIDTH)
    ) u_branch_control (
        .opcode_i(d_opcode),
        .funct3_i(d_funct3),
        .rs1_i(rs1data_o), // from register file becuase
        .rs2_i(rs2data_o), // rs1_i and rs2_i will be muxed to select pc and imm rather than register data
        .breq_o(breq_o),
        .brlt_o(brlt_o)
    );


    // Excute stage - ALU
    alu #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_alu (
        .pc_i(d_pc),
        .rs1_i(rs1_i), 
        .rs2_i(rs2_i), 
        .funct3_i(d_funct3),
        .funct7_i(d_funct7),
        .opcode_i(d_opcode),
        .alusel_i(ctrl_alusel),
        .eq(breq_o),
        .lt(brlt_o),
        .res_o(alu_res),      
        .brtaken_o(br_taken)   
    );



    // Register File
    register_file #(
        .DWIDTH(DWIDTH)
    ) u_register_file (
        .clk(clk),
        .rst(reset),
        .rs1_i(d_rs1),
        .rs2_i(d_rs2),
        .rd_i(d_rd),
        .datawb_i(writeback_data_o),      
        .regwren_i(ctrl_regwren),
        .rs1data_o(rs1data_o),     
        .rs2data_o(rs2data_o)      
    );   

    // Ok up to here my pipeline handles fetch, decode, execute stages
    // but fetch needs to know which pc to fetch from based on branch taken or not so it needs to be modifed to include that logic
    // next we have our result which is correct for all stages so we need to mux and decide wether to write back alu result or memory data
    // we need to implement memory for data memory access stage which I think is easiest if we just have another memory instance for data memory

    // we need mux here to get correct size encoded signal based on funct3
    // Opcodes
    localparam OPCODE_LOAD  = 7'b0000011;
    localparam OPCODE_STORE = 7'b0100011;

    always_comb begin
        case (d_opcode)
            OPCODE_LOAD, OPCODE_STORE: begin
                case (d_funct3)
                    3'b000, 3'b100: size_encoded = 2'b00; // byte (LB/LBU or SB)
                    3'b001, 3'b101: size_encoded = 2'b01; // halfword (LH/LHU or SH)
                    3'b010:         size_encoded = 2'b10; // word (LW or SW)
                    default:        size_encoded = 2'b00; // default to word
                endcase
            end
            default: size_encoded = 2'b00; // default word for others
        endcase
    end

    // Instruction Memory
    memory #(
        .AWIDTH(32),
        .DWIDTH(32),
        .BASE_ADDR(32'h01000000)
       ) memory1 (
        .clk(clk),
        .rst(reset),
        .addr_i(f_pc),
        .addr_dat(alu_res),
        .data_i(data_i),
        .data_dat(rs2data_o),
        .read_en_i(read_en),
        .write_en_i(write_en),
        .read_en_dat(ctrl_memren),
        .write_en_dat(ctrl_memwren),
        .size_encoded(size_encoded), // new input for size encoding
        .data_o(f_insn),
        .data_dat_o(memory_data_i)
   );


    writeback #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_writeback (
        .pc_i(d_pc),
        .alu_res_i(alu_res),
        .memory_data_i(memory_data_i), 
        .wbsel_i(ctrl_wbsel),
        .brtaken_i(br_taken),
        .writeback_data_o(writeback_data_o),
        .next_pc_o(next_pc_o)
    );



    // Probes (required by testbench)

    `define PROBE_F_PC      f_pc
    `define PROBE_F_INSN    f_insn

    `define PROBE_D_PC      d_pc
    `define PROBE_D_OPCODE  d_opcode
    `define PROBE_D_RD      d_rd
    `define PROBE_D_FUNCT3  d_funct3
    `define PROBE_D_RS1     d_rs1
    `define PROBE_D_RS2     d_rs2
    `define PROBE_D_FUNCT7  d_funct7
    `define PROBE_D_IMM     d_imm
    `define PROBE_D_SHAMT   d_shamt

    `define PROBE_R_WRITE_ENABLE  ctrl_regwren  // ??
    `define PROBE_R_WRITE_DESTINATION  d_rd // ??
    `define PROBE_R_WRITE_DATA datawb_i // ??
    `define PROBE_R_READ_RS1 d_rs1  // ??
    `define PROBE_R_READ_RS2 d_rs2  // ??
    `define PROBE_R_READ_RS1_DATA rs1data_o    // ??
    `define PROBE_R_READ_RS2_DATA  rs2data_o   // ??

    `define PROBE_E_PC       d_pc         // ??
    `define PROBE_E_ALU_RES  alu_res       // ??
    `define PROBE_E_BR_TAKEN  br_taken       // ??

    `define PROBE_M_PC      d_pc          // ??
    `define PROBE_M_ADDRESS        alu_res   // ??
    `define PROBE_M_SIZE_ENCODED    size_encoded // ??
    `define PROBE_M_DATA            memory_data_i  // ??

    `define PROBE_W_PC            d_pc    // ??
    `define PROBE_W_ENABLE         ctrl_regwren  // ??
    `define PROBE_W_DESTINATION     d_rd  // ??
    `define PROBE_W_DATA      writeback_data_o        // ??


// program termination logic
reg is_program = 0;
always_ff @(posedge clk) begin
    if (f_insn == 32'h00000073) $finish;  // directly terminate if see ecall
    if (f_insn == 32'h00008067) is_program = 1;  // if see ret instruction, it is simple program test
    // [TODO] Change register_file_0.registers[2] to the appropriate x2 register based on your module instantiations...
    if (is_program && (u_register_file.regs[2] == 32'h01000000 + `MEM_DEPTH)) $finish;
end

endmodule : pd4