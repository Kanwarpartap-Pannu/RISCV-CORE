typedef struct packed {
    logic       reg_write;
    logic       mem_to_reg;
    logic       mem_read;
    logic       mem_write;
    logic       branch;     // optional: branch control
    logic       alu_src;
    logic [3:0] alu_op;
    } ctl_bundle_t;

module id_ex_reg (
    input  logic         clk,
    input  logic         reset,
    input  logic         write_en,      // typically tied to 1; IF/ID freeze prevents new decode
    input  logic         inject_bubble, // when 1: replace inputs with bubble/NOP
    input  logic         flush,         // when 1: clear (branch)
    input  ctl_bundle_t  ctl_in,
    input  logic [31:0]  pc_in,
    input  logic [31:0]  rs1_data_in,
    input  logic [31:0]  rs2_data_in,
    input  logic [31:0]  imm_in,
    input  logic [4:0]   rs1_in,
    input  logic [4:0]   rs2_in,
    input  logic [4:0]   rd_in,
    output ctl_bundle_t  ctl_out,
    output logic [31:0]  pc_out,
    output logic [31:0]  rs1_data_out,
    output logic [31:0]  rs2_data_out,
    output logic [31:0]  imm_out,
    output logic [4:0]   rs1_out,
    output logic [4:0]   rs2_out,
    output logic [4:0]   rd_out
);
    localparam ctl_bundle_t CTL_NOP = '{reg_write:0, mem_to_reg:0, mem_read:0, mem_write:0, branch:0, alu_src:0, alu_op:4'd0};

    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            ctl_out <= CTL_NOP;
            pc_out <= 32'd0;
            rs1_data_out <= 32'd0;
            rs2_data_out <= 32'd0;
            imm_out <= 32'd0;
            rs1_out <= 5'd0;
            rs2_out <= 5'd0;
            rd_out <= 5'd0;
        end else begin
        if (!write_en) begin
            // freeze ID/EX (we expect write_en normally 1; freeze occurs by keeping IF/ID)
            ctl_out <= ctl_out;
            pc_out <= pc_out;
            rs1_data_out <= rs1_data_out;
            rs2_data_out <= rs2_data_out;
            imm_out <= imm_out;
            rs1_out <= rs1_out;
            rs2_out <= rs2_out;
            rd_out <= rd_out;
        end else if (inject_bubble || flush) begin
            // inject bubble or flush -> NOP
            ctl_out <= CTL_NOP;
            pc_out <= 32'd0;
            rs1_data_out <= 32'd0;
            rs2_data_out <= 32'd0;
            imm_out <= 32'd0;
            rs1_out <= 5'd0;
            rs2_out <= 5'd0;
            rd_out <= 5'd0;
        end else begin
            ctl_out <= ctl_in;
            pc_out <= pc_in;
            rs1_data_out <= rs1_data_in;
            rs2_data_out <= rs2_data_in;
            imm_out <= imm_in;
            rs1_out <= rs1_in;
            rs2_out <= rs2_in;
            rd_out <= rd_in;
            end
        end
    end
endmodule
