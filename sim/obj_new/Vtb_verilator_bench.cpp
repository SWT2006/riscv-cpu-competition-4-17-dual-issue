// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_verilator_bench__pch.h"

//============================================================
// Constructors

Vtb_verilator_bench::Vtb_verilator_bench(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_verilator_bench__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_verilator_bench::Vtb_verilator_bench(const char* _vcname__)
    : Vtb_verilator_bench(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_verilator_bench::~Vtb_verilator_bench() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_verilator_bench___024root___eval_debug_assertions(Vtb_verilator_bench___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_verilator_bench___024root___eval_static(Vtb_verilator_bench___024root* vlSelf);
void Vtb_verilator_bench___024root___eval_initial(Vtb_verilator_bench___024root* vlSelf);
void Vtb_verilator_bench___024root___eval_settle(Vtb_verilator_bench___024root* vlSelf);
void Vtb_verilator_bench___024root___eval(Vtb_verilator_bench___024root* vlSelf);

void Vtb_verilator_bench::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_verilator_bench::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_verilator_bench___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_verilator_bench___024root___eval_static(&(vlSymsp->TOP));
        Vtb_verilator_bench___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_verilator_bench___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_verilator_bench___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_verilator_bench::eventsPending() { return false; }

uint64_t Vtb_verilator_bench::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_verilator_bench::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_verilator_bench___024root___eval_final(Vtb_verilator_bench___024root* vlSelf);

VL_ATTR_COLD void Vtb_verilator_bench::final() {
    Vtb_verilator_bench___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_verilator_bench::hierName() const { return vlSymsp->name(); }
const char* Vtb_verilator_bench::modelName() const { return "Vtb_verilator_bench"; }
unsigned Vtb_verilator_bench::threads() const { return 1; }
void Vtb_verilator_bench::prepareClone() const { contextp()->prepareClone(); }
void Vtb_verilator_bench::atClone() const {
    contextp()->threadPoolpOnClone();
}
