

// ----  Probes  ----

// IF stage (fetch)
`define PROBE_F_PC        if_pc
`define PROBE_F_INSN      if_insn

// DECODE stage (ID)
`define PROBE_D_PC        id_pc
`define PROBE_D_OPCODE    id_opcode
`define PROBE_D_RD        id_rd
`define PROBE_D_FUNCT3    id_funct3
`define PROBE_D_RS1       id_rs1
`define PROBE_D_RS2       id_rs2
`define PROBE_D_FUNCT7    id_funct7
`define PROBE_D_IMM       id_imm
`define PROBE_D_SHAMT     id_shamt

// REGISTER file probes
// Write happens in WB stage so we use WB-stage control and destination
`define PROBE_R_WRITE_ENABLE   wb_ctrl_regwren
`define PROBE_R_WRITE_DESTINATION  wb_rd
`define PROBE_R_WRITE_DATA    wb_writeback_data
// Reads are from ID stage
`define PROBE_R_READ_RS1      id_rs1
`define PROBE_R_READ_RS2      id_rs2
`define PROBE_R_READ_RS1_DATA id_rs1data
`define PROBE_R_READ_RS2_DATA id_rs2data

// EXECUTE stage probes
`define PROBE_E_PC           ex_pc
`define PROBE_E_ALU_RES      ex_alu_res
`define PROBE_E_BR_TAKEN     ex_brtaken

// MEMORY stage probes
`define PROBE_M_PC           mem_alu_res   // memory address / ALU result at MEM stage
`define PROBE_M_ADDRESS      mem_alu_res
`define PROBE_M_SIZE_ENCODED size_encoded
`define PROBE_M_DATA         mem_read_data

// WRITEBACK stage probes
`define PROBE_W_PC           wb_alu_res    
`define PROBE_W_ENABLE       wb_ctrl_regwren
`define PROBE_W_DESTINATION  wb_rd
`define PROBE_W_DATA         wb_writeback_data

// ----  Top module  ----
`define TOP_MODULE  pd5
