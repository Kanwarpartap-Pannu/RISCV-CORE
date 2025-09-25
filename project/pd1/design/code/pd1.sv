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
    parameter int DWIDTH = 32
)(
    input  logic clk,
    input  logic reset
);

    // ---------------------------------------------------
    // Internal signals
    // ---------------------------------------------------

    logic [AWIDTH-1:0] pc;        // program counter
    logic [DWIDTH-1:0] insn;      // fetched instruction
    logic [DWIDTH-1:0] mem_data_out;

    // ---------------------------------------------------
    // Probe signals (driven by testbench)
    // ---------------------------------------------------
    logic [AWIDTH-1:0] probe_addr;
    logic [DWIDTH-1:0] probe_data_in;
    logic              probe_read_en;
    logic              probe_write_en;

    // ---------------------------------------------------
    // Muxed signals into memory
    // ---------------------------------------------------
    logic [AWIDTH-1:0] addr_sel;
    logic [DWIDTH-1:0] data_in_sel;
    logic              read_en_sel;
    logic              write_en_sel;

    // Testbench takes priority if it asserts read/write
    assign addr_sel     = (probe_read_en || probe_write_en) ? probe_addr     : pc;
    assign data_in_sel  = (probe_write_en)                  ? probe_data_in  : '0;
    assign read_en_sel  = (probe_read_en || probe_write_en) ? probe_read_en  : 1'b1;
    assign write_en_sel = (probe_read_en || probe_write_en) ? probe_write_en : 1'b0;

    // ---------------------------------------------------
    // FETCH stage
    // ---------------------------------------------------
    fetch #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_fetch (
        .clk   (clk),
        .rst   (reset),
        .data_i(mem_data_out),   // instruction from memory
        .pc_o  (pc),
        .insn_o(insn)
    );

    // ---------------------------------------------------
    // MEMORY
    // ---------------------------------------------------
    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_memory (
        .clk       (clk),
        .rst       (reset),
        .addr_i    (addr_sel),
        .data_i    (data_in_sel),
        .read_en_i (read_en_sel),
        .write_en_i(write_en_sel),
        .data_o    (mem_data_out)
    );

    // ---------------------------------------------------
    // Probes for testbench/macros
    // ---------------------------------------------------
    // pattern_check.h will use:
    //   `PROBE_ADDR, `PROBE_DATA_IN, `PROBE_DATA_OUT,
    //   `PROBE_READ_EN, `PROBE_WRITE_EN
    // which we mapped in probes.svh to these signals:
    //   probe_addr, probe_data_in, mem_data_out, probe_read_en, probe_write_en

endmodule : pd1
