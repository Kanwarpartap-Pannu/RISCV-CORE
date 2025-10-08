/*
 * Module: decode
 *
 * Description: Decode stage
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 * 3) insn_iruction ins_i
 * 4) program counter pc_i
 * Outputs:
 * 1) AWIDTH wide program counter pc_o
 * 2) DWIDTH wide insn_iruction output insn_o
 * 3) 5-bit wide destination register ID rd_o
 * 4) 5-bit wide source 1 register ID rs1_o
 * 5) 5-bit wide source 2 register ID rs2_o
 * 6) 7-bit wide funct7 funct7_o
 * 7) 3-bit wide funct3 funct3_o
 * 8) 32-bit wide immediate imm_o
 * 9) 5-bit wide shift amount shamt_o
 * 10) 7-bit width opcode_o
 */

`include "constants.svh"

// decode.sv
// Decode stage of pipeline

module decode (
    input  logic [31:0] ins_i,

    // Outputs for control / datapath
    output logic [4:0]  rs1_o,
    output logic [4:0]  rs2_o,
    output logic [4:0]  rd_o,
    output logic [31:0] imm_o,

    // Control signals
    output logic       reg_write_o,
    output logic       mem_read_o,
    output logic       mem_write_o,
    output logic       mem_to_reg_o,
    output logic       alu_src_o,
    output logic       branch_o,
    output logic       jump_o,
    output logic [1:0] alu_op_o
);

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign opcode = ins_i[6:0];
    assign rd_o   = ins_i[11:7];
    assign funct3 = ins_i[14:12];
    assign rs1_o  = ins_i[19:15];
    assign rs2_o  = ins_i[24:20];
    assign funct7 = ins_i[31:25];

    // Immediate Generator
    igen igen_inst (
        .ins_i (ins_i),
        .imm_o (imm_o)
    );

    // Control Unit
    control control_inst (
        .opcode_i    (opcode),
        .funct3_i    (funct3),
        .funct7_i    (funct7),
        .reg_write_o (reg_write_o),
        .mem_read_o  (mem_read_o),
        .mem_write_o (mem_write_o),
        .mem_to_reg_o(mem_to_reg_o),
        .alu_src_o   (alu_src_o),
        .branch_o    (branch_o),
        .jump_o      (jump_o),
        .alu_op_o    (alu_op_o)
    );

endmodule

