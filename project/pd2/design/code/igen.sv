/*
 * Module: igen
 *
 * Description: Immediate value generator
 *
 * Inputs:
 * 1) opcode opcode_i
 * Outputs:
 * 2) 32-bit immediate value imm_o
 */

// igen.sv
// Immediate generator for RISC-V

module igen (
    input  logic [31:0] ins_i,
    output logic [31:0] imm_o
);
    logic [6:0] opcode;
    assign opcode = ins_i[6:0];

    always_comb begin
        case (opcode)
            7'b0010011, 7'b0000011, 7'b1100111: // I-type (ADDI, LOAD, JALR)
                imm_o = {{20{ins_i[31]}}, ins_i[31:20]};

            7'b0100011: // S-type (STORE)
                imm_o = {{20{ins_i[31]}}, ins_i[31:25], ins_i[11:7]};

            7'b1100011: // B-type (BRANCH)
                imm_o = {{19{ins_i[31]}}, ins_i[31], ins_i[7], ins_i[30:25], ins_i[11:8], 1'b0};

            7'b0010111, 7'b0110111: // U-type (AUIPC, LUI)
                imm_o = {ins_i[31:12], 12'b0};

            7'b1101111: // J-type (JAL)
                imm_o = {{11{ins_i[31]}}, ins_i[31], ins_i[19:12], ins_i[20], ins_i[30:21], 1'b0};

            default:
                imm_o = 32'b0;
        endcase
    end
endmodule

