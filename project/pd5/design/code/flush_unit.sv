module flush_unit #(
    parameter int DWIDTH=32
)(
    input logic br_taken,
    input logic pcsel,

    output logic flush_o

);

/*
This module sets flush_o if branch was taken, this module is a simple assign but it was made into a module
for better readabilty and for clearer design 
*/

always_comb begin

    // if branch was taken br_taken is set high and so is flush otherise it is low
    // or if its a jump and link
    flush_o = (br_taken || pcsel);

end



endmodule : flush_unit