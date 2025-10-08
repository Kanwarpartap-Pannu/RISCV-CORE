module pd2 (
    input  logic         clk,
    input  logic         rst

    `ifdef PROBE_F_PC
        , output logic [31:0] probe_f_pc_o
    `endif

    `ifdef PROBE_F_INSN
        , output logic [31:0] probe_f_insn_o
    `endif

    `ifdef PROBE_D_PC
        , output logic [31:0] probe_d_pc_o
    `endif

    `ifdef PROBE_D_OPCODE
        , output logic [6:0]  probe_d_opcode_o
    `endif

    `ifdef PROBE_D_RD
        , output logic [4:0]  probe_d_rd_o
    `endif

    `ifdef PROBE_D_FUNCT3
        , output logic [2:0]  probe_d_funct3_o
    `endif

    `ifdef PROBE_D_RS1
        , output logic [4:0]  probe_d_rs1_o
    `endif

    `ifdef PROBE_D_RS2
        , output logic [4:0]  probe_d_rs2_o
    `endif

    `ifdef PROBE_D_FUNCT7
        , output logic [6:0]  probe_d_funct7_o
    `endif

    `ifdef PROBE_D_IMM
        , output logic [31:0] probe_d_imm_o
    `endif

    `ifdef PROBE_D_SHAMT
        , output logic [4:0]  probe_d_shamt_o
    `endif
);

    // ----------------------------------------------------
    // FETCH → DECODE signals
    // ----------------------------------------------------
    logic [31:0] pc_f, instruction_f;

    // DECODE → EXECUTE signals
    logic [4:0]  rd_d, rs1_d, rs2_d;
    logic [31:0] imm_d;
    logic [6:0]  opcode_d, funct7_d;
    logic [2:0]  funct3_d;
    logic        reg_write_d, mem_read_d, mem_write_d, mem_to_reg_d;
    logic        alu_src_d, branch_d, jump_d;
    logic [1:0]  alu_op_d;

    // ----------------------------------------------------
    // FETCH STAGE
    // ----------------------------------------------------
    fetch FETCH_STAGE (
        .clk(clk),
        .rst(rst),
        .pc_o(pc_f),
        .instruction_o(instruction_f)
    );

    // ----------------------------------------------------
    // DECODE STAGE
    // ----------------------------------------------------
    assign opcode_d = instruction_f[6:0];
    assign funct3_d = instruction_f[14:12];
    assign funct7_d = instruction_f[31:25];

    decode DECODE_STAGE (
        .ins_i(instruction_f),
        .rd_o(rd_d),
        .rs1_o(rs1_d),
        .rs2_o(rs2_d),
        .imm_o(imm_d),
        .reg_write_o(reg_write_d),
        .mem_read_o(mem_read_d),
        .mem_write_o(mem_write_d),
        .mem_to_reg_o(mem_to_reg_d),
        .alu_src_o(alu_src_d),
        .branch_o(branch_d),
        .jump_o(jump_d),
        .alu_op_o(alu_op_d)
    );

    // ----------------------------------------------------
    // PROBE CONNECTIONS
    // ----------------------------------------------------
    `ifdef PROBE_F_PC
        assign probe_f_pc_o = pc_f;
    `endif

    `ifdef PROBE_F_INSN
        assign probe_f_insn_o = instruction_f;
    `endif

    `ifdef PROBE_D_PC
        assign probe_d_pc_o = pc_f;  // Assuming PC passes through decode unchanged
    `endif

    `ifdef PROBE_D_OPCODE
        assign probe_d_opcode_o = opcode_d;
    `endif

    `ifdef PROBE_D_RD
        assign probe_d_rd_o = rd_d;
    `endif

    `ifdef PROBE_D_FUNCT3
        assign probe_d_funct3_o = funct3_d;
    `endif

    `ifdef PROBE_D_RS1
        assign probe_d_rs1_o = rs1_d;
    `endif

    `ifdef PROBE_D_RS2
        assign probe_d_rs2_o = rs2_d;
    `endif

    `ifdef PROBE_D_FUNCT7
        assign probe_d_funct7_o = funct7_d;
    `endif

    `ifdef PROBE_D_IMM
        assign probe_d_imm_o = imm_d;
    `endif

    `ifdef PROBE_D_SHAMT
        assign probe_d_shamt_o = imm_d[4:0];  // For shift instructions
    `endif

endmodule
