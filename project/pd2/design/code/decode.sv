`include "constants.svh"

module decode (
    input  logic [31:0] ins_i,

    // Outputs for datapath
    output logic [4:0]  rs1_o,
    output logic [4:0]  rs2_o,
    output logic [4:0]  rd_o,
    output logic [31:0] imm_o,

    // Control signals
    output logic        reg_write_o,
    output logic        mem_read_o,
    output logic        mem_write_o,
    output logic        mem_to_reg_o,
    output logic        alu_src_o,
    output logic        branch_o,
    output logic        jump_o,
    output logic [1:0]  alu_op_o
);

    // -----------------------------
    // Instruction fields
    // -----------------------------
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign opcode = ins_i[6:0];
    assign rd_o   = ins_i[11:7];
    assign funct3 = ins_i[14:12];
    assign rs1_o  = ins_i[19:15];
    assign rs2_o  = ins_i[24:20];
    assign funct7 = ins_i[31:25];

    // -----------------------------
    // Immediate Generator
    // -----------------------------
    igen igen_inst (
        .opcode_i(opcode),
        .insn_i(ins_i),
        .imm_o(imm_o)
    );

    // -----------------------------
    // Control Unit
    // -----------------------------
    control control_inst (
        .opcode_i    (opcode),
        .funct3_i    (funct3),
        .funct7_i    (funct7),
        .reg_write_o (reg_write_o),
        .mem_read_o  (mem_read_o),
        .mem_write_o (mem_write_o),
        .mem_to_reg_o(mem_to_reg_o),
        .alu_src_o   (alu_src_o),
        .branch_o    (branch_o),
        .jump_o      (jump_o),
        .alu_op_o    (alu_op_o)
    );

endmodule
