module ix_mem_pipe #(
    parameter int DWIDTH = 32,
    parameter int AWIDTH = 32
)(
    input  logic clk,
    input  logic rst,


    // Inputs FROM EX

    input  logic [DWIDTH-1:0] alu_res_i,     // ALU result
    input  logic              brtaken_i,     // branch decision (EX)
    input  logic [AWIDTH-1:0] pc_i,          // PC+4 or branch target
    input  logic [DWIDTH-1:0] rs2_val_i,     // for store instructions
    input  logic [4:0]        rd_i,          // destination register number
    input  logic [4:0]        rs1_i,
    input  logic [4:0]        rs2_i,
    input  logic [2:0]        funct3_i,     // funct3 from EX stage
    input  logic [6:0]        opcode_i,
    
    // Control signals from ID/EX
    input  logic              memren_i,
    input  logic              memwren_i,
    input  logic              regwren_i,
    input  logic [1:0]        wbsel_i,       // ALU vs MEM vs PC+4
    input  logic [3:0]        alusel_i,

    // ================
    // Outputs TO MEM
    // ================
    output logic [DWIDTH-1:0] alu_res_o,
    output logic              brtaken_o,
    output logic [AWIDTH-1:0] pc_o,
    output logic [DWIDTH-1:0] rs2_val_o,
    output logic [4:0]        rd_o,
    output logic [4:0]        rs1_o,
    output logic [4:0]        rs2_o,
    output logic [2:0]        funct3_o,
    output logic [6:0]        opcode_o,

    // Control
    output logic              memren_o,
    output logic              memwren_o,
    output logic              regwren_o,
    output logic [1:0]        wbsel_o,
    output logic [3:0]        alusel_o
);

    // =======================
    // Internal pipeline regs
    // =======================
    logic [DWIDTH-1:0] alu_res_pipe;
    logic              brtaken_pipe;
    logic [AWIDTH-1:0] pc_pipe;
    logic [DWIDTH-1:0] rs2_val_pipe;
    logic [4:0]        rs2_pipe;
    logic [4:0]        rd_pipe;

    logic              memren_pipe;
    logic              memwren_pipe;
    logic              regwren_pipe;
    logic [1:0]        wbsel_pipe;
    logic [3:0]        alusel_pipe;
    logic [2:0]        funct3_pipe;
    logic [6:0]        opcode_pipe; 

    // =======================
    // Pipeline register logic
    // =======================
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            
            alu_res_pipe  <= '0;
            brtaken_pipe  <= 1'b0;
            pc_pipe       <= '0;
            rs2_val_pipe  <= '0;
            rs2_pipe      <= '0;
            rd_pipe       <= 5'b0;
            funct3_pipe   <= 3'b0;
            opcode_pipe   <= 0;


            memren_pipe   <= 1'b0;
            memwren_pipe  <= 1'b0;
            regwren_pipe  <= 1'b0;
            wbsel_pipe    <= 2'b0;
            alusel_pipe   <= 4'b0;
        end
            else begin
            
            // Normal update from EX stage
            alu_res_pipe  <= alu_res_i;
            brtaken_pipe  <= brtaken_i;
            pc_pipe       <= pc_i;
            rs2_val_pipe  <= rs2_val_i;
            rs2_pipe      <= rs2_i;
            rd_pipe       <= rd_i;
            funct3_pipe   <= funct3_i;
            opcode_pipe   <= opcode_i;

            memren_pipe   <= memren_i;
            memwren_pipe  <= memwren_i;
            regwren_pipe  <= regwren_i;
            wbsel_pipe    <= wbsel_i;
            alusel_pipe   <= alusel_i;

        end
        // else stall_i == 1 → hold values
    end

    // =======================
    // Outputs
    // =======================
    always_comb begin
        alu_res_o  = alu_res_pipe;
        brtaken_o  = brtaken_pipe;
        pc_o       = pc_pipe;
        rs2_val_o  = rs2_val_pipe;
        rs2_o      = rs2_pipe;
        rd_o       = rd_pipe;
        funct3_o   = funct3_pipe;
        opcode_o   = opcode_pipe;

        memren_o   = memren_pipe;
        memwren_o  = memwren_pipe;
        regwren_o  = regwren_pipe;
        wbsel_o    = wbsel_pipe;
        alusel_o   = alusel_pipe;
    end

endmodule
