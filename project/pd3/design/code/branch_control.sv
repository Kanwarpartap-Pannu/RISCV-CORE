`include "constants.svh"

/*
 * Module: branch_control
 *
 * Description: Branch control logic. Only sets the branch control bits based on the
 * branch instruction
 */

module branch_control #(
    parameter int DWIDTH=32
)(
    // inputs
    input  logic [6:0]               opcode_i,
    input  logic [2:0]               funct3_i,
    input  logic [DWIDTH-1:0]        rs1_i,
    input  logic [DWIDTH-1:0]        rs2_i,
    // outputs
    output logic                     breq_o,
    output logic                     brlt_o
);

    always_comb begin
        breq_o = 1'b0;
        brlt_o = 1'b0;

        if (opcode_i == `OP_BRANCH) begin
            breq_o = (rs1_i == rs2_i);
            // unsigned compare for BLTU / BGEU (funct3 == 110/111), signed otherwise
            if ((funct3_i == 3'b110) || (funct3_i == 3'b111)) begin
                brlt_o = (rs1_i < rs2_i);
            end else begin
                brlt_o = ($signed(rs1_i) < $signed(rs2_i));
            end
        end
    end

endmodule : branch_control

