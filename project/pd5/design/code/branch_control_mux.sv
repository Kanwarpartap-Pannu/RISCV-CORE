/*
    The branch control mux module is responsible for selecting
    between the decoded source operand values and any values
    available through a bypass path 
*/

module branch_control_mux # (
    parameter int DWIDTH=32
)(
    //inputs (decoded values, bypassed values and control signals)
    input logic [DWIDTH-1:0] rs1_val_i,
    input logic [DWIDTH-1:0] rs2_val_i,
    input logic [DWIDTH-1:0] alu_res_i,
    input logic [DWIDTH-1:0] writeback_data_i,
    input logic [1:0]        MX_enable,
    input logic [1:0]        WX_enable,

    //output (selected operands)
    output logic [DWIDTH-1:0] rs1_branch_o,
    output logic [DWIDTH-1:0] rs2_branch_o
);

//combinational block for rs1 logic
always_comb begin

    if (MX_enable == 2'b01) begin
        rs1_branch_o = alu_res_i;
    end

    else if (WX_enable == 2'b01) begin
        rs1_branch_o = writeback_data_i;
    end

    else begin 
        rs1_branch_o = rs1_val_i ;
    end

end

//combinational block for rs2 logic
always_comb begin

    if (MX_enable == 2'b10) begin
        rs2_branch_o = alu_res_i;
    end

    else if (WX_enable == 2'b10) begin
        rs2_branch_o = writeback_data_i;
    end

    else begin 
        rs2_branch_o = rs2_val_i;
    end

end


endmodule : branch_control_mux
