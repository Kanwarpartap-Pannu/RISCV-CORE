/*
 * Module: alu
 *
 * Description: ALU implementation for execute stage.
 *
 * Inputs:
 * 1) 32-bit PC pc_i
 * 2) 32-bit rs1 data rs1_i
 * 3) 32-bit rs2 data rs2_i
 * 4) 3-bit funct3 funct3_i
 * 5) 7-bit funct7 funct7_i
 *
 * Outputs:
 * 1) 32-bit result of ALU res_o
 * 2) 1-bit branch taken signal brtaken_o
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
    input  logic [6:0]        opcode_i,     // added for branch evaluation
    input  logic [3:0]        alusel_i,     // from control
    input  logic eq,                        // for branch evaluation
    input  logic lt,                        // for branch evaluation
    input  logic ltu,                       // for branch evaluation new signal since last pd
    output logic [DWIDTH-1:0] res_o,
    output logic              brtaken_o
);

    // Internal signals for signed operations
    logic signed [DWIDTH-1:0] s_rs1, s_rs2;

    assign s_rs1 = rs1_i;
    assign s_rs2 = rs2_i;
    

    // Main ALU
    always_comb begin
        res_o     = '0;      // default to zero
        brtaken_o = 1'b0;
        
        unique case (alusel_i)
            4'd0:  res_o = rs1_i + rs2_i; // ADD                        // ADD
            4'd1:  res_o = rs1_i - rs2_i; // SUB                         // SUB
            4'd2:  res_o = rs1_i & rs2_i; // AND                            // AND
            4'd3:  res_o = rs1_i | rs2_i; // OR                           // OR
            4'd4:  res_o = rs1_i ^ rs2_i; // XOR                           // XOR
            4'd5:  res_o = (s_rs1 < s_rs2) ? 32'd1 : 32'd0;  // SLT        // SLT
            4'd6:  res_o = rs1_i << rs2_i[4:0]; // SLL
            4'd7:  res_o = rs1_i >> rs2_i[4:0]; // SRL                      // SRL
            4'd8:  res_o = $signed(rs1_i) >>> rs2_i[4:0]; // SRA                 // SRA  
            4'd9:  res_o = rs2_i;  // LUI
            4'd10: res_o = rs1_i + rs2_i; // Branch ADD
            4'd15: res_o = 32'd0; // NOP                                    // NOP
            default: res_o = 32'd0;
        endcase

        // BRANCH evaluation
        if (opcode_i == 7'b1100011) begin  // BRANCH
            case (funct3_i) // uses signals from branch control
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
