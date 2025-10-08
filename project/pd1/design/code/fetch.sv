/*
 * Module: fetch
 *
 * Description: Fetch stage
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 *
 * Outputs:
 * 1) AWIDTH wide program counter pc_o
 * 2) DWIDTH wide instruction output insn_o
 */

module fetch #(
    parameter int DWIDTH   = 32,
    parameter int AWIDTH   = 32,
    parameter int BASEADDR = 32'h01000000
)(
    // inputs
    input  logic              clk,
    input  logic              rst,

    // outputs
    output logic [AWIDTH-1:0] pc_o,
    output logic [DWIDTH-1:0] insn_o,

    // connection to memory
    output logic [AWIDTH-1:0] mem_addr_o,
    output logic              mem_read_en_o,
    input  logic [DWIDTH-1:0] mem_data_i
);

    // Program counter
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            pc_o <= BASEADDR;
        end else begin
            pc_o <= pc_o + 4;
        end
    end

    // Memory interface
    assign mem_addr_o    = pc_o;
    assign mem_read_en_o = 1'b1;      // always reading instructions
    assign insn_o        = mem_data_i;

endmodule : fetch
