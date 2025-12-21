
`include "constants.svh"

/*
This unit checks for data hazards and generates a stall signal
if one is present. The stall will hold the curent pc and 
propgate a bubble(NOP) into the pipeline.
Two hazards will cause a stall:
1) Load-use hazard: If the insturction proceeding a load happens to read from the loaded value
we need to produce a stall as no forwarding can provide the correct value
2) Writeback-Decode hazard: If the instruction currently in writeback is writing to a value the 
the instruction currently in decode is reading from this must be stalled as no 
forwarding paths exist to bypass the register file
*/


module stall_unit #(
    parameter int DWIDTH = 32 
) (
    input logic [6:0] opcode_id_ex_i,
    input logic [6:0] opcode_if_id_i,
    input logic [4:0] rd_id_ex_i,
    input logic [4:0] rd_mem_wb_i,
    input logic [4:0] rs1_if_id_i,
    input logic [4:0] rs2_if_id_i,
    input logic       regwren_i,
    input logic       flush_i, 

    output logic stall_o
);


always_comb begin

    // load-use hazard detection 
    if ( ((opcode_id_ex_i == OP_LOAD) )&& ( (rs1_if_id_i == rd_id_ex_i) || 
    ( (rs2_if_id_i == rd_id_ex_i) && (opcode_if_id_i != OP_STORE) ) ) && (rd_id_ex_i != 0) ) begin
        stall_o = 1; 
    end

    // write-decode hazard detection
    else if ( (( (rs1_if_id_i == rd_mem_wb_i) || 
    ( (rs2_if_id_i == rd_mem_wb_i) ) ) && (rd_mem_wb_i != 0) ) && (regwren_i) && (!flush_i) )  begin 
        stall_o = 1;
    end

    else begin
        stall_o = 0;
    end
    
end




endmodule : stall_unit
