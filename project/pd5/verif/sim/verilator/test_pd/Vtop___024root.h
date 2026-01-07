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
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__stall;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_pcsel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_regwren;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_rs1sel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_rs2sel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__ctrl_memwren;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__ctrl_wbsel;
        CData/*3:0*/ top__DOT__dut__DOT__core__DOT__ctrl_alusel;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_taken;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_program;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe;
        CData/*3:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memwren_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__regwren_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__wbsel_pipe;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__opcode_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__regwren_pipe;
        CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe;
        CData/*0:0*/ __Vdpi_export_trigger;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0;
        CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1;
        CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v2;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3;
        CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v4;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v5;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v6;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7;
        CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v8;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v9;
        CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v10;
        CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v0;
        CData/*4:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33;
        CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__clock__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__reset__0;
        IData/*31:0*/ top__DOT__genblk1__DOT_____05Ftrace_fd;
        IData/*31:0*/ top__DOT__clkg__DOT__counter;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__f_pc;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__f_insn;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__d_imm;
    };
    struct {
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_res;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__writeback_data_o;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_res_mem_o;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__rs2_val_topipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__store_data;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_0;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_1;
        IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
        IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v2;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v4;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v5;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v6;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v8;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v9;
        IData/*21:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v10;
        IData/*31:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs;
        VlUnpacked<IData/*31:0*/, 127> top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory;
        VlUnpacked<CData/*7:0*/, 4194304> top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VnbaTriggered;
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
