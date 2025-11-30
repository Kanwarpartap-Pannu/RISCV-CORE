/*
 * Module: writeback
 *
 * Description: Write-back control stage implementation
 *
 * Inputs:
 * 1) PC pc_i
 * 2) result from alu alu_res_i
 * 3) data from memory memory_data_i
 * 4) branch taken signal brtaken_i
 *
 * Outputs:
 * 1) DWIDTH wide write back data write_data_o
 */

module writeback #(
    parameter int DWIDTH=32,
    parameter int AWIDTH=32
) (
    input  logic [AWIDTH-1:0] pc_i,
    input  logic [DWIDTH-1:0] alu_res_i,
    input  logic [DWIDTH-1:0] memory_data_i,
    input  logic [1:0]       wbsel_i,          // 00=ALU, 01=MEM, 10=PC+4
    input  logic             brtaken_i,
    output logic [DWIDTH-1:0] writeback_data_o,
    output logic [AWIDTH-1:0] next_pc_o
);

    always_comb begin
        unique case (wbsel_i)
            2'b00: writeback_data_o = alu_res_i;
            2'b01: writeback_data_o = memory_data_i;
            2'b10: writeback_data_o = pc_i + 32'd4;
            default: writeback_data_o = alu_res_i;
        endcase

        // Provide next_pc_o
        next_pc_o = pc_i + 32'd4;
    end

endmodule : writeback