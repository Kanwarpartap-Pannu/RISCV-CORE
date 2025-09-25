// ----  Probes  ----
`define PROBE_ADDR       u_memory.addr_i
`define PROBE_DATA_IN    u_memory.data_i
`define PROBE_DATA_OUT   u_memory.data_o
`define PROBE_READ_EN    u_memory.read_en_i
`define PROBE_WRITE_EN   u_memory.write_en_i

`define PROBE_F_PC       u_fetch.pc_o
`define PROBE_F_INSN     u_fetch.insn_o
// ----  Probes  ----

// ----  Top module  ----
`define TOP_MODULE  pd1
// ----  Top module  ----