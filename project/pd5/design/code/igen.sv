`include "constants.svh"

/*
 * Module: igen
 *
 * Description: Immediate value generator
 *
 * Inputs:
 * 1) opcode opcode_i
 * 2) input instruction insn_i
 * Outputs:
 * 2) 32-bit immediate value imm_o
 */

module igen #(
    parameter int DWIDTH=32
    )(
    input  logic [6:0]        opcode_i,
    input  logic [DWIDTH-1:0] insn_i,
    output logic [31:0]       imm_o
);

    // Intermediate wires for different immediate types
    logic [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;

    // I-type (ADDI, ANDI, ORI, LOAD, JALR)
    assign imm_i = {{20{insn_i[31]}}, insn_i[31:20]};

    // S-type (STORE)
    assign imm_s = {{20{insn_i[31]}}, insn_i[31:25], insn_i[11:7]};

    // B-type (BEQ, BNE, BLT, etc.)
    assign imm_b = {{19{insn_i[31]}}, insn_i[31], insn_i[7],
                    insn_i[30:25], insn_i[11:8], 1'b0};

    // U-type (LUI, AUIPC)
    assign imm_u = {insn_i[31:12], 12'b0};

    // J-type (JAL)
    assign imm_j = {{11{insn_i[31]}}, insn_i[31], insn_i[19:12],
                    insn_i[20], insn_i[30:21], 1'b0};

    // Select correct immediate based on opcode
    always_comb begin

        unique case (opcode_i)
            OP_I, OP_LOAD, OP_JALR: imm_o = imm_i;
            OP_STORE:               imm_o = imm_s;
            OP_BRANCH:              imm_o = imm_b;
            OP_LUI, OP_AUIPC:       imm_o = imm_u;
            OP_JAL:                 imm_o = imm_j;
            default:                imm_o = 32'b0;
        endcase
        
    end

endmodule : igen
