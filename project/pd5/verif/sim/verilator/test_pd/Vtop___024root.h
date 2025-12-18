// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__clock;
        CData/*0:0*/ top__DOT__reset;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__WX_enable;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__MX_enable;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_pcsel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_immsel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_regwren;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_rs1sel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_rs2sel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_memren;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_memwren;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__ctrl_wbsel;
        CData/*3:0*/ top__DOT__dut__DOT__core__DOT__ctrl_alusel;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__rs1_mem_o;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_program;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__fetch1__DOT__br_taken;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__fetch1__DOT__stall;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct7_pipe;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__shamt_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__immsel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memren_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe;
        CData/*3:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__brtaken_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memren_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memwren_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__regwren_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__wbsel_pipe;
        CData/*3:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alusel_pipe;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__opcode_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__regwren_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe;
        CData/*0:0*/ __Vdpi_export_trigger;
        CData/*0:0*/ __VdfgRegularize_hebeb780c_0_8;
        CData/*0:0*/ __VdfgRegularize_hebeb780c_0_16;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__clock__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__reset__0;
        IData/*31:0*/ top__DOT__genblk1__DOT_____05Ftrace_fd;
        IData/*31:0*/ top__DOT__genblk2__DOT_____05Fdump_fd;
        VlWide<24>/*767:0*/ top__DOT__genblk2__DOT__pattern_dump;
        VlWide<4>/*127:0*/ top__DOT__genblk2__DOT__pattern_dump_proc__DOT__stage;
        IData/*31:0*/ top__DOT__clkg__DOT__counter;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__datawb_i;
    };
    struct {
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__addr_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__data_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__memory_data_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_res_mem_o;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__f_pc;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__f_insn;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__rs2_val_topipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__fetch1__DOT__alu_res;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_decode__DOT__imm_o;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_register_file__DOT__rs1data_o;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_register_file__DOT__rs2data_o;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_register_file__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_igen__DOT__imm_o;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs1_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs2_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__memory1__DOT__data_dat;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__memory1__DOT__i;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe;
        IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
        IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs;
        VlUnpacked<IData/*31:0*/, 72> top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory;
        VlUnpacked<CData/*7:0*/, 4194304> top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
