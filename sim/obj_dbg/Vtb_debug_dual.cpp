// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_debug_dual__pch.h"

//============================================================
// Constructors

Vtb_debug_dual::Vtb_debug_dual(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_debug_dual__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_debug_dual::Vtb_debug_dual(const char* _vcname__)
    : Vtb_debug_dual(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_debug_dual::~Vtb_debug_dual() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_debug_dual___024root___eval_debug_assertions(Vtb_debug_dual___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_debug_dual___024root___eval_static(Vtb_debug_dual___024root* vlSelf);
void Vtb_debug_dual___024root___eval_initial(Vtb_debug_dual___024root* vlSelf);
void Vtb_debug_dual___024root___eval_settle(Vtb_debug_dual___024root* vlSelf);
void Vtb_debug_dual___024root___eval(Vtb_debug_dual___024root* vlSelf);

void Vtb_debug_dual::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_debug_dual::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_debug_dual___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_debug_dual___024root___eval_static(&(vlSymsp->TOP));
        Vtb_debug_dual___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_debug_dual___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_debug_dual___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_debug_dual::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_debug_dual::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_debug_dual::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_debug_dual___024root___eval_final(Vtb_debug_dual___024root* vlSelf);

VL_ATTR_COLD void Vtb_debug_dual::final() {
    Vtb_debug_dual___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_debug_dual::hierName() const { return vlSymsp->name(); }
const char* Vtb_debug_dual::modelName() const { return "Vtb_debug_dual"; }
unsigned Vtb_debug_dual::threads() const { return 1; }
void Vtb_debug_dual::prepareClone() const { contextp()->prepareClone(); }
void Vtb_debug_dual::atClone() const {
    contextp()->threadPoolpOnClone();
}
