// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0 
        = vlSelfRef.top__DOT__clock;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__reset__0 
        = vlSelfRef.top__DOT__reset;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__clkg__DOT__counter = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__is_program = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc = 0x01000000U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o = 0x01000000U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd 
        = VL_FOPEN_NN("SwapShift.trace"s, "w"s);
    ;
    vlSelfRef.top__DOT__genblk2__DOT_____05Fdump_fd 
        = VL_FOPEN_NN("SwapShift.dump"s, "w"s);
    ;
    vlSelfRef.top__DOT__reset = 1U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00400000U, vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[(0x003fffffU 
                                                                            & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)] = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i 
            = ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i);
    }
    VL_READMEM_N(true, 32, 72, 0, "/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/rv32-bmarks/full-bmarks/SwapShift.x"s
                 ,  &(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory)
                 , 0, ~0ULL);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000048U, vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[(0x003fffffU 
                                                                            & VL_MULS_III(32, (IData)(4U), vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i))] 
            = ((0x47U >= (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i))
                ? (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory
                   [(0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)])
                : 0U);
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[(0x003fffffU 
                                                                            & ((IData)(1U) 
                                                                               + 
                                                                               VL_MULS_III(32, (IData)(4U), vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)))] 
            = (0x000000ffU & (((0x47U >= (0x0000007fU 
                                          & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i))
                                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory
                               [(0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)]
                                : 0U) >> 8U));
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[(0x003fffffU 
                                                                            & ((IData)(2U) 
                                                                               + 
                                                                               VL_MULS_III(32, (IData)(4U), vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)))] 
            = (0x000000ffU & (((0x47U >= (0x0000007fU 
                                          & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i))
                                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory
                               [(0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)]
                                : 0U) >> 0x10U));
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[(0x003fffffU 
                                                                            & ((IData)(3U) 
                                                                               + 
                                                                               VL_MULS_III(32, (IData)(4U), vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)))] 
            = (((0x47U >= (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i))
                 ? vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory
                [(0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i)]
                 : 0U) >> 0x18U);
        vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i 
            = ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i);
    }
    VL_WRITEF_NX("IMEMORY: Loaded 72 32-bit words from /Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/rv32-bmarks/full-bmarks/SwapShift.x\n",0);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/verif/tests/test_pd.sv", 4, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*1:0*/, 8> Vtop__ConstPool__TABLE_hd6134ef5_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_4;
    __VdfgRegularize_hebeb780c_0_4 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_5;
    __VdfgRegularize_hebeb780c_0_5 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_6;
    __VdfgRegularize_hebeb780c_0_6 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_7;
    __VdfgRegularize_hebeb780c_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_12;
    __VdfgRegularize_hebeb780c_0_12 = 0;
    // Body
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: writeback.sv:36: Assertion failed in %Ntop.dut.core.u_writeback: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),2,
                             (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe));
                VL_STOP_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/design/code/writeback.sv", 36, "");
            }
        }
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__rs1data_o 
        = ((0U == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                  >> 0x0000000fU)))
            ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
           [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                            >> 0x0000000fU))]);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__rs2data_o 
        = ((0U == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                  >> 0x00000014U)))
            ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
           [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                            >> 0x00000014U))]);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc = vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc;
    if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
        if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
            __VdfgRegularize_hebeb780c_0_4 = (((- (IData)(
                                                          (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                           >> 0x0000001fU))) 
                                               << 0x0000000cU) 
                                              | (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                 >> 0x00000014U));
            __VdfgRegularize_hebeb780c_0_5 = (0xfffff000U 
                                              & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe);
        } else {
            __VdfgRegularize_hebeb780c_0_4 = 0U;
            __VdfgRegularize_hebeb780c_0_5 = 0U;
        }
    } else {
        __VdfgRegularize_hebeb780c_0_4 = 0U;
        __VdfgRegularize_hebeb780c_0_5 = 0U;
    }
    __Vtableidx1 = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded 
        = Vtop__ConstPool__TABLE_hd6134ef5_0[__Vtableidx1];
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memren = 0U;
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
                                vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
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
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 1U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 2U;
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
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
                            vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
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
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memren = 0U;
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
                                    VL_WRITEF_NX("[%0t] %%Error: control.sv:102: Assertion failed in %Ntop.dut.core.u_control: unique case, but multiple matches found for '10'h%x'\n",0,
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
                                    VL_STOP_MT("/Users/kanwarpannu/Desktop/RISC-V_Core/RISCV-CORE/project/pd5/design/code/control.sv", 102, "");
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
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
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
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 0U;
                        vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                    }
                }
            } else if ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                if ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)) {
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
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
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = 0U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memren = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel = 1U;
                    vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel = 0U;
                }
            }
        }
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_decode__DOT__imm_o 
        = ((0x00000040U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
            ? ((0x00000020U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                ? ((0x00000010U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                    ? 0U : ((8U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                             ? ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                 ? ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                     ? ((1U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                         ? ((((0x00000ffeU 
                                               & ((- (IData)(
                                                             (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                              >> 0x0000001fU))) 
                                                  << 1U)) 
                                              | (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                 >> 0x0000001fU)) 
                                             << 0x00000014U) 
                                            | ((((0x000001feU 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x0000000bU)) 
                                                 | (1U 
                                                    & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                       >> 0x00000014U))) 
                                                << 0x0000000bU) 
                                               | (0x000007feU 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                     >> 0x00000014U))))
                                         : 0U) : 0U)
                                 : 0U) : ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                           ? __VdfgRegularize_hebeb780c_0_4
                                           : ((2U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                               ? ((1U 
                                                   & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                                >> 0x0000001fU))) 
                                                    << 0x0000000dU) 
                                                   | ((((2U 
                                                         & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                            >> 0x0000001eU)) 
                                                        | (1U 
                                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                              >> 7U))) 
                                                       << 0x0000000bU) 
                                                      | ((0x000007e0U 
                                                          & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                             >> 0x00000014U)) 
                                                         | (0x0000001eU 
                                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 7U)))))
                                                   : 0U)
                                               : 0U))))
                : 0U) : ((0x00000020U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                          ? ((0x00000010U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                              ? ((8U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                  ? 0U : ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                           ? __VdfgRegularize_hebeb780c_0_5
                                           : 0U)) : 
                             ((8U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                               ? 0U : ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                        ? 0U : ((2U 
                                                 & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                                 ? 
                                                ((1U 
                                                  & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                               >> 0x0000001fU))) 
                                                   << 0x0000000cU) 
                                                  | ((0x00000fe0U 
                                                      & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                         >> 0x00000014U)) 
                                                     | (0x0000001fU 
                                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                           >> 7U))))
                                                  : 0U)
                                                 : 0U))))
                          : ((0x00000010U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                              ? ((8U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                  ? 0U : ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                           ? __VdfgRegularize_hebeb780c_0_5
                                           : __VdfgRegularize_hebeb780c_0_4))
                              : ((8U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                  ? 0U : ((4U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)
                                           ? 0U : __VdfgRegularize_hebeb780c_0_4)))));
    if ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))) {
            __VdfgRegularize_hebeb780c_0_6 = (((- (IData)(
                                                          (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                           >> 0x0000001fU))) 
                                               << 0x0000000cU) 
                                              | (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                 >> 0x00000014U));
            __VdfgRegularize_hebeb780c_0_7 = (0xfffff000U 
                                              & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe);
        } else {
            __VdfgRegularize_hebeb780c_0_6 = 0U;
            __VdfgRegularize_hebeb780c_0_7 = 0U;
        }
    } else {
        __VdfgRegularize_hebeb780c_0_6 = 0U;
        __VdfgRegularize_hebeb780c_0_7 = 0U;
    }
    vlSelfRef.__VdfgRegularize_hebeb780c_0_8 = ((0x63U 
                                                 != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)) 
                                                & (0x6fU 
                                                   != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__MX_enable 
        = ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe) 
             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)) 
            & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)))
            ? 1U : ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe) 
                      == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)) 
                     & ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe)) 
                        & (0x23U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))))
                     ? 2U : 0U));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__WX_enable 
        = ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe) 
             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
            & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)))
            ? 1U : ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe) 
                      == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
                     & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)))
                     ? 2U : 0U));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i 
        = ((0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe
            : ((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe
                : ((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe))
                    ? ((IData)(4U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe)
                    : 0U)));
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
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_igen__DOT__imm_o 
        = ((0x00000040U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
            ? ((0x00000020U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                ? ((0x00000010U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                    ? 0U : ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                             ? ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                 ? ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                     ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                         ? ((((0x00000ffeU 
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
                                         : 0U) : 0U)
                                 : 0U) : ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                           ? __VdfgRegularize_hebeb780c_0_6
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
                          ? ((0x00000010U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                              ? ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                  ? 0U : ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                           ? __VdfgRegularize_hebeb780c_0_7
                                           : 0U)) : 
                             ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                               ? 0U : ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                        ? 0U : ((2U 
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
                          : ((0x00000010U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                              ? ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                  ? 0U : ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                           ? __VdfgRegularize_hebeb780c_0_7
                                           : __VdfgRegularize_hebeb780c_0_6))
                              : ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                  ? 0U : ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))
                                           ? 0U : __VdfgRegularize_hebeb780c_0_6)))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_16 = ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8) 
                                                 & ((0x67U 
                                                     != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)) 
                                                    & (3U 
                                                       != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat 
        = ((0x01000000U > vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o)
            ? (0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o)
            : (0x003fffffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o 
                              - (IData)(0x01000000U))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__data_dat 
        = ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe) 
             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
            & ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
               & (0x23U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe))))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
        = (((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__MX_enable)) 
            & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : (((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__WX_enable)) 
                & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i
                : ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe)
                    ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe
                    : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs1_i 
        = ((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__MX_enable))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : ((1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__WX_enable))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rs2_val_topipe 
        = ((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__WX_enable))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i 
        = (((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__MX_enable)) 
            & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16) 
               & (0x13U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe))))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : (((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__WX_enable)) 
                & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16) 
                   & ((0x23U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)) 
                      & (0x13U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)))))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i
                : ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe)
                    ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe
                    : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_igen__DOT__imm_o)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__memory_data_i 
        = ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
            ? (((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                 [(0x003fffffU & ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                 << 0x00000018U) | (vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                    [(0x003fffffU & 
                                      ((IData)(2U) 
                                       + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                    << 0x00000010U)) 
               | ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                   [(0x003fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                   << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                  [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)]))
            : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
                ? ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                    [(0x003fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                    << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                   [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)])
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
               [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)]));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs2_i 
        = ((2U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__MX_enable))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__rs2_val_topipe);
    __VdfgRegularize_hebeb780c_0_12 = (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                                       + vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o 
        = (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs1_i 
           == vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs2_i);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o 
        = VL_LTS_III(32, vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs1_i, vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs2_i);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o 
        = (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs1_i 
           < vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs2_i);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__alu_res 
        = ((8U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
            ? ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                ? 0U : ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                         ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                             ? 0U : __VdfgRegularize_hebeb780c_0_12)
                         : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                             ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i
                             : VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i, 
                                              (0x0000001fU 
                                               & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)))))
            : ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                ? ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           >> (0x0000001fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i))
                        : (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           << (0x0000001fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)))
                    : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (VL_LTS_III(32, vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i, vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)
                            ? 1U : 0U) : (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                                          ^ vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)))
                : ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           | vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)
                        : (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i))
                    : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe))
                        ? (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i 
                           - vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i)
                        : __VdfgRegularize_hebeb780c_0_12))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__br_taken 
        = ((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe)) 
           & ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
               ? ((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                   ? ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                       ? ((~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o)) 
                          | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o))
                       : ((~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o)) 
                          & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o)))
                   : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                       ? ((~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o)) 
                          | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o))
                       : ((~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o)) 
                          & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o))))
               : ((~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe) 
                      >> 1U)) & ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe))
                                  ? (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o))
                                  : (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o)))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__br_taken) 
           | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__stall 
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

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(negedge top.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge top.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge top.reset)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'act' trigger - DPI export trigger\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->top__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5844775645289313205ull);
    vlSelf->top__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4457194187413456923ull);
    vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14329879011005447780ull);
    vlSelf->top__DOT__genblk2__DOT_____05Fdump_fd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2131419011722022482ull);
    VL_SCOPED_RAND_RESET_W(768, vlSelf->top__DOT__genblk2__DOT__pattern_dump, __VscopeHash, 10955522923576967124ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->top__DOT__genblk2__DOT__pattern_dump_proc__DOT__stage, __VscopeHash, 15181666039126907824ull);
    vlSelf->top__DOT__clkg__DOT__counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7673510899991897937ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__WX_enable = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5686853691186960074ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__MX_enable = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2376413430892509051ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_pcsel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10686638355514389766ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_immsel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10681644234800914881ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_regwren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15262114789201477911ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_rs1sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10240656596297212566ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_rs2sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 471957362543877739ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_memren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1567572989115520987ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_memwren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3500837860527987176ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_wbsel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1623172971839010771ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__ctrl_alusel = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13751281761010357945ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__datawb_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4319913143758400611ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13360777589716865042ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6861737920208188584ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__memory_data_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13967569771835543805ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_res_mem_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1548765175618114972ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__rs1_mem_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3075351747560446652ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__f_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12048714892135156921ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__f_insn = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7374491624312029756ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__rs2_val_topipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7503168904509333645ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_program = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3526790071870633143ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__fetch1__DOT__br_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16730294685179973108ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__fetch1__DOT__stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17944291657750469910ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__fetch1__DOT__alu_res = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14992685173505823175ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14244068164273144251ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2701729220794879877ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15784443755006551458ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5830065378097553995ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_decode__DOT__imm_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15907191119245891220ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_register_file__DOT__datawb_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8582211320315560906ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_register_file__DOT__rs1data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16670470279282918997ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_register_file__DOT__rs2data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7272624275598689431ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7109203292283159794ull);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__u_register_file__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12679573184010041090ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8249489788170654373ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 10035451878406092452ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10426059568228703754ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18214147729729202271ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18304222802037467321ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13059956732179627869ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1089557721547378087ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct7_pipe = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 13946975450396780064ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7773490810753547747ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__shamt_pipe = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9461740754378669716ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12395548119836169176ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__immsel_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2257857855349694946ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9003423546804288276ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 868942452124997832ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3625548565581020288ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memren_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13146092892716350773ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3645427788649398914ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2835194894273307580ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6075740319664119452ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_igen__DOT__imm_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4374189577568148239ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs1_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15223551446174877548ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__rs2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8694635776684618537ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7194696944789599777ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2624328808673329300ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5923458818870065263ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15291085382531802272ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2110719926654311276ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13608861023862185731ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__brtaken_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1296920787933534143ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13178300053457154092ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7518623186435595504ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6483786829128482488ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8292822508385389642ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memren_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17802041364787447165ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memwren_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4237861150151595731ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__regwren_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15271523631889411064ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__wbsel_pipe = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5423189332640045679ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alusel_pipe = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16308340067163169819ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1278721823227477555ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__opcode_pipe = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 4522668384722921166ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__memory1__DOT__data_dat = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14355729866617842401ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12353522417987407201ull);
    for (int __Vi0 = 0; __Vi0 < 72; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__memory1__DOT__temp_memory[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1463922315813575142ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4194304; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11844625093970627893ull);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2656009914071697065ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__memory1__DOT__i = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15755179073698010739ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8952380299666420006ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18059513134127870516ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2608750402094267907ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 17925702315076811205ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__regwren_pipe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13681805782848475076ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 399768792375696707ull);
    vlSelf->__Vdpi_export_trigger = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7580800412365679880ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_16 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1099577120989408200ull);
    vlSelf->__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16428810916465138658ull);
    vlSelf->__Vdly__top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14321006111533182203ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14234138457933551086ull);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16527897109859793802ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
