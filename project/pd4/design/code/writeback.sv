/*
 * Module: writeback
 *
 * Description: Write-back control stage implementation
 *
 * Inputs:
 * 1) PC pc_i
 * 2) result from alu alu_res_i
 * 3) data from memory memory_data_i
 * 4) data to select for write-back wbsel_i
 * 5) branch taken signal brtaken_i
 *
 * Outputs:
 * 1) DWIDTH wide write back data write_data_o
 * 2) AWIDTH wide next computed PC next_pc_o
 */

 module writeback #(
     parameter int DWIDTH=32,
     parameter int AWIDTH=32
 )(
     input logic [AWIDTH-1:0] pc_i,
     input logic [DWIDTH-1:0] alu_res_i,
     input logic [DWIDTH-1:0] memory_data_i,
     input logic [1:0] wbsel_i,
     input logic brtaken_i,
     output logic [DWIDTH-1:0] writeback_data_o,
     output logic [AWIDTH-1:0] next_pc_o
 );

    /*
     * Process definitions to be filled by
     * student below...
     */


     // Mux for write-back data selection we need to mux between alu result and memory data
    // ok essentially we have a mux that just selects between alu res
    // or memory data or pc+4 based on wbsel input 
    always_comb begin
        unique case (wbsel_i)
            2'd0: writeback_data_o = alu_res_i;        // ALU result
            2'd1: writeback_data_o = memory_data_i;    // Memory data
            2'd2: writeback_data_o = pc_i + 32'd4;     // PC + 4
            default: writeback_data_o = 0;
        endcase

    end

    assign next_pc_o = pc_i + 32'd4;  
endmodule : writeback