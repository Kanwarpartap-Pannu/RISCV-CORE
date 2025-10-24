/*
 * Module: register_file
 *
 * Description: Branch control logic. Only sets the branch control bits based on the
 * branch instruction
 *
 * Inputs:
 * 1) clk
 * 2) reset signal rst
 * 3) 5-bit rs1 address rs1_i
 * 4) 5-bit rs2 address rs2_i
 * 5) 5-bit rd address rd_i
 * 6) DWIDTH-wide data writeback datawb_i
 * 7) register write enable regwren_i
 * Outputs:
 * 1) 32-bit rs1 data rs1data_o
 * 2) 32-bit rs2 data rs2data_o
 */

 module register_file #(
     parameter DWIDTH = 32,
     // PD3 stack pointer reset value coded at top instead 
     parameter [31:0] SP_INIT = 32'h0100_0000
 )(
     // inputs
     input logic clk,
     input logic rst,
     input logic [4:0] rs1_i,
     input logic [4:0] rs2_i,
     input logic [4:0] rd_i,
     input logic [DWIDTH-1:0] datawb_i,
     input logic regwren_i,
     // outputs
     output logic [DWIDTH-1:0] rs1data_o,
     output logic [DWIDTH-1:0] rs2data_o
 );

    // 32 x DWIDTH register file. reg[0] hardwired to 0.
    logic [DWIDTH-1:0] regs [0:31];
    int i;

//Removed below to test if it is overiding values from pd3 constant causing a stack pointer mismatch 
    // Compute initial SP value if macros are available; provide safe default otherwise.
//`ifdef STACK_ADDR
//    localparam logic [DWIDTH-1:0] SP_INIT = `STACK_ADDR;
//`elsif LINE_COUNT
    // If LINE_COUNT is defined (memory words), place SP at end of memory region (BASE addr + bytes).
    // Note: BASE_ADDR may be a parameter elsewhere; fall back to 0x01000000 if not provided.
//`ifdef BASE_ADDR
   // localparam logic [DWIDTH-1:0] SP_INIT = BASE_ADDR + (`LINE_COUNT * (DWIDTH/8));
//`else
//    localparam logic [DWIDTH-1:0] SP_INIT = 32'h01000000 + (`LINE_COUNT * (DWIDTH/8));
//`endif
//`else
  //  localparam logic [DWIDTH-1:0] SP_INIT = 32'h01100000;
//`endif

    // Synchronous reset + write-back on rising clock.
    always_ff @(posedge clk) begin
        if (rst) begin
            // clear registers, set stack pointer x2
            for (i = 0; i < 32; i = i + 1)
                regs[i] <= '0;
            regs[2] <= SP_INIT; // x2 = stack pointer (stack grows down)
        end else begin
            if (regwren_i && (rd_i != 5'd0)) begin
                regs[rd_i] <= datawb_i; // writeback (x0 is immutable)
            end
        end
    end

    // Combinational read ports (x0 reads as zero)
    assign rs1data_o = (rs1_i == 5'd0) ? '0 : regs[rs1_i];
    assign rs2data_o = (rs2_i == 5'd0) ? '0 : regs[rs2_i];

endmodule : register_file
