/*
 * Module: pd5
 *
 * Description: Top level module that will contain sub-module instantiations.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

module pd5 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32)(
    input logic clk,
    input logic reset
);
    // stall signals 
    logic stall;

    //flush signals
    logic flush;

    //forwarding signals
    logic       WM_enable;
    logic [1:0] WX_enable;
    logic [1:0] MX_enable;  

    //Excute stage Signals
    logic [DWIDTH - 1:0] rs1_i;  
    logic [DWIDTH - 1:0] rs2_i; 
    logic [DWIDTH - 1:0] alu_res; 
    logic                br_taken; 

     // CONTROL Signals (Decode Stage)
    logic              ctrl_pcsel; 
    logic              ctrl_immsel; 
    logic              ctrl_regwren; 
    logic              ctrl_rs1sel; 
    logic              ctrl_rs2sel; 
    logic              ctrl_memren;  
    logic              ctrl_memwren; 
    logic [1:0]        ctrl_wbsel; 
    logic [3:0]        ctrl_alusel; 
   

   
    //register file signals
    logic [DWIDTH - 1:0] datawb_i; // **UNUSED** use diiferent signal to feed writeback
    logic [DWIDTH - 1:0] rs1data_o; 
    logic [DWIDTH - 1:0] rs2data_o; 


    // imemory signals
    logic [DWIDTH - 1:0] addr_i; // instruction memory address input
    logic [DWIDTH - 1:0] data_i; // *** Unused *** data input 
    logic write_en; // ** UNUSED ** instruction memory never writes or has acess to write enable data
    logic read_en; 

     // Writeback stage signals
    logic [DWIDTH - 1:0] alu_res_wb_o; 
    logic [DWIDTH - 1:0] load_data_wb_o; 
    logic [AWIDTH - 1:0] pc_wb_o; 
    logic [4:0]          rd_wb_o; 
    logic [6:0]          opcode_wb_o;

    logic              regwren_wb_o; 
    logic [1:0]        wbsel_wb_o; 

    // memory stage signals
    logic [1:0] size_encoded_o; 

    // writeback signals
    logic [DWIDTH - 1:0] writeback_data_o; // data to write back to register file
    logic [DWIDTH - 1:0] next_pc_o; 
    logic [DWIDTH - 1:0] memory_data_i; 

 
    logic [2:0]        funct3_mem_o; // funct3 from ix_mem pipe to memory for size encoding
    
    // pipe signals for ID/EX
    logic [AWIDTH-1:0] ix_pc_o;
    logic [DWIDTH-1:0] ix_ins_o;
    logic [6:0]        ix_opcode_o;
    logic [4:0]        ix_rd_o;
    logic [4:0]        ix_rs1_o;
    logic [4:0]        ix_rs2_o;
    logic [DWIDTH-1:0] ix_rs1_data_o;
    logic [DWIDTH-1:0] ix_rs2_data_o;
    logic [6:0]        ix_funct7_o;
    logic [2:0]        ix_funct3_o;
    logic [4:0]        ix_shamt_o;
    logic             ix_pcsel_o;
    logic             ix_immsel_o;
    logic             ix_regwren_o;
    logic             ix_rs1sel_o;
    logic             ix_rs2sel_o;
    logic             ix_memren_o;
    logic             ix_memwren_o;
    logic [1:0]       ix_wbsel_o;
    logic [3:0]       ix_alusel_o;


    // EX/MEM pipe signals
    logic [DWIDTH-1:0] alu_res_mem_o;
    logic [AWIDTH-1:0] pc_mem_o;
    logic [DWIDTH-1:0] rs2_val_mem_o;
    logic [4:0]        rd_mem_o;
    logic [4:0]        rs1_mem_o;
    logic [4:0]        rs2_mem_o; 
    logic              br_taken_mem_o;
    logic [6:0]        opcode_mem_o;

    logic              memren_mem_o;
    logic              memwren_mem_o;
    logic              regwren_mem_o;
    logic [1:0]        wbsel_mem_o;
    logic [3:0]        alusel_mem_o;

    // Default memory signals for instruction memory
    assign read_en = 1'b1;
    assign write_en = 1'b0; // ** UNUSED ** instruction memory is read only in this design

    // Fetch signals
    logic [DWIDTH - 1:0] f_pc; 
    logic [DWIDTH - 1:0] f_insn; 

    // Fetch 
    fetch #(
        .AWIDTH(32),
        .DWIDTH(32),
        .BASEADDR(32'h01000000)
    ) fetch1 (
        .clk(clk),
        .rst(reset),
        .pcsel(ix_pcsel_o),
        .br_taken(br_taken),
        .stall(stall),
        .alu_res(alu_res),
        .pc_o(f_pc),           
        .insn_o(f_insn)         
    );


     // DECODE stage signals
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


    // Fetch to Decode pipeline
    if_id_pipe #(
        .DWIDTH(DWIDTH)
    ) u_if_id_pipe (
        .clk(clk),
        .rst(reset),
        .stall_i(stall),
        .flush_i(flush),
        .pc_i(f_pc),
        .pc_o(d_pc),
        .ins_i(f_insn),
        .ins_o(d_insn)
    );


 


    // Decode stage
    decode #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_decode (
        .clk(clk),
        .rst(reset),
        .insn_i(d_insn),
        .pc_i(d_pc),
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



    // Register File
    register_file #(
        .DWIDTH(DWIDTH)
    ) u_register_file (
        .clk(clk),
        .rst(reset),
        .rs1_i(d_rs1),
        .rs2_i(d_rs2),
        .rd_i(rd_wb_o),
        .datawb_i(writeback_data_o),      
        .regwren_i(regwren_wb_o),
        .rs1data_o(rs1data_o),     
        .rs2data_o(rs2data_o)      
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


    
    // Decode to Execute Pipeline
    // note ix = ex modules were labelled ix early on by mistake
    // note many pipelines propgate values that may not be needed 
    // due to time constraints we did not slim down the registers but they can be reduced
    id_ix_pipe #(
        .AWIDTH(AWIDTH),
        .DWIDTH(DWIDTH)
    ) u_id_ix_pipe (
        .clk(clk),
        .rst(reset),
        .stall_i(stall),
        .flush_i(flush),
        .pc_i(d_pc),
        .pc_o(ix_pc_o),
        .ins_i(d_insn),
        .ins_o(ix_ins_o),
        .opcode_i(d_opcode),
        .opcode_o(ix_opcode_o),
        .rd_i(d_rd),
        .rd_o(ix_rd_o),
        .rs1_i(d_rs1),
        .rs2_i(d_rs2),
        .rs1_o(ix_rs1_o),
        .rs2_o(ix_rs2_o),
        .rs1_data_i(rs1data_o),
        .rs2_data_i(rs2data_o),
        .rs1_data_o(ix_rs1_data_o),
        .rs2_data_o(ix_rs2_data_o),
        .funct7_i(d_funct7),
        .funct7_o(ix_funct7_o),
        .funct3_i(d_funct3),
        .funct3_o(ix_funct3_o),
        .shamt_i(d_shamt),
        .shamt_o(ix_shamt_o),
        .pcsel_i(ctrl_pcsel),
        .pcsel_o(ix_pcsel_o),
        .immsel_i(ctrl_immsel),
        .immsel_o(ix_immsel_o),
        .regwren_i(ctrl_regwren),
        .regwren_o(ix_regwren_o),
        .rs1sel_i(ctrl_rs1sel),
        .rs1sel_o(ix_rs1sel_o),
        .rs2sel_i(ctrl_rs2sel),
        .rs2sel_o(ix_rs2sel_o),
        .memren_i(ctrl_memren),
        .memren_o(ix_memren_o),
        .memwren_i(ctrl_memwren),
        .memwren_o(ix_memwren_o),
        .wbsel_i(ctrl_wbsel),
        .wbsel_o(ix_wbsel_o),
        .alusel_i(ctrl_alusel),
        .alusel_o(ix_alusel_o)
    );


    
    

    logic [31:0] imm_o;

    // Immediate Generation now outside of decode and in execute stage 
    igen #(
        .DWIDTH(DWIDTH)
    ) u_igen (
        .opcode_i(ix_opcode_o),
        .insn_i(ix_ins_o),
        .imm_o(imm_o)
    );


    // mux feeding execute source operands 
    // forwards values if needed otherwise chose based
    // on source operand select control signals
    execute_mux # (

    ) u_execute_mux (
        .rs1(ix_rs1_data_o),
        .rs2(ix_rs2_data_o),
        .ex_mem_alures(alu_res_mem_o),
        .writeback(writeback_data_o),
        .pc(ix_pc_o),
        .imm(imm_o),
        .opcode_i(ix_opcode_o),
        .rs1_sel(ix_rs1sel_o),
        .rs2_sel(ix_rs2sel_o),
        .MX_enable(MX_enable),
        .WX_enable(WX_enable),
        .rs1_o(rs1_i),
        .rs2_o(rs2_i)
    );



    //branch control signals, while branch compares the register data for many operations
    // execute uses imm or pc so different muxes are needed but still take advantage 
    // of bypass paths 
    // for now its in top module but should probably be in seperate file
    logic breq_o;
    logic brlt_o;
    logic brltu_o;
    logic [DWIDTH-1:0] rs1_branch;
    logic [DWIDTH-1:0] rs2_branch;
    //rs1 source for branch 
    always_comb begin
    if (MX_enable == 2'b01) begin
        rs1_branch = alu_res_mem_o;
    end
    else if (WX_enable == 2'b01) begin
        rs1_branch = writeback_data_o;
    end
    else begin 
        rs1_branch = ix_rs1_data_o ;
    end
    end
    // rs2 source for brach 
    always_comb begin
    if (MX_enable == 2'b10) begin
        rs2_branch = alu_res_mem_o;
    end
    else if (WX_enable == 2'b10) begin
        rs2_branch = writeback_data_o;
    end
    else begin 
        rs2_branch = ix_rs2_data_o;
    end
    end

    // Branch control unit
    branch_control #(
        .DWIDTH(DWIDTH)
    ) u_branch_control (
        .opcode_i(ix_opcode_o),
        .funct3_i(ix_funct3_o),
        .rs1_i(rs1_branch), 
        .rs2_i(rs2_branch), 
        .breq_o(breq_o),
        .brlt_o(brlt_o),
        .brltu_o(brltu_o)
    );

    // Execute stage - ALU
    alu #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_alu (
        .pc_i(ix_pc_o),
        .rs1_i(rs1_i), 
        .rs2_i(rs2_i), 
        .funct3_i(ix_funct3_o),
        .funct7_i(ix_funct7_o),
        .opcode_i(ix_opcode_o),
        .alusel_i(ix_alusel_o),
        .eq(breq_o),
        .lt(brlt_o),
        .ltu(brltu_o),
        .res_o(alu_res),      
        .brtaken_o(br_taken)   
    );
    

    // Execute to Memory stage pipeline
    ix_mem_pipe #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_ix_mem_pipe (
        .clk(clk),
        .rst(reset),
        .alu_res_i(alu_res),
        .brtaken_i(br_taken),
        .pc_i(ix_pc_o),
        .rs2_val_i(ix_rs2_data_o),
        .rd_i(ix_rd_o),
        .rs1_i(ix_rs1_o),
        .rs2_i(ix_rs2_o),
        .opcode_i(ix_opcode_o),
        .memren_i(ix_memren_o),
        .memwren_i(ix_memwren_o),
        .regwren_i(ix_regwren_o),
        .wbsel_i(ix_wbsel_o),
        .alusel_i(ix_alusel_o),
        .alu_res_o(alu_res_mem_o),
        .brtaken_o(br_taken_mem_o),
        .pc_o(pc_mem_o),
        .rs2_val_o(rs2_val_mem_o),
        .rd_o(rd_mem_o),
        .rs1_o(rs1_mem_o),
        .rs2_o(rs2_mem_o),
        .opcode_o(opcode_mem_o),
        .funct3_i(ix_funct3_o),
        .funct3_o(funct3_mem_o),
        .memren_o(memren_mem_o),
        .memwren_o(memwren_mem_o),
        .regwren_o(regwren_mem_o),
        .wbsel_o(wbsel_mem_o),
        .alusel_o(alusel_mem_o)
    );


    // select correct store data depending on the bypass    
    logic [DWIDTH-1:0] store_data;
    assign store_data = (WM_enable) ? writeback_data_o : rs2_val_mem_o;
    
    
    // Memory
    memory #(
        .AWIDTH(32),
        .DWIDTH(32),
        .BASE_ADDR(32'h01000000)
       ) memory1 (
        .clk(clk),
        .rst(reset),
        .addr_i(f_pc),
        .addr_dat(alu_res_mem_o),
        .data_i(data_i), 
        .data_dat(store_data), 
        .read_en_i(read_en), 
        .write_en_i(write_en),
        .read_en_dat(read_en), // controls for data memory 
        .write_en_dat(memwren_mem_o),
        .funct3_i(funct3_mem_o),
        .size_encoded_o(size_encoded_o), // new output for size encoding
        .data_o(f_insn),
        .data_dat_o(memory_data_i) // data read from data memory
   );


    // Memory to Writeback Pipeline
    mem_wb_pipe #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_mem_wb_pipe (
        .clk(clk),
        .rst(reset),
        .alu_res_i(alu_res_mem_o),
        .load_data_i(memory_data_i),
        .pc_i(pc_mem_o),
        .rd_i(rd_mem_o),
        .opcode_i(opcode_mem_o),
        .regwren_i(regwren_mem_o),
        .wbsel_i(wbsel_mem_o),
        .alu_res_o(alu_res_wb_o),
        .load_data_o(load_data_wb_o),
        .pc_o(pc_wb_o),
        .rd_o(rd_wb_o),
        .opcode_o(opcode_wb_o),
        .regwren_o(regwren_wb_o),
        .wbsel_o(wbsel_wb_o)
    );

   
    // Writeback Stage
    writeback #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_writeback (
        .pc_i(pc_wb_o), 
        .alu_res_i(alu_res_wb_o),
        .memory_data_i(load_data_wb_o), // data from data memory
        .wbsel_i(wbsel_wb_o), // control signal to select what to write back
        .brtaken_i(br_taken), // to drive next pc logic
        .writeback_data_o(writeback_data_o), // data to write back to register file
        .next_pc_o(next_pc_o)
    );



    //hazard units 
    stall_unit #()
    u_stall_unit (
        .opcode_id_ex_i(ix_opcode_o),
        .opcode_if_id_i(d_opcode),
        .rd_id_ex_i(ix_rd_o),
        .rd_mem_wb_i(rd_wb_o),
        .rs1_if_id_i(d_rs1),
        .rs2_if_id_i(d_rs2),
        .stall_o(stall)
    );

    flush_unit #()
    u_flush_unit(
        .br_taken(br_taken),
        .pcsel(ix_pcsel_o),
        .flush_o(flush)
    );

    forwarding_unit #()
    u_forwarding_unit(
        .rd_ex_mem_i(rd_mem_o),
        .rd_mem_wb_i(rd_wb_o),
        .rs1_id_ex_i(ix_rs1_o),
        .rs2_id_ex_i(ix_rs2_o),
        .ix_opcode_o(ix_opcode_o),
        .wb_opcode_o(opcode_wb_o),
        .rs2_ex_mem_i(rs2_mem_o),
        .WM_enable(WM_enable),
        .WX_enable(WX_enable),
        .MX_enable(MX_enable)
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

    `define PROBE_R_WRITE_ENABLE  regwren_wb_o 
    `define PROBE_R_WRITE_DESTINATION  rd_wb_o 
    `define PROBE_R_WRITE_DATA writeback_data_o 
    `define PROBE_R_READ_RS1 d_rs1  
    `define PROBE_R_READ_RS2 d_rs2  
    `define PROBE_R_READ_RS1_DATA rs1data_o    
    `define PROBE_R_READ_RS2_DATA  rs2data_o   

    `define PROBE_E_PC       ix_pc_o        
    `define PROBE_E_ALU_RES  alu_res      
    `define PROBE_E_BR_TAKEN  br_taken       

    `define PROBE_M_PC      pc_mem_o         
    `define PROBE_M_ADDRESS        alu_res_mem_o   
    `define PROBE_M_SIZE_ENCODED    size_encoded_o 
    `define PROBE_M_DATA            memory_data_i  

    `define PROBE_W_PC            pc_wb_o  
    `define PROBE_W_ENABLE         regwren_mem_o  
    `define PROBE_W_DESTINATION     rd_wb_o  
    `define PROBE_W_DATA      writeback_data_o        


// program termination logic, if program at termination and x15 is one benchmark passed
reg is_program = 0;
always_ff @(posedge clk) begin

    if (f_insn == 32'h00000073) begin  // directly terminate if see ecall
        if (u_register_file.regs[15] == 32'd1 ) begin
        $display(" *** TEST PASSED *** ECALL");
        end
        else begin
            $display(" *** TEST FAILED *** ECALL");
        end
        $finish;
    end


    if (f_insn == 32'h00008067) is_program = 1;  // if see ret instruction, it is simple program test
    


    if (is_program && (u_register_file.regs[2] == 32'h01000000 + `MEM_DEPTH)) begin 
        if (u_register_file.regs[15] == 32'd1 ) begin
        $display(" *** TEST PASSED *** %s" ,`MEM_PATH);
        end
        else begin
            $display(" *** TEST FAILED *** ");
        end
        $finish;
    end
end

endmodule : pd5