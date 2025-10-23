`include "constants.svh"

module decode #(
    parameter int DWIDTH = 32,
    parameter int AWIDTH = 32
)(
    input  logic clk,
    input  logic rst,
    input  logic [DWIDTH-1:0] insn_i,
    input  logic [AWIDTH-1:0] pc_i,

    output logic [AWIDTH-1:0] pc_o,
    output logic [DWIDTH-1:0] insn_o,
    output logic [6:0] opcode_o,
    output logic [4:0] rd_o,
    output logic [4:0] rs1_o,
    output logic [4:0] rs2_o,
    output logic [6:0] funct7_o,
    output logic [2:0] funct3_o,
    output logic [4:0] shamt_o,
    output logic [DWIDTH-1:0] imm_o
);

  

    // Field extraction (combinational logic)
    assign opcode_o = insn_o[6:0];       // [6:0]   opcode
    assign funct3_o = insn_o[14:12];     // [14:12] funct3
    assign rs1_o    = insn_o[19:15];     // [19:15] source 1


assign rd_o     = ((opcode_o == 7'h33) || (opcode_o == 7'h13) || (opcode_o == 7'h03) ||
                   (opcode_o == 7'h37) || (opcode_o == 7'h17) || (opcode_o == 7'h6F)) ? insn_i[11:7] : 5'b0;

assign rs2_o    = ((opcode_o == 7'h33) || (opcode_o == 7'h23) || (opcode_o == 7'h63)) ? insn_i[24:20] : 5'b0;
assign funct7_o = (opcode_o == 7'h33) ? insn_i[31:25] : 7'b0;
assign shamt_o  = insn_i[24:20];

    assign pc_o   = pc_i;
    assign insn_o = insn_i;

    
    // Immediate Generation (through the provided igen module)
    igen #(
        .DWIDTH(DWIDTH)
    ) u_igen (
        .opcode_i(opcode_o),
        .insn_i(insn_o),
        .imm_o(imm_o)
    );

endmodule : decode
