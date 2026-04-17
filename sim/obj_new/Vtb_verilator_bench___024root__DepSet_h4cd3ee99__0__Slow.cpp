// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_verilator_bench.h for the primary calling header

#include "Vtb_verilator_bench__pch.h"
#include "Vtb_verilator_bench__Syms.h"
#include "Vtb_verilator_bench___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_verilator_bench___024root___dump_triggers__stl(Vtb_verilator_bench___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_verilator_bench___024root___eval_triggers__stl(Vtb_verilator_bench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_verilator_bench___024root___eval_triggers__stl\n"); );
    Vtb_verilator_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.setBit(1U, ((IData)(vlSelfRef.tb_verilator_bench__DOT__clk) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_verilator_bench__DOT__clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_verilator_bench__DOT__clk__0 
        = vlSelfRef.tb_verilator_bench__DOT__clk;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_verilator_bench___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
