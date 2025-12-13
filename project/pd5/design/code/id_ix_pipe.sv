module id_ix_pipe #(
    parameter int DWIDTH = 32,
    parameter int AWIDTH = 32
) (
    input  logic              clk,
    input  logic              rst,

    // hazard control
    input  logic              stall_i,   // 1 = hold ID/EX
    input  logic              flush_i,   // 1 = bubble this stage

    // data from ID
    input  logic [DWIDTH-1:0] ins_i,
    input  logic [AWIDTH-1:0] pc_i,
    input  logic [DWIDTH-1:0] rs1_data_i,
    input  logic [DWIDTH-1:0] rs2_data_i,
    input  logic [6:0]        opcode_i,
    input  logic [4:0]        rd_i,
    input  logic [4:0]        rs1_i,
    input  logic [4:0]        rs2_i,
    input  logic [6:0]        funct7_i,
    input  logic [2:0]        funct3_i,
    input  logic [4:0]        shamt_i,

    // control signals from ID (control unit)
    input  logic              pcsel_i,
    input  logic              immsel_i,
    input  logic              regwren_i,
    input  logic              rs1sel_i,
    input  logic              rs2sel_i,
    input  logic              memren_i,
    input  logic              memwren_i,
    input  logic [1:0]        wbsel_i,
    input  logic [3:0]        alusel_i,

    // outputs to EX
    output logic [AWIDTH-1:0] pc_o,
    output logic [DWIDTH-1:0] ins_o,
    output logic [6:0]        opcode_o,
    output logic [4:0]        rd_o,
    output  logic [4:0]        rs1_o,
    output  logic [4:0]        rs2_o,
    output logic [DWIDTH-1:0] rs1_data_o,
    output logic [DWIDTH-1:0] rs2_data_o,
    output logic [6:0]        funct7_o,
    output logic [2:0]        funct3_o,
    output logic [4:0]        shamt_o,

    // pipelined control signals
    output logic              pcsel_o,
    output logic              immsel_o,
    output logic              regwren_o,
    output logic              rs1sel_o,
    output logic              rs2sel_o,
    output logic              memren_o,
    output logic              memwren_o,
    output logic [1:0]        wbsel_o,
    output logic [3:0]        alusel_o
);

    // data pipes
    logic [DWIDTH-1:0] ins_pipe;
    logic [AWIDTH-1:0] pc_pipe;
    logic [6:0]        opcode_pipe;
    logic [4:0]        rd_pipe;
    logic [4:0]        rs1_pipe;
    logic [4:0]        rs2_pipe;
    logic [DWIDTH-1:0] rs1_data_pipe;
    logic [DWIDTH-1:0] rs2_data_pipe;
    logic [6:0]        funct7_pipe;
    logic [2:0]        funct3_pipe;
    logic [4:0]        shamt_pipe;

    // control pipes
    logic              pcsel_pipe;
    logic              immsel_pipe;
    logic              regwren_pipe;
    logic              rs1sel_pipe;
    logic              rs2sel_pipe;
    logic              memren_pipe;
    logic              memwren_pipe;
    logic [1:0]        wbsel_pipe;
    logic [3:0]        alusel_pipe;

    // ID/EX pipeline register
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            // clear everything on reset
            ins_pipe      <= '0;
            pc_pipe       <= '0;
            opcode_pipe   <= '0;
            rd_pipe       <= '0;
            rs1_pipe      <= '0;
            rs2_pipe      <= '0;
            rs1_data_pipe <= '0;
            rs2_data_pipe <= '0;
            funct7_pipe   <= '0;
            funct3_pipe   <= '0;
            shamt_pipe    <= '0;

            pcsel_pipe    <= 1'b0;
            immsel_pipe   <= 1'b0;
            regwren_pipe  <= 1'b0;
            rs1sel_pipe   <= 1'b0;
            rs2sel_pipe   <= 1'b0;
            memren_pipe   <= 1'b0;
            memwren_pipe  <= 1'b0;
            wbsel_pipe    <= 2'b0;
            alusel_pipe   <= 4'b0;

        end else if (flush_i) begin
            // bubble: kill this instruction and its side effects
            ins_pipe      <= 32'h00000013;  // ADDI x0,x0,0 (NOP) - optional
            pc_pipe       <= '0;
            opcode_pipe   <= 7'b0;
            rd_pipe       <= 5'b0;
            rs1_pipe      <= '0;
            rs2_pipe      <= '0;
            rs1_data_pipe      <= '0;
            rs2_data_pipe      <= '0;
            funct7_pipe   <= '0;
            funct3_pipe   <= '0;
            shamt_pipe    <= '0;

            // **IMPORTANT**: disable all writes / mem ops
            pcsel_pipe    <= 1'b0;   // depends on how you use pcsel in EX, but safe default
            immsel_pipe   <= 1'b0;
            regwren_pipe  <= 1'b0;   // no writeback
            rs1sel_pipe   <= 1'b0;
            rs2sel_pipe   <= 1'b0;
            memren_pipe   <= 1'b0;
            memwren_pipe  <= 1'b0;
            wbsel_pipe    <= 2'b0;
            alusel_pipe   <= 4'b0;

        end else if (!stall_i) begin
            // normal operation: latch ID outputs into ID/EX
            ins_pipe      <= ins_i;
            pc_pipe       <= pc_i;

            opcode_pipe   <= opcode_i;
            rd_pipe       <= rd_i;
            rs1_data_pipe      <= rs1_data_i;
            rs2_data_pipe      <= rs2_data_i;
            rs1_pipe      <= rs1_i;
            rs2_pipe      <= rs2_i;
            funct7_pipe   <= funct7_i;
            funct3_pipe   <= funct3_i;
            shamt_pipe    <= shamt_i;

            pcsel_pipe    <= pcsel_i;
            immsel_pipe   <= immsel_i;
            regwren_pipe  <= regwren_i;
            rs1sel_pipe   <= rs1sel_i;
            rs2sel_pipe   <= rs2sel_i;
            memren_pipe   <= memren_i;
            memwren_pipe  <= memwren_i;
            wbsel_pipe    <= wbsel_i;
            alusel_pipe   <= alusel_i;

        end
        // else: stall_i == 1 → hold all pipeline regs (no assignments)
    end

    // combinational outputs
    always_comb begin
        ins_o      = ins_pipe;
        pc_o       = pc_pipe;
        opcode_o   = opcode_pipe;
        rd_o       = rd_pipe;
        rs1_o      = rs1_pipe;
        rs2_o      = rs2_pipe;
        rs1_data_o      = rs1_data_pipe;
        rs2_data_o      = rs2_data_pipe;
        funct7_o   = funct7_pipe;
        funct3_o   = funct3_pipe;
        shamt_o    = shamt_pipe;

        pcsel_o    = pcsel_pipe;
        immsel_o   = immsel_pipe;
        regwren_o  = regwren_pipe;
        rs1sel_o   = rs1sel_pipe;
        rs2sel_o   = rs2sel_pipe;
        memren_o   = memren_pipe;
        memwren_o  = memwren_pipe;
        wbsel_o    = wbsel_pipe;
        alusel_o   = alusel_pipe;
    end

endmodule
