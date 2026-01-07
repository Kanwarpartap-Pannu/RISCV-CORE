/*
 * Good practice to define constants and refer to them in the
 * design files. An example of some constants are provided to you
 * as a starting point
 *
 */
`ifndef CONSTANTS_SVH_
`define CONSTANTS_SVH_

parameter logic [31:0] ZERO = 32'd0;

    // Opcode group definitions (RV32I base ISA)
    // Constants.svh not working here, so redefining
    parameter logic [6:0]
        OP_R      = 7'b0110011, // R-type
        OP_I      = 7'b0010011, // I-type arithmetic
        OP_LOAD   = 7'b0000011, // Load
        OP_STORE  = 7'b0100011, // Store
        OP_BRANCH = 7'b1100011, // Branch
        OP_JALR   = 7'b1100111, // Jump register
        OP_JAL    = 7'b1101111, // Jump and link
        OP_LUI    = 7'b0110111, // Load upper immediate
        OP_AUIPC  = 7'b0010111; // Add upper immediate to PC

    // ALU operation encodings
    parameter logic [3:0]
        ALU_ADD = 4'd0,
        ALU_SUB = 4'd1,
        ALU_AND = 4'd2,
        ALU_OR  = 4'd3,
        ALU_XOR = 4'd4,
        ALU_SLT = 4'd5,
        ALU_SLL = 4'd6,
        ALU_SRL = 4'd7,
        ALU_SRA = 4'd8,
        ALU_LUI = 4'd9,
        ALU_BRANCH = 4'd10,
        ALU_NOP = 4'd15;

`endif
