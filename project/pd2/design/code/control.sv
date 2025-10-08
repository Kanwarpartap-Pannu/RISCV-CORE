/*
 * Module: control
 *
 * Description: This module sets the control bits (control path) based on the decoded
 * instruction. Note that this is part of the decode stage but housed in a separate
 * module for better readability, debug and design purposes.
 *
 * Inputs:
 * 1) DWIDTH instruction ins_i
 * 2) 7-bit opcode opcode_i
 * 3) 7-bit funct7 funct7_i
 * 4) 3-bit funct3 funct3_i
 *
 * Outputs:
 * 1) 1-bit PC select pcsel_o
 * 2) 1-bit Immediate select immsel_o
 * 3) 1-bit register write en regwren_o
 * 4) 1-bit rs1 select rs1sel_o
 * 5) 1-bit rs2 select rs2sel_o
 * 6) k-bit ALU select alusel_o
 * 7) 1-bit memory read en memren_o
 * 8) 1-bit memory write en memwren_o
 * 9) 2-bit writeback sel wbsel_o
 */

`include "constants.svh"
// control.sv
// Generates control signals based on opcode, funct3, and funct7

module control (
    input  logic [6:0] opcode_i,
    input  logic [2:0] funct3_i,
    input  logic [6:0] funct7_i,

    output logic       reg_write_o,
    output logic       mem_read_o,
    output logic       mem_write_o,
    output logic       mem_to_reg_o,
    output logic       alu_src_o,
    output logic       branch_o,
    output logic       jump_o,
    output logic [1:0] alu_op_o
);

    // RISC-V opcodes
    localparam OPCODE_RTYPE = 7'b0110011;
    localparam OPCODE_ITYPE = 7'b0010011;
    localparam OPCODE_LOAD  = 7'b0000011;
    localparam OPCODE_STORE = 7'b0100011;
    localparam OPCODE_BRANCH= 7'b1100011;
    localparam OPCODE_JAL   = 7'b1101111;
    localparam OPCODE_JALR  = 7'b1100111;
    localparam OPCODE_LUI   = 7'b0110111;
    localparam OPCODE_AUIPC = 7'b0010111;

    always_comb begin
        // default values
        reg_write_o  = 0;
        mem_read_o   = 0;
        mem_write_o  = 0;
        mem_to_reg_o = 0;
        alu_src_o    = 0;
        branch_o     = 0;
        jump_o       = 0;
        alu_op_o     = 2'b00;

        case (opcode_i)
            OPCODE_RTYPE: begin
                reg_write_o  = 1;
                alu_op_o     = 2'b10; // determined by funct3/funct7
            end

            OPCODE_ITYPE: begin
                reg_write_o  = 1;
                alu_src_o    = 1;
                alu_op_o     = 2'b11; // I-type ALU
            end

            OPCODE_LOAD: begin
                reg_write_o  = 1;
                mem_read_o   = 1;
                mem_to_reg_o = 1;
                alu_src_o    = 1;
                alu_op_o     = 2'b00;
            end

            OPCODE_STORE: begin
                mem_write_o  = 1;
                alu_src_o    = 1;
                alu_op_o     = 2'b00;
            end

            OPCODE_BRANCH: begin
                branch_o     = 1;
                alu_op_o     = 2'b01;
            end

            OPCODE_JAL, OPCODE_JALR: begin
                reg_write_o  = 1;
                jump_o       = 1;
            end

            OPCODE_LUI, OPCODE_AUIPC: begin
                reg_write_o  = 1;
                alu_src_o    = 1;
            end

            default: begin
                // invalid or unsupported instruction
            end
        endcase
    end

endmodule
