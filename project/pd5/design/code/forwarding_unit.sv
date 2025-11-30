module forwarding_unit (
    input  logic [4:0] id_ex_rs1,
    input  logic [4:0] id_ex_rs2,
    input  logic [4:0] ex_mem_rd,
    input  logic [4:0] mem_wb_rd,
    input  logic       ex_mem_regwrite,
    input  logic       mem_wb_regwrite,
    output logic [1:0] forwardA, // 00 = use id_ex, 10 = from ex_mem, 01 = from mem_wb
    output logic [1:0] forwardB
    );
    always_comb begin
        forwardA = 2'b00;
        forwardB = 2'b00;

        // highest priority: EX/MEM then MEM/WB
        if (ex_mem_regwrite && (ex_mem_rd != 0) && (ex_mem_rd == id_ex_rs1))
        forwardA = 2'b10;
        else if (mem_wb_regwrite && (mem_wb_rd != 0) && (mem_wb_rd == id_ex_rs1))
        forwardA = 2'b01;

        if (ex_mem_regwrite && (ex_mem_rd != 0) && (ex_mem_rd == id_ex_rs2))
        forwardB = 2'b10;
        else if (mem_wb_regwrite && (mem_wb_rd != 0) && (mem_wb_rd == id_ex_rs2))
        forwardB = 2'b01;
    end
endmodule
