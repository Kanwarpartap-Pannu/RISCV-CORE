`timescale 1ns/1ps

module test_pd2;

    // Parameters
    localparam AWIDTH = 32;
    localparam DWIDTH = 32;

    // DUT signals
    logic clk;
    logic reset;

    // Instantiate DUT
    pd2 #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) dut (
        .clk(clk),
        .reset(reset)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk; // 100MHz clock

    // Reset sequence
    initial begin
        reset = 1;
        #20;
        reset = 0;
    end

    // Optional: Monitor outputs
    initial begin
        $display("Time\tPC\tINSTRUCTION\tOPCODE\tRD\tRS1\tRS2\tFUNCT3\tFUNCT7\tIMM");
        $monitor("%0t\t%h\t%h\t%h\t%h\t%h\t%h\t%h\t%h\t%h",
            $time,
            dut.`PROBE_D_PC,
            dut.`PROBE_F_INSN,
            dut.`PROBE_D_OPCODE,
            dut.`PROBE_D_RD,
            dut.`PROBE_D_RS1,
            dut.`PROBE_D_RS2,
            dut.`PROBE_D_FUNCT3,
            dut.`PROBE_D_FUNCT7,
            dut.`PROBE_D_IMM
        );
    end

    // Simulation end
    initial begin
        #5000;
        $finish;
    end

endmodule