// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root____Vdpiexp_top__DOT__clkg__DOT__toggleClock_TOP(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiexp_top__DOT__clkg__DOT__toggleClock_TOP\n"); );
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.top__DOT__clock = (1U & (~ (IData)(vlSymsp->TOP.top__DOT__clock)));
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__clock = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/tests/clockgen.sv", 
                                             18);
        vlSelfRef.top__DOT__clock = (1U & (~ (IData)(vlSelfRef.top__DOT__clock)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VactTriggered
                                      [1U]) | (IData)((IData)(vlSelfRef.__Vdpi_export_trigger)));
    vlSelfRef.__Vdpi_export_trigger = 0U;
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.top__DOT__reset) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__reset__0))) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.top__DOT__clock) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0))) 
                                                         << 1U) 
                                                        | ((~ (IData)(vlSelfRef.top__DOT__clock)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0 
        = vlSelfRef.top__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__reset__0 
        = vlSelfRef.top__DOT__reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__clkg__DOT__counter = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
    __Vdly__top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc = 0;
    // Body
    __Vdly__top__DOT__clkg__DOT__counter = vlSelfRef.top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
    vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0 = 0U;
    vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1 = 0U;
    vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3 = 0U;
    vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7 = 0U;
    if (VL_UNLIKELY(((0x00000073U == vlSelfRef.top__DOT__dut__DOT__core__DOT__f_insn)))) {
        if ((1U == vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
             [0x0fU])) {
            VL_WRITEF_NX(" *** TEST PASSED *** ECALL\n",0);
        } else {
            VL_WRITEF_NX(" *** TEST FAILED *** ECALL\n",0);
        }
        VL_FINISH_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/design/code/pd5.sv", 580, "");
    }
    if ((0x00008067U == vlSelfRef.top__DOT__dut__DOT__core__DOT__f_insn)) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__is_program = 1U;
    }
    if (VL_UNLIKELY((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__is_program) 
                      & (0x01100000U == vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
                         [2U]))))) {
        if ((1U == vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
             [0x0fU])) {
            VL_WRITEF_NX(" *** TEST PASSED *** /Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/rv32-bmarks/full-bmarks/BubbleSort.x\n",0);
        } else {
            VL_WRITEF_NX(" *** TEST FAILED *** \n",0);
        }
        VL_FINISH_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/design/code/pd5.sv", 595, "");
    }
    if (vlSelfRef.top__DOT__reset) {
        __Vdly__top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc = 0x01000000U;
    } else if (vlSelfRef.top__DOT__dut__DOT__core__DOT__stall) {
        __Vdly__top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
    } else {
        __Vdly__top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc 
            = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o)
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res
                : ((IData)(4U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc));
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o) 
                                                << 1U) 
                                               | (1U 
                                                  & (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o)))))))))) {
            if ((0U != (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o) 
                         << 1U) | (1U & (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o)))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: fetch.sv:51: Assertion failed in %Ntop.dut.core.fetch1: unique case, but multiple matches found for '1'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -12,vlSymsp->name(),
                                 1,(IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o));
                    VL_STOP_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/design/code/fetch.sv", 51, "");
                }
            }
        }
    }
    if (VL_UNLIKELY((vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memwren_pipe))) {
        VL_WRITEF_NX("[%0t] IMEMORY: Wrote 0x%08x to 0x%08x\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,32,
                     vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data,
                     32,vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o);
        if ((0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))) {
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0 
                = (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data);
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0 
                = (0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat);
            vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0 = 1U;
        } else if ((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))) {
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1 
                = (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data);
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1 
                = (0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat);
            vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1 = 1U;
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v2 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v2 
                = (0x003fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat));
        } else if ((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))) {
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3 
                = (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data);
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3 
                = (0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat);
            vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3 = 1U;
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v4 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v4 
                = (0x003fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat));
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v5 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v5 
                = (0x003fffffU & ((IData)(2U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat));
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v6 
                = (vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
                   >> 0x18U);
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v6 
                = (0x003fffffU & ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat));
        } else {
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7 
                = (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data);
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7 
                = (0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat);
            vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7 = 1U;
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v8 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v8 
                = (0x003fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat));
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v9 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v9 
                = (0x003fffffU & ((IData)(2U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat));
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v10 
                = (vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
                   >> 0x18U);
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v10 
                = (0x003fffffU & ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat));
        }
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc 
        = __Vdly__top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
    vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
    vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v0 = 0U;
    vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33 = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memwren_pipe 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe));
    if (vlSelfRef.top__DOT__reset) {
        vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe = 0U;
        vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe = 0U;
        vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v0 = 1U;
    } else {
        if (vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o) {
            vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe = 0U;
            vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe = 0x00000013U;
        } else if (vlSelfRef.top__DOT__dut__DOT__core__DOT__stall) {
            vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
            vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
        } else {
            vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc;
            vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__f_insn;
        }
        if (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__regwren_pipe) 
             & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)))) {
            vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o;
            vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe;
            vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33 = 1U;
        }
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__regwren_pipe 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__regwren_pipe));
    if (vlSelfRef.top__DOT__reset) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe = 0U;
    } else {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__rs2_val_topipe;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe;
        if (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o) 
             | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe = 0x00000013U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall)))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe 
                = ((0U == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                          >> 0x0000000fU)))
                    ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
                   [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                    >> 0x0000000fU))]);
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe 
                = ((0U == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                          >> 0x00000014U)))
                    ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
                   [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                    >> 0x00000014U))]);
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe 
                = (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                  >> 0x0000000fU));
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe 
                = (7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                         >> 0x0000000cU));
        }
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe 
            = ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
                ? (((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                     [(0x003fffffU & ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                     << 0x00000018U) | (vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                        [(0x003fffffU 
                                          & ((IData)(2U) 
                                             + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                        << 0x00000010U)) 
                   | ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                       [(0x003fffffU & ((IData)(1U) 
                                        + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                       << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                      [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)]))
                : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
                    ? ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                        [(0x003fffffU & ((IData)(1U) 
                                         + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                        << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                       [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)])
                    : vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                   [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)]));
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__wbsel_pipe;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__opcode_pipe;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe;
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: writeback.sv:37: Assertion failed in %Ntop.dut.core.u_writeback: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),2,
                             (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe));
                VL_STOP_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/design/code/writeback.sv", 37, "");
            }
        }
    }
    if (vlSelfRef.top__DOT__reset) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__wbsel_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__opcode_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe = 0U;
    } else {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__wbsel_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__opcode_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe;
        if (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o) 
             | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall)))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe 
                = (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                  >> 0x00000014U));
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memwren;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe 
                = (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe);
        }
    }
    if ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))) {
            vlSelfRef.__VdfgRegularize_hebeb780c_0_0 
                = (((- (IData)((vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                >> 0x0000001fU))) << 0x0000000cU) 
                   | (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                      >> 0x00000014U));
            vlSelfRef.__VdfgRegularize_hebeb780c_0_1 
                = (0xfffff000U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe);
        } else {
            vlSelfRef.__VdfgRegularize_hebeb780c_0_0 = 0U;
            vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = 0U;
        }
    } else {
        vlSelfRef.__VdfgRegularize_hebeb780c_0_0 = 0U;
        vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = 0U;
    }
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.top__DOT__reset)))))) {
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[F] %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__f_insn);
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[D] %x %x %x %x %x %x %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe,
                      7,(0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe),
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                        >> 7U)),5,(0x0000001fU 
                                                   & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                      >> 0x0000000fU)),
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                        >> 0x00000014U)),
                      3,(7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                               >> 0x0000000cU)),7,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                   >> 0x00000019U),
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__d_imm,
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                        >> 0x00000014U)));
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[R] %x %x %x %x\n",0,
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                        >> 0x0000000fU)),
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                        >> 0x00000014U)),
                      32,((0U == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                 >> 0x0000000fU)))
                           ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
                          [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                           >> 0x0000000fU))]),
                      32,((0U == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                 >> 0x00000014U)))
                           ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
                          [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                           >> 0x00000014U))]));
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[E] %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res,
                      1,(IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken));
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[M] %x %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o,
                      2,(IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded),
                      32,((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
                           ? (((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                [(0x003fffffU & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                << 0x00000018U) | (
                                                   vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                                   [
                                                   (0x003fffffU 
                                                    & ((IData)(2U) 
                                                       + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                                   << 0x00000010U)) 
                              | ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                  [(0x003fffffU & ((IData)(1U) 
                                                   + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                  << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                 [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)]))
                           : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
                               ? ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                   [(0x003fffffU & 
                                     ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                   << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                  [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)])
                               : vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                              [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)])));
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[W] %x %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe,
                      1,(IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__regwren_pipe),
                      5,vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o);
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
    }
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc = vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
    if (vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v0;
    }
    if (vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v1;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v2] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v2;
    }
    if (vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v3;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v4] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v4;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v5] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v5;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v6] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v6;
    }
    if (vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v7;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v8] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v8;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v9] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v9;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v10] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory__v10;
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__f_insn 
        = (((0x01000000U <= vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc) 
            & (0x01400000U > ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc)))
            ? (((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                 [(0x003fffffU & ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc))] 
                 << 0x00000018U) | (vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                    [(0x003fffffU & 
                                      ((IData)(2U) 
                                       + vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc))] 
                                    << 0x00000010U)) 
               | ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                   [(0x003fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc))] 
                   << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                  [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc)]))
            : 0xdeadbeefU);
}

extern const VlUnpacked<CData/*1:0*/, 8> Vtop__ConstPool__TABLE_hd6134ef5_0;

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable;
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable;
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs1_branch_o;
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs1_branch_o = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs2_branch_o;
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs2_branch_o = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o;
    top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o;
    top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o;
    top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i;
    top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i;
    top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i = 0;
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_7;
    __VdfgRegularize_hebeb780c_0_7 = 0;
    // Body
    __Vtableidx1 = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded 
        = Vtop__ConstPool__TABLE_hd6134ef5_0[__Vtableidx1];
    if (vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v0) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[1U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[2U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[3U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[4U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[5U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[6U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[7U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[8U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[9U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x0aU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x0bU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x0cU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x0dU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x0eU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x0fU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x10U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x11U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x12U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x13U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x14U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x15U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x16U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x17U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x18U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x19U] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x1aU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x1bU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x1cU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x1dU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x1eU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0x1fU] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[2U] = 0x01100000U;
    }
    if (vlSelfRef.__VdlySet__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[vlSelfRef.__VdlyDim0__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33] 
            = vlSelfRef.__VdlyVal__top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs__v33;
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat 
        = ((0x01000000U > vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o)
            ? (0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o)
            : (0x003fffffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o 
                              - (IData)(0x01000000U))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__regwren_pipe 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe));
    if (vlSelfRef.top__DOT__reset) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe = 0U;
    } else {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe;
        if (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o) 
             | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall)))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe 
                = (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                  >> 7U));
        }
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o 
        = ((0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe
            : ((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe
                : ((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe))
                    ? ((IData)(4U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe)
                    : 0U)));
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable 
        = ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe) 
             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
            & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)))
            ? 1U : ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe) 
                      == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
                     & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)))
                     ? 2U : 0U));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__store_data 
        = ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe) 
             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
            & ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
               & (0x23U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe))))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rs2_val_topipe 
        = ((2U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe);
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable 
        = ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe) 
             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)) 
            & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)))
            ? 1U : ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe) 
                      == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)) 
                     & ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)) 
                        & (0x23U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))))
                     ? 2U : 0U));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe 
        = vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe;
    top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i 
        = (((2U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable)) 
            & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : (((2U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable)) 
                & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o
                : ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe)
                    ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe
                    : ((0x00000040U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                        ? ((0x00000020U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                            ? ((0x00000010U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                ? 0U : ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                         ? ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                                  ? 
                                                 ((((0x00000ffeU 
                                                     & ((- (IData)(
                                                                   (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                                    >> 0x0000001fU))) 
                                                        << 1U)) 
                                                    | (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                       >> 0x0000001fU)) 
                                                   << 0x00000014U) 
                                                  | ((((0x000001feU 
                                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                           >> 0x0000000bU)) 
                                                       | (1U 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                             >> 0x00000014U))) 
                                                      << 0x0000000bU) 
                                                     | (0x000007feU 
                                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                           >> 0x00000014U))))
                                                  : 0U)
                                                 : 0U)
                                             : 0U) : 
                                        ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                          ? vlSelfRef.__VdfgRegularize_hebeb780c_0_0
                                          : ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                               >> 0x0000001fU))) 
                                                   << 0x0000000dU) 
                                                  | ((((2U 
                                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                           >> 0x0000001eU)) 
                                                       | (1U 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                             >> 7U))) 
                                                      << 0x0000000bU) 
                                                     | ((0x000007e0U 
                                                         & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                            >> 0x00000014U)) 
                                                        | (0x0000001eU 
                                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                              >> 7U)))))
                                                  : 0U)
                                              : 0U))))
                            : 0U) : ((0x00000020U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                      ? ((0x00000010U 
                                          & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                          ? ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                               ? vlSelfRef.__VdfgRegularize_hebeb780c_0_1
                                               : 0U))
                                          : ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                                 >> 0x0000001fU))) 
                                                     << 0x0000000cU) 
                                                    | ((0x00000fe0U 
                                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                           >> 0x00000014U)) 
                                                       | (0x0000001fU 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                             >> 7U))))
                                                    : 0U)
                                                   : 0U))))
                                      : ((0x00000010U 
                                          & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                          ? ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                               ? vlSelfRef.__VdfgRegularize_hebeb780c_0_1
                                               : vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                                          : ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                               ? 0U
                                               : vlSelfRef.__VdfgRegularize_hebeb780c_0_0))))))));
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs2_branch_o 
        = ((2U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__rs2_val_topipe);
    top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs1_branch_o 
        = ((1U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : ((1U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
        = vlSelfRef.__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe;
    top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
        = (((1U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable)) 
            & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : (((1U == (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable)) 
                & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__writeback_data_o
                : ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe)
                    ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe
                    : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe)));
    top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o 
        = (top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs1_branch_o 
           == top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs2_branch_o);
    top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o 
        = VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs1_branch_o, top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs2_branch_o);
    top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o 
        = (top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs1_branch_o 
           < top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs2_branch_o);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memwren = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0x0fU;
    if ((0x00000040U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
        if ((0x00000020U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
            if ((1U & (~ (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                            if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                                vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                                vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel = 1U;
                                vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 0U;
                                vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                                vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 2U;
                                vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel = 1U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 1U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 2U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0x0aU;
                    }
                }
            }
        }
    } else if ((0x00000020U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
        if ((0x00000010U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
            if ((1U & (~ (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                          >> 3U)))) {
                if ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 0U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 0U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 9U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 1U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 1U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memwren = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel 
                            = (((((((((0U == ((0x000003f8U 
                                               & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                    >> 0x0000000cU)))) 
                                      | (0x0100U == 
                                         ((0x000003f8U 
                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                              >> 0x00000016U)) 
                                          | (7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                   >> 0x0000000cU))))) 
                                     | (7U == ((0x000003f8U 
                                                & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                   >> 0x00000016U)) 
                                               | (7U 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x0000000cU))))) 
                                    | (6U == ((0x000003f8U 
                                               & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                    >> 0x0000000cU))))) 
                                   | (4U == ((0x000003f8U 
                                              & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                 >> 0x00000016U)) 
                                             | (7U 
                                                & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                   >> 0x0000000cU))))) 
                                  | (2U == ((0x000003f8U 
                                             & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                >> 0x00000016U)) 
                                            | (7U & 
                                               (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                >> 0x0000000cU))))) 
                                 | (1U == ((0x000003f8U 
                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                               >> 0x00000016U)) 
                                           | (7U & 
                                              (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                               >> 0x0000000cU))))) 
                                | (5U == ((0x000003f8U 
                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                              >> 0x00000016U)) 
                                          | (7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                   >> 0x0000000cU)))))
                                ? ((0U == ((0x000003f8U 
                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                               >> 0x00000016U)) 
                                           | (7U & 
                                              (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                               >> 0x0000000cU))))
                                    ? 0U : ((0x0100U 
                                             == ((0x000003f8U 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x00000016U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                       >> 0x0000000cU))))
                                             ? 1U : 
                                            ((7U == 
                                              ((0x000003f8U 
                                                & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                   >> 0x00000016U)) 
                                               | (7U 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x0000000cU))))
                                              ? 2U : 
                                             ((6U == 
                                               ((0x000003f8U 
                                                 & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                    >> 0x00000016U)) 
                                                | (7U 
                                                   & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                      >> 0x0000000cU))))
                                               ? 3U
                                               : ((4U 
                                                   == 
                                                   ((0x000003f8U 
                                                     & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                        >> 0x00000016U)) 
                                                    | (7U 
                                                       & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                          >> 0x0000000cU))))
                                                   ? 4U
                                                   : 
                                                  ((2U 
                                                    == 
                                                    ((0x000003f8U 
                                                      & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                         >> 0x00000016U)) 
                                                     | (7U 
                                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                           >> 0x0000000cU))))
                                                    ? 5U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     ((0x000003f8U 
                                                       & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                          >> 0x00000016U)) 
                                                      | (7U 
                                                         & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                            >> 0x0000000cU))))
                                                     ? 6U
                                                     : 7U)))))))
                                : ((0x0105U == ((0x000003f8U 
                                                 & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                    >> 0x00000016U)) 
                                                | (7U 
                                                   & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                      >> 0x0000000cU))))
                                    ? 8U : 0U));
                        if ((1U & (~ VL_ONEHOT_I(((
                                                   ((((0x0105U 
                                                       == 
                                                       ((0x000003f8U 
                                                         & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                            >> 0x00000016U)) 
                                                        | (7U 
                                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                              >> 0x0000000cU)))) 
                                                      << 4U) 
                                                     | (((5U 
                                                          == 
                                                          ((0x000003f8U 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x00000016U)) 
                                                           | (7U 
                                                              & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                 >> 0x0000000cU)))) 
                                                         << 3U) 
                                                        | ((1U 
                                                            == 
                                                            ((0x000003f8U 
                                                              & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                 >> 0x00000016U)) 
                                                             | (7U 
                                                                & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                   >> 0x0000000cU)))) 
                                                           << 2U))) 
                                                    | (((2U 
                                                         == 
                                                         ((0x000003f8U 
                                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                              >> 0x00000016U)) 
                                                          | (7U 
                                                             & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                >> 0x0000000cU)))) 
                                                        << 1U) 
                                                       | (4U 
                                                          == 
                                                          ((0x000003f8U 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x00000016U)) 
                                                           | (7U 
                                                              & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                 >> 0x0000000cU)))))) 
                                                   << 4U) 
                                                  | ((((6U 
                                                        == 
                                                        ((0x000003f8U 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                             >> 0x00000016U)) 
                                                         | (7U 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x0000000cU)))) 
                                                       << 3U) 
                                                      | ((7U 
                                                          == 
                                                          ((0x000003f8U 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x00000016U)) 
                                                           | (7U 
                                                              & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                 >> 0x0000000cU)))) 
                                                         << 2U)) 
                                                     | (((0x0100U 
                                                          == 
                                                          ((0x000003f8U 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x00000016U)) 
                                                           | (7U 
                                                              & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                 >> 0x0000000cU)))) 
                                                         << 1U) 
                                                        | (0U 
                                                           == 
                                                           ((0x000003f8U 
                                                             & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                >> 0x00000016U)) 
                                                            | (7U 
                                                               & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                  >> 0x0000000cU))))))))))) {
                            if ((0U != ((((((0x0105U 
                                             == ((0x000003f8U 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x00000016U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                       >> 0x0000000cU)))) 
                                            << 4U) 
                                           | (((5U 
                                                == 
                                                ((0x000003f8U 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x00000016U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                       >> 0x0000000cU)))) 
                                               << 3U) 
                                              | ((1U 
                                                  == 
                                                  ((0x000003f8U 
                                                    & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                       >> 0x00000016U)) 
                                                   | (7U 
                                                      & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                         >> 0x0000000cU)))) 
                                                 << 2U))) 
                                          | (((2U == 
                                               ((0x000003f8U 
                                                 & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                    >> 0x00000016U)) 
                                                | (7U 
                                                   & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                      >> 0x0000000cU)))) 
                                              << 1U) 
                                             | (4U 
                                                == 
                                                ((0x000003f8U 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x00000016U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                       >> 0x0000000cU)))))) 
                                         << 4U) | (
                                                   (((6U 
                                                      == 
                                                      ((0x000003f8U 
                                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                           >> 0x00000016U)) 
                                                       | (7U 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                             >> 0x0000000cU)))) 
                                                     << 3U) 
                                                    | ((7U 
                                                        == 
                                                        ((0x000003f8U 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                             >> 0x00000016U)) 
                                                         | (7U 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x0000000cU)))) 
                                                       << 2U)) 
                                                   | (((0x0100U 
                                                        == 
                                                        ((0x000003f8U 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                             >> 0x00000016U)) 
                                                         | (7U 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x0000000cU)))) 
                                                       << 1U) 
                                                      | (0U 
                                                         == 
                                                         ((0x000003f8U 
                                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                              >> 0x00000016U)) 
                                                          | (7U 
                                                             & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                >> 0x0000000cU))))))))) {
                                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                                    VL_WRITEF_NX("[%0t] %%Error: control.sv:76: Assertion failed in %Ntop.dut.core.u_control: unique case, but multiple matches found for '10'h%x'\n",0,
                                                 64,
                                                 VL_TIME_UNITED_Q(1),
                                                 -12,
                                                 vlSymsp->name(),
                                                 10,
                                                 ((0x000003f8U 
                                                   & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                      >> 0x00000016U)) 
                                                  | (7U 
                                                     & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                        >> 0x0000000cU))));
                                    VL_STOP_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/design/code/control.sv", 76, "");
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                          >> 2U)))) {
                if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 1U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memwren = 1U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                    }
                }
            }
        }
    } else if ((0x00000010U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
        if ((1U & (~ (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                      >> 3U)))) {
            if ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                    }
                }
            } else if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 0U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel = 0U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel 
                        = ((0x00004000U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                            ? ((0x00002000U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                ? ((0x00001000U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                    ? 2U : 3U) : ((0x00001000U 
                                                   & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x00000019U))
                                                    ? 7U
                                                    : 8U)
                                                   : 4U))
                            : ((0x00002000U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                ? ((0x00001000U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                    ? 0U : 5U) : ((0x00001000U 
                                                   & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                                   ? 6U
                                                   : 0U)));
                }
            }
        }
    } else if ((1U & (~ (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                         >> 3U)))) {
        if ((1U & (~ (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                      >> 2U)))) {
            if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                }
            }
        }
    }
    __VdfgRegularize_hebeb780c_0_7 = (top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                                      + top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken 
        = ((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)) 
           & ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
               ? ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                   ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                       ? ((~ (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o)) 
                          | (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o))
                       : ((~ (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o)) 
                          & (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o)))
                   : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                       ? ((~ (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o)) 
                          | (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o))
                       : ((~ (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o)) 
                          & (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o))))
               : ((~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe) 
                      >> 1U)) & ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                                  ? (~ (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o))
                                  : (IData)(top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o)))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res 
        = ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
            ? ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                ? 0U : ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                         ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                             ? 0U : __VdfgRegularize_hebeb780c_0_7)
                         : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                             ? top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i
                             : VL_SHIFTRS_III(32,32,5, top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i, 
                                              (0x0000001fU 
                                               & top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)))))
            : ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                ? ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           >> (0x0000001fU & top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i))
                        : (top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           << (0x0000001fU & top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)))
                    : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i, top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)
                            ? 1U : 0U) : (top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                                          ^ top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)))
                : ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           | top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)
                        : (top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           & top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i))
                    : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           - top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)
                        : __VdfgRegularize_hebeb780c_0_7))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken) 
           | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__stall 
        = (((3U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)) 
            & ((((0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                 >> 0x0000000fU)) == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe)) 
                | (((0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                    >> 0x00000014U)) 
                    == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe)) 
                   & (0x23U != (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)))) 
               & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe)))) 
           | (((((0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                 >> 0x0000000fU)) == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
                | ((0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                   >> 0x00000014U)) 
                   == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe))) 
               & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe))) 
              & ((~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o)) 
                 & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__regwren_pipe))));
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__clkg__DOT__counter = 0;
    // Body
    __Vdly__top__DOT__clkg__DOT__counter = ((IData)(1U) 
                                            + vlSelfRef.top__DOT__clkg__DOT__counter);
    vlSelfRef.top__DOT__reset = VL_GTS_III(32, 5U, vlSelfRef.top__DOT__clkg__DOT__counter);
    if (VL_UNLIKELY(((0x0000c350U == vlSelfRef.top__DOT__clkg__DOT__counter)))) {
        VL_WRITEF_NX("Timeout\n",0);
        VL_FINISH_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/tests/clockgen.sv", 32, "");
    }
    vlSelfRef.top__DOT__clkg__DOT__counter = __Vdly__top__DOT__clkg__DOT__counter;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
}

void Vtop___024root___timing_resume(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_resume\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 2> &out, const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtop___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 2> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/tests/test_pd.sv", 4, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/tests/test_pd.sv", 4, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
