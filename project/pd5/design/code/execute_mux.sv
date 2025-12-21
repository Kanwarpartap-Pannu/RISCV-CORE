`include "constants.svh"

/*
This module holds all necessary muxs and logic for the inputs feeding 
the source operands of the alu. Source operand select signals will be 
used unless a specific bypass is available, bypass of the newest 
instruction will be prioritized. Instructions thar do not use rs1 or rs2
will not be bypassed. 
*/

module execute_mux #(
    parameter int DWIDTH=32
) (
    //inputs 
    input logic [DWIDTH-1:0] rs1,
    input logic [DWIDTH-1:0] rs2,
    input logic [DWIDTH-1:0] ex_mem_alures,
    input logic [DWIDTH-1:0] writeback,
    input logic [DWIDTH-1:0] pc,
    input logic [DWIDTH-1:0] imm,
    input logic [6:0]        opcode_i,
    input logic              rs1_sel,
    input logic              rs2_sel,
    input logic [1:0]        MX_enable,
    input logic [1:0]        WX_enable,

    //outputs
    output logic [DWIDTH-1:0] rs1_o,
    output logic [DWIDTH-1:0] rs2_o
);


// combinational block for rs1 
always_comb begin

    if ( (MX_enable == 2'b01) && (rs1_sel)) begin
        rs1_o = ex_mem_alures; 
    end

    else if ((WX_enable == 2'b01) && (rs1_sel)) begin
        rs1_o = writeback; 
    end

    else begin 
        rs1_o = (rs1_sel) ? rs1 : pc;
    end

end


//combinational block for rs2 
always_comb begin

    if ((MX_enable == 2'b10) && (rs2_sel)) begin
        rs2_o = ex_mem_alures;
    end

    else if ((WX_enable == 2'b10) && (rs2_sel)) begin
        rs2_o = writeback;
    end

    else begin 
        rs2_o = (rs2_sel) ? rs2 : imm;
    end
    
end

endmodule : execute_mux