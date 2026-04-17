// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_verilator_bench.h for the primary calling header

#include "Vtb_verilator_bench__pch.h"
#include "Vtb_verilator_bench___024root.h"

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_static__TOP(Vtb_verilator_bench___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_static(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_static\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_verilator_bench___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_verilator_bench__DOT__clk__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_verilator_bench__DOT__clk__1 = 0U;
}

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_static__TOP(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_static__TOP\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_verilator_bench__DOT__clk = 0U;
    vlSelfRef.tb_verilator_bench__DOT__rst_n = 0U;
    vlSelfRef.tb_verilator_bench__DOT__cycle_count = 0ULL;
    vlSelfRef.tb_verilator_bench__DOT__stable_count = 0U;
    vlSelfRef.tb_verilator_bench__DOT__prev_pc = 0xffffffffU;
    vlSelfRef.tb_verilator_bench__DOT__prev2_pc = 0xffffffffU;
    vlSelfRef.tb_verilator_bench__DOT__prev3_pc = 0xffffffffU;
    vlSelfRef.tb_verilator_bench__DOT__dual_issue_count = 0ULL;
}

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_initial__TOP(Vtb_verilator_bench___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_initial(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_initial\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_verilator_bench___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_initial__TOP(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_initial__TOP\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_verilator_bench__DOT__ii;
    tb_verilator_bench__DOT__ii = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__ii;
    tb_verilator_bench__DOT__u_soc__DOT__ii = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
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
    vlSelfRef.tb_verilator_bench__DOT__rst_n = 1U;
    tb_verilator_bench__DOT__u_soc__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x1000U, tb_verilator_bench__DOT__u_soc__DOT__ii)) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem[(0xfffU 
                                                             & tb_verilator_bench__DOT__u_soc__DOT__ii)] = 0x13U;
        tb_verilator_bench__DOT__u_soc__DOT__ii = ((IData)(1U) 
                                                   + tb_verilator_bench__DOT__u_soc__DOT__ii);
    }
    tb_verilator_bench__DOT__u_soc__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x10000U, tb_verilator_bench__DOT__u_soc__DOT__ii)) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem[(0xffffU 
                                                             & tb_verilator_bench__DOT__u_soc__DOT__ii)] = 0U;
        tb_verilator_bench__DOT__u_soc__DOT__ii = ((IData)(1U) 
                                                   + tb_verilator_bench__DOT__u_soc__DOT__ii);
    }
    __Vtemp_3[0U] = 0x2e686578U;
    __Vtemp_3[1U] = 0x69726f6dU;
    __Vtemp_3[2U] = 0x7263305fU;
    __Vtemp_3[3U] = 0x73U;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_3)
                 ,  &(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem)
                 , 0, ~0ULL);
    __Vtemp_4[0U] = 0x2e686578U;
    __Vtemp_4[1U] = 0x6472616dU;
    __Vtemp_4[2U] = 0x7263305fU;
    __Vtemp_4[3U] = 0x73U;
    VL_READMEM_N(true, 32, 65536, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_4)
                 ,  &(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_final(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_final\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_bench___024root___dump_triggers__stl(Vtb_verilator_bench___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_verilator_bench___024root___eval_phase__stl(Vtb_verilator_bench___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_settle(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_settle\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_verilator_bench___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_verilator_bench.v", 16, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_verilator_bench___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_bench___024root___dump_triggers__stl(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___dump_triggers__stl\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] tb_verilator_bench.clk)\n");
    }
}
#endif  // VL_DEBUG

void Vtb_verilator_bench___024root___act_sequent__TOP__0(Vtb_verilator_bench___024root* vlSelf);
VL_ATTR_COLD void Vtb_verilator_bench___024root___stl_sequent__TOP__1(Vtb_verilator_bench___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_stl(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_stl\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_verilator_bench___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_verilator_bench___024root___stl_sequent__TOP__1(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_verilator_bench___024root___stl_sequent__TOP__1(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___stl_sequent__TOP__1\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__perip_mask;
    tb_verilator_bench__DOT__u_soc__DOT__perip_mask = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
    tb_verilator_bench__DOT__u_soc__DOT__perip_wdata = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_cur;
    tb_verilator_bench__DOT__u_soc__DOT__dram_cur = 0;
    IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_rdata;
    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata = 0;
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
    CData/*6:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op = 0;
    CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 = 0;
    CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd = 0;
    CData/*6:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op = 0;
    CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr;
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr = 0;
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
    // Body
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed 
        = ((0xfU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x11U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial 
        = (0x1ffffffffULL & ((((QData)((IData)((0x7fffffffU 
                                                & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))) 
                               << 1U) | (QData)((IData)(
                                                        (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                                                         >> 0x1fU)))) 
                             - (QData)((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg))));
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read) 
           | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op 
        = (0x7fU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & ((IData)(1U) + (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                      >> 2U)))]);
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 
        = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 0xfU));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign 
        = ((0xbU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0xcU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem 
        = ((0x11U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x12U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 
        = (7U & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                 [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                             >> 2U))] >> 0xcU));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward 
        = (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))] >> 0x1fU);
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_intra_valid 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd 
        = (0x1fU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 7U));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem)
            ? ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r)
                ? ((IData)(1U) + (~ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))
                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem)
            : ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q)
                ? ((IData)(1U) + (~ vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo))
                : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op 
        = (0x7fU & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))]);
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read) 
              | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr))));
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign) 
           | ((0xdU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (0xeU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op 
        = ((0xfU == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | ((0x10U == (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link 
        = ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd)) 
           | (5U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr 
        = ((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           & (0U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3)));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken 
        = ((0x63U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward));
    if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) {
        tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data;
        tb_verilator_bench__DOT__u_soc__DOT__perip_mask 
            = (3U & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3));
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result;
    } else {
        tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data;
        tb_verilator_bench__DOT__u_soc__DOT__perip_mask 
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start 
        = ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op) 
           & ((1U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
              & (2U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state))));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall 
        = (((2U != (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
            & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op)) 
           | ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid)) 
              & (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call 
        = (((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
            | (0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return 
        = ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           & ((~ ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link) 
                  & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd) 
                     == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))) 
              & ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)) 
                 | (5U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))));
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw 
        = (1U & (~ ((((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                      | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))) 
                     & ((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                        | (0x23U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)))) 
                    | (((~ (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                             & (1U != (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                       [(0xfffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                       >> 0x19U))) 
                            | ((0x13U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                               | ((0x37U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                  | (0x17U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)))))) 
                        & (((0x33U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                            | ((0x13U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                               | ((3U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                  | ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                     | ((0x67U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                        | ((0x37U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                           | ((0x17U 
                                               == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                              | (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr)))))))) 
                           & ((0U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd)) 
                              & (((0x37U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                  & ((0x17U != (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                     & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd) 
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
                                    & ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd) 
                                       == (0x1fU & 
                                           (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__imem
                                            [(0xfffU 
                                              & ((IData)(1U) 
                                                 + 
                                                 (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                  >> 2U)))] 
                                            >> 0x14U)))))))) 
                       | (((0x73U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                           & (0U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3))) 
                          | (((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr) 
                              | (0xfU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))) 
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
        = ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_sel 
        = ((0x80100000U <= vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr) 
           & (0x80140000U > vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr));
    tb_verilator_bench__DOT__u_soc__DOT__dram_cur = 
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dmem
        [(0xffffU & (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr 
                     >> 2U))];
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall 
        = ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__hz_stall) 
           | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a 
        = ((0x6fU == (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           | ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken) 
              | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return)));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
        = tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
    if ((0U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
            = ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                ? ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                        << 0x18U) | (0xffffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur))
                    : ((0xff000000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff0000U & (tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                                        << 0x10U)) 
                          | (0xffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur))))
                : ((1U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)
                    ? ((0xffff0000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff00U & (tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                                      << 8U)) | (0xffU 
                                                 & tb_verilator_bench__DOT__u_soc__DOT__dram_cur)))
                    : ((0xffffff00U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                       | (0xffU & tb_verilator_bench__DOT__u_soc__DOT__perip_wdata))));
    } else if ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
        if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
            if ((2U & vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__perip_addr)) {
                vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
                    = ((tb_verilator_bench__DOT__u_soc__DOT__perip_wdata 
                        << 0x10U) | (0xffffU & tb_verilator_bench__DOT__u_soc__DOT__dram_cur));
            }
        } else {
            vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
                = ((0xffff0000U & tb_verilator_bench__DOT__u_soc__DOT__dram_cur) 
                   | (0xffffU & tb_verilator_bench__DOT__u_soc__DOT__perip_wdata));
        }
    } else {
        vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_wdata 
            = tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
    }
    tb_verilator_bench__DOT__u_soc__DOT__dram_rdata = 0U;
    if (vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__dram_sel) {
        if ((0U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
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
        } else if ((1U == (IData)(tb_verilator_bench__DOT__u_soc__DOT__perip_mask))) {
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final 
        = ((~ (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a)) 
           & (IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw));
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
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush 
        = ((IData)(tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__hz_stall) 
           | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect));
    vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0 
        = (1U & (~ ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall) 
                    | (IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect))));
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
    tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b 
        = ((IData)(vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src)
            ? vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm
            : vlSelfRef.tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_b_rs2_data_fwd);
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

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_triggers__stl(Vtb_verilator_bench___024root* vlSelf);

VL_ATTR_COLD bool Vtb_verilator_bench___024root___eval_phase__stl(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_phase__stl\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_verilator_bench___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_verilator_bench___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_bench___024root___dump_triggers__act(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___dump_triggers__act\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] tb_verilator_bench.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_verilator_bench.clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_bench___024root___dump_triggers__nba(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___dump_triggers__nba\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] tb_verilator_bench.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_verilator_bench.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_verilator_bench___024root___ctor_var_reset(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___ctor_var_reset\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_verilator_bench__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16725395465868395014ull);
    vlSelf->tb_verilator_bench__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17882866840252382700ull);
    vlSelf->tb_verilator_bench__DOT__cycle_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12011698984269615416ull);
    vlSelf->tb_verilator_bench__DOT__stable_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7625912161642282229ull);
    vlSelf->tb_verilator_bench__DOT__prev_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4437870753136558731ull);
    vlSelf->tb_verilator_bench__DOT__prev2_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3804809926667587116ull);
    vlSelf->tb_verilator_bench__DOT__prev3_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6101342628222654029ull);
    vlSelf->tb_verilator_bench__DOT__dual_issue_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2729586511401045246ull);
    vlSelf->tb_verilator_bench__DOT__dump_regs__Vstatic__rv = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17899938885729201716ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__perip_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14016161776791344969ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_verilator_bench__DOT__u_soc__DOT__imem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16974880906573605060ull);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_verilator_bench__DOT__u_soc__DOT__dmem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5595305005975527085ull);
    }
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__dram_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9295969695640621006ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__dram_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10685825283205959794ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2317728635033144287ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1790111005000945382ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8816085015701374906ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1822917998314204855ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1084298562764661700ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14930458729424196791ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_target_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1846505159432233119ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13253948249532523180ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11534598265533989692ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9660472957563032062ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1635909067749141927ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11894999938961725932ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2498624465737136034ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8683011764072422487ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15149888670955681982ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16359682131102566853ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15822501096102073505ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4670391966984043022ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15391842248521482387ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16394202527674699225ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5880328241879581619ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4043806375336237403ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6631008438476846168ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17126836489811293114ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6777348733200948207ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13281994520954095960ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12629242468084646619ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8966161944657061817ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12952091335538032659ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2048248749762748261ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14431516133305239197ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7601281087841942284ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2692448420038204086ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1769065668007157608ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8856035379253712779ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6495527328655707504ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8219639588191628291ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3051947905879650365ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17663609754454576795ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5942688761810973064ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6690268400008116601ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10980636149244782062ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17875859249847526582ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3693318122127717563ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4114060739297491356ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2333647306432187801ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5957232682742160297ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14521092879081235972ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14229601364507079139ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18101963961386344906ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13308308580456847873ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6549050950032285020ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17761202859064176665ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11940862082841770918ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7367079471616794571ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15412875473252451359ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11727150209182279176ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14566941073061632942ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16603754845821914150ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13423294591362595905ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9314036367547774109ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1988619427825757646ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11161652672537256062ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10339212616719522891ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3400897254690120225ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12421749322922845203ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6626941953101945050ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2580461116939798620ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16922083982497636454ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3008564536527087676ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3033022098998661793ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1948521484251245098ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15151589100165458441ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5496958121660232998ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18293852830854578707ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2600317617056174556ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10334407296810089939ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13603991129950443917ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3320561403451206818ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12682349260969379013ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_b_rs2_data_fwd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7307184551667113996ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2683677778770136893ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4199546437586955151ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7404044244627827252ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 85398899540048642ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10128726308164031529ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13050638581926641004ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10483846043843681418ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5257232240149333442ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 848825078355582551ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3604312933877813925ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 152875305357176798ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14519454576957721250ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3368615586302867817ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15432704514809160751ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5390186997476281963ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12779360484457914486ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 746572189580748999ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15562681851958617318ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8695068797817257845ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10869032815880016723ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17737691673509958859ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10444269092356667847ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3983193498687205528ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13340169426279577757ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 614234143139273612ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1310993094518872277ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5437103076331085776ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4096066220452041935ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5116660372099519726ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14345149445063247102ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11021544636461706383ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4139592134463891730ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2458171924240202354ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14965828575572422109ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3147869622786288341ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5694741073356043049ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1314251086734517829ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10138002125584961908ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6827114883778594671ull);
    }
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15070539799252716375ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17653241560239945365ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12152441095156092588ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8032807392328209914ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2874183140060017244ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2747545662237200070ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3243080835287701029ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12515807278028704368ull);
    for (int __Vi0 = 0; __Vi0 < 31; ++__Vi0) {
        vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14790681820476730667ull);
    }
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_ha9063eb7__0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10813499000522327137ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_h7b474f3b__0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6985648859984294162ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5257893687847217506ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6848333808943154334ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16912539979110429756ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12665997921703319048ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15658099812814997628ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1354946149433310525ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16817820558138109516ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7221872987011412291ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14920106235266497241ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r, __VscopeHash, 8537454698075898189ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6315959039188146970ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1109235217539646050ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15817642885124329298ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14403061728443542071ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3594655529128336158ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12893371553667175898ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14386853647820464592ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13468878527296568066ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11229241267203980553ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6438304780096383450ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 6344210769746996406ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11212878490161376130ull);
    vlSelf->tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7303968618552575679ull);
    vlSelf->__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7913136553811473246ull);
    vlSelf->__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10615592010365609883ull);
    vlSelf->__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1546906640617984895ull);
    vlSelf->__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2337520422555772969ull);
    vlSelf->__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9906904146294201556ull);
    vlSelf->__Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12826004031097001243ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_verilator_bench__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11915151219982329240ull);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_verilator_bench__DOT__clk__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2061130250328196080ull);
    vlSelf->__VactDidInit = 0;
}
