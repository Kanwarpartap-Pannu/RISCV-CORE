/*
 * Module: pd2
 *
 * Top-level module connecting Fetch, Decode, IGEN, Control and Memory.
 */

`include "constants.svh"

module pd2 #(
    parameter int AWIDTH   = 32,
    parameter int DWIDTH   = 32,
    parameter int BASEADDR = 32'h01000000
)(
    input  logic clk,
    input  logic reset   // external connection (wrapper expects this)
);


    // ----------------------------------------------------
    // DECODE stage outputs
    // ----------------------------------------------------
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

    // ----------------------------------------------------
    // CONTROL outputs
    // ----------------------------------------------------
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
       
    memory #(
        .AWIDTH(32),
        .DWIDTH(32),
        .BASE_ADDR(32'h01000000)
       ) memory1 (
        .clk(clk),
        .rst(reset),
        .addr_i(f_pc),
        .data_i(data_i),
        .read_en_i(read_en),
        .write_en_i(write_en),
        .data_o(f_insn)
   );
 
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
        .pc_o(f_pc)           
        //.insn_o(f_insn)         
    );

    // ----------------------------------------------------
    // Decode stage
    // ----------------------------------------------------
    decode #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_decode (
        .clk(clk),
        .rst(rst),
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

    // ----------------------------------------------------
    // Immediate generator
    // ----------------------------------------------------
    igen #(
        .DWIDTH(DWIDTH)
    ) u_igen (
        .opcode_i(d_opcode),
        .insn_i(d_insn),
        .imm_o(d_imm)
    );

    // ----------------------------------------------------
    // Control unit
    // ----------------------------------------------------
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

    // ----------------------------------------------------
    // Probes (required by testbench)
    // ----------------------------------------------------
    `define PROBE_ADDR      mem_addr
    `define PROBE_DATA_IN   mem_data_in
    `define PROBE_DATA_OUT  mem_data_out
    `define PROBE_READ_EN   mem_read_en
    `define PROBE_WRITE_EN  mem_write_en

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

endmodule : pd2
