/*
 * Module: pd1
 *
 * Description: Top level module that will contain sub-module instantiations.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

module pd1 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32)(
    input logic clk,
    input logic reset
);

 
    //Internal signals

    logic [AWIDTH-1:0] pc;      // program counter
    logic [DWIDTH-1:0] insn;    // fetched instruction


    //Memory interface

    logic [DWIDTH-1:0] mem_data_out;

    //Instantiate FETCH stage
  
    fetch #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_fetch (
        .clk   (clk),
        .rst   (reset),
        .data_i(mem_data_out),  // instruction from memory
        .pc_o  (pc),
        .insn_o(insn)
    );

    // Instantiate MEMORY
    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_memory (
        .clk       (clk),
        .rst       (reset),
        .addr_i    (pc),         // fetch provides PC as address
        .data_i    ('0),         // no writes in PD1
        .read_en_i (1'b1),       // always reading instructions
        .write_en_i(1'b0),       // no writes in fetch
        .data_o    (mem_data_out)
    );

    // Add probes for testing/monitoring (link with design/probes.svh)

endmodule : pd1