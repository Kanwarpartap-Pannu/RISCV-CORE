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
    input logic pcsel_o,
    input logic [DWIDTH - 1:0] alu_res, // target pc from alu according to cycle path if jump or branch
	// outputs	
	output logic [AWIDTH - 1:0] pc_o,
    output logic [DWIDTH - 1:0] insn_o
);
    /*
     * Process definitions to be filled by
     * student below...
     */

     // must be extended to include which pc to fetch from based on branch taken or not or jump instructions 
    
    logic [AWIDTH - 1:0] pc;
      
    always_ff @(posedge clk) begin 
        if (rst) begin
            pc <= BASEADDR;
        end else begin
            unique case (pcsel_o)
                1'b0: pc <= pc + 32'd4; // sequential
                1'b1: pc <= alu_res;         //  based on pcsel from control either branch target or jump target
                default: pc <= pc + 32'd4;
            endcase
        end
    end
       
	assign pc_o = pc;

endmodule : fetch
				
