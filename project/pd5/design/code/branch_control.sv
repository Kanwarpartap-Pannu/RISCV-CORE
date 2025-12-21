/*
The branch control module is responsible for generating 
the appropriate branch control signals for use in determining 
the outcome of a branch 

The module supports three types of comparisons:
    1) Checking if the operands are equal
    2) Checking if the rs1 is less than rs2 assuming both are unsigned values
    3) Checking if the rs1 is less than rs2 assuming both are signed values
*/

 module branch_control #(
    parameter int DWIDTH=32 
)(
    // inputs (values of rs1 and rs2)
    input logic [DWIDTH-1:0] rs1_i, 
    input logic [DWIDTH-1:0] rs2_i,
    // outputs (various control signals)
    output logic breq_o,
    output logic brlt_o,
    output logic brltu_o
);

    // combinational circuits for value comparisons 
    assign breq_o = (rs1_i == rs2_i);
    assign brlt_o = ($signed(rs1_i) < $signed(rs2_i));
    assign brltu_o = (rs1_i < rs2_i);  

endmodule : branch_control