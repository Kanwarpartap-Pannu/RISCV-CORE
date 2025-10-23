/*
 * Good practice to define constants and refer to them in the
 * design files. An example of some constants are provided to you
 * as a starting point
 *
 */
`ifndef CONSTANTS_SVH_
`define CONSTANTS_SVH_

// ZERO macro
`ifndef ZERO
`define ZERO 32'd0
`endif

// Opcode group definitions (RV32I base ISA) as macros to avoid
// duplicate-parameter issues across separate compilation units.
`ifndef OP_R
`define OP_R      7'b0110011
`endif
`ifndef OP_I
`define OP_I      7'b0010011
`endif
`ifndef OP_LOAD
`define OP_LOAD   7'b0000011
`endif
`ifndef OP_STORE
`define OP_STORE  7'b0100011
`endif
`ifndef OP_BRANCH
`define OP_BRANCH 7'b1100011
`endif
`ifndef OP_JALR
`define OP_JALR   7'b1100111
`endif
`ifndef OP_JAL
`define OP_JAL    7'b1101111
`endif
`ifndef OP_LUI
`define OP_LUI    7'b0110111
`endif
`ifndef OP_AUIPC
`define OP_AUIPC  7'b0010111
`endif

`endif // CONSTANTS_SVH_
