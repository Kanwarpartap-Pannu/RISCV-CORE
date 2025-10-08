`timescale 1ns/1ps

module test_pd1;

  // Clock and reset
  logic clk;
  logic reset;

  // Probe signals
  wire [31:0] f_pc;
  wire [31:0] f_insn;
  wire [31:0] mem_data_out;

  // Clock generator: 10ns period
  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  // Reset sequence
  initial begin
    reset = 1;
    #20;
    reset = 0;
  end

  // Instantiate top module
  pd1 dut (
    .clk (clk),
    .rst (reset)   // ✅ make sure matches your pd1.sv
  );

  // Dump waves for GTKWave/ModelSim
  initial begin
    $dumpfile("pd1_tb.vcd");
    $dumpvars(0, test_pd1);
  end

  // Run simulation for some cycles
  initial begin
    #2000;   // run 2000ns
    $finish;
  end

  initial begin
  $monitor("Time=%0t PC=%h INSN=%h MEM_OUT=%h",
            $time, dut.f_pc, dut.f_insn, dut.mem_data_out);
  end


endmodule
