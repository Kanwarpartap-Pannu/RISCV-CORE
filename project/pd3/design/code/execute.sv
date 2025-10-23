/*
 * Module: alu
 *
 * Description: ALU implementation for execute stage.
 *
 * Inputs:
 * 1) 32-bit PC pc_i
 * 2) 32-bit rs1 data rs1_i
 * 3) 32-bit rs2 data rs2_i
 * 4) 3-bit funct3 funct3_i
 * 5) 7-bit funct7 funct7_i
 *
 * Outputs:
 * 1) 32-bit result of ALU res_o
 * 2) 1-bit branch taken signal brtaken_o
 */

module alu #(
    parameter int DWIDTH=32,
    parameter int AWIDTH=32
)(
    input logic [AWIDTH-1:0] pc_i,
    input logic [DWIDTH-1:0] rs1_i,
    input logic [DWIDTH-1:0] rs2_i,
    input logic [2:0] funct3_i,
    input logic [6:0] funct7_i,
    output logic [DWIDTH-1:0] res_o,
    output logic brtaken_o
);

    // lower 5 bits used as shift amount for RV32
    logic [4:0] shamt;

    always_comb begin
        shamt = rs2_i[4:0];
        // defaults
        res_o     = '0;
        brtaken_o = 1'b0;

        // ALU datapath: arithmetic / logical / shift ops selected by funct3/funct7
        unique case (funct3_i)
            3'b000: begin
                // ADD / SUB (SUB indicated by funct7 == 7'b0100000)
                if (funct7_i == 7'b0100000)
                    res_o = rs1_i - rs2_i; // SUB
                else
                    res_o = rs1_i + rs2_i; // ADD (also used for load/store addr calc)
            end

            3'b001: res_o = rs1_i << shamt; // SLL

            3'b010: // SLT (signed)
                res_o = ($signed(rs1_i) < $signed(rs2_i)) ? 32'd1 : 32'd0;

            3'b011: // SLTU (unsigned)
                res_o = (rs1_i < rs2_i) ? 32'd1 : 32'd0;

            3'b100: res_o = rs1_i ^ rs2_i; // XOR

            3'b101: begin // SRL / SRA
                if (funct7_i == 7'b0100000)
                    res_o = $signed(rs1_i) >>> shamt; // SRA (arithmetic)
                else
                    res_o = rs1_i >> shamt;           // SRL (logical)
            end

            3'b110: res_o = rs1_i | rs2_i; // OR
            3'b111: res_o = rs1_i & rs2_i; // AND

            default: res_o = rs1_i + rs2_i;
        endcase

        // Branch comparison results (funct3 encodes branch type)
        unique case (funct3_i)
            3'b000: brtaken_o = (rs1_i == rs2_i);                   // BEQ
            3'b001: brtaken_o = (rs1_i != rs2_i);                   // BNE
            3'b100: brtaken_o = ($signed(rs1_i) < $signed(rs2_i));  // BLT
            3'b101: brtaken_o = ($signed(rs1_i) >= $signed(rs2_i)); // BGE
            3'b110: brtaken_o = (rs1_i < rs2_i);                    // BLTU
            3'b111: brtaken_o = (rs1_i >= rs2_i);                   // BGEU
            default: brtaken_o = 1'b0;
        endcase
    end

endmodule : alu
