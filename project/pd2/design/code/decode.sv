`include "constants.svh"

module decode #(
    parameter int DWIDTH = 32,
    parameter int AWIDTH = 32
)(
    input  logic clk,
    input  logic rst,
    input  logic [DWIDTH-1:0] insn_i,
    input  logic [DWIDTH-1:0] pc_i,

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

    // ------------------------------------------------------------------
    // Pipeline latch: Register PC and Instruction
    // ------------------------------------------------------------------
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            pc_o   <= '0;
            insn_o <= '0;
        end else begin
            pc_o   <= pc_i;
            insn_o <= insn_i;
        end
    end

    // ------------------------------------------------------------------
    // Field extraction (combinational logic)
    // ------------------------------------------------------------------
    assign opcode_o = insn_o[6:0];       // [6:0]   opcode
    assign rd_o     = insn_o[11:7];      // [11:7]  destination
    assign funct3_o = insn_o[14:12];     // [14:12] funct3
    assign rs1_o    = insn_o[19:15];     // [19:15] source 1
    assign rs2_o    = insn_o[24:20];     // [24:20] source 2
    assign funct7_o = insn_o[31:25];     // [31:25] funct7
    assign shamt_o  = insn_o[24:20];     // [24:20] shift amount (for shift ops)

    // ------------------------------------------------------------------
    // Immediate Generation (through the provided igen module)
    // ------------------------------------------------------------------
    igen #(
        .DWIDTH(DWIDTH)
    ) u_igen (
        .opcode_i(opcode_o),
        .insn_i(insn_o),
        .imm_o(imm_o)
    );

endmodule : decode
