module pd4_testbench;
  wire clock, reset;
  clockgen clkg(
    .clk(clock),
    .rst(reset)
  );

  pd4 #(.AWIDTH(32), .DWIDTH(32)) dut (
        .clk(clk),
        .reset(reset)
    );

    // Dump for waveform view
    initial begin
        $dumpfile("pd4_tb.vcd");
        $dumpvars(0, pd4_testbench);
    end

    // ---------------------------------------------
    // Initialize instruction memory manually
    // ---------------------------------------------
    initial begin
        // Clear memory
        integer i;
        for (i = 0; i < 256; i = i + 1)
            dut.memory1.mem_array[i] = 32'b0;

        // Base address = 0x01000000

        //  ADDI x1, x0, 5        
        dut.memory1.mem_array[0] = 32'h00500093;

        //  ADDI x2, x0, 3        
        dut.memory1.mem_array[1] = 32'h00300113;

        //  ADD  x3, x1, x2       
        dut.memory1.mem_array[2] = 32'h002081B3;

        //  SUB  x4, x1, x2       
        dut.memory1.mem_array[3] = 32'h40208233;

        //  BEQ  x3, x4, 8
        dut.memory1.mem_array[4] = 32'h00418663;

        //  ADDI x5, x0, 9   
        dut.memory1.mem_array[5] = 32'h00900293;

        //  ADDI x6, x0, 6        
        dut.memory1.mem_array[6] = 32'h00600313;

        //  JAL  x0, -4           
        dut.memory1.mem_array[7] = 32'hFF5FF06F;
    end

    // Monitor key probe values
    always @(posedge clk) begin
        if (!reset) begin
            $display("[%0t] M(PC:0x%h ADDR:0x%h DATA:0x%h) | W(PC:0x%h EN:%b DEST:x%d DATA:0x%h)",
                $time,
                dut.`PROBE_M_PC,
                dut.`PROBE_M_ADDRESS,
                dut.`PROBE_M_DATA,
                dut.`PROBE_W_PC,
                dut.`PROBE_W_ENABLE,
                dut.`PROBE_W_DESTINATION,
                dut.`PROBE_W_DATA
            );
        end
    end

    // Stop simulation after some cycles
    initial begin
        #400;
        $display("==== Simulation finished ====");
        $finish;
    end



  endmodule