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
    input  logic reset
);

    // ----------------------------------------------------
    // FETCH stage wires
    // ----------------------------------------------------
    logic [AWIDTH-1:0] f_pc;
    logic [DWIDTH-1:0] f_insn;

    // ----------------------------------------------------
    // MEMORY interface wires
    // ----------------------------------------------------
    logic [AWIDTH-1:0] mem_addr;
    logic [DWIDTH-1:0] mem_data_in;
    logic [DWIDTH-1:0] mem_data_out;
    logic              mem_read_en;
    logic              mem_write_en;

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

    // ----------------------------------------------------
    // Instantiate fetch (instruction fetch from memory)
    // ----------------------------------------------------
    fetch #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASEADDR(BASEADDR)
    ) u_fetch (
        .clk(clk),
        .rst(reset),              // fetch expects 'rst'
        .pc_o(f_pc),
        .insn_o(f_insn),
        .mem_addr_o(mem_addr),
        .mem_read_en_o(mem_read_en),
        .mem_data_i(mem_data_out)
    );

    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASE_ADDR(BASEADDR)
    ) u_memory (
        .clk(clk),
        .rst(reset),              // memory expects 'rst'
        .addr_i(mem_addr),
        .data_i(mem_data_in),
        .read_en_i(mem_read_en),
        .write_en_i(mem_write_en),
        .data_o(mem_data_out)
    );


    // no writes for now (fetch-only)
    assign mem_data_in  = '0;
    assign mem_write_en = 1'b0;

    // ----------------------------------------------------
    // Decode stage
    // Must match decode module header exactly (14 ports)
    // ----------------------------------------------------
    decode #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_decode (
        .clk(clk),                // input
        .rst(reset),              // input (module uses 'rst')
        .insn_i(f_insn),          // input
        .pc_i(f_pc),              // input

        // outputs (all supplied)
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
    // Immediate generator (igen)
    // Matches igen header: opcode_i, insn_i -> imm_o
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
    // Matches control header exactly
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
    // Probes (same pattern as pd1)
    // Keep macros exactly as in pd1 to pass the testbench checks
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
