// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_verilator_bench.h for the primary calling header

#include "Vtb_verilator_bench__pch.h"
#include "Vtb_verilator_bench___024root.h"

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_initial__TOP(Vtb_verilator_bench___024root* vlSelf);
VlCoroutine Vtb_verilator_bench___024root___eval_initial__TOP__Vtiming__0(Vtb_verilator_bench___024root* vlSelf);
VlCoroutine Vtb_verilator_bench___024root___eval_initial__TOP__Vtiming__1(Vtb_verilator_bench___024root* vlSelf);

void Vtb_verilator_bench___024root___eval_initial(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_initial\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_verilator_bench___024root___eval_initial__TOP(vlSelf);
    Vtb_verilator_bench___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_verilator_bench___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_verilator_bench___024root___eval_initial__TOP__Vtiming__0(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_verilator_bench__DOT__ii;
    tb_verilator_bench__DOT__ii = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    tb_verilator_bench__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x1000U, tb_verilator_bench__DOT__ii)) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem[(0xfffU 
                                                             & tb_verilator_bench__DOT__ii)] = 0x13U;
        tb_verilator_bench__DOT__ii = ((IData)(1U) 
                                       + tb_verilator_bench__DOT__ii);
    }
    tb_verilator_bench__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x10000U, tb_verilator_bench__DOT__ii)) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem[(0xffffU 
                                                             & tb_verilator_bench__DOT__ii)] = 0U;
        tb_verilator_bench__DOT__ii = ((IData)(1U) 
                                       + tb_verilator_bench__DOT__ii);
    }
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x69726f6dU;
    __Vtemp_1[2U] = 0x7263305fU;
    __Vtemp_1[3U] = 0x73U;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_1)
                 ,  &(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem)
                 , 0, ~0ULL);
    __Vtemp_2[0U] = 0x2e686578U;
    __Vtemp_2[1U] = 0x6472616dU;
    __Vtemp_2[2U] = 0x7263305fU;
    __Vtemp_2[3U] = 0x73U;
    VL_READMEM_N(true, 32, 65536, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_2)
                 ,  &(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem)
                 , 0, ~0ULL);
    vlSelfRef.tb_verilator_bench__DOT__rst_n = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x19a28ULL, 
                                         nullptr, "tb_verilator_bench.v", 
                                         38);
    vlSelfRef.tb_verilator_bench__DOT__rst_n = 1U;
}

void Vtb_verilator_bench___024root___act_sequent__TOP__0(Vtb_verilator_bench___024root* vlSelf);

void Vtb_verilator_bench___024root___eval_act(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_act\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_verilator_bench___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_verilator_bench___024root___act_sequent__TOP__0(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___act_sequent__TOP__0\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_cur;
    tb_verilator_bench__DOT__u_soc__DOT__dram_cur = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_rdata;
    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata = 0;
    CData/*6:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode = 0;
    CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd = 0;
    CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw = 0;
    CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 = 0;
    CData/*6:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr = 0;
    // Body
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op 
        = (0x7fU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & ((IData)(1U) + (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                      >> 2U)))]);
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 
        = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 0xfU));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 
        = (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                 [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                             >> 2U))] >> 0xcU));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward 
        = (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))] >> 0x1fU);
    tb_verilator_bench__DOT__u_soc__DOT__dram_cur = 
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
        [(0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                     >> 2U))];
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd 
        = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 7U));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode 
        = (0x7fU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))]);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
    if ((0U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
            = ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                        << 0x18U) | (0xffffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur))
                    : ((0xff000000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff0000U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                                        << 0x10U)) 
                          | (0xffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur))))
                : ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((0xffff0000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff00U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                                      << 8U)) | (0xffU 
                                                 & tb_verilator_bench__DOT__u_soc__DOT__dram_cur)))
                    : ((0xffffff00U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | (0xffU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata))));
    } else if ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
            if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
                    = ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                        << 0x10U) | (0xffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur));
            }
        } else {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
                = ((0xffff0000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                   | (0xffffU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata));
        }
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
    }
    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata = 0U;
    if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_sel) {
        if ((0U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
            tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                = ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x18U)
                        : (0xffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                    [(0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                                 >> 2U))] 
                                    >> 0x10U))) : (
                                                   (1U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                                                    ? 
                                                   (0xffU 
                                                    & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                                       [
                                                       (0xffffU 
                                                        & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                                           >> 2U))] 
                                                       >> 8U))
                                                    : 
                                                   (0xffU 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                                    [
                                                    (0xffffU 
                                                     & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                                        >> 2U))])));
        } else if ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
            if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
                if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
                    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                        = VL_SHIFTR_III(32,32,32, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x10U);
                }
            } else {
                tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                    = (0xffffU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                       [(0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                    >> 2U))]);
            }
        } else {
            tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                = tb_verilator_bench__DOT__u_soc__DOT__dram_cur;
        }
    }
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link 
        = ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)) 
           | (5U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr 
        = ((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & (0U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken 
        = ((0x63U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b = 0U;
    if (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) 
         & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read))) {
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
            = tb_verilator_bench__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b 
            = vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a = 0U;
    if ((((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem) 
          & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem))) 
         & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read))) {
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
            = tb_verilator_bench__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a 
            = vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call 
        = (((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
            | (0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return 
        = ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & ((~ ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link) 
                  & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                     == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))) 
              & ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)) 
                 | (5U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw 
        = (1U & (~ ((((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                      | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
                     & ((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                        | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)))) 
                    | (((~ (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                             & (1U != (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                       [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                       >> 0x19U))) 
                            | ((0x13U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                               | ((0x37U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                  | (0x17U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)))))) 
                        & (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                            | ((0x13U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                               | ((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                  | ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                     | ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                        | ((0x37U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                           | ((0x17U 
                                               == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                              | (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr)))))))) 
                           & ((0U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)) 
                              & (((0x37U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                  & ((0x17U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                     & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                                        == (0x1fU & 
                                            (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                             [(0xfffU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U)))] 
                                             >> 0xfU))))) 
                                 | (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                     | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op))) 
                                    & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                                       == (0x1fU & 
                                           (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                            [(0xfffU 
                                              & ((IData)(1U) 
                                                 + 
                                                 (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                  >> 2U)))] 
                                            >> 0x14U)))))))) 
                       | (((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                           & (0U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3))) 
                          | (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr) 
                              | (0xfU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
                             | ((0x63U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                | ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                   | ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                      | ((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                         | ((0xfU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                            | ((0x33U 
                                                == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                               & (1U 
                                                  == 
                                                  (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                                   [
                                                   (0xfffU 
                                                    & ((IData)(1U) 
                                                       + 
                                                       (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                        >> 2U)))] 
                                                   >> 0x19U))))))))))))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a 
        = ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))
            ? (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
               + (((- (IData)((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                   << 0x14U) | (((0xff000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                  [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                              >> 2U))]) 
                                 | (0x800U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              >> 9U))) 
                                | (0x7feU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                             [(0xfffU 
                                               & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                  >> 2U))] 
                                             >> 0x14U)))))
            : ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken)
                ? (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                   + (((- (IData)((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                       << 0xcU) | ((0x800U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              << 4U)) 
                                   | ((0x7e0U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                                 [(0xfffU 
                                                   & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                 >> 0x14U)) 
                                      | (0x1eU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                                  [
                                                  (0xfffU 
                                                   & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                  >> 7U))))))
                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras
               [(7U & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr) 
                       - (IData)(1U)))]));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a 
        = ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           | ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken) 
              | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final 
        = ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a)) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw));
}

void Vtb_verilator_bench___024root___nba_sequent__TOP__0(Vtb_verilator_bench___024root* vlSelf);
void Vtb_verilator_bench___024root___nba_comb__TOP__0(Vtb_verilator_bench___024root* vlSelf);

void Vtb_verilator_bench___024root___eval_nba(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_nba\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_verilator_bench___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_verilator_bench___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_verilator_bench___024root___nba_sequent__TOP__0(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___nba_sequent__TOP__0\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__hz_stall;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__hz_stall = 0;
    CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1 = 0;
    CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2 = 0;
    CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1 = 0;
    CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2 = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0 = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1 = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2 = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3 = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_intra_valid;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_intra_valid = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b = 0;
    IData/*31:0*/ __VdfgRegularize_h495687df_0_2;
    __VdfgRegularize_h495687df_0_2 = 0;
    IData/*31:0*/ __VdfgRegularize_h495687df_0_3;
    __VdfgRegularize_h495687df_0_3 = 0;
    IData/*31:0*/ __VdfgRegularize_h495687df_0_4;
    __VdfgRegularize_h495687df_0_4 = 0;
    IData/*31:0*/ __VdfgRegularize_h495687df_0_7;
    __VdfgRegularize_h495687df_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_h495687df_0_8;
    __VdfgRegularize_h495687df_0_8 = 0;
    IData/*31:0*/ __VdfgRegularize_h495687df_0_9;
    __VdfgRegularize_h495687df_0_9 = 0;
    QData/*63:0*/ __Vdly__tb_verilator_bench__DOT__cycle_count;
    __Vdly__tb_verilator_bench__DOT__cycle_count = 0;
    IData/*31:0*/ __Vdly__tb_verilator_bench__DOT__stable_count;
    __Vdly__tb_verilator_bench__DOT__stable_count = 0;
    IData/*31:0*/ __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a = 0;
    CData/*2:0*/ __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr = 0;
    IData/*31:0*/ __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo = 0;
    IData/*31:0*/ __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem = 0;
    CData/*1:0*/ __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = 0;
    CData/*4:0*/ __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count = 0;
    IData/*31:0*/ __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0;
    __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0;
    __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0;
    __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0;
    __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1;
    __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1 = 0;
    CData/*2:0*/ __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1;
    __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1 = 0;
    IData/*31:0*/ __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0;
    __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0;
    __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1;
    __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1 = 0;
    CData/*4:0*/ __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1;
    __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v2;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v2 = 0;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    __Vdly__tb_verilator_bench__DOT__cycle_count = vlSelfRef.tb_verilator_bench__DOT__cycle_count;
    __Vdly__tb_verilator_bench__DOT__stable_count = vlSelfRef.tb_verilator_bench__DOT__stable_count;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0 = 0U;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1 = 0U;
    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0 = 0U;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0 = 0U;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1 = 0U;
    __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v2 = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op) 
              & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid))));
    if (vlSelfRef.tb_verilator_bench__DOT__rst_n) {
        __Vdly__tb_verilator_bench__DOT__cycle_count 
            = (1ULL + vlSelfRef.tb_verilator_bench__DOT__cycle_count);
        __Vdly__tb_verilator_bench__DOT__stable_count 
            = (((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                 == vlSelfRef.tb_verilator_bench__DOT__prev3_pc) 
                & (0xffffffffU != vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a))
                ? ((IData)(1U) + vlSelfRef.tb_verilator_bench__DOT__stable_count)
                : 0U);
        if (VL_UNLIKELY(((0xc8U <= vlSelfRef.tb_verilator_bench__DOT__stable_count)))) {
            VL_WRITEF_NX("\n=== TEST: src0 (dual-issue) ===\n  Self-loop at PC = 0x%08x after %0# cycles\n  Dual-issue cycles (b_valid in EX): %0#\n",0,
                         32,vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a,
                         64,vlSelfRef.tb_verilator_bench__DOT__cycle_count,
                         64,vlSelfRef.tb_verilator_bench__DOT__dual_issue_count);
            if (VL_UNLIKELY(((0ULL < vlSelfRef.tb_verilator_bench__DOT__cycle_count)))) {
                VL_WRITEF_NX("  Dual-issue rate: %0#%%\n",0,
                             64,VL_DIV_QQQ(64, (0x64ULL 
                                                * vlSelfRef.tb_verilator_bench__DOT__dual_issue_count), vlSelfRef.tb_verilator_bench__DOT__cycle_count));
            }
            VL_WRITEF_NX("  Register file:\n",0);
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x1 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [1U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x2 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [2U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x3 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [3U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x4 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [4U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x5 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [5U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x6 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [6U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x7 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [7U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x8 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [8U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x9 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [9U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x10 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xaU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x11 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xbU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x12 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xcU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x13 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xdU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x14 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xeU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x15 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xfU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x16 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x10U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x17 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x11U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x18 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x12U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x19 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x13U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x20 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x14U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x21 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x15U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x22 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x16U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x23 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x17U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x24 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x18U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x25 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x19U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x26 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1aU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x27 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1bU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x28 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1cU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x29 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1dU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x30 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1eU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x31 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            if ((0x80000010U == vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a)) {
                VL_WRITEF_NX("  RESULT: *** PASS ***\n",0);
            } else {
                VL_WRITEF_NX("  RESULT: *** STUCK at 0x%08x ***\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a);
            }
            VL_FINISH_MT("tb_verilator_bench.v", 91, "");
        }
        vlSelfRef.tb_verilator_bench__DOT__prev3_pc 
            = vlSelfRef.tb_verilator_bench__DOT__prev2_pc;
        if (VL_UNLIKELY(((0xb2d05e00ULL <= vlSelfRef.tb_verilator_bench__DOT__cycle_count)))) {
            VL_WRITEF_NX("\n=== TIMEOUT after %0# cycles ===\n  PC = 0x%08x\n  Dual-issue cycles: %0#\n",0,
                         64,vlSelfRef.tb_verilator_bench__DOT__cycle_count,
                         32,vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a,
                         64,vlSelfRef.tb_verilator_bench__DOT__dual_issue_count);
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x1 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [1U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x2 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [2U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x3 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [3U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x4 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [4U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x5 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [5U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x6 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [6U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x7 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [7U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x8 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [8U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x9 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [9U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x10 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xaU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x11 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xbU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x12 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xcU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x13 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xdU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x14 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xeU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x15 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0xfU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x16 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x10U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x17 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x11U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x18 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x12U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x19 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x13U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x20 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x14U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x21 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x15U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x22 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x16U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x23 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x17U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x24 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x18U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x25 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x19U];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x26 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1aU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x27 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1bU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x28 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1cU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x29 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1dU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x30 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                [0x1eU];
            if (VL_UNLIKELY(((0U != vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv)))) {
                VL_WRITEF_NX("    x31 = 0x%08x\n",0,
                             32,vlSelfRef.tb_verilator_bench__DOT__dump_regs__Vstatic__rv);
            }
            VL_WRITEF_NX("  RESULT: FAIL (timeout)\n",0);
            VL_FINISH_MT("tb_verilator_bench.v", 101, "");
        }
        if (VL_UNLIKELY((((0U == (0x7ffffffU & (IData)(vlSelfRef.tb_verilator_bench__DOT__cycle_count))) 
                          & (0ULL < vlSelfRef.tb_verilator_bench__DOT__cycle_count))))) {
            VL_WRITEF_NX("[PROGRESS] %0#M cycles, PC=0x%08x, dual=%0#\n",0,
                         64,VL_DIV_QQQ(64, vlSelfRef.tb_verilator_bench__DOT__cycle_count, 0xf4240ULL),
                         32,vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a,
                         64,vlSelfRef.tb_verilator_bench__DOT__dual_issue_count);
        }
        vlSelfRef.tb_verilator_bench__DOT__prev2_pc 
            = vlSelfRef.tb_verilator_bench__DOT__prev_pc;
        vlSelfRef.tb_verilator_bench__DOT__prev_pc 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a;
    } else {
        __Vdly__tb_verilator_bench__DOT__cycle_count = 0ULL;
        __Vdly__tb_verilator_bench__DOT__stable_count = 0U;
        vlSelfRef.tb_verilator_bench__DOT__prev_pc = 0xffffffffU;
        vlSelfRef.tb_verilator_bench__DOT__prev2_pc = 0xffffffffU;
        vlSelfRef.tb_verilator_bench__DOT__prev3_pc = 0xffffffffU;
    }
    if (((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n) 
         & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))) {
        vlSelfRef.tb_verilator_bench__DOT__dual_issue_count 
            = (1ULL + vlSelfRef.tb_verilator_bench__DOT__dual_issue_count);
    }
    if (((((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem) 
           | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem)) 
          & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem)
              ? (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write)
              : (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write))) 
         & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_sel))) {
        __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata;
        __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0 
            = (0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                          >> 2U));
        __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0 = 1U;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read 
        = ((1U & (~ ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                     | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) 
           && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read));
    VL_EXTENDS_WQ(66,33, __Vtemp_3, (((QData)((IData)(
                                                      ((0xeU 
                                                        != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
                                                       & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                                          >> 0x1fU)))) 
                                      << 0x20U) | (QData)((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a))));
    __Vtemp_4[0U] = __Vtemp_3[0U];
    __Vtemp_4[1U] = __Vtemp_3[1U];
    __Vtemp_4[2U] = (3U & __Vtemp_3[2U]);
    VL_EXTENDS_WQ(66,33, __Vtemp_6, (((QData)((IData)(
                                                      ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign) 
                                                       & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b 
                                                          >> 0x1fU)))) 
                                      << 0x20U) | (QData)((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))));
    __Vtemp_7[0U] = __Vtemp_6[0U];
    __Vtemp_7[1U] = __Vtemp_6[1U];
    __Vtemp_7[2U] = (3U & __Vtemp_6[2U]);
    VL_MULS_WWW(66, __Vtemp_8, __Vtemp_4, __Vtemp_7);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[2U] 
        = (3U & __Vtemp_8[2U]);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read 
        = ((1U & (~ ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                     | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) 
           && ((1U & (~ ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) 
                         | (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))))) 
               && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n) 
           && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid));
    vlSelfRef.tb_verilator_bench__DOT__cycle_count 
        = __Vdly__tb_verilator_bench__DOT__cycle_count;
    vlSelfRef.tb_verilator_bench__DOT__stable_count 
        = __Vdly__tb_verilator_bench__DOT__stable_count;
    if (vlSelfRef.tb_verilator_bench__DOT__rst_n) {
        if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) {
            __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                = (((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken)) 
                    & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target);
        } else if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall)))) {
            __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a)
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a
                    : ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final)
                        ? ((IData)(8U) + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a)
                        : ((IData)(4U) + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a)));
            if (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call) 
                 & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return))) {
                __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0 
                    = ((IData)(4U) + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a);
                __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0 
                    = (7U & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr) 
                             - (IData)(1U)));
                __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0 = 1U;
            } else if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call) {
                __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1 
                    = ((IData)(4U) + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a);
                __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr;
                __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1 = 1U;
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr)));
            } else if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return) {
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr 
                    = (7U & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr) 
                             - (IData)(1U)));
            }
        }
    } else {
        __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr = 0U;
        __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a = 0x80000000U;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr 
        = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr;
    if (__VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras[__VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0] 
            = __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v0;
    }
    if (__VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras[__VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1] 
            = __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras__v1;
    }
    if (__VdlySet__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem[__VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0] 
            = __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__dmem__v0;
    }
    if (vlSelfRef.tb_verilator_bench__DOT__rst_n) {
        if (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
             & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))) {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_ha9063eb7__0 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data;
            if ((0x1eU >= (0x1fU & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr) 
                                    - (IData)(1U))))) {
                __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_ha9063eb7__0;
                __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0 
                    = (0x1fU & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr) 
                                - (IData)(1U)));
                __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0 = 1U;
            }
        }
        if (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
             & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))) {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_h7b474f3b__0 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data;
            if ((0x1eU >= (0x1fU & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr) 
                                    - (IData)(1U))))) {
                __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_h7b474f3b__0;
                __VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1 
                    = (0x1fU & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr) 
                                - (IData)(1U)));
                __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1 = 1U;
            }
        }
        if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) {
            if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3 = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data = 0U;
            } else {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_target_a;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr 
                    = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                >> 0xfU));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr 
                    = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                >> 0x14U));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3 
                    = (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                             >> 0xcU));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr 
                    = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                >> 0x14U));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr 
                    = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                >> 0xfU));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata 
                    = (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op) 
                        & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr) 
                           == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                               >> 0x14U))) ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd
                        : ((0x300U == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                       >> 0x14U)) ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus
                            : ((0x305U == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 0x14U))
                                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec
                                : ((0x340U == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                               >> 0x14U))
                                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch
                                    : ((0x341U == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   >> 0x14U))
                                        ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc
                                        : ((0x342U 
                                            == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0x14U))
                                            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause
                                            : ((0x343U 
                                                == 
                                                (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U))
                                                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval
                                                : 0U)))))));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data 
                    = ((0U == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                        >> 0xfU))) ? 0U
                        : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
                            & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr) 
                               == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                            >> 0xfU))))
                            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data
                            : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
                                & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr) 
                                   == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                >> 0xfU))))
                                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                                : ((0x1eU >= (0x1fU 
                                              & ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                  >> 0xfU) 
                                                 - (IData)(1U))))
                                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                                   [(0x1fU & ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                               >> 0xfU) 
                                              - (IData)(1U)))]
                                    : 0U))));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data 
                    = ((0U == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                        >> 0x14U)))
                        ? 0U : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
                                 & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr) 
                                    == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x14U))))
                                 ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data
                                 : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
                                     & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr) 
                                        == (0x1fU & 
                                            (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                             >> 0x14U))))
                                     ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                                     : ((0x1eU >= (0x1fU 
                                                   & ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                       >> 0x14U) 
                                                      - (IData)(1U))))
                                         ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                                        [(0x1fU & (
                                                   (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                    >> 0x14U) 
                                                   - (IData)(1U)))]
                                         : 0U))));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data 
                    = ((0U == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                        >> 0x14U)))
                        ? 0U : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
                                 & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr) 
                                    == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U))))
                                 ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data
                                 : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
                                     & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr) 
                                        == (0x1fU & 
                                            (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                             >> 0x14U))))
                                     ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                                     : ((0x1eU >= (0x1fU 
                                                   & ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                       >> 0x14U) 
                                                      - (IData)(1U))))
                                         ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                                        [(0x1fU & (
                                                   (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                    >> 0x14U) 
                                                   - (IData)(1U)))]
                                         : 0U))));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data 
                    = ((0U == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                        >> 0xfU))) ? 0U
                        : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
                            & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr) 
                               == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                            >> 0xfU))))
                            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data
                            : (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
                                & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr) 
                                   == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0xfU))))
                                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                                : ((0x1eU >= (0x1fU 
                                              & ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0xfU) 
                                                 - (IData)(1U))))
                                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile
                                   [(0x1fU & ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                               >> 0xfU) 
                                              - (IData)(1U)))]
                                    : 0U))));
            }
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr));
        }
        if ((0U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state))) {
            if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem;
                if ((0U == vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)) {
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo = 0xffffffffU;
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem 
                        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a;
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q = 0U;
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r = 0U;
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = 2U;
                } else if ((((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed) 
                             & (0x80000000U == vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a)) 
                            & (0xffffffffU == vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))) {
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo = 0x80000000U;
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem = 0U;
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q = 0U;
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r = 0U;
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = 2U;
                } else {
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                        = (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed) 
                            & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                               >> 0x1fU)) ? ((IData)(1U) 
                                             + (~ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a))
                            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a);
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg 
                        = (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed) 
                            & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b 
                               >> 0x1fU)) ? ((IData)(1U) 
                                             + (~ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))
                            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b);
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem = 0U;
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q 
                        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed) 
                           & ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                               ^ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b) 
                              >> 0x1fU));
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r 
                        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed) 
                           & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                              >> 0x1fU));
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count = 0x1fU;
                    __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = 1U;
                }
            }
        } else if ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state))) {
            if ((1U & (IData)((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial 
                               >> 0x20U)))) {
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem 
                    = ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem 
                        << 1U) | (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                                  >> 0x1fU));
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                    = (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                       << 1U);
            } else {
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                    = (1U | (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                             << 1U));
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem 
                    = (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial);
            }
            if ((0U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count))) {
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = 2U;
            } else {
                __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count 
                    = (0x1fU & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count) 
                                - (IData)(1U)));
            }
        } else {
            __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = 0U;
        }
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem;
    } else {
        __VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v2 = 1U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target = 0U;
        __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = 0U;
        __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count = 0U;
        __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo = 0U;
        __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem 
            = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3 = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data = 0U;
    }
    if (__VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[__VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0] 
            = __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v0;
    }
    if (__VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[__VdlyDim0__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1] 
            = __VdlyVal__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v1;
    }
    if (__VdlySet__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile__v2) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[1U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[2U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[3U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[4U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[5U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[6U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[7U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[8U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[9U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0xaU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0xbU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0xcU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0xdU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0xeU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0xfU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x10U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x11U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x12U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x13U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x14U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x15U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x16U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x17U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x18U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x19U] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x1aU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x1bU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x1cU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x1dU] = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[0x1eU] = 0U;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write 
        = ((1U & (~ ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                     | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) 
           && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_write));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write 
        = ((1U & (~ ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                     | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) 
           && ((1U & (~ ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) 
                         | (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))))) 
               && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_write)));
    if ((1U & ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
               | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3 = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3 = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data = 0U;
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2;
        if ((1U & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) 
                   | (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))))) {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data = 0U;
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3 = 0U;
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data = 0U;
        } else {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_b_rs2_data_fwd;
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3;
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data 
                = ((2U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out);
        }
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data 
            = ((2U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel))
                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4
                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result);
    }
    if (vlSelfRef.tb_verilator_bench__DOT__rst_n) {
        if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_a));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read));
            if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3 = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3 = 0U;
            } else {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3 
                    = (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                             >> 0xcU));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3 
                    = (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                             >> 0xcU));
            }
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read));
        }
        if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall) {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause 
                = ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))
                    ? 3U : 0xbU);
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc 
                = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc;
        }
        if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op) {
            if ((0x300U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd;
            }
            if ((0x300U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                if ((0x305U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                    if ((0x340U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch 
                            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd;
                    }
                    if ((0x340U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                        if ((0x341U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                            if ((0x342U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                                if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall)))) {
                                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause 
                                        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd;
                                }
                            }
                            if ((0x342U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                                if ((0x343U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                                    if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall)))) {
                                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval 
                                            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd;
                                    }
                                }
                            }
                        }
                        if ((0x341U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                            if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall)))) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc 
                                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd;
                            }
                        }
                    }
                }
                if ((0x305U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr))) {
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec 
                        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd;
                }
            }
        }
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data 
            = ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel))
                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a
                : ((2U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_pc_plus4
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result));
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3 = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3 = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data = 0U;
    }
    if ((1U & ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
               | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_pc_plus4 = 0U;
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_pc_plus4 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)
            ? (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr)
            : 0U);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr 
        = ((1U & ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                  | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))
            ? 0U : (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)
            ? ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid)
                ? (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr)
                : 0U) : 0U);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr 
        = ((1U & ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                  | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))
            ? 0U : ((1U & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) 
                           | (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))))
                     ? 0U : (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)
            ? ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid)
                ? ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b
                    : ((2U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel))
                        ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4
                        : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result))
                : 0U) : 0U);
    if ((1U & ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
               | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4 = 0U;
    } else if ((1U & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) 
                      | (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4 = 0U;
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4;
    }
    if (vlSelfRef.tb_verilator_bench__DOT__rst_n) {
        if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_write 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_write 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc 
                = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush)
                    ? 0U : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a);
        }
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_write = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_write = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc = 0U;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial 
        = (0x1ffffffffULL & ((((QData)((IData)((0x7fffffffU 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))) 
                               << 1U) | (QData)((IData)(
                                                        (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                                                         >> 0x1fU)))) 
                             - (QData)((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem)
            ? ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r)
                ? ((IData)(1U) + (~ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))
                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem)
            : ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q)
                ? ((IData)(1U) + (~ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo))
                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n) 
           && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n) 
           && ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
               & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read) 
           | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed 
        = ((0xfU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x11U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign 
        = ((0xbU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0xcU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem 
        = ((0x11U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x12U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write 
        = ((1U & (~ ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                     | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) 
           && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write 
        = ((1U & (~ ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                     | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) 
           && ((1U & (~ ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) 
                         | (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))))) 
               && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_reg_write)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid 
        = ((1U & (~ ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
                     | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) 
           && (1U & (~ ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect) 
                        | (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid))))));
    if (vlSelfRef.tb_verilator_bench__DOT__rst_n) {
        if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall)))) {
            if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4 = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel = 0U;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4 = 0U;
            } else {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr 
                    = (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                       >> 0x14U);
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a_plus4;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr 
                    = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                >> 7U));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr 
                    = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                >> 7U));
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel;
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4 
                    = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b_plus4;
            }
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_reg_write 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write));
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid 
                = ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush))) 
                   && (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid));
        }
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4 = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_reg_write = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4 = 0U;
    }
    if ((1U & ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__rst_n)) 
               | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect)))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_target_a = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_a = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a_plus4 = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a = 0x13U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b = 0x13U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid = 0U;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b_plus4 = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall)))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_target_a 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b 
            = ((IData)(4U) + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a);
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_a 
            = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0) 
               & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a_plus4 
            = ((IData)(4U) + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a);
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
            [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                        >> 2U))];
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
            [(0xfffU & ((IData)(1U) + (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                       >> 2U)))];
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid 
            = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0) 
               & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b_plus4 
            = ((IData)(8U) + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a);
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign) 
           | ((0xdU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (0xeU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op 
        = ((0xfU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | ((0x10U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start 
        = ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op) 
           & ((1U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
              & (2U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read) 
              | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr))));
    if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask 
            = (3U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result;
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data;
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask 
            = (3U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result;
    }
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1 
        = (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr)))
            ? 4U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr)))
                     ? 3U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2 
        = (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr)))
            ? 4U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr)))
                     ? 3U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2 
        = (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr)))
            ? 4U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr)))
                     ? 3U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1 
        = (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
            ? 4U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
                     ? 3U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall 
        = (((2U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
            & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op)) 
           | ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid)) 
              & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_sel 
        = ((0x80100000U <= vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr) 
           & (0x80140000U > vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2 
        = ((4U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
            ? ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data
                : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                ? ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
        = ((4U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
            ? ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data
                : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                ? ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_intra_valid 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src)
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm
            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd 
        = ((4U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
            ? ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)) 
                       & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata)
                    : (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata 
                       | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
                : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)
                    : tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
            : ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? ((~ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1) 
                       & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata)
                    : (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata 
                       | tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
                : tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal) 
           | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr) 
              | (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch) 
                  & ((4U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                      ? ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                          ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                              ? (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                 >= vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                              : (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                 < vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2))
                          : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                              ? VL_GTES_III(32, tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                              : VL_LTS_III(32, tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)))
                      : ((~ ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3) 
                             >> 1U)) & ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                                         ? (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                            != vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                                         : (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                            == vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2))))) 
                 | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall) 
                    | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret)))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret)
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc
            : ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall)
                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec
                : ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr)
                    ? (0xfffffffeU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm 
                                      + tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
                    : (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm 
                       + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc)
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc
            : tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
        = __Vdly__tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = 0U;
    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                      >> 5U)))) {
            if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = 0U;
    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            __VdfgRegularize_h495687df_0_4 = (0xfffff000U 
                                              & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a);
            __VdfgRegularize_h495687df_0_2 = (((- (IData)(
                                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U));
        } else {
            __VdfgRegularize_h495687df_0_4 = 0U;
            __VdfgRegularize_h495687df_0_2 = 0U;
        }
    } else {
        __VdfgRegularize_h495687df_0_4 = 0U;
        __VdfgRegularize_h495687df_0_2 = 0U;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = 0U;
    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                      >> 5U)))) {
            if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 0U;
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            __VdfgRegularize_h495687df_0_9 = (0xfffff000U 
                                              & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b);
            __VdfgRegularize_h495687df_0_7 = (((- (IData)(
                                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x14U));
        } else {
            __VdfgRegularize_h495687df_0_9 = 0U;
            __VdfgRegularize_h495687df_0_7 = 0U;
        }
    } else {
        __VdfgRegularize_h495687df_0_9 = 0U;
        __VdfgRegularize_h495687df_0_7 = 0U;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect 
        = (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken) 
            ^ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted)) 
           | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken) 
              & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted) 
                 & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr) 
                    & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target 
                       != vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target)))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op)
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata
            : ((0x10U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                ? ((8U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                    ? 0U : ((4U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? 0U : ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                      ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                          ? 0U : tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result)
                                      : tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result)))
                : ((8U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                    ? ((4U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                        ? ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result
                                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[1U])
                            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[1U])
                        : ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[0U]
                                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                            : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                : (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   | vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))))
                    : ((4U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                        ? ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a, 
                                                 (0x1fU 
                                                  & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))
                                : (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   >> (0x1fU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))
                            : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   ^ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                : ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                    < vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                    ? 1U : 0U))) : 
                       ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                         ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? (VL_LTS_III(32, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                 ? 1U : 0U) : (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                               << (0x1fU 
                                                   & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))
                         : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                - vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                             : (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                + vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__hz_stall 
        = (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read) 
            & ((0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr)) 
               & (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                   == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                >> 0xfU))) | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                                              == (0x1fU 
                                                  & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 0x14U)))))) 
           | (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read) 
               & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid) 
                  & ((0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr)) 
                     & (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                         == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                      >> 0xfU))) | 
                        ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                         == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                      >> 0x14U))))))) 
              | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read) 
                 & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid) 
                    & (((0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr)) 
                        & (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                            == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                         >> 0xfU))) 
                           | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                              == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 0x14U))))) 
                       | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid) 
                          & ((0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr)) 
                             & (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                 == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                              >> 0xfU))) 
                                | ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                   == (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                >> 0x14U)))))))))));
    __VdfgRegularize_h495687df_0_3 = ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                       ? 0U : __VdfgRegularize_h495687df_0_2);
    if ((0x40U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
        if ((0x20U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                if ((0U == (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0xcU)))) {
                                    if ((0U != (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0x14U))) {
                                        if ((1U != 
                                             (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                              >> 0x14U))) {
                                            if ((0x302U 
                                                 == 
                                                 (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0x14U))) {
                                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = 1U;
                                            }
                                        }
                                    }
                                    if ((0U == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0x14U))) {
                                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 1U;
                                    } else if ((1U 
                                                == 
                                                (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U))) {
                                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 1U;
                                    }
                                }
                                if ((0U != (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0xcU)))) {
                                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = 1U;
                                }
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : __VdfgRegularize_h495687df_0_3);
            } else if ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                                = ((((- (IData)((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x1fU))) 
                                     << 0x15U) | (0x100000U 
                                                  & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 0xbU))) 
                                   | (((0xff000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a) 
                                       | (0x800U & 
                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 9U))) 
                                      | (0x7feU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   >> 0x14U))));
                        } else {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                        }
                    } else {
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                    }
                } else {
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                }
            } else if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = __VdfgRegularize_h495687df_0_2;
            } else {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                            ? (((- (IData)((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                            >> 0x1fU))) 
                                << 0xdU) | (((0x1000U 
                                              & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x13U)) 
                                             | (0x800U 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   << 4U))) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 7U)))))
                            : 0U) : 0U);
            }
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 1U;
                        }
                    }
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = 1U;
                            }
                        }
                    }
                }
                if ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 2U;
                        }
                    }
                }
            }
        } else {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
        }
    } else {
        if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 1U;
                            }
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op 
                                = ((1U == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 0x19U))
                                    ? ((0x4000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0x12U
                                                : 0x11U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0x10U
                                                : 0xfU))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0xeU
                                                : 0xdU)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0xcU
                                                : 0xbU)))
                                    : ((0x4000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 2U
                                                : (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 1U
                                                    : 0U)))));
                        }
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                 ? __VdfgRegularize_h495687df_0_4
                                 : 0U));
            } else {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                 ? 0U : ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                          ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                              ? (((- (IData)(
                                                             (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                          >> 7U))))
                                              : 0U)
                                          : 0U)));
            }
        } else if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op 
                            = ((0x4000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                ? ((0x2000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                    ? ((0x1000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? 9U : 8U) : 
                                   ((0x1000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                     ? ((0x40000000U 
                                         & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                         ? 7U : 6U)
                                     : 5U)) : ((0x2000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 4U
                                                    : 3U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 2U
                                                    : 0U)));
                    }
                }
            }
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                    ? 0U : ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                             ? __VdfgRegularize_h495687df_0_4
                             : __VdfgRegularize_h495687df_0_2));
        } else {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                        }
                    }
                }
            }
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                    ? ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                            ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                ? 4U : 0U) : 0U) : 0U)
                    : __VdfgRegularize_h495687df_0_3);
        }
    }
    __VdfgRegularize_h495687df_0_8 = ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                       ? 0U : __VdfgRegularize_h495687df_0_7);
    if ((0x40U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
        if ((0x20U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 2U;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 1U;
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                if ((0U != (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                  >> 0xcU)))) {
                                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                                }
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : __VdfgRegularize_h495687df_0_8);
            } else if ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                                = ((((- (IData)((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x1fU))) 
                                     << 0x15U) | (0x100000U 
                                                  & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                     >> 0xbU))) 
                                   | (((0xff000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b) 
                                       | (0x800U & 
                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                           >> 9U))) 
                                      | (0x7feU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   >> 0x14U))));
                        } else {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                        }
                    } else {
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                    }
                } else {
                    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                }
            } else if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = __VdfgRegularize_h495687df_0_7;
            } else {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                            ? (((- (IData)((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                            >> 0x1fU))) 
                                << 0xdU) | (((0x1000U 
                                              & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x13U)) 
                                             | (0x800U 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   << 4U))) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                     >> 7U)))))
                            : 0U) : 0U);
            }
        } else {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
        }
    } else {
        if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op 
                                = ((1U == (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                           >> 0x19U))
                                    ? ((0x4000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0x12U
                                                : 0x11U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0x10U
                                                : 0xfU))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0xeU
                                                : 0xdU)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0xcU
                                                : 0xbU)))
                                    : ((0x4000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 2U
                                                : (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 1U
                                                    : 0U)))));
                        }
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                 ? __VdfgRegularize_h495687df_0_9
                                 : 0U));
            } else {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                 ? 0U : ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                          ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                              ? (((- (IData)(
                                                             (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                          >> 7U))))
                                              : 0U)
                                          : 0U)));
            }
        } else if ((0x10U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op 
                            = ((0x4000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                ? ((0x2000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                    ? ((0x1000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? 9U : 8U) : 
                                   ((0x1000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                     ? ((0x40000000U 
                                         & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                         ? 7U : 6U)
                                     : 5U)) : ((0x2000U 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 4U
                                                    : 3U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 2U
                                                    : 0U)));
                    }
                }
            }
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                    ? 0U : ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                             ? __VdfgRegularize_h495687df_0_9
                             : __VdfgRegularize_h495687df_0_7));
        } else {
            if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                        }
                    }
                }
            }
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                = ((8U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                    ? ((4U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                            ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                ? 4U : 0U) : 0U) : 0U)
                    : __VdfgRegularize_h495687df_0_8);
        }
    }
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc)
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc
            : (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_intra_valid) 
                & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                   == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr)))
                ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result
                : ((4U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                    ? ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                        ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data
                        : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data
                            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
                    : ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                        ? ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                        : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data)))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_b_rs2_data_fwd 
        = (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_intra_valid) 
            & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr)))
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result
            : ((4U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                ? ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                    ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data
                    : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                        ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data
                        : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
                : ((2U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                    ? ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                        ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                        : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                    : ((1U & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                        ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                        : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush 
        = ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__hz_stall) 
           | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall 
        = ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__hz_stall) 
           | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src)
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm
            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_b_rs2_data_fwd);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0 
        = (1U & (~ ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall) 
                    | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out 
        = ((0x10U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
            ? 0U : ((8U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                     ? ((4U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                         ? 0U : ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                  ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                      ? 0U : tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                  : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                      ? (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                         & tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                      : (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                         | tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))))
                     : ((4U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                         ? ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                             ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                 ? VL_SHIFTRS_III(32,32,5, tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a, 
                                                  (0x1fU 
                                                   & tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))
                                 : (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                    >> (0x1fU & tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)))
                             : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                 ? (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                    ^ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                 : ((tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                     < tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                     ? 1U : 0U))) : 
                        ((2U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                          ? ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                              ? (VL_LTS_III(32, tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a, tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                  ? 1U : 0U) : (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                                << 
                                                (0x1fU 
                                                 & tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)))
                          : ((1U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                              ? (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                 - tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                              : (tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                 + tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))))));
}

VL_INLINE_OPT void Vtb_verilator_bench___024root___nba_comb__TOP__0(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___nba_comb__TOP__0\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_cur;
    tb_verilator_bench__DOT__u_soc__DOT__dram_cur = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_rdata;
    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata = 0;
    CData/*6:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode = 0;
    CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd = 0;
    CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw = 0;
    CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 = 0;
    CData/*6:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr = 0;
    // Body
    tb_verilator_bench__DOT__u_soc__DOT__dram_cur = 
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
        [(0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                     >> 2U))];
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op 
        = (0x7fU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & ((IData)(1U) + (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                      >> 2U)))]);
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 
        = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 0xfU));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 
        = (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                 [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                             >> 2U))] >> 0xcU));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward 
        = (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))] >> 0x1fU);
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd 
        = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 7U));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode 
        = (0x7fU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))]);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
        = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
    if ((0U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
            = ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                        << 0x18U) | (0xffffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur))
                    : ((0xff000000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff0000U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                                        << 0x10U)) 
                          | (0xffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur))))
                : ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((0xffff0000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff00U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                                      << 8U)) | (0xffU 
                                                 & tb_verilator_bench__DOT__u_soc__DOT__dram_cur)))
                    : ((0xffffff00U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | (0xffU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata))));
    } else if ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
            if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
                    = ((vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                        << 0x10U) | (0xffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur));
            }
        } else {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
                = ((0xffff0000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                   | (0xffffU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata));
        }
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
    }
    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata = 0U;
    if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_sel) {
        if ((0U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
            tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                = ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x18U)
                        : (0xffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                    [(0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                                 >> 2U))] 
                                    >> 0x10U))) : (
                                                   (1U 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                                                    ? 
                                                   (0xffU 
                                                    & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                                       [
                                                       (0xffffU 
                                                        & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                                           >> 2U))] 
                                                       >> 8U))
                                                    : 
                                                   (0xffU 
                                                    & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                                    [
                                                    (0xffffU 
                                                     & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                                        >> 2U))])));
        } else if ((1U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
            if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
                if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
                    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                        = VL_SHIFTR_III(32,32,32, vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x10U);
                }
            } else {
                tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                    = (0xffffU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
                       [(0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                                    >> 2U))]);
            }
        } else {
            tb_verilator_bench__DOT__u_soc__DOT__dram_rdata 
                = tb_verilator_bench__DOT__u_soc__DOT__dram_cur;
        }
    }
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link 
        = ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)) 
           | (5U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr 
        = ((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & (0U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken 
        = ((0x63U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b = 0U;
    if (((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) 
         & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read))) {
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
            = tb_verilator_bench__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b 
            = vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a = 0U;
    if ((((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem) 
          & (~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem))) 
         & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read))) {
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
            = tb_verilator_bench__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3;
        vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a 
            = vlSelfRef.__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout;
    }
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call 
        = (((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
            | (0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return 
        = ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & ((~ ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link) 
                  & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                     == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))) 
              & ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)) 
                 | (5U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw 
        = (1U & (~ ((((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                      | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
                     & ((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                        | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)))) 
                    | (((~ (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                             & (1U != (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                       [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                       >> 0x19U))) 
                            | ((0x13U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                               | ((0x37U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                  | (0x17U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)))))) 
                        & (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                            | ((0x13U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                               | ((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                  | ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                     | ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                        | ((0x37U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                           | ((0x17U 
                                               == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                              | (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr)))))))) 
                           & ((0U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)) 
                              & (((0x37U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                  & ((0x17U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                     & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                                        == (0x1fU & 
                                            (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                             [(0xfffU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U)))] 
                                             >> 0xfU))))) 
                                 | (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                     | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op))) 
                                    & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                                       == (0x1fU & 
                                           (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                            [(0xfffU 
                                              & ((IData)(1U) 
                                                 + 
                                                 (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                  >> 2U)))] 
                                            >> 0x14U)))))))) 
                       | (((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                           & (0U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3))) 
                          | (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr) 
                              | (0xfU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
                             | ((0x63U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                | ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                   | ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                      | ((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                         | ((0xfU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                            | ((0x33U 
                                                == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                               & (1U 
                                                  == 
                                                  (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                                   [
                                                   (0xfffU 
                                                    & ((IData)(1U) 
                                                       + 
                                                       (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                        >> 2U)))] 
                                                   >> 0x19U))))))))))))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a 
        = ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))
            ? (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
               + (((- (IData)((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                   << 0x14U) | (((0xff000U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                  [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                              >> 2U))]) 
                                 | (0x800U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              >> 9U))) 
                                | (0x7feU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                             [(0xfffU 
                                               & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                  >> 2U))] 
                                             >> 0x14U)))))
            : ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken)
                ? (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                   + (((- (IData)((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                       << 0xcU) | ((0x800U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              << 4U)) 
                                   | ((0x7e0U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                                 [(0xfffU 
                                                   & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                 >> 0x14U)) 
                                      | (0x1eU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                                  [
                                                  (0xfffU 
                                                   & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                  >> 7U))))))
                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras
               [(7U & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr) 
                       - (IData)(1U)))]));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a 
        = ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           | ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken) 
              | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final 
        = ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a)) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw));
}

void Vtb_verilator_bench___024root___timing_resume(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___timing_resume\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_verilator_bench___024root___eval_triggers__act(Vtb_verilator_bench___024root* vlSelf);

bool Vtb_verilator_bench___024root___eval_phase__act(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_phase__act\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_verilator_bench___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_verilator_bench___024root___timing_resume(vlSelf);
        Vtb_verilator_bench___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_verilator_bench___024root___eval_phase__nba(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_phase__nba\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_verilator_bench___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_bench___024root___dump_triggers__nba(Vtb_verilator_bench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_bench___024root___dump_triggers__act(Vtb_verilator_bench___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_verilator_bench___024root___eval(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_verilator_bench___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_verilator_bench.v", 16, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_verilator_bench___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_verilator_bench.v", 16, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_verilator_bench___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_verilator_bench___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_verilator_bench___024root___eval_debug_assertions(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_debug_assertions\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
