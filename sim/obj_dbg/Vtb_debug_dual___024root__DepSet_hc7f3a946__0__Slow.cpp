// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_debug_dual.h for the primary calling header

#include "Vtb_debug_dual__pch.h"
#include "Vtb_debug_dual___024root.h"

VL_ATTR_COLD void Vtb_debug_dual___024root___eval_static__TOP(Vtb_debug_dual___024root* vlSelf);

VL_ATTR_COLD void Vtb_debug_dual___024root___eval_static(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___eval_static\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_debug_dual___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_debug_dual__DOT__clk__0 = 0U;
}

VL_ATTR_COLD void Vtb_debug_dual___024root___eval_static__TOP(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___eval_static__TOP\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_debug_dual__DOT__clk = 0U;
    vlSelfRef.tb_debug_dual__DOT__rst_n = 0U;
    vlSelfRef.tb_debug_dual__DOT__cyc = 0ULL;
    vlSelfRef.tb_debug_dual__DOT__stable = 0U;
    vlSelfRef.tb_debug_dual__DOT__prev_pc = 0xffffffffU;
    vlSelfRef.tb_debug_dual__DOT__prev2 = 0xffffffffU;
    vlSelfRef.tb_debug_dual__DOT__prev3 = 0xffffffffU;
    vlSelfRef.tb_debug_dual__DOT__tracing = 0U;
}

VL_ATTR_COLD void Vtb_debug_dual___024root___eval_final(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___eval_final\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_debug_dual___024root___dump_triggers__stl(Vtb_debug_dual___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_debug_dual___024root___eval_phase__stl(Vtb_debug_dual___024root* vlSelf);

VL_ATTR_COLD void Vtb_debug_dual___024root___eval_settle(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___eval_settle\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_debug_dual___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_debug_dual.v", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_debug_dual___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_debug_dual___024root___dump_triggers__stl(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___dump_triggers__stl\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_debug_dual___024root___stl_sequent__TOP__0(Vtb_debug_dual___024root* vlSelf);

VL_ATTR_COLD void Vtb_debug_dual___024root___eval_stl(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___eval_stl\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_debug_dual___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_debug_dual___024root___stl_sequent__TOP__0(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___stl_sequent__TOP__0\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_debug_dual__DOT__u_soc__DOT__dram_cur;
    tb_debug_dual__DOT__u_soc__DOT__dram_cur = 0;
    IData/*31:0*/ tb_debug_dual__DOT__u_soc__DOT__dram_rdata;
    tb_debug_dual__DOT__u_soc__DOT__dram_rdata = 0;
    CData/*4:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link = 0;
    CData/*6:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op = 0;
    CData/*2:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 = 0;
    CData/*4:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd = 0;
    CData/*6:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0 = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1 = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2 = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3 = 0;
    IData/*31:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 = 0;
    CData/*0:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op = 0;
    IData/*31:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result = 0;
    IData/*31:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a = 0;
    IData/*31:0*/ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b;
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b = 0;
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
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = 0U;
    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                      >> 5U)))) {
            if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = 0U;
    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                      >> 5U)))) {
            if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed 
        = ((0xfU == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x11U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial 
        = (0x1ffffffffULL & ((((QData)((IData)((0x7fffffffU 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))) 
                               << 1U) | (QData)((IData)(
                                                        (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                                                         >> 0x1fU)))) 
                             - (QData)((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg))));
    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            __VdfgRegularize_h495687df_0_4 = (0xfffff000U 
                                              & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a);
            __VdfgRegularize_h495687df_0_2 = (((- (IData)(
                                                          (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U));
        } else {
            __VdfgRegularize_h495687df_0_4 = 0U;
            __VdfgRegularize_h495687df_0_2 = 0U;
        }
    } else {
        __VdfgRegularize_h495687df_0_4 = 0U;
        __VdfgRegularize_h495687df_0_2 = 0U;
    }
    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            __VdfgRegularize_h495687df_0_9 = (0xfffff000U 
                                              & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b);
            __VdfgRegularize_h495687df_0_7 = (((- (IData)(
                                                          (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x14U));
        } else {
            __VdfgRegularize_h495687df_0_9 = 0U;
            __VdfgRegularize_h495687df_0_7 = 0U;
        }
    } else {
        __VdfgRegularize_h495687df_0_9 = 0U;
        __VdfgRegularize_h495687df_0_7 = 0U;
    }
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem)
            ? ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r)
                ? ((IData)(1U) + (~ vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))
                : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem)
            : ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q)
                ? ((IData)(1U) + (~ vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo))
                : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read) 
           | (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op 
        = (0x7fU & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
           [(0xfffU & ((IData)(1U) + (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                      >> 2U)))]);
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 
        = (0x1fU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 0xfU));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign 
        = ((0xbU == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0xcU == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    vlSelfRef.tb_debug_dual__DOT__hz_stall = (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read) 
                                               & ((0U 
                                                   != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr)) 
                                                  & (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                          >> 0xfU))) 
                                                     | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                            >> 0x14U)))))) 
                                              | (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read) 
                                                  & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid) 
                                                     & ((0U 
                                                         != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr)) 
                                                        & (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                                >> 0xfU))) 
                                                           | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                                                              == 
                                                              (0x1fU 
                                                               & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                                  >> 0x14U))))))) 
                                                 | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read) 
                                                    & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid) 
                                                       & (((0U 
                                                            != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr)) 
                                                           & (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                                               == 
                                                               (0x1fU 
                                                                & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                                   >> 0xfU))) 
                                                              | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                                     >> 0x14U))))) 
                                                          | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid) 
                                                             & ((0U 
                                                                 != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr)) 
                                                                & (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                                        >> 0xfU))) 
                                                                   | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                                          >> 0x14U)))))))))));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem 
        = ((0x11U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x12U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 
        = (7U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                 [(0xfffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                             >> 2U))] >> 0xcU));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward 
        = (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))] >> 0x1fU);
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd 
        = (0x1fU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 7U));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op 
        = (0x7fU & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))]);
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read) 
              | (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr))));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid) 
           & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr))));
    __VdfgRegularize_h495687df_0_3 = ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                       ? 0U : __VdfgRegularize_h495687df_0_2);
    if ((0x40U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
        if ((0x20U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                if ((0U == (7U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0xcU)))) {
                                    if ((0U != (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0x14U))) {
                                        if ((1U != 
                                             (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                              >> 0x14U))) {
                                            if ((0x302U 
                                                 == 
                                                 (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0x14U))) {
                                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = 1U;
                                            }
                                        }
                                    }
                                    if ((0U == (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0x14U))) {
                                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 1U;
                                    } else if ((1U 
                                                == 
                                                (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U))) {
                                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 1U;
                                    }
                                }
                                if ((0U != (7U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0xcU)))) {
                                    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                                    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = 1U;
                                }
                            }
                        }
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : __VdfgRegularize_h495687df_0_3);
            } else if ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                                = ((((- (IData)((vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x1fU))) 
                                     << 0x15U) | (0x100000U 
                                                  & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 0xbU))) 
                                   | (((0xff000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a) 
                                       | (0x800U & 
                                          (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 9U))) 
                                      | (0x7feU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   >> 0x14U))));
                        } else {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                        }
                    } else {
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                    }
                } else {
                    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                }
            } else if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = __VdfgRegularize_h495687df_0_2;
            } else {
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                            ? (((- (IData)((vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                            >> 0x1fU))) 
                                << 0xdU) | (((0x1000U 
                                              & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x13U)) 
                                             | (0x800U 
                                                & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   << 4U))) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 7U)))))
                            : 0U) : 0U);
            }
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 1U;
                        }
                    }
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = 1U;
                            }
                        }
                    }
                }
                if ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 2U;
                        }
                    }
                }
            }
        } else {
            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
        }
    } else {
        if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 1U;
                            }
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op 
                                = ((1U == (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 0x19U))
                                    ? ((0x4000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0x12U
                                                : 0x11U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0x10U
                                                : 0xfU))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0xeU
                                                : 0xdU)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0xcU
                                                : 0xbU)))
                                    : ((0x4000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 2U
                                                : (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 1U
                                                    : 0U)))));
                        }
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                 ? __VdfgRegularize_h495687df_0_4
                                 : 0U));
            } else {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                            }
                        }
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                 ? 0U : ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                          ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                              ? (((- (IData)(
                                                             (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                          >> 7U))))
                                              : 0U)
                                          : 0U)));
            }
        } else if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op 
                            = ((0x4000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                ? ((0x2000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                    ? ((0x1000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? 9U : 8U) : 
                                   ((0x1000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                     ? ((0x40000000U 
                                         & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                         ? 7U : 6U)
                                     : 5U)) : ((0x2000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 4U
                                                    : 3U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 2U
                                                    : 0U)));
                    }
                }
            }
            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                    ? 0U : ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                             ? __VdfgRegularize_h495687df_0_4
                             : __VdfgRegularize_h495687df_0_2));
        } else {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                        }
                    }
                }
            }
            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                    ? ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                            ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                ? 4U : 0U) : 0U) : 0U)
                    : __VdfgRegularize_h495687df_0_3);
        }
    }
    __VdfgRegularize_h495687df_0_8 = ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                       ? 0U : __VdfgRegularize_h495687df_0_7);
    if ((0x40U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
        if ((0x20U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 2U;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 1U;
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                if ((0U != (7U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                  >> 0xcU)))) {
                                    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                                }
                            }
                        }
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : __VdfgRegularize_h495687df_0_8);
            } else if ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                                = ((((- (IData)((vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x1fU))) 
                                     << 0x15U) | (0x100000U 
                                                  & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                     >> 0xbU))) 
                                   | (((0xff000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b) 
                                       | (0x800U & 
                                          (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                           >> 9U))) 
                                      | (0x7feU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   >> 0x14U))));
                        } else {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                        }
                    } else {
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                    }
                } else {
                    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                }
            } else if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = __VdfgRegularize_h495687df_0_7;
            } else {
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                            ? (((- (IData)((vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                            >> 0x1fU))) 
                                << 0xdU) | (((0x1000U 
                                              & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x13U)) 
                                             | (0x800U 
                                                & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   << 4U))) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                     >> 7U)))))
                            : 0U) : 0U);
            }
        } else {
            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
        }
    } else {
        if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op 
                                = ((1U == (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                           >> 0x19U))
                                    ? ((0x4000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0x12U
                                                : 0x11U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0x10U
                                                : 0xfU))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0xeU
                                                : 0xdU)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0xcU
                                                : 0xbU)))
                                    : ((0x4000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 2U
                                                : (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 1U
                                                    : 0U)))));
                        }
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                 ? __VdfgRegularize_h495687df_0_9
                                 : 0U));
            } else {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                            }
                        }
                    }
                }
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                 ? 0U : ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                          ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                              ? (((- (IData)(
                                                             (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                          >> 7U))))
                                              : 0U)
                                          : 0U)));
            }
        } else if ((0x10U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op 
                            = ((0x4000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                ? ((0x2000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                    ? ((0x1000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? 9U : 8U) : 
                                   ((0x1000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                     ? ((0x40000000U 
                                         & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                         ? 7U : 6U)
                                     : 5U)) : ((0x2000U 
                                                & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 4U
                                                    : 3U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 2U
                                                    : 0U)));
                    }
                }
            }
            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                    ? 0U : ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                             ? __VdfgRegularize_h495687df_0_9
                             : __VdfgRegularize_h495687df_0_7));
        } else {
            if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                        }
                    }
                }
            }
            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                = ((8U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                    ? ((4U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                            ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                ? 4U : 0U) : 0U) : 0U)
                    : __VdfgRegularize_h495687df_0_8);
        }
    }
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign) 
           | ((0xdU == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (0xeU == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op 
        = ((0xfU == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | ((0x10U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link 
        = ((1U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd)) 
           | (5U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr 
        = ((0x73U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           & (0U != (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken 
        = ((0x63U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           & (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward));
    if (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) {
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data;
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_mask 
            = (3U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3));
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
            = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result;
    } else {
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data;
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_mask 
            = (3U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3));
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
            = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result;
    }
    vlSelfRef.tb_debug_dual__DOT__fwd_b1 = (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
                                             & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
                                                == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr)))
                                             ? 4U : 
                                            (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                                              & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                                                 == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr)))
                                              ? 3U : 
                                             (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                                               & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr) 
                                                  == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                                               ? 2U
                                               : (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                                   & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr) 
                                                      == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                                   ? 1U
                                                   : 0U))));
    vlSelfRef.tb_debug_dual__DOT__fwd_b2 = (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
                                             & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
                                                == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr)))
                                             ? 4U : 
                                            (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                                              & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                                                 == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr)))
                                              ? 3U : 
                                             (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                                               & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr) 
                                                  == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                                               ? 2U
                                               : (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                                   & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr) 
                                                      == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                                   ? 1U
                                                   : 0U))));
    vlSelfRef.tb_debug_dual__DOT__fwd_a2 = (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
                                             & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
                                                == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr)))
                                             ? 4U : 
                                            (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                                              & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                                                 == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr)))
                                              ? 3U : 
                                             (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                                               & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr) 
                                                  == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                                               ? 2U
                                               : (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                                   & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr) 
                                                      == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                                   ? 1U
                                                   : 0U))));
    vlSelfRef.tb_debug_dual__DOT__fwd_a1 = (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
                                             & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
                                                == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
                                             ? 4U : 
                                            (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                                              & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                                                 == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
                                              ? 3U : 
                                             (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                                               & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr) 
                                                  == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                                               ? 2U
                                               : (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                                   & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr) 
                                                      == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                                   ? 1U
                                                   : 0U))));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start 
        = ((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op) 
           & ((1U != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
              & (2U != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state))));
    vlSelfRef.tb_debug_dual__DOT__ex_stall = (((2U 
                                                != (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
                                               & (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op)) 
                                              | ((~ (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid)) 
                                                 & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op)));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call 
        = (((0x6fU == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
            | (0x67U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))) 
           & (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return 
        = ((0x67U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           & ((~ ((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link) 
                  & ((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd) 
                     == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))) 
              & ((1U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)) 
                 | (5U == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))));
    vlSelfRef.tb_debug_dual__DOT__can_dual = (1U & 
                                              (~ ((
                                                   ((3U 
                                                     == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                    | (0x23U 
                                                       == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))) 
                                                   & ((3U 
                                                       == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                      | (0x23U 
                                                         == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)))) 
                                                  | ((((0x33U 
                                                        == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                       | ((0x13U 
                                                           == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                          | ((3U 
                                                              == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                             | ((0x6fU 
                                                                 == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                                | ((0x67U 
                                                                    == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                                   | ((0x37U 
                                                                       == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                                      | ((0x17U 
                                                                          == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                                         | (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr)))))))) 
                                                      & ((0U 
                                                          != (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd)) 
                                                         & (((0x37U 
                                                              != (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                             & ((0x17U 
                                                                 != (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                                & ((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd) 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                                                       [
                                                                       (0xfffU 
                                                                        & ((IData)(1U) 
                                                                           + 
                                                                           (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                                            >> 2U)))] 
                                                                       >> 0xfU))))) 
                                                            | (((0x33U 
                                                                 == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                                | (0x23U 
                                                                   == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op))) 
                                                               & ((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_rd) 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                                                      [
                                                                      (0xfffU 
                                                                       & ((IData)(1U) 
                                                                          + 
                                                                          (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                                           >> 2U)))] 
                                                                      >> 0x14U))))))) 
                                                     | (((0x73U 
                                                          == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
                                                         & (0U 
                                                            == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3))) 
                                                        | (((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr) 
                                                            | (0xfU 
                                                               == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))) 
                                                           | ((0x63U 
                                                               == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                              | ((0x6fU 
                                                                  == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                                 | ((0x67U 
                                                                     == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                                    | ((0x73U 
                                                                        == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                                       | ((0xfU 
                                                                           == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                                          | ((0x33U 
                                                                              == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                                                             & (1U 
                                                                                == 
                                                                                (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                                                                [
                                                                                (0xfffU 
                                                                                & ((IData)(1U) 
                                                                                + 
                                                                                (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                                                >> 2U)))] 
                                                                                >> 0x19U))))))))))))));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a 
        = ((0x6fU == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op))
            ? (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
               + (((- (IData)((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                   << 0x14U) | (((0xff000U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                  [(0xfffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                              >> 2U))]) 
                                 | (0x800U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              >> 9U))) 
                                | (0x7feU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                             [(0xfffU 
                                               & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                  >> 2U))] 
                                             >> 0x14U)))))
            : ((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken)
                ? (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                   + (((- (IData)((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                       << 0xcU) | ((0x800U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              << 4U)) 
                                   | ((0x7e0U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                                 [(0xfffU 
                                                   & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                 >> 0x14U)) 
                                      | (0x1eU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__imem
                                                  [
                                                  (0xfffU 
                                                   & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                  >> 7U))))))
                : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras
               [(7U & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr) 
                       - (IData)(1U)))]));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dram_sel 
        = ((0x80100000U <= vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr) 
           & (0x80140000U > vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr));
    tb_debug_dual__DOT__u_soc__DOT__dram_cur = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dmem
        [(0xffffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
                     >> 2U))];
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc)
            ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc
            : ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b1))
                ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b1))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data
                    : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b1))
                        ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data
                        : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
                : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b1))
                    ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b1))
                        ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                        : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                    : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b1))
                        ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                        : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data))));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_b2 
        = ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b2))
            ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b2))
                ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data
                : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b2))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b2))
                ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b2))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_b2))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data)));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2 
        = ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a2))
            ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a2))
                ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data
                : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a2))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a2))
                ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a2))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a2))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data)));
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
        = ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a1))
            ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a1))
                ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data
                : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a1))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a1))
                ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a1))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__fwd_a1))
                    ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data)));
    vlSelfRef.tb_debug_dual__DOT__stall = ((IData)(vlSelfRef.tb_debug_dual__DOT__hz_stall) 
                                           | (IData)(vlSelfRef.tb_debug_dual__DOT__ex_stall));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a 
        = ((0x6fU == (IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_op)) 
           | ((IData)(tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken) 
              | (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return)));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dram_wdata 
        = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata;
    if ((0U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_mask))) {
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dram_wdata 
            = ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)
                ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)
                    ? ((vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata 
                        << 0x18U) | (0xffffffU & tb_debug_dual__DOT__u_soc__DOT__dram_cur))
                    : ((0xff000000U & tb_debug_dual__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff0000U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata 
                                        << 0x10U)) 
                          | (0xffffU & tb_debug_dual__DOT__u_soc__DOT__dram_cur))))
                : ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)
                    ? ((0xffff0000U & tb_debug_dual__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff00U & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata 
                                      << 8U)) | (0xffU 
                                                 & tb_debug_dual__DOT__u_soc__DOT__dram_cur)))
                    : ((0xffffff00U & tb_debug_dual__DOT__u_soc__DOT__dram_cur) 
                       | (0xffU & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata))));
    } else if ((1U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_mask))) {
        if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)) {
            if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)) {
                vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dram_wdata 
                    = ((vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata 
                        << 0x10U) | (0xffffU & tb_debug_dual__DOT__u_soc__DOT__dram_cur));
            }
        } else {
            vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dram_wdata 
                = ((0xffff0000U & tb_debug_dual__DOT__u_soc__DOT__dram_cur) 
                   | (0xffffU & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata));
        }
    } else {
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dram_wdata 
            = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_wdata;
    }
    tb_debug_dual__DOT__u_soc__DOT__dram_rdata = 0U;
    if (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dram_sel) {
        if ((0U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_mask))) {
            tb_debug_dual__DOT__u_soc__DOT__dram_rdata 
                = ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)
                    ? ((1U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)
                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x18U)
                        : (0xffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dmem
                                    [(0xffffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
                                                 >> 2U))] 
                                    >> 0x10U))) : (
                                                   (1U 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)
                                                    ? 
                                                   (0xffU 
                                                    & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dmem
                                                       [
                                                       (0xffffU 
                                                        & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
                                                           >> 2U))] 
                                                       >> 8U))
                                                    : 
                                                   (0xffU 
                                                    & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dmem
                                                    [
                                                    (0xffffU 
                                                     & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
                                                        >> 2U))])));
        } else if ((1U == (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_mask))) {
            if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)) {
                if ((2U & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr)) {
                    tb_debug_dual__DOT__u_soc__DOT__dram_rdata 
                        = VL_SHIFTR_III(32,32,32, vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x10U);
                }
            } else {
                tb_debug_dual__DOT__u_soc__DOT__dram_rdata 
                    = (0xffffU & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__dmem
                       [(0xffffU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__perip_addr 
                                    >> 2U))]);
            }
        } else {
            tb_debug_dual__DOT__u_soc__DOT__dram_rdata 
                = tb_debug_dual__DOT__u_soc__DOT__dram_cur;
        }
    }
    tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src)
            ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm
            : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_b2);
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src)
            ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm
            : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2);
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd 
        = ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
            ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? ((~ (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)) 
                       & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata)
                    : (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata 
                       | (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
                : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)
                    : tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
            : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? ((~ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1) 
                       & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata)
                    : (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata 
                       | tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
                : tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc)
            ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc
            : tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1);
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal) 
           | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr) 
              | (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch) 
                  & ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                      ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                          ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                              ? (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                 >= vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                              : (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                 < vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2))
                          : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                              ? VL_GTES_III(32, tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1, vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                              : VL_LTS_III(32, tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1, vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)))
                      : ((~ ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3) 
                             >> 1U)) & ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                                         ? (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                            != vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                                         : (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                            == vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2))))) 
                 | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall) 
                    | (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret)))));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret)
            ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc
            : ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall)
                ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec
                : ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr)
                    ? (0xfffffffeU & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm 
                                      + tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
                    : (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm 
                       + vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc))));
    vlSelfRef.tb_debug_dual__DOT__can_fin = ((~ (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a)) 
                                             & (IData)(vlSelfRef.tb_debug_dual__DOT__can_dual));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b = 0U;
    if (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) 
         & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read))) {
        vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
            = tb_debug_dual__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3 
            = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3;
        vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))));
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b 
            = vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout;
    }
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a = 0U;
    if ((((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem) 
          & (~ (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem))) 
         & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read))) {
        vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
            = tb_debug_dual__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3 
            = vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3;
        vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))));
        vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a 
            = vlSelfRef.__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout;
    }
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out 
        = ((0x10U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
            ? 0U : ((8U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                     ? ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                         ? 0U : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                  ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                      ? 0U : tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                  : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                      ? (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                         & tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                      : (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                         | tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))))
                     : ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                         ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                             ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                 ? VL_SHIFTRS_III(32,32,5, tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a, 
                                                  (0x1fU 
                                                   & tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))
                                 : (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                    >> (0x1fU & tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)))
                             : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                 ? (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                    ^ tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                 : ((tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                     < tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                     ? 1U : 0U))) : 
                        ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                          ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                              ? (VL_LTS_III(32, tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a, tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                  ? 1U : 0U) : (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                                << 
                                                (0x1fU 
                                                 & tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)))
                          : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                              ? (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                 - tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                              : (tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                 + tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))))));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op)
            ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata
            : ((0x10U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                ? ((8U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                    ? 0U : ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? 0U : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                      ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                          ? 0U : tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result)
                                      : tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result)))
                : ((8U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                    ? ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                        ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result
                                : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[1U])
                            : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[1U])
                        : ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[0U]
                                : vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                            : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                : (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   | vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))))
                    : ((4U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                        ? ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a, 
                                                 (0x1fU 
                                                  & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))
                                : (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   >> (0x1fU & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))
                            : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   ^ vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                : ((vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                    < vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                    ? 1U : 0U))) : 
                       ((2U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                         ? ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? (VL_LTS_III(32, vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a, vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                 ? 1U : 0U) : (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                               << (0x1fU 
                                                   & vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))
                         : ((1U & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                - vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                             : (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                + vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))))));
    vlSelfRef.tb_debug_dual__DOT__flush = (((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken) 
                                            ^ (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted)) 
                                           | ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken) 
                                              & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted) 
                                                 & ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr) 
                                                    & (vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target 
                                                       != vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target)))));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush 
        = ((IData)(vlSelfRef.tb_debug_dual__DOT__hz_stall) 
           | (IData)(vlSelfRef.tb_debug_dual__DOT__flush));
    vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0 
        = (1U & (~ ((IData)(vlSelfRef.tb_debug_dual__DOT__stall) 
                    | (IData)(vlSelfRef.tb_debug_dual__DOT__flush))));
    vlSelfRef.tb_debug_dual__DOT__bv_if = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0) 
                                           & (IData)(vlSelfRef.tb_debug_dual__DOT__can_fin));
    vlSelfRef.tb_debug_dual__DOT__pred_a = ((IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0) 
                                            & (IData)(vlSelfRef.tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a));
}

VL_ATTR_COLD void Vtb_debug_dual___024root___eval_triggers__stl(Vtb_debug_dual___024root* vlSelf);

VL_ATTR_COLD bool Vtb_debug_dual___024root___eval_phase__stl(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___eval_phase__stl\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_debug_dual___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_debug_dual___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_debug_dual___024root___dump_triggers__act(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___dump_triggers__act\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_debug_dual.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_debug_dual.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_debug_dual___024root___dump_triggers__nba(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___dump_triggers__nba\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_debug_dual.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_debug_dual.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_debug_dual___024root___ctor_var_reset(Vtb_debug_dual___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_debug_dual___024root___ctor_var_reset\n"); );
    Vtb_debug_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_debug_dual__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15014089997332202220ull);
    vlSelf->tb_debug_dual__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6989669283267637252ull);
    vlSelf->tb_debug_dual__DOT__bv_if = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3184072032896391658ull);
    vlSelf->tb_debug_dual__DOT__pred_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10024887433596775093ull);
    vlSelf->tb_debug_dual__DOT__can_dual = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7044881335242036990ull);
    vlSelf->tb_debug_dual__DOT__can_fin = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6154250371940537363ull);
    vlSelf->tb_debug_dual__DOT__stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17065670677643371672ull);
    vlSelf->tb_debug_dual__DOT__flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14639532332710648814ull);
    vlSelf->tb_debug_dual__DOT__hz_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3826108501617866525ull);
    vlSelf->tb_debug_dual__DOT__ex_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8969386443909364669ull);
    vlSelf->tb_debug_dual__DOT__fwd_a1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10208701734740330220ull);
    vlSelf->tb_debug_dual__DOT__fwd_a2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12479250700246687292ull);
    vlSelf->tb_debug_dual__DOT__fwd_b1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6932208085003894779ull);
    vlSelf->tb_debug_dual__DOT__fwd_b2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14700316919104719652ull);
    vlSelf->tb_debug_dual__DOT__cyc = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10904170666600050688ull);
    vlSelf->tb_debug_dual__DOT__stable = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8831733555423038476ull);
    vlSelf->tb_debug_dual__DOT__prev_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17828941469080702141ull);
    vlSelf->tb_debug_dual__DOT__prev2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11732169223905721677ull);
    vlSelf->tb_debug_dual__DOT__prev3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6921974966907127421ull);
    vlSelf->tb_debug_dual__DOT__tracing = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 999278164122875396ull);
    vlSelf->tb_debug_dual__DOT__dump_regs__Vstatic__rv = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17158190386843305047ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__perip_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17916898930571917357ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__perip_mask = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11003522317914228078ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__perip_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5096983526337502354ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_debug_dual__DOT__u_soc__DOT__imem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15244475271907957433ull);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_debug_dual__DOT__u_soc__DOT__dmem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4294708353388386707ull);
    }
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__dram_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17352787591836988039ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__dram_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10151021771592364460ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1560359756370695148ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10211154862689114613ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2676932408297916520ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13620673712640767321ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4710195562449911649ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10822781892381947292ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_target_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5267529920039693289ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5321460926086939059ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10501702249026104603ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6513758687402210301ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1296398336802506070ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4880530740259682165ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11040686973098779852ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6125521352834261404ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4451175826261975148ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 289713753211717485ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11131252145703341172ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5734085678908430455ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5304672673404423061ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9090526726111372066ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5399454494273730458ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9976451726666059803ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8315485861761616478ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14975590747914437221ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6324518673172824834ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10343037513277097534ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13015430137400821565ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15415366091597215410ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17592211071094886830ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3566613437619787534ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7795265660311676875ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17354320688451774892ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1619753793228414032ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6556360307196885068ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6514123904114356024ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18412183758224988283ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7641713488014492715ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5258099188785445944ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5341267105307467783ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14922105924939017216ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17336760636455301130ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5406755758543506776ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10157659823326745453ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16880768937391333147ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15720410374544416156ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15115555295826645833ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10798769007704549591ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7760023498403502232ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11708858174138415832ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11966170331398922294ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5784985488735054644ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6850531748166160495ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3540672250879738938ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12446332622157786179ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17624270266626862914ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9308201601690704739ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18363410656767354182ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8534261874960424597ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13623302108489896256ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12764662459783785127ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7747794806048441492ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12764488510024464572ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16665586398325553969ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6273184221291560245ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3601741720440950179ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2238055408393757840ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10614451501469727130ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7841954421842074714ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7829962945194814063ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1219058005303176161ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5836192577438564646ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5225977763711528631ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18439184764593250934ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8632306771298085769ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9020500990334136940ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15337554114182388326ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4535071773179219953ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2666909976631385818ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13937975697912584990ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12873081193008697654ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4497099156034098717ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10242445109002845999ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15534098675544374984ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1281226064181658347ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3074770958920682722ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16694965200761181805ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17513415381623724348ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14127280904515712262ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16533251761516596971ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10533462191004022930ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8159631318069027809ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11553241770943333620ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17608423722742293796ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7883316759778778319ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16245524486763428031ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1657989819874824543ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9716646082607999111ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2128144201175096199ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4829518769811581363ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8066665631283943113ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2533885818158362963ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1798710733783996458ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13812252095439755524ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4127224633841154592ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5368585596028354953ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17555043547823167253ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1978664479665510570ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2546172328777047825ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2757866842215027809ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16689921375503077773ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17104435717802731586ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13401997306471822656ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8597659429116059714ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14984742211485791302ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 682131224215750116ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13384528578361117691ull);
    }
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2164494635296401755ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3007056288405779963ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11630121940823528407ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17984351290241553453ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4309216934507790843ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9667730699982558037ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15156871616011274374ull);
    for (int __Vi0 = 0; __Vi0 < 31; ++__Vi0) {
        vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1953201367371777178ull);
    }
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_ha9063eb7__0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18119599300928742336ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_h7b474f3b__0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13113292497598580614ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12151657425335365490ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_b2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15408885453705967282ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5618054807661748290ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13017426931320132320ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6684783845189603588ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15484831278551558370ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4231449924009097919ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1643048949023433389ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4482119572143214941ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11435103614413413509ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r, __VscopeHash, 2136756814834469824ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3226876237685365774ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 626360319194399295ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10584884409477967009ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 93374819186536587ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12203113047936722094ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1094465990253442705ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9380654706173088690ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17639840039539326253ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 140749340100249218ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7889485050177736537ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 2211887817494750944ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7622359635799634958ull);
    vlSelf->tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 929879542859203461ull);
    vlSelf->__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 333969721782510965ull);
    vlSelf->__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16149494027960160771ull);
    vlSelf->__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4372226222609285543ull);
    vlSelf->__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8131753015281782832ull);
    vlSelf->__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4620733599548672579ull);
    vlSelf->__Vfunc_tb_debug_dual__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 340239116246265386ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_debug_dual__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14699847566179448915ull);
}
