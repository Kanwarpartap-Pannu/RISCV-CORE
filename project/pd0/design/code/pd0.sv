/*
 * Module: pd0
 *
 * Description: Top level module that will contain sub-module instantiations.
 * An instantiation of the assign_xor module is shown as an example. The other
 * modules must be instantiated similarly. Probes are defined, which will be used
 * to test This file also defines probes that will be used to test the design. Note
 * that the top level module should have only two inputs: clk and rest signals.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

// Include the probe definitions
`include "../probes.svh"

module pd0 #(
    parameter int DWIDTH = 32
)(
    input logic clk,
    input logic reset
);

    // assign_xor signals + instantiation
    logic assign_xor_op1;
    logic assign_xor_op2;
    logic assign_xor_res;

    assign_xor assign_xor_0 (
        .op1_i(assign_xor_op1),
        .op2_i(assign_xor_op2),
        .res_o(assign_xor_res)
    );

    // Connect probes
    assign `PROBE_ASSIGN_XOR_OP1 = assign_xor_op1;
    assign `PROBE_ASSIGN_XOR_OP2 = assign_xor_op2;
    assign `PROBE_ASSIGN_XOR_RES = assign_xor_res;

    // ALU signals + instantiation
    logic [DWIDTH-1:0] alu_op1;
    logic [DWIDTH-1:0] alu_op2;
    logic [1:0]        alu_sel;
    logic [DWIDTH-1:0] alu_res;

    alu #(.DWIDTH(DWIDTH)) alu_0 (
        .sel_i(alu_sel),
        .op1_i(alu_op1),
        .op2_i(alu_op2),
        .res_o(alu_res),
        .zero_o(),  // not observed
        .neg_o()    // not observed
    );

    // Connect probes
    assign `PROBE_ALU_OP1 = alu_op1;
    assign `PROBE_ALU_OP2 = alu_op2;
    assign `PROBE_ALU_SEL = alu_sel;
    assign `PROBE_ALU_RES = alu_res;

    // Register signals + instantiation
    logic [DWIDTH-1:0] reg_in;
    logic [DWIDTH-1:0] reg_out;

    reg_rst #(.DWIDTH(DWIDTH)) reg_0 (
        .clk(clk),
        .rst(reset),
        .in_i(reg_in),
        .out_o(reg_out)
    );

    // Connect probes
    assign `PROBE_REG_IN  = reg_in;
    assign `PROBE_REG_OUT = reg_out;

    // Three-stage pipeline signals + instantiation
    logic [DWIDTH-1:0] pipe_op1;
    logic [DWIDTH-1:0] pipe_op2;
    logic [DWIDTH-1:0] pipe_res;

    three_stage_pipeline #(.DWIDTH(DWIDTH)) pipeline_0 (
        .clk(clk),
        .rst(reset),
        .op1_i(pipe_op1),
        .op2_i(pipe_op2),
        .res_o(pipe_res)
    );

    // Connect probes
    assign `PROBE_TSP_OP1 = pipe_op1;
    assign `PROBE_TSP_OP2 = pipe_op2;
    assign `PROBE_TSP_RES = pipe_res;

endmodule: pd0