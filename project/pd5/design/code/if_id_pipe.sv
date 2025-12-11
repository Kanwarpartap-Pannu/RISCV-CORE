module if_id_pipe #(
    parameter int DWIDTH = 32
)(
    input  logic             clk,
    input  logic             rst,

    // Incoming from IF stage
    input  logic [DWIDTH-1:0] ins_i,
    input  logic [DWIDTH-1:0] pc_i,

    // Control signals (placeholder)
    input  logic stall_i,
    input  logic flush_i,

    // Outputs to ID stage
    output logic [DWIDTH-1:0] ins_o,
    output logic [DWIDTH-1:0] pc_o
);

    logic [DWIDTH-1:0] ins_pipe;
    logic [DWIDTH-1:0] pc_pipe;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            ins_pipe <= '0;
            pc_pipe  <= '0;

        end else if (flush_i) begin
            // Flush pipeline → Insert NOP instruction
            ins_pipe <= 32'h00000013; // ADDI x0, x0, 0   (NOP)
            pc_pipe  <= '0;

        end else if (!stall_i) begin
            // Normal pipeline write
            ins_pipe <= ins_i;
            pc_pipe  <= pc_i;

        end else begin
            // Stall Hold values (no change)
            ins_pipe <= ins_pipe;
            pc_pipe  <= pc_pipe;
        end 
    end

    assign ins_o = ins_pipe;
    assign pc_o  = pc_pipe;

endmodule : if_id_pipe