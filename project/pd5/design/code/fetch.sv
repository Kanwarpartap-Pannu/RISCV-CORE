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
    input logic pcsel,
    input logic br_taken,
    input logic stall, 
    input logic [DWIDTH - 1:0] alu_res, 

	// outputs	
	output logic [AWIDTH - 1:0] pc_o,
    output logic [DWIDTH - 1:0] insn_o
);
   

    logic [AWIDTH - 1:0] pc;
    logic pcsel_o;
    
    // control signal to select pc for branch or jal/jalr instructions
    assign pcsel_o = (pcsel || br_taken); 
      
    always_ff @(posedge clk) begin 

        if (rst) begin
            pc <= BASEADDR;
        end 

        else if (stall) begin 
            pc <= pc;
        end

        else begin
            unique case (pcsel_o)
                1'b0: pc <= pc + 32'd4; // sequential
                1'b1: pc <= alu_res;    // target pc
                default: pc <= pc + 32'd4;
            endcase
        end

    end
       
	assign pc_o = pc;

endmodule : fetch
				
