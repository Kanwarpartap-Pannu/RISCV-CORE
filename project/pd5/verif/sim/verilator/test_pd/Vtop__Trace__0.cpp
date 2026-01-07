// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe),32);
        bufp->chgCData(oldp+1,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__opcode_pipe),7);
        bufp->chgCData(oldp+2,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_pipe),5);
        bufp->chgCData(oldp+3,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_pipe),5);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1_data_pipe),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2_data_pipe),32);
        bufp->chgCData(oldp+6,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct7_pipe),7);
        bufp->chgCData(oldp+7,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__funct3_pipe),3);
        bufp->chgCData(oldp+8,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__shamt_pipe),5);
        bufp->chgBit(oldp+9,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pcsel_pipe));
        bufp->chgBit(oldp+10,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__immsel_pipe));
        bufp->chgBit(oldp+11,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs1sel_pipe));
        bufp->chgBit(oldp+12,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rs2sel_pipe));
        bufp->chgBit(oldp+13,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memren_pipe));
        bufp->chgBit(oldp+14,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__memwren_pipe));
        bufp->chgCData(oldp+15,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__wbsel_pipe),2);
        bufp->chgCData(oldp+16,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__alusel_pipe),4);
        bufp->chgCData(oldp+17,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__funct3_pipe),3);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_val_pipe),32);
        bufp->chgCData(oldp+19,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe),5);
        bufp->chgBit(oldp+20,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__brtaken_pipe));
        bufp->chgCData(oldp+21,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__opcode_pipe),7);
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memren_pipe));
        bufp->chgBit(oldp+23,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__memwren_pipe));
        bufp->chgCData(oldp+24,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__wbsel_pipe),2);
        bufp->chgCData(oldp+25,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alusel_pipe),4);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__load_data_pipe),32);
        bufp->chgCData(oldp+28,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe),7);
        bufp->chgBit(oldp+29,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__regwren_pipe));
        bufp->chgCData(oldp+30,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__wbsel_pipe),2);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_igen__DOT__imm_o),32);
        bufp->chgIData(oldp+32,((((- (IData)((vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                  >> 0x00000014U))),32);
        bufp->chgIData(oldp+33,((((- (IData)((vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 ((0x00000fe0U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                  >> 0x00000014U)) 
                                  | (0x0000001fU & 
                                     (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                      >> 7U))))),32);
        bufp->chgIData(oldp+34,((((- (IData)((vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                              >> 0x0000001fU))) 
                                  << 0x0000000dU) | 
                                 ((((2U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                           >> 0x0000001eU)) 
                                    | (1U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                             >> 7U))) 
                                   << 0x0000000bU) 
                                  | ((0x000007e0U & 
                                      (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                       >> 0x00000014U)) 
                                     | (0x0000001eU 
                                        & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                           >> 7U)))))),32);
        bufp->chgIData(oldp+35,((0xfffff000U & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe)),32);
        bufp->chgIData(oldp+36,(((((0x00000ffeU & (
                                                   (- (IData)(
                                                              (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                                               >> 0x0000001fU))) 
                                                   << 1U)) 
                                   | (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                      >> 0x0000001fU)) 
                                  << 0x00000014U) | 
                                 ((((0x000001feU & 
                                     (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                      >> 0x0000000bU)) 
                                    | (1U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                             >> 0x00000014U))) 
                                   << 0x0000000bU) 
                                  | (0x000007feU & 
                                     (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__ins_pipe 
                                      >> 0x00000014U))))),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__alu_res_pipe),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__dut__DOT__core__DOT__f_insn),32);
        bufp->chgIData(oldp+41,((vlSelfRef.top__DOT__dut__DOT__core__DOT__f_pc 
                                 - (IData)(0x01000000U))),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+42,(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__stall));
        bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pcsel_o));
        bufp->chgCData(oldp+44,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__WX_enable),2);
        bufp->chgCData(oldp+45,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__MX_enable),2);
        bufp->chgBit(oldp+46,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_pcsel));
        bufp->chgBit(oldp+47,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_immsel));
        bufp->chgBit(oldp+48,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_regwren));
        bufp->chgBit(oldp+49,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs1sel));
        bufp->chgBit(oldp+50,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_rs2sel));
        bufp->chgBit(oldp+51,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memren));
        bufp->chgBit(oldp+52,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_memwren));
        bufp->chgCData(oldp+53,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_wbsel),2);
        bufp->chgCData(oldp+54,(vlSelfRef.top__DOT__dut__DOT__core__DOT__ctrl_alusel),4);
        bufp->chgIData(oldp+55,(((0U == (0x0000001fU 
                                         & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                            >> 0x0000000fU)))
                                  ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
                                 [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                  >> 0x0000000fU))])),32);
        bufp->chgIData(oldp+56,(((0U == (0x0000001fU 
                                         & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                            >> 0x00000014U)))
                                  ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs
                                 [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                  >> 0x00000014U))])),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__pc_pipe),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe),32);
        bufp->chgCData(oldp+59,((0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe)),7);
        bufp->chgCData(oldp+60,((0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                >> 7U))),5);
        bufp->chgCData(oldp+61,((0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+62,((0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                                >> 0x00000014U))),5);
        bufp->chgCData(oldp+63,((vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                 >> 0x00000019U)),7);
        bufp->chgCData(oldp+64,((7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__u_if_id_pipe__DOT__ins_pipe 
                                       >> 0x0000000cU))),3);
        bufp->chgIData(oldp+65,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__pc_pipe),32);
        bufp->chgCData(oldp+66,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__rd_pipe),5);
        bufp->chgBit(oldp+67,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_id_ix_pipe__DOT__regwren_pipe));
        bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs1_i),32);
        bufp->chgIData(oldp+69,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_alu__DOT__rs2_i),32);
        bufp->chgIData(oldp+70,(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__alu_res),32);
        bufp->chgBit(oldp+71,(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__br_taken));
        bufp->chgBit(oldp+72,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__breq_o));
        bufp->chgBit(oldp+73,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brlt_o));
        bufp->chgBit(oldp+74,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control__DOT__brltu_o));
        bufp->chgIData(oldp+75,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs1_branch_o),32);
        bufp->chgIData(oldp+76,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__rs2_branch_o),32);
        bufp->chgCData(oldp+77,(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded),2);
        bufp->chgIData(oldp+78,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_branch_control_mux__DOT__writeback_data_i),32);
        bufp->chgIData(oldp+79,(vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_res_mem_o),32);
        bufp->chgIData(oldp+80,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__pc_pipe),32);
        bufp->chgCData(oldp+81,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rd_pipe),5);
        bufp->chgBit(oldp+82,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__regwren_pipe));
        bufp->chgIData(oldp+83,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe),32);
        bufp->chgCData(oldp+84,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe),5);
        bufp->chgIData(oldp+85,(vlSelfRef.top__DOT__dut__DOT__core__DOT__rs2_val_topipe),32);
        bufp->chgIData(oldp+86,(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__data_dat),32);
        bufp->chgIData(oldp+87,(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat),32);
        bufp->chgIData(oldp+88,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[0]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[1]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[2]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[3]),32);
        bufp->chgIData(oldp+92,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[4]),32);
        bufp->chgIData(oldp+93,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[5]),32);
        bufp->chgIData(oldp+94,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[6]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[7]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[8]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[9]),32);
        bufp->chgIData(oldp+98,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[10]),32);
        bufp->chgIData(oldp+99,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[11]),32);
        bufp->chgIData(oldp+100,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[12]),32);
        bufp->chgIData(oldp+101,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[13]),32);
        bufp->chgIData(oldp+102,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[14]),32);
        bufp->chgIData(oldp+103,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[15]),32);
        bufp->chgIData(oldp+104,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[16]),32);
        bufp->chgIData(oldp+105,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[17]),32);
        bufp->chgIData(oldp+106,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[18]),32);
        bufp->chgIData(oldp+107,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[19]),32);
        bufp->chgIData(oldp+108,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[20]),32);
        bufp->chgIData(oldp+109,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[21]),32);
        bufp->chgIData(oldp+110,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[22]),32);
        bufp->chgIData(oldp+111,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[23]),32);
        bufp->chgIData(oldp+112,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[24]),32);
        bufp->chgIData(oldp+113,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[25]),32);
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[26]),32);
        bufp->chgIData(oldp+115,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[27]),32);
        bufp->chgIData(oldp+116,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[28]),32);
        bufp->chgIData(oldp+117,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[29]),32);
        bufp->chgIData(oldp+118,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[30]),32);
        bufp->chgIData(oldp+119,(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_register_file__DOT__regs[31]),32);
    }
    bufp->chgBit(oldp+120,(vlSelfRef.top__DOT__clock));
    bufp->chgBit(oldp+121,(vlSelfRef.top__DOT__reset));
    bufp->chgIData(oldp+122,(vlSelfRef.top__DOT__clkg__DOT__counter),32);
    bufp->chgBit(oldp+123,((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_ix_mem_pipe__DOT__rs2_pipe) 
                             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
                            & ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__rd_pipe)) 
                               & (0x23U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__opcode_pipe))))));
    bufp->chgIData(oldp+124,(((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__br_taken)
                               ? vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__alu_res_pipe
                               : ((IData)(4U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__u_mem_wb_pipe__DOT__pc_pipe))),32);
    bufp->chgIData(oldp+125,(((2U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
                               ? (((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                    [(0x003fffffU & 
                                      ((IData)(3U) 
                                       + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                    << 0x00000018U) 
                                   | (vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                      [(0x003fffffU 
                                        & ((IData)(2U) 
                                           + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                      << 0x00000010U)) 
                                  | ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                      [(0x003fffffU 
                                        & ((IData)(1U) 
                                           + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                      << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                     [(0x003fffffU 
                                       & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)]))
                               : ((1U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__size_encoded))
                                   ? ((vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                       [(0x003fffffU 
                                         & ((IData)(1U) 
                                            + vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat))] 
                                       << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                      [(0x003fffffU 
                                        & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)])
                                   : vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__main_memory
                                  [(0x003fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__address_dat)]))),32);
    bufp->chgBit(oldp+126,(vlSelfRef.top__DOT__dut__DOT__core__DOT__is_program));
    bufp->chgIData(oldp+127,(vlSelfRef.top__DOT__dut__DOT__core__DOT__fetch1__DOT__pc),32);
    bufp->chgIData(oldp+128,(vlSelfRef.top__DOT__dut__DOT__core__DOT__memory1__DOT__i),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
