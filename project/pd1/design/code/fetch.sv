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
    parameter int DWIDTH=32,
    parameter int AWIDTH=32,
    parameter int BASEADDR=32'h01000000
    )(
	// inputs
	input logic clk,
	input logic rst,
    input  logic [DWIDTH-1:0] data_i,   // instruction word from memory
	// outputs	
	output logic [AWIDTH - 1:0] pc_o,   // program counter (address to memory)
    output logic [DWIDTH - 1:0] insn_o  // instruction fetched
);
    
    // Program Counter
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            pc_o <= BASEADDR; // start address
        end else begin
            pc_o <= pc_o + 4; // increment PC by word (4 bytes)
        end
    end

    // Instruction register
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            insn_o <= '0;
        end else begin
            insn_o <= data_i; // latch instruction from memory
        end
    end


endmodule : fetch
				