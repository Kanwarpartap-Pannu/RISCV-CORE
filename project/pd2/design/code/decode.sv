`include "constants.svh"

module decode #(
    parameter int DWIDTH=32,
    parameter int AWIDTH=32
)(
	// inputs
	input logic clk,
	input logic rst,
	input logic [DWIDTH - 1:0] insn_i,
	input logic [DWIDTH - 1:0] pc_i,

    // outputs
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
    // Register PC and instruction (pipeline latch)
    // ------------------------------------------------------------------
    // pc_i is DWIDTH wide per template; pc_o is AWIDTH wide. Handle both
    // truncation and zero-extension safely based on parameters.
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            pc_o   <= '0;
            insn_o <= '0;
        end else begin
            // safe width conversion: if AWIDTH <= DWIDTH -> slice,
            // else zero-extend MSBs.
            if (AWIDTH <= DWIDTH) begin
                pc_o <= pc_i[AWIDTH-1:0];
            end else begin
                pc_o <= {{(AWIDTH-DWIDTH){1'b0}}, pc_i};
            end

            insn_o <= insn_i;
        end
    end

    // ------------------------------------------------------------------
    // Field extraction (combinational from the registered instruction)
    // ------------------------------------------------------------------
    // We extract from insn_o (the pipeline-registered instruction).
    // All extractions are safe when DWIDTH == 32 (default).
    assign opcode_o = insn_o[6:0];
    assign rd_o     = insn_o[11:7];
    assign funct3_o = insn_o[14:12];
    assign rs1_o    = insn_o[19:15];
    assign rs2_o    = insn_o[24:20];
    assign funct7_o = insn_o[31:25];
    assign shamt_o  = insn_o[24:20]; // shift amount (5 bits)

    // ------------------------------------------------------------------
    // Immediate generation - use existing igen module so behavior matches
    // ------------------------------------------------------------------
    // Connect the opcode extracted above and the registered instruction.
    // imm_o is DWIDTH bits; igen produces 32-bit imm (DWIDTH default = 32).
    igen #(
        .DWIDTH(DWIDTH)
    ) u_igen (
        .opcode_i(opcode_o),
        .insn_i(insn_o),
        .imm_o(imm_o)
    );

endmodule : decode
