
`include "constants.svh"

/*
This module will detect all hazard that can be handled with a forwarding path including the following:
1) Writeback-Memory Bypass: If the data to be stored is coming from a register currently being written then we need to bypass
that value in to store correct value in memory 
2) Memory-Execute Bypass: If one of the source operands currently being excuted in excute stage has dependancy in memory stage
bypass that value to the correct source operand, cannot be done if operation in mem stage is a load check stall unit for this case
3) Writeback-Execute Bypass: If one of the source operands currently being excuted in excute stage has dependancy in writeback stage
bypass that value to the correct source operand

Important to note this module only sets the control signals high if any of the following hazards are detected 
the actual values to use are driven by the muxes 
*/


module forwarding_unit #(
    parameter int DWIDTH=32
)(
    input logic [6:0] ix_opcode_o,
    input logic [6:0] wb_opcode_o,
    input logic [4:0] rd_ex_mem_i,
    input logic [4:0] rd_mem_wb_i,
    input logic [4:0] rs1_id_ex_i,
    input logic [4:0] rs2_id_ex_i,
    input logic [4:0] rs2_ex_mem_i,
    output logic WM_enable,
    output logic [1:0] MX_enable,
    output logic [1:0] WX_enable

);


// Writeback-Memory Bypass block 
always_comb begin

    if ( (rd_mem_wb_i == rs2_ex_mem_i) && (rd_mem_wb_i != 0) && (wb_opcode_o != OP_STORE)) begin
        WM_enable=1; 
    end

    else begin
        WM_enable=0;
    end

end

// Memory-Execute Bypass Block
always_comb begin

     // Memory-Execute Bypass RS1
    if ( (rd_ex_mem_i == rs1_id_ex_i) && (rd_ex_mem_i != 0) ) begin
        MX_enable=2'b01;
    end

    // Memory-Execute Bypass RS2
    else if ( (rd_ex_mem_i == rs2_id_ex_i) && (rd_ex_mem_i != 0) && (ix_opcode_o != OP_STORE)) begin
        MX_enable=2'b10;
    end

    else begin
        MX_enable=2'b00;
    end

end

// Writeback-Execute Bypass Block 
always_comb begin

    // Writeback-Execute Bypass RS1
    if ( (rd_mem_wb_i == rs1_id_ex_i) && (rd_mem_wb_i != 0)) begin
        WX_enable=2'b01;
    end

    // Writeback-Execute Bypass RS2
    else if ( (rd_mem_wb_i == rs2_id_ex_i) && (rd_mem_wb_i != 0) ) begin
        WX_enable=2'b10;
    end

    else begin
        WX_enable=2'b00;
    end

end


endmodule : forwarding_unit