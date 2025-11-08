/*
 * Module: memory
 *
 * Description: Byte-addressable memory implementation. Supports both read and write operations.
 * Reads are combinational and writes are performed on the rising clock edge.
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 * 3) AWIDTH address addr_i
 * 4) DWIDTH data to write data_i
 * 5) read enable signal read_en_i
 * 6) write enable signal write_en_i
 *
 * Outputs:
 * 1) DWIDTH data output data_o
 */

module memory #(
  // parameters
  parameter int AWIDTH = 32,
  parameter int DWIDTH = 32,
  parameter logic [31:0] BASE_ADDR = 32'h01000000,
  parameter logic [31:0] MEM_DEPTH = 32'h00000268
) (
  // inputs
  input logic clk,
  input logic rst,
  input logic [AWIDTH-1:0] addr_i = BASE_ADDR,
  input logic [AWIDTH-1:0] addr_dat = BASE_ADDR,
  input logic [DWIDTH-1:0] data_i,
  input logic [DWIDTH-1:0] data_dat,
  input logic read_en_i,
  input logic write_en_i,
  input logic read_en_dat,
  input logic write_en_dat,
  input logic [1:0] size_encoded, // new input for size encoding
  // outputs
  output logic [DWIDTH-1:0] data_o,
  output logic [DWIDTH-1:0] data_dat_o
);

    localparam int MEM_BYTES = MEM_DEPTH * (DWIDTH/8);

	logic [DWIDTH-1:0] temp_memory [0:`LINE_COUNT - 1];
   	// Byte-addressable memory
  	logic [7:0] main_memory [0:MEM_BYTES - 1];  // Byte-addressable memory
   	logic [AWIDTH-1:0] address;
    logic [AWIDTH-1:0] address_dat;
   	assign address = addr_i - BASE_ADDR;
    assign address_dat = ((32'(addr_dat) < 32'(BASE_ADDR)) ?
                      ((32'(addr_dat) + 32'(BASE_ADDR)) - 32'(BASE_ADDR)) :
                      ((addr_dat) - (BASE_ADDR))) % MEM_BYTES;
  	int i;
 
   	initial begin

        // Initialize all main memory bytes to 0
    for (i = 0; i < MEM_BYTES; i++) begin
        main_memory[i] = 8'h00;
    end
        $readmemh(`MEM_PATH, temp_memory);
        // Load data from temp_memory into main_memory
		for (i = 0; i < `LINE_COUNT; i++) begin
       	    main_memory[4*i]     = temp_memory[i][7:0];
       		main_memory[4*i + 1] = temp_memory[i][15:8];
       		main_memory[4*i + 2] = temp_memory[i][23:16];
       		main_memory[4*i + 3] = temp_memory[i][31:24];
     	end
		$display("IMEMORY: Loaded %0d 32-bit words from %s", `LINE_COUNT, `MEM_PATH);
	end

	always_comb begin
	    data_o = '0; // default to zero
        if (read_en_i) begin
            if ($isunknown(addr_i)) begin
                data_o = '0;
            end else if ((addr_i >= BASE_ADDR) && (addr_i + 32'd3 < BASE_ADDR + MEM_BYTES)) begin
                // Word-aligned fetch: little-endian assembly
                data_o = {
                          main_memory[address + 3],
                          main_memory[address + 2],
                          main_memory[address + 1],
                          main_memory[address]
                };
            end else begin
                data_o = 32'hDEAD_BEEF;
                //$display("IMEMORY: OOB read @0x%08h (mapped 0x%08h)", addr_i, address);
            end
        end
  	end

    always_comb begin
	    data_dat_o = '0; // default to zero
        if (read_en_i) begin
            if ($isunknown(addr_dat)) begin
                data_dat_o = '0;
            end else if (read_en_i) begin
                // Word-aligned fetch: little-endian assembly
                data_dat_o = {
                          main_memory[address_dat + 3],
                          main_memory[address_dat + 2],
                          main_memory[address_dat + 1],
                          main_memory[address_dat]
                };
            end else begin
                data_dat_o = 32'h0;
                //$display("IMEMORY: OOB read @0x%08h (mapped 0x%08h)", addr_dat, address);
            end
        end
  	end

    always_ff @(posedge clk) begin
        if (write_en_dat) begin
            if (write_en_dat) begin
                main_memory[address_dat] <= data_dat[7:0];
                main_memory[address_dat + 1] <= data_dat[15:8];
                main_memory[address_dat + 2] <= data_dat[23:16];
                main_memory[address_dat + 3] <= data_dat[31:24];
                $display("[%0t] IMEMORY: Wrote 0x%08h to 0x%08h",$time, data_dat, addr_dat);
            end else begin
                //$display("IMEMORY: OOB write @0x%08h", addr_i);
            end
        end
 	end
	
	always_ff @(posedge clk) begin
        if (write_en_i) begin
            if ((addr_i >= BASE_ADDR) && (addr_i + 32'd3 < BASE_ADDR + MEM_BYTES)) begin
                main_memory[address] <= data_i[7:0];
                main_memory[address + 1] <= data_i[15:8];
                main_memory[address + 2] <= data_i[23:16];
                main_memory[address + 3] <= data_i[31:24];
                //$display("IMEMORY: Wrote 0x%08h to 0x%08h", data_i, addr_i);
            end else begin
                //$display("IMEMORY: OOB write @0x%08h", addr_i);
            end
        end
 	end

    always_ff @(posedge clk) begin
    if (!rst) begin
        // Debug writes to instruction/data ports
        if (write_en_i || write_en_dat) begin
            $display("[%0t] WRITE @ PC(?)", $time);
            $display("  addr_i      = 0x%08h | addr_dat    = 0x%08h", addr_i, addr_dat);
            $display("  address     = 0x%08h | address_dat = 0x%08h", address, address_dat);
            $display("  data_i      = 0x%08h | data_dat    = 0x%08h", data_i, data_dat);
            $display("  write_en_i  = %b      | write_en_dat = %b", write_en_i, write_en_dat);
            $display("  read_en_i   = %b      | read_en_dat  = %b", read_en_i, read_en_dat);
            $display("  MEM_BYTES   = %0d bytes (%0d words)", MEM_BYTES, MEM_BYTES/4);
            $display("  BASE_ADDR   = 0x%08h", BASE_ADDR);
            $display("------------------------------------------------------------");
        end

        // Debug reads from instruction/data ports
        if (read_en_i || read_en_dat) begin
            $display("[%0t] READ", $time);
            $display("  addr_i      = 0x%08h | addr_dat    = 0x%08h", addr_i, addr_dat);
            $display("  address     = 0x%08h | address_dat = 0x%08h", address, address_dat);
            $display("  data_o      = 0x%08h | data_dat_o  = 0x%08h", data_o, data_dat_o);
            $display("  read_en_i   = %b      | read_en_dat  = %b", read_en_i, read_en_dat);
            $display("  write_en_i  = %b      | write_en_dat = %b", write_en_i, write_en_dat);
            $display("------------------------------------------------------------");
        end
    end
end
 
endmodule : memory
