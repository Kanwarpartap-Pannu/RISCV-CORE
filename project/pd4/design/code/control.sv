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

module control #(
	parameter int DWIDTH=32
)(
	// inputs
    input  logic [DWIDTH-1:0] insn_i,
    input  logic [6:0]        opcode_i,
    input  logic [6:0]        funct7_i,
    input  logic [2:0]        funct3_i,
    input  logic         br_taken,

    // outputs
    output logic              pcsel_o,
    output logic              immsel_o,
    output logic              regwren_o,
    output logic              rs1sel_o,
    output logic              rs2sel_o,
    output logic              memren_o,
    output logic              memwren_o,
    output logic [1:0]        wbsel_o,
    output logic [3:0]        alusel_o
);

    // Opcode group definitions (RV32I base ISA)
    // Constants.svh not working here, so redefining
    localparam [6:0]
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
    localparam [3:0]
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

    // Control signal generation
    always_comb begin
        // Default safe values
        pcsel_o    = 1'b0;
        immsel_o   = 1'b0;
        regwren_o  = 1'b0;
        rs1sel_o   = 1'b0;
        rs2sel_o   = 1'b0;
        memren_o   = 1'b0;
        memwren_o  = 1'b0;
        wbsel_o    = 2'b00;
        alusel_o   = ALU_NOP;

        unique case (opcode_i)

            // -------------------- R-TYPE --------------------
            OP_R: begin
                regwren_o  = 1'b1;   // Write to rd
                rs1sel_o   = 1'b1;
                rs2sel_o   = 1'b1;
                immsel_o   = 1'b0;
                wbsel_o    = 2'b00;  // Writeback from ALU
                memren_o   = 1'b0;
                memwren_o  = 1'b0;
                pcsel_o    = 1'b0;
                unique casez ({funct7_i, funct3_i})
                    {7'b0000000, 3'b000}: alusel_o = ALU_ADD;
                    {7'b0100000, 3'b000}: alusel_o = ALU_SUB;
                    {7'b0000000, 3'b111}: alusel_o = ALU_AND;
                    {7'b0000000, 3'b110}: alusel_o = ALU_OR;
                    {7'b0000000, 3'b100}: alusel_o = ALU_XOR;
                    {7'b0000000, 3'b010}: alusel_o = ALU_SLT;
                    {7'b0000000, 3'b001}: alusel_o = ALU_SLL;
                    {7'b0000000, 3'b101}: alusel_o = ALU_SRL;
                    {7'b0100000, 3'b101}: alusel_o = ALU_SRA;
                    default:              alusel_o = ALU_ADD;
                endcase
            end

            // -------------------- I-TYPE (ALU IMM) --------------------
            OP_I: begin
                regwren_o = 1'b1;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b1;
                rs2sel_o  = 1'b0;
                wbsel_o   = 2'b00;
                pcsel_o   = 1'b0;
                unique case (funct3_i)
                    3'b000: alusel_o = ALU_ADD; // ADDI
                    3'b111: alusel_o = ALU_AND; // ANDI
                    3'b110: alusel_o = ALU_OR;  // ORI
                    3'b100: alusel_o = ALU_XOR; // XORI
                    3'b010: alusel_o = ALU_SLT; // SLTI
                    3'b001: alusel_o = ALU_SLL; // SLLI
                    3'b101: alusel_o = (funct7_i == 7'b0000000) ? ALU_SRL : ALU_SRA;
                    default: alusel_o = ALU_ADD;
                endcase
            end

            // -------------------- LOAD --------------------
            OP_LOAD: begin
                regwren_o = 1'b1;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b1;
                rs2sel_o  = 1'b0;
                memren_o  = 1'b1;
                wbsel_o   = 2'b01; // Writeback from memory
                alusel_o  = ALU_ADD; // address = rs1 + imm
            end

            // -------------------- STORE --------------------
            OP_STORE: begin
                regwren_o = 1'b0;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b1;
                rs2sel_o  = 1'b0;
                memwren_o = 1'b1;
                alusel_o  = ALU_ADD;
            end

            // -------------------- BRANCH --------------------
            OP_BRANCH: begin
                regwren_o = 1'b0;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b0;
                rs2sel_o  = 1'b0;
                pcsel_o   = (br_taken) ? 1'b1 : 1'b0;  // use branch target PC
                alusel_o  = ALU_BRANCH; // for compare
            end

            // -------------------- JAL --------------------
            OP_JAL: begin
                regwren_o = 1'b1;
                pcsel_o   = 1'b1;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b0;
                rs2sel_o  = 1'b0;
                wbsel_o   = 2'b10; // write PC+4
                alusel_o  = ALU_ADD;
            end

            // -------------------- JALR --------------------
            OP_JALR: begin
                regwren_o = 1'b1;
                pcsel_o   = 1'b1;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b1;
                rs2sel_o  = 1'b0;
                wbsel_o   = 2'b10;
                alusel_o  = ALU_ADD;
            end

            // -------------------- LUI --------------------
            OP_LUI: begin
                regwren_o = 1'b1;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b0;
                rs2sel_o  = 1'b0;
                wbsel_o   = 2'b00;
                alusel_o  = ALU_LUI;
            end

            // -------------------- AUIPC --------------------
            OP_AUIPC: begin
                regwren_o = 1'b1;
                immsel_o  = 1'b1;
                rs1sel_o  = 1'b0;
                rs2sel_o  = 1'b0;
                wbsel_o   = 2'b00;
                alusel_o  = ALU_ADD;
            end

            // -------------------- DEFAULT --------------------
            default: begin
                // Already defaulted above
            end
        endcase
    end

endmodule : control
