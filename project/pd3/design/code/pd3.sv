/*
 * Module: pd3
 *
 * Description: Top level module that will contain sub-module instantiations.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

module pd3 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32)(
    input logic clk,
    input logic reset
);

// DECODE stage outputs
    logic [AWIDTH-1:0] d_pc;
    logic [DWIDTH-1:0] d_insn;
    logic [6:0]        d_opcode;
    logic [4:0]        d_rd;
    logic [4:0]        d_rs1;
    logic [4:0]        d_rs2;
    logic [6:0]        d_funct7;
    logic [2:0]        d_funct3;
    logic [4:0]        d_shamt;
    logic [DWIDTH-1:0] d_imm;

    // CONTROL outputs
    logic              ctrl_pcsel;
    logic              ctrl_immsel;
    logic              ctrl_regwren;
    logic              ctrl_rs1sel;
    logic              ctrl_rs2sel;
    logic              ctrl_memren;
    logic              ctrl_memwren;
    logic [1:0]        ctrl_wbsel;
    logic [3:0]        ctrl_alusel;

    // imemory signals
    logic [DWIDTH - 1:0] addr_i;
    logic [DWIDTH - 1:0] data_i;
    logic write_en;
    logic read_en;
       
    // Fetch signals
    logic [DWIDTH - 1:0] f_pc;
    logic [DWIDTH - 1:0] f_insn;

    // Alu signals
    logic [DWIDTH - 1:0] rs1_i; // not to be confused as registers
    logic [DWIDTH - 1:0] rs2_i; // simply two operand inputs
    logic [DWIDTH - 1:0] alu_res;
    logic                br_taken;

    //register file signals
    logic [DWIDTH - 1:0] datawb_i;
    logic [DWIDTH - 1:0] rs1data_o;
    logic [DWIDTH - 1:0] rs2data_o;

    //branch control signals
    logic breq_o;
    logic brlt_o;


    memory #(
        .AWIDTH(32),
        .DWIDTH(32),
        .BASE_ADDR(32'h01000000)
       ) memory1 (
        .clk(clk),
        .rst(reset),
        .addr_i(f_pc),
        .data_i(data_i),
        .read_en_i(read_en),
        .write_en_i(write_en),
        .data_o(f_insn)
   );
 
    assign read_en = 1'b1;
    assign write_en = 1'b0;

    // Fetch
    fetch #(
        .AWIDTH(32),
        .DWIDTH(32),
        .BASEADDR(32'h01000000)
    ) fetch1 (
        .clk(clk),
        .rst(reset),
        .pc_o(f_pc),           
        .insn_o(f_insn)         
    );

    // Decode stage
    decode #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_decode (
        .clk(clk),
        .rst(reset),
        .insn_i(f_insn),
        .pc_i(f_pc),
        .pc_o(d_pc),
        .insn_o(d_insn),
        .opcode_o(d_opcode),
        .rd_o(d_rd),
        .rs1_o(d_rs1),
        .rs2_o(d_rs2),
        .funct7_o(d_funct7),
        .funct3_o(d_funct3),
        .shamt_o(d_shamt),
        .imm_o(d_imm)
    );

    // Control unit
    control #(
        .DWIDTH(DWIDTH)
    ) u_control (
        .insn_i(d_insn),
        .opcode_i(d_opcode),
        .funct7_i(d_funct7),
        .funct3_i(d_funct3),

        .pcsel_o(ctrl_pcsel),
        .immsel_o(ctrl_immsel),
        .regwren_o(ctrl_regwren),
        .rs1sel_o(ctrl_rs1sel),
        .rs2sel_o(ctrl_rs2sel),
        .memren_o(ctrl_memren),
        .memwren_o(ctrl_memwren),
        .wbsel_o(ctrl_wbsel),
        .alusel_o(ctrl_alusel)
    );

    assign rs1_i = (ctrl_rs1sel) ?  rs1data_o : d_pc;
    assign rs2_i = (ctrl_rs2sel) ?  rs2data_o : d_imm;
    always_ff @(posedge clk) begin
    if (!reset) begin
        $display("[%0t] DEBUG: PC=%h OPCODE=%b IMM=%h RS1=%0d RS2=%0d", 
                  $time, d_pc, d_opcode, d_imm, d_rs1, d_rs2);
    end
end

    branch_control #(
        .DWIDTH(DWIDTH)
    ) u_branch_control (
        .opcode_i(d_opcode),
        .funct3_i(d_funct3),
        .rs1_i(rs1data_o), // from register file becuase
        .rs2_i(rs2data_o), // rs1_i and rs2_i will be muxed to select pc and imm rather than register data
        .breq_o(breq_o),
        .brlt_o(brlt_o)
    );


    alu #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_alu (
        .pc_i(d_pc),
        .rs1_i(rs1_i), // to be connected
        .rs2_i(rs2_i), // to be connected
        .funct3_i(d_funct3),
        .funct7_i(d_funct7),
        .opcode_i(d_opcode),
        .alusel_i(ctrl_alusel),
        .eq(breq_o),
        .lt(brlt_o),
        .res_o(alu_res),      // to be connected
        .brtaken_o(br_taken)   // to be connected
    );

    assign datawb_i =  32'b0; // default

    register_file #(
        .DWIDTH(DWIDTH)
    ) u_register_file (
        .clk(clk),
        .rst(reset),
        .rs1_i(d_rs1),
        .rs2_i(d_rs2),
        .rd_i(d_rd),
        .datawb_i(datawb_i),      // to be connected
        .regwren_i(ctrl_regwren),
        .rs1data_o(rs1data_o),     // to be connected
        .rs2data_o(rs2data_o)      // to be connected
    );



    // Probes (required by testbench)

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

 /*
  * Instantiate other submodules and
  * probes. To be filled by student...
  *
  */

endmodule : pd3