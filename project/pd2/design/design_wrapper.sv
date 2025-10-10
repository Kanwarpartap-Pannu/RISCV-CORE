`include "constants.svh"

module design_wrapper (
    input  logic clk,
    input  logic reset,

    // FETCH stage probes
    output logic [31:0] probe_f_pc_o,
    output logic [31:0] probe_f_insn_o,

    // DECODE stage probes
    output logic [31:0] probe_d_pc_o,
    output logic [6:0]  probe_d_opcode_o,
    output logic [4:0]  probe_d_rd_o,
    output logic [2:0]  probe_d_funct3_o,
    output logic [4:0]  probe_d_rs1_o,
    output logic [4:0]  probe_d_rs2_o,
    output logic [6:0]  probe_d_funct7_o,
    output logic [31:0] probe_d_imm_o,
    output logic [4:0]  probe_d_shamt_o
);

    // Instantiate PD2 core
    pd2 core (
        .clk(clk),
        .rst(reset),

        // FETCH stage probes
        .probe_f_pc_o(probe_f_pc_o),
        .probe_f_insn_o(probe_f_insn_o),

        // DECODE stage probes
        .probe_d_pc_o(probe_d_pc_o),
        .probe_d_opcode_o(probe_d_opcode_o),
        .probe_d_rd_o(probe_d_rd_o),
        .probe_d_funct3_o(probe_d_funct3_o),
        .probe_d_rs1_o(probe_d_rs1_o),
        .probe_d_rs2_o(probe_d_rs2_o),
        .probe_d_funct7_o(probe_d_funct7_o),
        .probe_d_imm_o(probe_d_imm_o),
        .probe_d_shamt_o(probe_d_shamt_o)
    );

endmodule
