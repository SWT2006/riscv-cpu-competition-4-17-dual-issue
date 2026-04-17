// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_debug_dual__pch.h"
#include "Vtb_debug_dual.h"
#include "Vtb_debug_dual___024root.h"

// FUNCTIONS
Vtb_debug_dual__Syms::~Vtb_debug_dual__Syms()
{
}

Vtb_debug_dual__Syms::Vtb_debug_dual__Syms(VerilatedContext* contextp, const char* namep, Vtb_debug_dual* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(574);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
