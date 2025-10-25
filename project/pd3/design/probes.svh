`define PROBE_F_PC      f_pc
    `define PROBE_F_INSN    f_insn

    `define PROBE_D_PC      d_pc
    `define PROBE_D_OPCODE  d_opcode
    `define PROBE_D_RD      d_rd
    `define PROBE_D_FUNCT3  d_funct3
    `define PROBE_D_RS1     d_rs1
    `define PROBE_D_RS2     d_rs2
    `define PROBE_D_FUNCT7  d_funct7
    `define PROBE_D_IMM     d_imm
    `define PROBE_D_SHAMT   d_shamt

    `define PROBE_R_WRITE_ENABLE  ctrl_regwren  // ??
    `define PROBE_R_WRITE_DESTINATION  d_rd // ??
    `define PROBE_R_WRITE_DATA datawb_i // ??
    `define PROBE_R_READ_RS1 d_rs1  // ??
    `define PROBE_R_READ_RS2 d_rs2  // ??
    `define PROBE_R_READ_RS1_DATA rs1data_o    // ??
    `define PROBE_R_READ_RS2_DATA  rs2data_o   // ??

    `define PROBE_E_PC       d_pc         // ??
    `define PROBE_E_ALU_RES  alu_res       // ??
    `define PROBE_E_BR_TAKEN  br_taken       // ??

// ----  Top module  ----
`define TOP_MODULE  pd3
// ----  Top module  ----