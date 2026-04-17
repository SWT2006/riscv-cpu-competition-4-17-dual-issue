// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_verilator_src0.h for the primary calling header

#include "Vtb_verilator_src0__pch.h"
#include "Vtb_verilator_src0___024root.h"

VL_ATTR_COLD void Vtb_verilator_src0___024root___eval_static__TOP(Vtb_verilator_src0___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_src0___024root___eval_static(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___eval_static\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_verilator_src0___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_verilator_src0__DOT__clk__0 = 0U;
}

VL_ATTR_COLD void Vtb_verilator_src0___024root___eval_static__TOP(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___eval_static__TOP\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_verilator_src0__DOT__clk = 0U;
    vlSelfRef.tb_verilator_src0__DOT__rst_n = 0U;
    vlSelfRef.tb_verilator_src0__DOT__cycle_count = 0ULL;
    vlSelfRef.tb_verilator_src0__DOT__stable_count = 0U;
    vlSelfRef.tb_verilator_src0__DOT__prev_pc = 0xffffffffU;
    vlSelfRef.tb_verilator_src0__DOT__prev2_pc = 0xffffffffU;
    vlSelfRef.tb_verilator_src0__DOT__prev3_pc = 0xffffffffU;
    vlSelfRef.tb_verilator_src0__DOT__dual_issue_count = 0ULL;
}

VL_ATTR_COLD void Vtb_verilator_src0___024root___eval_final(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___eval_final\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_src0___024root___dump_triggers__stl(Vtb_verilator_src0___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_verilator_src0___024root___eval_phase__stl(Vtb_verilator_src0___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_src0___024root___eval_settle(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___eval_settle\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_verilator_src0___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_verilator_src0.v", 10, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_verilator_src0___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_src0___024root___dump_triggers__stl(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___dump_triggers__stl\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vtb_verilator_src0___024root___stl_sequent__TOP__0(Vtb_verilator_src0___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_src0___024root___eval_stl(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___eval_stl\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_verilator_src0___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_verilator_src0___024root___stl_sequent__TOP__0(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___stl_sequent__TOP__0\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_verilator_src0__DOT__u_soc__DOT__dram_cur;
    tb_verilator_src0__DOT__u_soc__DOT__dram_cur = 0;
    IData/*31:0*/ tb_verilator_src0__DOT__u_soc__DOT__dram_rdata;
    tb_verilator_src0__DOT__u_soc__DOT__dram_rdata = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__hz_stall;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__hz_stall = 0;
    CData/*2:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1 = 0;
    CData/*2:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2 = 0;
    CData/*2:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1 = 0;
    CData/*2:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2 = 0;
    CData/*6:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode = 0;
    CData/*4:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd = 0;
    CData/*4:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw = 0;
    CData/*2:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 = 0;
    CData/*6:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0 = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1 = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2 = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3 = 0;
    IData/*31:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 = 0;
    CData/*0:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op = 0;
    IData/*31:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result = 0;
    IData/*31:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a = 0;
    IData/*31:0*/ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b;
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b = 0;
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
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = 0U;
    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                      >> 5U)))) {
            if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = 0U;
    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                      >> 5U)))) {
            if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = 1U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed 
        = ((0xfU == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x11U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial 
        = (0x1ffffffffULL & ((((QData)((IData)((0x7fffffffU 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))) 
                               << 1U) | (QData)((IData)(
                                                        (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo 
                                                         >> 0x1fU)))) 
                             - (QData)((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg))));
    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            __VdfgRegularize_h495687df_0_4 = (0xfffff000U 
                                              & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a);
            __VdfgRegularize_h495687df_0_2 = (((- (IData)(
                                                          (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U));
        } else {
            __VdfgRegularize_h495687df_0_4 = 0U;
            __VdfgRegularize_h495687df_0_2 = 0U;
        }
    } else {
        __VdfgRegularize_h495687df_0_4 = 0U;
        __VdfgRegularize_h495687df_0_2 = 0U;
    }
    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            __VdfgRegularize_h495687df_0_9 = (0xfffff000U 
                                              & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b);
            __VdfgRegularize_h495687df_0_7 = (((- (IData)(
                                                          (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                           >> 0x1fU))) 
                                               << 0xcU) 
                                              | (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x14U));
        } else {
            __VdfgRegularize_h495687df_0_9 = 0U;
            __VdfgRegularize_h495687df_0_7 = 0U;
        }
    } else {
        __VdfgRegularize_h495687df_0_9 = 0U;
        __VdfgRegularize_h495687df_0_7 = 0U;
    }
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem)
            ? ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r)
                ? ((IData)(1U) + (~ vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem))
                : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem)
            : ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q)
                ? ((IData)(1U) + (~ vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo))
                : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read) 
           | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op 
        = (0x7fU & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
           [(0xfffU & ((IData)(1U) + (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                      >> 2U)))]);
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1 
        = (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 0xfU));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign 
        = ((0xbU == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0xcU == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__hz_stall 
        = (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read) 
            & ((0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr)) 
               & (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                   == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                >> 0xfU))) | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                                              == (0x1fU 
                                                  & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 0x14U)))))) 
           | (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read) 
               & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid) 
                  & ((0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr)) 
                     & (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                         == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                      >> 0xfU))) | 
                        ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr) 
                         == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                      >> 0x14U))))))) 
              | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read) 
                 & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid) 
                    & (((0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr)) 
                        & (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                            == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                         >> 0xfU))) 
                           | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                              == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 0x14U))))) 
                       | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid) 
                          & ((0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr)) 
                             & (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                 == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                              >> 0xfU))) 
                                | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr) 
                                   == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                >> 0x14U)))))))))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem 
        = ((0x11U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | (0x12U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3 
        = (7U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                 [(0xfffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                             >> 2U))] >> 0xcU));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward 
        = (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))] >> 0x1fU);
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd 
        = (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                    [(0xfffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                >> 2U))] >> 7U));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode 
        = (0x7fU & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
           [(0xfffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                       >> 2U))]);
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read) 
              | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write) 
           & (0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr))));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid) 
           & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write) 
              & (0U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr))));
    __VdfgRegularize_h495687df_0_3 = ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                       ? 0U : __VdfgRegularize_h495687df_0_2);
    if ((0x40U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
        if ((0x20U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                if ((0U == (7U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0xcU)))) {
                                    if ((0U != (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0x14U))) {
                                        if ((1U != 
                                             (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                              >> 0x14U))) {
                                            if ((0x302U 
                                                 == 
                                                 (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0x14U))) {
                                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = 1U;
                                            }
                                        }
                                    }
                                    if ((0U == (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                >> 0x14U))) {
                                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 1U;
                                    } else if ((1U 
                                                == 
                                                (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x14U))) {
                                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = 1U;
                                    }
                                }
                                if ((0U != (7U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                  >> 0xcU)))) {
                                    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                                    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = 1U;
                                }
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : __VdfgRegularize_h495687df_0_3);
            } else if ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                                = ((((- (IData)((vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x1fU))) 
                                     << 0x15U) | (0x100000U 
                                                  & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 0xbU))) 
                                   | (((0xff000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a) 
                                       | (0x800U & 
                                          (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 9U))) 
                                      | (0x7feU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   >> 0x14U))));
                        } else {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                        }
                    } else {
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                    }
                } else {
                    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
                }
            } else if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = __VdfgRegularize_h495687df_0_2;
            } else {
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                            ? (((- (IData)((vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                            >> 0x1fU))) 
                                << 0xdU) | (((0x1000U 
                                              & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                 >> 0x13U)) 
                                             | (0x800U 
                                                & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   << 4U))) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                     >> 7U)))))
                            : 0U) : 0U);
            }
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 1U;
                        }
                    }
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = 1U;
                            }
                        }
                    }
                }
                if ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 2U;
                        }
                    }
                }
            }
        } else {
            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = 0U;
        }
    } else {
        if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = 1U;
                            }
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op 
                                = ((1U == (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                           >> 0x19U))
                                    ? ((0x4000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0x12U
                                                : 0x11U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0x10U
                                                : 0xfU))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0xeU
                                                : 0xdU)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 0xcU
                                                : 0xbU)))
                                    : ((0x4000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? 2U
                                                : (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 1U
                                                    : 0U)))));
                        }
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                 ? __VdfgRegularize_h495687df_0_4
                                 : 0U));
            } else {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                    = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                 ? 0U : ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                          ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                              ? (((- (IData)(
                                                             (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                                                          >> 7U))))
                                              : 0U)
                                          : 0U)));
            }
        } else if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                    if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op 
                            = ((0x4000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                ? ((0x2000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                    ? ((0x1000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                        ? 9U : 8U) : 
                                   ((0x1000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                     ? ((0x40000000U 
                                         & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                         ? 7U : 6U)
                                     : 5U)) : ((0x2000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 4U
                                                    : 3U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                                    ? 2U
                                                    : 0U)));
                    }
                }
            }
            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                    ? 0U : ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                             ? __VdfgRegularize_h495687df_0_4
                             : __VdfgRegularize_h495687df_0_2));
        } else {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = 0U;
                        }
                    }
                }
            }
            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm 
                = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                    ? ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                        ? ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                            ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a)
                                ? 4U : 0U) : 0U) : 0U)
                    : __VdfgRegularize_h495687df_0_3);
        }
    }
    __VdfgRegularize_h495687df_0_8 = ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                       ? 0U : __VdfgRegularize_h495687df_0_7);
    if ((0x40U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
        if ((0x20U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 2U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 2U;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 1U;
                        }
                    }
                }
            }
            if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                if ((0U != (7U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                  >> 0xcU)))) {
                                    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                                }
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : __VdfgRegularize_h495687df_0_8);
            } else if ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                                = ((((- (IData)((vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x1fU))) 
                                     << 0x15U) | (0x100000U 
                                                  & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                     >> 0xbU))) 
                                   | (((0xff000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b) 
                                       | (0x800U & 
                                          (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                           >> 9U))) 
                                      | (0x7feU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   >> 0x14U))));
                        } else {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                        }
                    } else {
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                    }
                } else {
                    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
                }
            } else if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = __VdfgRegularize_h495687df_0_7;
            } else {
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                            ? (((- (IData)((vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                            >> 0x1fU))) 
                                << 0xdU) | (((0x1000U 
                                              & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                 >> 0x13U)) 
                                             | (0x800U 
                                                & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   << 4U))) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                     >> 7U)))))
                            : 0U) : 0U);
            }
        } else {
            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = 0U;
        }
    } else {
        if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0xaU;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op 
                                = ((1U == (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                           >> 0x19U))
                                    ? ((0x4000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0x12U
                                                : 0x11U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0x10U
                                                : 0xfU))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0xeU
                                                : 0xdU)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 0xcU
                                                : 0xbU)))
                                    : ((0x4000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 9U
                                                : 8U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 7U
                                                    : 6U)
                                                : 5U))
                                        : ((0x2000U 
                                            & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                            ? ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 4U
                                                : 3U)
                                            : ((0x1000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? 2U
                                                : (
                                                   (0x40000000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 1U
                                                    : 0U)))));
                        }
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                 ? __VdfgRegularize_h495687df_0_9
                                 : 0U));
            } else {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                            }
                        }
                    }
                }
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                    = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? 0U : ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                 ? 0U : ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                          ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                              ? (((- (IData)(
                                                             (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                                                          >> 7U))))
                                              : 0U)
                                          : 0U)));
            }
        } else if ((0x10U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                    if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op 
                            = ((0x4000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                ? ((0x2000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                    ? ((0x1000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                        ? 9U : 8U) : 
                                   ((0x1000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                     ? ((0x40000000U 
                                         & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                         ? 7U : 6U)
                                     : 5U)) : ((0x2000U 
                                                & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 4U
                                                    : 3U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                                    ? 2U
                                                    : 0U)));
                    }
                }
            }
            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                    ? 0U : ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                             ? __VdfgRegularize_h495687df_0_9
                             : __VdfgRegularize_h495687df_0_7));
        } else {
            if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                        if ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)) {
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = 1U;
                            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = 0U;
                        }
                    }
                }
            }
            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm 
                = ((8U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                    ? ((4U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                        ? ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                            ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b)
                                ? 4U : 0U) : 0U) : 0U)
                    : __VdfgRegularize_h495687df_0_8);
        }
    }
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign) 
           | ((0xdU == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (0xeU == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op 
        = ((0xfU == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
           | ((0x10U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op)) 
              | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link 
        = ((1U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)) 
           | (5U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr 
        = ((0x73U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & (0U != (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken 
        = ((0x63U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward));
    if (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) {
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data;
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_mask 
            = (3U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3));
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
            = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result;
    } else {
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata 
            = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data;
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_mask 
            = (3U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3));
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
            = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result;
    }
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1 
        = (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr)))
            ? 4U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr)))
                     ? 3U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2 
        = (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr)))
            ? 4U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr)))
                     ? 3U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2 
        = (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr)))
            ? 4U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr)))
                     ? 3U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1 
        = (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_3) 
            & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr) 
               == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
            ? 4U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_0) 
                     & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr) 
                        == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
                     ? 3U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_2) 
                              & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr) 
                                 == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr)))
                              ? 2U : (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_fwd__DOT____VdfgRegularize_h796461b2_0_1) 
                                       & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr) 
                                          == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr)))
                                       ? 1U : 0U))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start 
        = ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op) 
           & ((1U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
              & (2U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_stall 
        = (((2U != (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state)) 
            & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_div_op)) 
           | ((~ (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid)) 
              & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op)));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call 
        = (((0x6fU == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
            | (0x67U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
           & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return 
        = ((0x67U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           & ((~ ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd_is_link) 
                  & ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                     == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))) 
              & ((1U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)) 
                 | (5U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rs1)))));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw 
        = (1U & (~ ((((3U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                      | (0x23U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
                     & ((3U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                        | (0x23U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)))) 
                    | ((((0x33U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                         | ((0x13U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                            | ((3U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                               | ((0x6fU == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                  | ((0x67U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                     | ((0x37U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                        | ((0x17U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                                           | (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr)))))))) 
                        & ((0U != (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd)) 
                           & (((0x37U != (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                               & ((0x17U != (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                  & ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                                     == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                                  [
                                                  (0xfffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                       >> 2U)))] 
                                                  >> 0xfU))))) 
                              | (((0x33U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                  | (0x23U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op))) 
                                 & ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_rd) 
                                    == (0x1fU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                       >> 2U)))] 
                                                 >> 0x14U))))))) 
                       | (((0x73U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
                           & (0U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_f3))) 
                          | (((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__a_is_csr) 
                              | (0xfU == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))) 
                             | ((0x63U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                | ((0x6fU == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                   | ((0x67U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                      | ((0x73U == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                         | ((0xfU == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                            | ((0x33U 
                                                == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__u_issue__DOT__b_op)) 
                                               & (1U 
                                                  == 
                                                  (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                                   [
                                                   (0xfffU 
                                                    & ((IData)(1U) 
                                                       + 
                                                       (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                        >> 2U)))] 
                                                   >> 0x19U))))))))))))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a 
        = ((0x6fU == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode))
            ? (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
               + (((- (IData)((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                   << 0x14U) | (((0xff000U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                  [(0xfffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                              >> 2U))]) 
                                 | (0x800U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              >> 9U))) 
                                | (0x7feU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                             [(0xfffU 
                                               & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                  >> 2U))] 
                                             >> 0x14U)))))
            : ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken)
                ? (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                   + (((- (IData)((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_backward))) 
                       << 0xcU) | ((0x800U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                              [(0xfffU 
                                                & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                   >> 2U))] 
                                              << 4U)) 
                                   | ((0x7e0U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                                 [(0xfffU 
                                                   & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                 >> 0x14U)) 
                                      | (0x1eU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__imem
                                                  [
                                                  (0xfffU 
                                                   & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a 
                                                      >> 2U))] 
                                                  >> 7U))))))
                : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras
               [(7U & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr) 
                       - (IData)(1U)))]));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dram_sel 
        = ((0x80100000U <= vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr) 
           & (0x80140000U > vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr));
    tb_verilator_src0__DOT__u_soc__DOT__dram_cur = 
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dmem
        [(0xffffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
                     >> 2U))];
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc)
            ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc
            : ((4U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                ? ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data
                    : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                        ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data
                        : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
                : ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                    ? ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                        ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                        : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                    : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs1))
                        ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                        : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_b2 
        = ((4U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
            ? ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data
                : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                ? ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_b_rs2))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data)));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2 
        = ((4U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
            ? ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data
                : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                ? ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs2))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data)));
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
        = ((4U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
            ? ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data
                : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data))
            : ((2U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                ? ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data)
                : ((1U & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__fwd_a_rs1))
                    ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data
                    : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data)));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall 
        = ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__hz_stall) 
           | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_stall));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a 
        = ((0x6fU == (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__a_opcode)) 
           | ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__branch_predict_taken) 
              | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return)));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dram_wdata 
        = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata;
    if ((0U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_mask))) {
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dram_wdata 
            = ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)
                ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)
                    ? ((vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata 
                        << 0x18U) | (0xffffffU & tb_verilator_src0__DOT__u_soc__DOT__dram_cur))
                    : ((0xff000000U & tb_verilator_src0__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff0000U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata 
                                        << 0x10U)) 
                          | (0xffffU & tb_verilator_src0__DOT__u_soc__DOT__dram_cur))))
                : ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)
                    ? ((0xffff0000U & tb_verilator_src0__DOT__u_soc__DOT__dram_cur) 
                       | ((0xff00U & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata 
                                      << 8U)) | (0xffU 
                                                 & tb_verilator_src0__DOT__u_soc__DOT__dram_cur)))
                    : ((0xffffff00U & tb_verilator_src0__DOT__u_soc__DOT__dram_cur) 
                       | (0xffU & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata))));
    } else if ((1U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_mask))) {
        if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)) {
            if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)) {
                vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dram_wdata 
                    = ((vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata 
                        << 0x10U) | (0xffffU & tb_verilator_src0__DOT__u_soc__DOT__dram_cur));
            }
        } else {
            vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dram_wdata 
                = ((0xffff0000U & tb_verilator_src0__DOT__u_soc__DOT__dram_cur) 
                   | (0xffffU & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata));
        }
    } else {
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dram_wdata 
            = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_wdata;
    }
    tb_verilator_src0__DOT__u_soc__DOT__dram_rdata = 0U;
    if (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dram_sel) {
        if ((0U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_mask))) {
            tb_verilator_src0__DOT__u_soc__DOT__dram_rdata 
                = ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)
                    ? ((1U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)
                        ? VL_SHIFTR_III(32,32,32, vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x18U)
                        : (0xffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dmem
                                    [(0xffffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
                                                 >> 2U))] 
                                    >> 0x10U))) : (
                                                   (1U 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)
                                                    ? 
                                                   (0xffU 
                                                    & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dmem
                                                       [
                                                       (0xffffU 
                                                        & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
                                                           >> 2U))] 
                                                       >> 8U))
                                                    : 
                                                   (0xffU 
                                                    & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dmem
                                                    [
                                                    (0xffffU 
                                                     & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
                                                        >> 2U))])));
        } else if ((1U == (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_mask))) {
            if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)) {
                if ((2U & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr)) {
                    tb_verilator_src0__DOT__u_soc__DOT__dram_rdata 
                        = VL_SHIFTR_III(32,32,32, vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dmem
                                        [(0xffffU & 
                                          (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
                                           >> 2U))], 0x10U);
                }
            } else {
                tb_verilator_src0__DOT__u_soc__DOT__dram_rdata 
                    = (0xffffU & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__dmem
                       [(0xffffU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__perip_addr 
                                    >> 2U))]);
            }
        } else {
            tb_verilator_src0__DOT__u_soc__DOT__dram_rdata 
                = tb_verilator_src0__DOT__u_soc__DOT__dram_cur;
        }
    }
    tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src)
            ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm
            : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_b2);
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src)
            ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm
            : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2);
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd 
        = ((4U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
            ? ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? ((~ (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)) 
                       & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata)
                    : (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata 
                       | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)))
                : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr)
                    : tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
            : ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                    ? ((~ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1) 
                       & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata)
                    : (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata 
                       | tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
                : tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc)
            ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc
            : tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1);
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal) 
           | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr) 
              | (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch) 
                  & ((4U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                      ? ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                          ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                              ? (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                 >= vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                              : (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                 < vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2))
                          : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                              ? VL_GTES_III(32, tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1, vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                              : VL_LTS_III(32, tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1, vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)))
                      : ((~ ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3) 
                             >> 1U)) & ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3))
                                         ? (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                            != vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2)
                                         : (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1 
                                            == vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2))))) 
                 | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall) 
                    | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret)))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret)
            ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc
            : ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall)
                ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec
                : ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr)
                    ? (0xfffffffeU & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm 
                                      + tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a1))
                    : (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm 
                       + vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final 
        = ((~ (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a)) 
           & (IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_raw));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b = 0U;
    if (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem) 
         & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read))) {
        vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
            = tb_verilator_src0__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3 
            = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3;
        vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata)))));
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b 
            = vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout;
    }
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a = 0U;
    if ((((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem) 
          & (~ (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem))) 
         & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read))) {
        vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
            = tb_verilator_src0__DOT__u_soc__DOT__dram_rdata;
        vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3 
            = vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3;
        vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (0xffffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)
                        : (0xffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))
                : ((2U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                    ? vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata
                    : ((1U & (IData)(vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3))
                        ? (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata))
                        : (((- (IData)((1U & (vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata)))));
        vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a 
            = vlSelfRef.__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout;
    }
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out 
        = ((0x10U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
            ? 0U : ((8U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                     ? ((4U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                         ? 0U : ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                  ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                      ? 0U : tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                  : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                      ? (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                         & tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                      : (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                         | tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))))
                     : ((4U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                         ? ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                             ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                 ? VL_SHIFTRS_III(32,32,5, tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a, 
                                                  (0x1fU 
                                                   & tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))
                                 : (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                    >> (0x1fU & tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)))
                             : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                                 ? (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                    ^ tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                 : ((tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                     < tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                     ? 1U : 0U))) : 
                        ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                          ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                              ? (VL_LTS_III(32, tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a, tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                                  ? 1U : 0U) : (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                                << 
                                                (0x1fU 
                                                 & tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)))
                          : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op))
                              ? (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                 - tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b)
                              : (tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_a 
                                 + tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_b))))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result 
        = ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op)
            ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata
            : ((0x10U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                ? ((8U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                    ? 0U : ((4U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? 0U : ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                      ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                          ? 0U : tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result)
                                      : tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result)))
                : ((8U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                    ? ((4U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                        ? ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_result
                                : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[1U])
                            : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[1U])
                        : ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r[0U]
                                : vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                            : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                : (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   | vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))))
                    : ((4U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                        ? ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                            ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a, 
                                                 (0x1fU 
                                                  & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b))
                                : (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   >> (0x1fU & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))
                            : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                                ? (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                   ^ vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                : ((vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                    < vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                    ? 1U : 0U))) : 
                       ((2U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                         ? ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? (VL_LTS_III(32, vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a, vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                                 ? 1U : 0U) : (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                               << (0x1fU 
                                                   & vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))
                         : ((1U & (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op))
                             ? (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                - vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)
                             : (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a 
                                + vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b)))))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect 
        = (((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken) 
            ^ (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted)) 
           | ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken) 
              & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted) 
                 & ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr) 
                    & (vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target 
                       != vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target)))));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush 
        = ((IData)(tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__hz_stall) 
           | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect));
    vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0 
        = (1U & (~ ((IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall) 
                    | (IData)(vlSelfRef.tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect))));
}

VL_ATTR_COLD void Vtb_verilator_src0___024root___eval_triggers__stl(Vtb_verilator_src0___024root* vlSelf);

VL_ATTR_COLD bool Vtb_verilator_src0___024root___eval_phase__stl(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___eval_phase__stl\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_verilator_src0___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_verilator_src0___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_src0___024root___dump_triggers__act(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___dump_triggers__act\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_verilator_src0.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_verilator_src0.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_src0___024root___dump_triggers__nba(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___dump_triggers__nba\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_verilator_src0.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_verilator_src0.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_verilator_src0___024root___ctor_var_reset(Vtb_verilator_src0___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_src0___024root___ctor_var_reset\n"); );
    Vtb_verilator_src0__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_verilator_src0__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1635346074097753167ull);
    vlSelf->tb_verilator_src0__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9951990394434295458ull);
    vlSelf->tb_verilator_src0__DOT__cycle_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15894587797408020406ull);
    vlSelf->tb_verilator_src0__DOT__stable_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2560112796500648565ull);
    vlSelf->tb_verilator_src0__DOT__prev_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3192443407393253676ull);
    vlSelf->tb_verilator_src0__DOT__prev2_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1837964877414673679ull);
    vlSelf->tb_verilator_src0__DOT__prev3_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18123560369595246819ull);
    vlSelf->tb_verilator_src0__DOT__dual_issue_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17115340229046908668ull);
    vlSelf->tb_verilator_src0__DOT__dump_regs__Vstatic__rv = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17760320013385678122ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__perip_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10153533380223357718ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__perip_mask = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6143131269699765860ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__perip_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 21620162517442691ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_verilator_src0__DOT__u_soc__DOT__imem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8890142363292424697ull);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_verilator_src0__DOT__u_soc__DOT__dmem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6950648502155164700ull);
    }
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__dram_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8037920902764056363ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__dram_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2482104159250629666ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3195636527369978954ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8509908212856486853ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8067037069182484773ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16935374637721697724ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4447604377044563287ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14737672771496503194ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_target_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18010436706161051213ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5988723110635159072ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17737930003010066704ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6308546790881288867ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3986645213953019630ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18330650189938223942ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13484247250770081603ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16625184179351593532ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16166765409608604581ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13454202979847297233ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 255357775434335263ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12784536216387172892ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 60205315466214949ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6098034229388907628ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7274026849271225975ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10576380553884609755ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12148368409051806425ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10611713709633144593ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10980023586707792245ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10220929778870393616ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8183599250797192887ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 69111651798569754ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18238251478709119890ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4192891190385427755ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13985327018282012396ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12706404220459122208ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1536714109732366009ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11949687064435749773ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12031574418303405052ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4324425682210630527ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 928236743038802769ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10290689507494021224ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6360340229386244548ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2278430205004425484ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6595117326685923409ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6430624561020034534ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12131437115064618690ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4430954977599373230ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 11759104007482338198ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14873883029702261032ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1189249201767748115ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5402451731871996527ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4458202358306268354ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2607230641356298913ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2470289869543233466ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6456738899869565010ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 806347280258000212ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14994615179334791819ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16652391357475634420ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12735277199330015000ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5964417601276389918ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16654750689039700659ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6720396952565450643ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1223962703811888726ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6707920005786549529ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8985036863802266321ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5672919944532012010ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3707731647444773822ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13761034436126588221ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2652704797394963205ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18312908354004260897ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6804929941555115567ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13579154887904192053ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9076685029976685981ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14660625423533306355ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1921954010111522169ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18177773088042819634ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11898188928279102435ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2201016990446219110ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 677269998175001154ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15399470157822458731ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1238999218668839536ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12655163401729782449ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8570650388604573585ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13777178678528300582ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1447664288092483022ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7867623674744571545ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7091972165387710954ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8080598184081771829ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5043274711942732048ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12005821376570533502ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2598230086474416921ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15420947098266766250ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14674579508258547526ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5328132126470074612ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5157622716697641597ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7689144704135984410ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7422683840499908828ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6865120510285596759ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17508611614527659858ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15699051688279617553ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11321392696013473425ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14351445814950777188ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11607848043713947875ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11955639499371039022ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1076669902824478227ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 370341861075389562ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10248833691357564411ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4298729235564211561ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17678172281550417254ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6732345833420615077ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11503373804130690233ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3737512246098630165ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7267486043546756835ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17915972270297150555ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6571830589253622665ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13841584348435358172ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6951115253623990763ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7717406696295497991ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11267598123455140988ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4814534366927767275ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4905675520502685516ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11445874670291555971ull);
    }
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12083159050617243278ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1220843673635696515ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17828298720620212750ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11654250920488491889ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16267535349649252237ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16165639116471708724ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4885200649924486087ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8767007392995860606ull);
    for (int __Vi0 = 0; __Vi0 < 31; ++__Vi0) {
        vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17521704073967100645ull);
    }
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_ha9063eb7__0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11009360053423578800ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_h7b474f3b__0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 656470611132785516ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16493807653938301463ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_b2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11153245498210390170ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9053413832289631883ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8823568783354743149ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13178695758843179605ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 88681648081171468ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2164434266830386041ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9131567616422622321ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18240564328724711412ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17754093015261957171ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r, __VscopeHash, 16570535072366599635ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17700471112174890059ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 909312036090839945ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9193609020057188886ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3459785182616630783ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10198030220331209180ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18205149408654382056ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1622258915369563959ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2028050047260616270ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4353537131367558799ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13479757189689445198ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 6783198064503630759ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16720059837995223113ull);
    vlSelf->tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1758106540681137175ull);
    vlSelf->__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5259338572660697080ull);
    vlSelf->__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16928593206608547025ull);
    vlSelf->__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11483363392038543685ull);
    vlSelf->__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8903347823269790055ull);
    vlSelf->__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7359222464715691251ull);
    vlSelf->__Vfunc_tb_verilator_src0__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5721612177062118583ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_verilator_src0__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16469219898262982489ull);
}
