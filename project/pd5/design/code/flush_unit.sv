module flush_unit #(
    parameter int DWIDTH=32,
)(
    input logic br_taken,

    output logic flush_o

);

/*
This module sets flush_o if branch was taken, this module is a simple assign but it was made into a module
for better readabilty and for clearer design 
*/

always_comb begin

    // if branch was taken br_taken is set high and so is flush otherise it is low
    flush_0 = br_taken;

end



endmodule : flush_unit