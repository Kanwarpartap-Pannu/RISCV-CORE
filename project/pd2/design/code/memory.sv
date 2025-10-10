/*
 * Module: pd2
 *
 * Description: Top level module that will contain sub-module instantiations.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

`include "constants.svh"

module pd2 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32
)(
    input  logic clk,
    input  logic reset
);

    // ------------------------------------------------------
    // ---- Internal pipeline wires ----
    // ------------------------------------------------------

    // FETCH <-> MEMORY interface
    logic [AWIDTH-1:0] mem_addr;
    logic              mem_read_en;
    logic [DWIDTH-1:0] mem_data;

    // FETCH outputs
    logic [AWIDTH-1:0] f_pc;
    logic [DWIDTH-1:0] f_insn;

    // DECODE outputs
    logic [6:0] d_opcode, d_funct7;
    logic [2:0] d_funct3;
    logic [4:0] d_rs1, d_rs2, d_rd;
    logic [31:0] d_imm, d_shamt;

    // CONTROL outputs
    logic pcsel, immsel, regwren, rs1sel, rs2sel;
    logic memren, memwren;
    logic [1:0] wbsel;
    logic [3:0] alusel;

    // MEMORY data output
    logic [DWIDTH-1:0] mem_data_out;

    // ------------------------------------------------------
    // ---- MEMORY (Instruction + Data Memory) ----
    // ------------------------------------------------------
    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_memory (
        .clk(clk),
        .rst(reset),
        .addr_i(mem_addr),
        .data_i('0),           // No data writes from fetch
        .read_en_i(mem_read_en),
        .write_en_i(1'b0),
        .data_o(mem_data)
    );

    // ------------------------------------------------------
    // ---- FETCH stage ----
    // ------------------------------------------------------
    fetch #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_fetch (
        .clk(clk),
        .rst(reset),
        .pc_o(f_pc),
        .insn_o(f_insn),
        .mem_addr_o(mem_addr),
        .mem_read_en_o(mem_read_en),
        .mem_data_i(mem_data)
    );

    // ------------------------------------------------------
    // ---- DECODE stage ----
    // ------------------------------------------------------
    decode u_decode (
        .insn_i(f_insn),
        .opcode_o(d_opcode),
        .funct3_o(d_funct3),
        .funct7_o(d_funct7),
        .rs1_o(d_rs1),
        .rs2_o(d_rs2),
        .rd_o(d_rd),
        .imm_o(d_imm),
        .shamt_o(d_shamt)
    );

    // ------------------------------------------------------
    // ---- CONTROL path ----
    // ------------------------------------------------------
    control u_control (
        .insn_i(f_insn),
        .opcode_i(d_opcode),
        .funct7_i(d_funct7),
        .funct3_i(d_funct3),
        .pcsel_o(pcsel),
        .immsel_o(immsel),
        .regwren_o(regwren),
        .rs1sel_o(rs1sel),
        .rs2sel_o(rs2sel),
        .memren_o(memren),
        .memwren_o(memwren),
        .wbsel_o(wbsel),
        .alusel_o(alusel)
    );

    // ------------------------------------------------------
    // ---- IMMEDIATE GENERATOR ----
    // ------------------------------------------------------
    igen #(
        .DWIDTH(DWIDTH)
    ) u_igen (
        .opcode_i(d_opcode),
        .insn_i(f_insn),
        .imm_o(d_imm)
    );

    // ------------------------------------------------------
    // ---- PROBES ----
    // ------------------------------------------------------
    // Enable these defines in constants.svh or uncomment here for waveform observation

    //`define PROBE_F_PC
    //`define PROBE_F_INSN
    //`define PROBE_D_OPCODE
    //`define PROBE_D_FUNCT3
    //`define PROBE_D_FUNCT7
    //`define PROBE_D_RS1
    //`define PROBE_D_RS2
    //`define PROBE_D_RD
    //`define PROBE_D_IMM
    //`define PROBE_D_SHAMT

    `ifdef PROBE_F_PC
        logic [AWIDTH-1:0] probe_f_pc = f_pc;
    `endif

    `ifdef PROBE_F_INSN
        logic [DWIDTH-1:0] probe_f_insn = f_insn;
    `endif

    `ifdef PROBE_D_OPCODE
        logic [6:0] probe_d_opcode = d_opcode;
    `endif

    `ifdef PROBE_D_FUNCT3
        logic [2:0] probe_d_funct3 = d_funct3;
    `endif

    `ifdef PROBE_D_FUNCT7
        logic [6:0] probe_d_funct7 = d_funct7;
    `endif

    `ifdef PROBE_D_RS1
        logic [4:0] probe_d_rs1 = d_rs1;
    `endif

    `ifdef PROBE_D_RS2
        logic [4:0] probe_d_rs2 = d_rs2;
    `endif

    `ifdef PROBE_D_RD
        logic [4:0] probe_d_rd = d_rd;
    `endif

    `ifdef PROBE_D_IMM
        logic [31:0] probe_d_imm = d_imm;
    `endif

    `ifdef PROBE_D_SHAMT
        logic [31:0] probe_d_shamt = d_shamt;
    `endif

endmodule : pd2
