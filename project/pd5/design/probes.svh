
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

    `define PROBE_R_WRITE_ENABLE  regwren_wb_o // ??
    `define PROBE_R_WRITE_DESTINATION  rd_wb_o // ??
    `define PROBE_R_WRITE_DATA writeback_data_o // ??
    `define PROBE_R_READ_RS1 d_rs1  // ??
    `define PROBE_R_READ_RS2 d_rs2  // ??
    `define PROBE_R_READ_RS1_DATA rs1data_o    // ??
    `define PROBE_R_READ_RS2_DATA  rs2data_o   // ??

    `define PROBE_E_PC       ix_pc_o         // ??
    `define PROBE_E_ALU_RES  alu_res       // ??
    `define PROBE_E_BR_TAKEN  br_taken       // ??

    `define PROBE_M_PC      pc_mem_o         // ??
    `define PROBE_M_ADDRESS        alu_res_mem_o   // ??
    `define PROBE_M_SIZE_ENCODED    size_encoded // ??
    `define PROBE_M_DATA            memory_data_i  // ??

    `define PROBE_W_PC            pc_wb_o  // ??
    `define PROBE_W_ENABLE         regwren_mem_o  // ??
    `define PROBE_W_DESTINATION     rd_wb_o  // ??
    `define PROBE_W_DATA      writeback_data_o        // ??


// ----  Probes  ----

// ----  Top module  ----
`define TOP_MODULE  pd5 
// ----  Top module  ----