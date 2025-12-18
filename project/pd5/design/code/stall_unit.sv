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

// Opcode group definitions (RV32I base ISA)
    // Constants.svh not working here, so redefining
    localparam [6:0]
        OP_R      = 7'b0110011, // R-type
        OP_I      = 7'b0010011, // I-type arithmetic
        OP_LOAD   = 7'b0000011, // Load
        OP_STORE  = 7'b0100011, // Store
        OP_BRANCH = 7'b1100011, // Branch
        OP_JALR   = 7'b1100111, // Jump register
        OP_JAL    = 7'b1101111, // Jump and link
        OP_LUI    = 7'b0110111, // Load upper immediate
        OP_AUIPC  = 7'b0010111; // Add upper immediate to PC


always_comb begin
    // hazard detection logic stall is set high when hazard is detected 

    
    // load-use hazard detection, note that if the newer instruction is a store writing to the same rd then no need to stall 
    if ( ((opcode_id_ex_i == OP_LOAD) )&& ( (rs1_if_id_i == rd_id_ex_i) || 
    ( (rs2_if_id_i == rd_id_ex_i) && (opcode_if_id_i != OP_STORE) ) ) && (rd_id_ex_i != 0) ) begin
        stall_o = 1; 
    end

    // write-decode hazard detection, again no stall for store to same rd  
    else if ( (( (rs1_if_id_i == rd_mem_wb_i) || 
    ( (rs2_if_id_i == rd_mem_wb_i) ) ) && (rd_mem_wb_i != 0) ) && (regwren_i) && (!flush_i) )  begin 
        stall_o = 1;
    end

    else begin
        stall_o = 0;
    end
end




endmodule : stall_unit
