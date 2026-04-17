// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_debug_dual.h for the primary calling header

#include "Vtb_debug_dual__pch.h"
#include "Vtb_debug_dual__Syms.h"
#include "Vtb_debug_dual___024root.h"

void Vtb_debug_dual___024root___ctor_var_reset(Vtb_debug_dual___024root* vlSelf);

Vtb_debug_dual___024root::Vtb_debug_dual___024root(Vtb_debug_dual__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_debug_dual___024root___ctor_var_reset(this);
}

void Vtb_debug_dual___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_debug_dual___024root::~Vtb_debug_dual___024root() {
}
