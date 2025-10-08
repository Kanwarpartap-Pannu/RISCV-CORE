module pd1 #(
    parameter int AWIDTH   = 32,
    parameter int DWIDTH   = 32,
    parameter int BASEADDR = 32'h01000000
)(
    input  logic clk,
    input  logic reset
);

    // Fetch wires
    logic [AWIDTH-1:0] f_pc;
    logic [DWIDTH-1:0] f_insn;

    // Memory wires
    logic [AWIDTH-1:0] mem_addr;
    logic [DWIDTH-1:0] mem_data_in;
    logic [DWIDTH-1:0] mem_data_out;
    logic              mem_read_en;
    logic              mem_write_en;

    // Fetch stage
    fetch #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASEADDR(BASEADDR)
    ) u_fetch (
        .clk(clk),
        .rst(rst),
        .pc_o(f_pc),
        .insn_o(f_insn),
        .mem_addr_o(mem_addr),
        .mem_read_en_o(mem_read_en),
        .mem_data_i(mem_data_out)
    );

    // Instruction memory
    memory #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH),
        .BASE_ADDR(BASEADDR)
    ) u_memory (
        .clk(clk),
        .rst(rst),
        .addr_i(mem_addr),
        .data_i(mem_data_in),      // unused for fetch
        .read_en_i(mem_read_en),
        .write_en_i(mem_write_en), // tie low
        .data_o(mem_data_out)
    );

    // For now, disable writes
    assign mem_data_in  = '0;
    assign mem_write_en = 1'b0;

    `define PROBE_ADDR      mem_addr
`define PROBE_DATA_IN   mem_data_in
`define PROBE_DATA_OUT  mem_data_out
`define PROBE_READ_EN   mem_read_en
`define PROBE_WRITE_EN  mem_write_en

`define PROBE_F_PC      f_pc
`define PROBE_F_INSN    f_insn


endmodule : pd1
