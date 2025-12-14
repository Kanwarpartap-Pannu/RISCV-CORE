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


// combinational block for rs1 
always_comb begin
    if ( (MX_enable == 2'b01) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL))) begin
        rs1_o = ex_mem_alures;
    end
    else if ((WX_enable == 2'b01) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL))) begin
        rs1_o = writeback;
    end
    else begin 
        rs1_o = (rs1_sel) ? rs1 : pc;
    end
end

//combinational block for rs2 
always_comb begin
    if ((MX_enable == 2'b10) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL) && (opcode_i != OP_JALR) )) begin
        rs2_o = ex_mem_alures;
    end
    else if ((WX_enable == 2'b10) && ((opcode_i != OP_BRANCH) && (opcode_i != OP_JAL) && (opcode_i != OP_JALR))) begin
        rs2_o = writeback;
    end
    else begin 
        rs2_o = (rs2_sel) ? rs2 : imm;
    end
end

endmodule : execute_mux