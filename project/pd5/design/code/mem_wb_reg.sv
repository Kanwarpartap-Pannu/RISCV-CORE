module mem_wb_reg (
  input  logic         clk,
  input  logic         reset,
  input  ctl_bundle_t  ctl_in,
  input  logic [31:0]  mem_read_data_in,
  input  logic [31:0]  alu_result_in,
  input  logic [4:0]   rd_in,
  output ctl_bundle_t  ctl_out,
  output logic [31:0]  mem_read_data_out,
  output logic [31:0]  alu_result_out,
  output logic [4:0]   rd_out
);
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      ctl_out <= '{default:0};
      mem_read_data_out <= 32'd0;
      alu_result_out <= 32'd0;
      rd_out <= 5'd0;
    end else begin
      ctl_out <= ctl_in;
      mem_read_data_out <= mem_read_data_in;
      alu_result_out <= alu_result_in;
      rd_out <= rd_in;
    end
  end
endmodule
