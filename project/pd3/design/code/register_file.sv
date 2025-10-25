/*
 * Module: register_file
 *
 * Description: Register file implementation 32 32-bit RV32 registers. Ensure that the stack pointer register ('x2') is set such that the stack grows downwards (from high address to low address).

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
     parameter int DWIDTH=32
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

    /*
     * Process definitions to be filled by
     * student below...
     */

     // 32 registers, 32 bits each
    logic [DWIDTH-1:0] regs [31:0];

    // ==================================================
    // RESET: clear all registers, initialize stack pointer
    // ==================================================
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int i = 0; i < 32; i++)
                regs[i] <= '0;

            // Initialize stack pointer (x2)
            // Stack "grows downward" in memory, so we start high.
            // Use some large address if known, or lab default.
            regs[2] <= 32'h01100000;  // example top of stack
        end
        else begin
            // Write-back stage: write to rd
            if (regwren_i && (rd_i != 5'd0)) begin
                regs[rd_i] <= datawb_i;
            end
        end
    end

    // ==================================================
    // Combinational reads for rs1 and rs2
    // ==================================================
    assign rs1data_o = (rs1_i == 5'd0) ? '0 : regs[rs1_i];
    assign rs2data_o = (rs2_i == 5'd0) ? '0 : regs[rs2_i];

endmodule : register_file