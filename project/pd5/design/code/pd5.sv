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

 /*
  * Instantiate other submodules and
  * probes. To be filled by student...
  *
  */


    
       
    
        //Excute stage Signals
    logic [DWIDTH - 1:0] rs1_i; // not to be confused as registers
    logic [DWIDTH - 1:0] rs2_i; // simply two operand inputs
    logic [DWIDTH - 1:0] alu_res;
    logic                br_taken;

     // CONTROL Signals
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
    logic [DWIDTH - 1:0] datawb_i;
    logic [DWIDTH - 1:0] rs1data_o;
    logic [DWIDTH - 1:0] rs2data_o;


    // imemory signals
    logic [DWIDTH - 1:0] addr_i;
    logic [DWIDTH - 1:0] data_i;
    logic write_en;
    logic read_en;
       // Memory data Signals
    logic [1:0] size_encoded;

     // Writeback stage signals
    logic [DWIDTH - 1:0] alu_res_wb_o;
    logic [DWIDTH - 1:0] load_data_wb_o;
    logic [AWIDTH - 1:0] pc_wb_o;
    logic [4:0]        rd_wb_o; 

    logic              regwren_wb_o;
    logic [1:0]        wbsel_wb_o;

        // writeback signals
    logic [DWIDTH - 1:0] writeback_data_o;
    logic [DWIDTH - 1:0] next_pc_o;
    logic [DWIDTH - 1:0] memory_data_i;

 



    // ok five stages 
    // FETCH, DECODE, EXECUTE, MEMORY, WRITEBACK
    // we need to pipeline them so have registers at each stage 
    // IF/ID this one is for fetch to decode this register holds the instruction for decode to decode while fetch fetches next instruction
    // ID/EXE this one is for decode to execute so decode sends coorect register and contorl to execute while decode decodes next instruction
    // EXE/MEM this register holds alu result and control signals and rs2 data for memory stage while execute executes nexT INSTRUCTION
    // MEM/WB this register holds data from memory alu result to then writeback while memory loads next data

    

    // Default memory signals for instruction memory
    assign read_en = 1'b1;
    assign write_en = 1'b0;

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
        .pcsel_o(ctrl_pcsel),
        .alu_res(alu_res),
        .pc_o(f_pc),           
        .insn_o(f_insn)         
    );

    // temp signals for flush and stall
    logic stall=0;
    logic flush=0;

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
        .br_taken(),
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


    // pipe signals for id/ix 
    logic [AWIDTH-1:0] ix_pc_o;
    logic [DWIDTH-1:0] ix_ins_o;
    logic [6:0]        ix_opcode_o;
    logic [4:0]        ix_rd_o;
    logic [DWIDTH-1:0] ix_rs1_o;
    logic [DWIDTH-1:0] ix_rs2_o;
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
        .rs1_data_i(rs1data_o),
        .rs2_data_i(rs2data_o),
        .rs1_o(ix_rs1_o),
        .rs2_o(ix_rs2_o),
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


    
     //branch control signals
    logic breq_o;
    logic brlt_o;
    logic brltu_o;
    // Branch control unit
    branch_control #(
        .DWIDTH(DWIDTH)
    ) u_branch_control (
        .opcode_i(ix_opcode_o),
        .funct3_i(ix_funct3_o),
        .rs1_i(ix_rs1_o), // from register file becuase
        .rs2_i(ix_rs2_o), // rs1_i and rs2_i will be muxed to select pc and imm rather than register data
        .breq_o(breq_o),
        .brlt_o(brlt_o),
        .brltu_o(brltu_o)
    );

    logic [31:0] imm_o;

    // Immediate Generation (through the provided igen module)
    igen #(
        .DWIDTH(DWIDTH)
    ) u_igen (
        .opcode_i(ix_opcode_o),
        .insn_i(ix_ins_o),
        .imm_o(imm_o)
    );


    // Select rs1 and rs2 inputs to ALU based on control signals
    assign rs1_i = (ix_rs1sel_o) ?  ix_rs1_o : ix_pc_o;
    assign rs2_i = (ix_rs2sel_o) ?  ix_rs2_o : imm_o;


    // Excute stage - ALU
    alu #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_alu (
        .pc_i(ix_pc_o),
        .rs1_i(ix_rs1_o), 
        .rs2_i(ix_rs2_o), 
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

    // EX/MEM pipe signals
    logic [DWIDTH-1:0] alu_res_mem_o;
    logic [AWIDTH-1:0] pc_mem_o;
    logic [DWIDTH-1:0] rs2_val_mem_o;
    logic [4:0]        rd_mem_o;
    logic             br_taken_mem_o;

    logic              memren_mem_o;
    logic              memwren_mem_o;
    logic              regwren_mem_o;
    logic [1:0]        wbsel_mem_o;
    logic [3:0]        alusel_mem_o;

    ix_mem_pipe #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_ix_mem_pipe (
        .clk(clk),
        .rst(reset),
        .stall_i(stall),
        .flush_i(flush),
        .alu_res_i(alu_res),
        .brtaken_i(br_taken),
        .pc_i(ix_pc_o),
        .rs2_val_i(ix_rs2_o),
        .rd_i(ix_rd_o),
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
        .memren_o(memren_mem_o),
        .memwren_o(memwren_mem_o),
        .regwren_o(regwren_mem_o),
        .wbsel_o(wbsel_mem_o),
        .alusel_o(alusel_mem_o)
    );

    // Data Memory size encoding logic based on lower 2 bits of funct3
    always_comb begin
                case (d_funct3)
                    3'b000, 3'b100: size_encoded = 2'b00; // word 
                    3'b001, 3'b101: size_encoded = 2'b01; // halfword 
                    3'b010:         size_encoded = 2'b10; // byte 
                    3'b111:         size_encoded = 2'b11; // doubleword
                    default:        size_encoded = 2'b00; // default to word
                endcase
            end
           

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
        .data_dat(rs2data_o), // data to write to data memory from rs2 only will happen is write enable is high
        .read_en_i(read_en), // controls for instruction memory hardset to always read never write
        .write_en_i(write_en),
        .read_en_dat(ctrl_memren), // controls for data memory 
        .write_en_dat(ctrl_memwren),
        .size_encoded(size_encoded), // new input for size encoding
        .data_o(f_insn),
        .data_dat_o(memory_data_i) // data read from data memory
   );

    mem_wb_pipe #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_mem_wb_pipe (
        .clk(clk),
        .rst(reset),
        .stall_i(stall),
        .flush_i(flush),
        .alu_res_i(alu_res_mem_o),
        .load_data_i(memory_data_i),
        .pc_i(pc_mem_o),
        .rd_i(rd_mem_o),
        .regwren_i(regwren_mem_o),
        .wbsel_i(wbsel_mem_o),
        .alu_res_o(alu_res_wb_o),
        .load_data_o(load_data_wb_o),
        .pc_o(pc_wb_o),
        .rd_o(rd_wb_o),
        .regwren_o(regwren_wb_o),
        .wbsel_o(wbsel_wb_o)
    );

   

    writeback #(
        .DWIDTH(DWIDTH),
        .AWIDTH(AWIDTH)
    ) u_writeback (
        .pc_i(d_pc), 
        .alu_res_i(alu_res_wb_o),
        .memory_data_i(load_data_wb_o), // data from data memory
        .wbsel_i(wbsel_wb_o), // control signal to select what to write back
        .brtaken_i(br_taken), // to drive next pc logic
        .writeback_data_o(writeback_data_o), // data to write back to register file
        .next_pc_o(next_pc_o)
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

    `define PROBE_R_WRITE_ENABLE  regwren_wb_o // ??
    `define PROBE_R_WRITE_DESTINATION  rd_wb_o // ??
    `define PROBE_R_WRITE_DATA writeback_data_o // ??
    `define PROBE_R_READ_RS1 d_rs1  // ??
    `define PROBE_R_READ_RS2 d_rs2  // ??
    `define PROBE_R_READ_RS1_DATA rs1data_o    // ??
    `define PROBE_R_READ_RS2_DATA  rs2data_o   // ??

    `define PROBE_E_PC       ix_pc_o         // ??
    `define PROBE_E_ALU_RES  alu_res       // ??
    `define PROBE_E_BR_TAKEN  br_taken       // ??

    `define PROBE_M_PC      pc_mem_o         // ??
    `define PROBE_M_ADDRESS        alu_res_mem_o   // ??
    `define PROBE_M_SIZE_ENCODED    size_encoded // ??
    `define PROBE_M_DATA            memory_data_i  // ??

    `define PROBE_W_PC            pc_wb_o  // ??
    `define PROBE_W_ENABLE         regwren_mem_o  // ??
    `define PROBE_W_DESTINATION     rd_wb_o  // ??
    `define PROBE_W_DATA      writeback_data_o        // ??


// program termination logic
reg is_program = 0;
always_ff @(posedge clk) begin
    if (f_insn == 32'h00000073) $finish;  // directly terminate if see ecall
    if (f_insn == 32'h00008067) is_program = 1;  // if see ret instruction, it is simple program test
    // [TODO] Change register_file_0.registers[2] to the appropriate x2 register based on your module instantiations...
    if (is_program && (u_register_file.regs[2] == 32'h01000000 + `MEM_DEPTH)) $finish;
end

endmodule : pd5