module if_id_reg (
  input  logic         clk,
  input  logic         reset,
  input  logic         write_en, // when 0: freeze (stall)
  input  logic         flush,    // when 1: insert NOP
  input  logic [31:0]  inst_in,
  input  logic [31:0]  pc_in,
  output logic [31:0]  inst_out,
  output logic [31:0]  pc_out
);
  localparam logic [31:0] NOP = 32'h00000013; // ADDI x0,x0,0
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      inst_out <= NOP;
      pc_out   <= 32'd0;
    end else begin
      if (!write_en) begin
        // freeze
        inst_out <= inst_out;
        pc_out   <= pc_out;
      end else if (flush) begin
        inst_out <= NOP;
        pc_out   <= 32'd0;
      end else begin
        inst_out <= inst_in;
        pc_out   <= pc_in;
      end
    end
  end
endmodule
