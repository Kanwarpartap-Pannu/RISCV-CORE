module execute_mux #(
    parameter int DWIDTH=32
) (
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

    output logic [DWIDTH-1:0] rs1_o,
    output logic [DWIDTH-1:0] rs2_o
);

/*
This module holds all nessecary muxs and logic for the inputs feeding the source operands of the 
alu. Source operand select signals will be used unless a specific bypass is avaible, bypass of 
the newest instruction will be priortized. 
*/

// contants.svh was not working due to trying to finish on the deadline opted for 
// less optimal copy paste but this should ideally be in a constants file
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


// combinational block for rs1 select logic 
always_comb begin

    // Bypass path from memory to execute, this path should not be active for branch or JAL 
    // becuase they use pc so we dont want any other value overriding the pc 
    // this will only bypass rs1 if rs1 is used by the instruction in the execute unit
    // note: not changing for submission because I do not want to break it but 
    // instead of checking opcode we can also check rs1 sel to see if it needs rs1 or not

    if ( (MX_enable == 2'b01) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL))) begin
        rs1_o = ex_mem_alures; // feed in alu result from the mem stage
    end

    // writeback to execute bpass similar logic to above
    else if ((WX_enable == 2'b01) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL))) begin
        rs1_o = writeback; // bypass writeback data from writeback stage
    end

    // no bypass or instruction needs pc standard logic
    else begin 
        rs1_o = (rs1_sel) ? rs1 : pc;
    end
end


//combinational block for rs2 
always_comb begin

    // Simmilar logic to rs1 block only instructions that actaully use rs2 in their operations
    // should have bypassing otherwise make sure to select immediate  
    // note: not changing for submission because I do not want to break it but 
    // instead of checking opcode we can also check rs2 sel to see if it needs rs2 or not

    if ((MX_enable == 2'b10) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL) && (opcode_i != OP_JALR) && (opcode_i != OP_LOAD) )) begin
        rs2_o = ex_mem_alures;
    end
    else if ((WX_enable == 2'b10) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL) && (opcode_i != OP_JALR) && (opcode_i != OP_LOAD) )) begin
        rs2_o = writeback;
    end
    else begin 
        rs2_o = (rs2_sel) ? rs2 : imm;
    end
end

endmodule : execute_mux