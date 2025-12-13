module forwarding_unit #(
    parameter int DWIDTH=32
)(
    input logic [4:0] rd_ex_mem_i,
    input logic [4:0] rd_mem_wb_i,
    input logic [4:0] rs1_id_ex_i,
    input logic [4:0] rs2_id_ex_i,
    input logic [4:0] rs2_ex_mem_i,
    input logic [6:0] opcode_ex_mem_i,

    output logic WM_enable,
    output logic [1:0] MX_enable,
    output logic [1:0] WX_enable

);

/*
This module will detect all hazard that can be handled with a forwarding path including the following:
1) Writeback-Memory Bypass: If the data to be stored is coming from a register currently being written then we need to bypass
that value in to store correct value in memory 
2) Memory-Excute Bypass: If one of the source operands currently being excuted in excute stage has dependancy in memory stage
bypass that value to the correct source operand, cannot be done if operation in mem stage is a load check stall unit for this case
3) Writeback-Excute Bypass: If one of the source operands currently being excuted in excute stage has dependancy in writeback stage
bypass that value to the correct source operand

Important to note this module only sets the control signals high if any of the following hazards are detected 
the actual values to use are driven by the muxes in top level module(pd5.sv)
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

// Writeback-Memory Bypass
if ( (rd_mem_wb_i == rs2_ex_mem_i) && (opcode_ex_mem_i == OP_STORE ) ) begin
    WM_enable=1;
end
else begin
    WM_enable=0;
end

// Memory-Execute Bypass RS1
if ( (rd_ex_mem_i == rs1_id_ex_i) ) begin
    MX_enable=2'b01;
end

// Memory-Execute Bypass RS2
else if ( (rd_ex_mem_i == rs2_id_ex_i) ) begin
    MX_enable=2'b10;
end

else begin
    MX_enable=2'b00;
end

// Writeback-Execute Bypass RS1
if ( (rd_mem_wb_i == rs1_id_ex_i) ) begin
    WX_enable=2'b01;
end

// Writeback-Execute Bypass RS1
else if ( (rd_mem_wb_i == rs2_id_ex_i) ) begin
    WX_enable=2'b10;
end
else begin
    WX_enable=2'b00;
end

end

endmodule : forwarding_unit