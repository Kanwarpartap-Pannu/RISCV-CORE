/*
 * Module: alu
 *
 * Description: ALU implementation for execute stage.
 *
 * Compatible with control module ALU op codes:
 *   ALU_ADD=0, ALU_SUB=1, ALU_AND=2, ALU_OR=3, ALU_XOR=4,
 *   ALU_SLT=5, ALU_SLL=6, ALU_SRL=7, ALU_SRA=8, ALU_NOP=15
 */

module alu #(
    parameter int DWIDTH=32,
    parameter int AWIDTH=32
)(
    input  logic [AWIDTH-1:0] pc_i,
    input  logic [DWIDTH-1:0] rs1_i,
    input  logic [DWIDTH-1:0] rs2_i,
    input  logic [2:0]        funct3_i,
    input  logic [6:0]        funct7_i,
    input  logic [6:0]        opcode_i,     // << optional, now supported
    input  logic [3:0]        alusel_i,     // from control
    output logic [DWIDTH-1:0] res_o,
    output logic              brtaken_o
);

    // =====================================================
    // Internal signals
    // =====================================================
    logic signed [DWIDTH-1:0] s_rs1, s_rs2;
    logic eq, lt, ltu;

    assign s_rs1 = rs1_i;
    assign s_rs2 = rs2_i;
    

    // =====================================================
    // Main ALU
    // =====================================================
    always_comb begin
        res_o     = '0;
        brtaken_o = 1'b0;

        // Basic compare flags
        eq  = (rs1_i == rs2_i);
        lt  = (s_rs1 < s_rs2);
        ltu = (rs1_i < rs2_i);
        $display("[%0t] ALU DEBUG: PC=%h RS1=%h RS2=%h RESULT=%h", 
                  $time, pc_i, rs1_i, rs2_i, res_o);
        unique case (alusel_i)
            4'd0:  res_o = rs1_i + rs2_i;                            // ADD
            4'd1:  res_o = rs1_i - rs2_i;                            // SUB
            4'd2:  res_o = rs1_i & rs2_i;                            // AND
            4'd3:  res_o = rs1_i | rs2_i;                            // OR
            4'd4:  res_o = rs1_i ^ rs2_i;                            // XOR
            4'd5:  res_o = (s_rs1 < s_rs2) ? 32'd1 : 32'd0;          // SLT
            4'd6:  res_o = rs1_i << rs2_i[4:0];                      // SLL
            4'd7:  res_o = rs1_i >> rs2_i[4:0];                      // SRL
            4'd8:  res_o = $signed(rs1_i) >>> rs2_i[4:0];  
            4'd9:  res_o = rs2_i;  // LUI: output immediate directly          // SRA
            4'd15: res_o = 32'd0;                                    // NOP
            default: res_o = 32'd0;
        endcase

        // Optional branch evaluation (if control later uses it)
        if (opcode_i == 7'b1100011) begin  // BRANCH
            case (funct3_i)
                3'b000: brtaken_o = eq;        // BEQ
                3'b001: brtaken_o = !eq;       // BNE
                3'b100: brtaken_o = lt;        // BLT
                3'b101: brtaken_o = !lt;       // BGE
                3'b110: brtaken_o = ltu;       // BLTU
                3'b111: brtaken_o = !ltu;      // BGEU
                default: brtaken_o = 1'b0;
            endcase
        end
    end

endmodule : alu
