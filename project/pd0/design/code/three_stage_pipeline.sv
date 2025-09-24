/*
 * Module: three_stage_pipeline
 *
 * A 3-stage pipeline (TSP) where the first stage performs an addition of two
 * operands (op1_i, op2_i) and registers the output, and the second stage computes
 * the difference between the output from the first stage and op1_i and registers the
 * output. This means that the output (res_o) must be available two cycles after the
 * corresponding inputs have been observed on the rising clock edge
 *
 * Visually, the circuit should look like this:
 *               <---         Stage 1           --->
 *                                                        <---         Stage 2           --->
 *                                                                                               <--    Stage 3    -->
 *                                    |------------------>|                    |
 * -- op1_i -->|                    | --> |         |     |                    |-->|         |   |                    |
 *             | pipeline registers |     | ALU add | --> | pipeline registers |   | ALU sub |-->| pipeline register  | -- res_o -->
 * -- op2_i -->|                    | --> |         |     |                    |-->|         |   |                    |
 *
 * Inputs:
 * 1) 1-bit clock signal
 * 2) 1-bit wide synchronous reset
 * 3) DWIDTH-wide input op1_i
 * 4) DWIDTH-wide input op2_i
 *
 * Outputs:
 * 1) DWIDTH-wide result res_o
 */

module three_stage_pipeline #(
parameter int DWIDTH = 8)(
        input logic clk,
        input logic rst,
        input logic [DWIDTH-1:0] op1_i,
        input logic [DWIDTH-1:0] op2_i,
        output logic [DWIDTH-1:0] res_o
    );

     // local constant for submodule parameter
    localparam int STAGE_DWIDTH = DWIDTH;

    // Stage 1
    logic [DWIDTH-1:0] stage1_res;

    alu #(.DWIDTH(STAGE_DWIDTH)) alu_stage1 (
        .sel_i(2'b00),        // ADD operation
        .op1_i(op1_i),
        .op2_i(op2_i),
        .res_o(stage1_res),
        .zero_o(),
        .neg_o()
    );

    logic [DWIDTH-1:0] stage1_reg_out;

    reg_rst #(.DWIDTH(STAGE_DWIDTH)) reg_stage1 (
        .clk(clk),
        .rst(rst),
        .in_i(stage1_res),
        .out_o(stage1_reg_out)
    );

    // Stage 2
    alu #(.DWIDTH(STAGE_DWIDTH)) alu_stage2 (
        .sel_i(2'b01),       // SUB operation
        .op1_i(stage1_reg_out),
        .op2_i(op1_i),
        .res_o(stage1_res),  // reuse stage1_res as temporary
        .zero_o(),
        .neg_o()
    );

    logic [DWIDTH-1:0] stage2_reg_out;

    reg_rst #(.DWIDTH(STAGE_DWIDTH)) reg_stage2 (
        .clk(clk),
        .rst(rst),
        .in_i(stage1_res),
        .out_o(stage2_reg_out)
    );

    // Stage 3
    reg_rst #(.DWIDTH(STAGE_DWIDTH)) reg_stage3 (
        .clk(clk),
        .rst(rst),
        .in_i(stage2_reg_out),
        .out_o(res_o)
    );


endmodule: three_stage_pipeline