module mem_wb_pipe #(
    parameter int DWIDTH = 32,
    parameter int AWIDTH = 32
)(
    input  logic clk,
    input  logic rst,
  
    // Inputs FROM MEM stage

    input  logic [DWIDTH-1:0] alu_res_i,     // ALU result
    input  logic [DWIDTH-1:0] load_data_i,   // data read from memory
    input  logic [AWIDTH-1:0] pc_i,          // PC+4 for JAL/JALR writeback
    input  logic [4:0]        rd_i,          // register destination

    // Control signals
    input  logic              regwren_i,     // register write enable
    input  logic [1:0]        wbsel_i,       // writeback select

   
    // Outputs TO WB stage

    output logic [DWIDTH-1:0] alu_res_o,
    output logic [DWIDTH-1:0] load_data_o,
    output logic [AWIDTH-1:0] pc_o,
    output logic [4:0]        rd_o,

    output logic              regwren_o,
    output logic [1:0]        wbsel_o
);

    // Internal pipeline regs
    logic [DWIDTH-1:0] alu_res_pipe;
    logic [DWIDTH-1:0] load_data_pipe;
    logic [AWIDTH-1:0] pc_pipe;
    logic [4:0]        rd_pipe;

    logic              regwren_pipe;
    logic [1:0]        wbsel_pipe;

    // Pipeline register
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            alu_res_pipe   <= '0;
            load_data_pipe <= '0;
            pc_pipe        <= '0;
            rd_pipe        <= 5'b0;

            regwren_pipe   <= 1'b0;
            wbsel_pipe     <= 2'b0;

        end 
        
        else begin
            // Normal propagation
            alu_res_pipe   <= alu_res_i;
            load_data_pipe <= load_data_i;
            pc_pipe        <= pc_i;
            rd_pipe        <= rd_i;

            regwren_pipe   <= regwren_i;
            wbsel_pipe     <= wbsel_i;

        end
        // else: stall → hold last values
    end

    // Outputs
    always_comb begin
        alu_res_o   = alu_res_pipe;
        load_data_o = load_data_pipe;
        pc_o        = pc_pipe;
        rd_o        = rd_pipe;

        regwren_o   = regwren_pipe;
        wbsel_o     = wbsel_pipe;
    end

endmodule
