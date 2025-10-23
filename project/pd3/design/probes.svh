// ----  Probes  ----
`ifndef PROBES_SVH_
`define PROBES_SVH_

// Probes are the short signal names defined inside the core instance.
// The testbench references them as dut.core.`PROBE_* so these macros must
// expand to the *local* net names (not full hierarchical paths).

// Fetch stage
`define PROBE_F_PC       f_pc
`define PROBE_F_INSN     f_insn

// Decode stage
`define PROBE_D_PC       d_pc
`define PROBE_D_OPCODE   d_opcode
`define PROBE_D_RD       d_rd
`define PROBE_D_FUNCT3   d_funct3
`define PROBE_D_RS1      d_rs1
`define PROBE_D_RS2      d_rs2
`define PROBE_D_FUNCT7   d_funct7
`define PROBE_D_IMM      d_imm
`define PROBE_D_SHAMT    d_shamt

// Register-file / R-stage (write ports)
`define PROBE_R_WRITE_ENABLE      r_write_enable
`define PROBE_R_WRITE_DESTINATION r_write_dest
`define PROBE_R_WRITE_DATA        r_write_data

// Register-file / R-stage (read ports)
`define PROBE_R_READ_RS1          r_read_rs1
`define PROBE_R_READ_RS2          r_read_rs2
`define PROBE_R_READ_RS1_DATA     r_read_rs1_data
`define PROBE_R_READ_RS2_DATA     r_read_rs2_data

// Execute / E-stage
`define PROBE_E_PC        e_pc
`define PROBE_E_ALU_RES   e_alu_res
`define PROBE_E_BR_TAKEN  e_br_taken

// Top module name expected by design_wrapper
`define TOP_MODULE  pd3

`endif // PROBES_SVH_
