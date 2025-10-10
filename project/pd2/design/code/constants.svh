/*
 * Good practice to define constants and refer to them in the
 * design files. An example of some constants are provided to you
 * as a starting point
 *
 */
`ifndef CONSTANTS_SVH_
`define CONSTANTS_SVH_

parameter logic [31:0] ZERO = 32'd0;

// Fetch stage probes
`define PROBE_F_PC
`define PROBE_F_INSN

// Decode stage probes
`define PROBE_D_PC
`define PROBE_D_OPCODE
`define PROBE_D_RD
`define PROBE_D_FUNCT3
`define PROBE_D_RS1
`define PROBE_D_RS2
`define PROBE_D_FUNCT7
`define PROBE_D_IMM
`define PROBE_D_SHAMT



`endif
