// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_coe.h for the primary calling header

#ifndef VERILATED_VTB_COE___024ROOT_H_
#define VERILATED_VTB_COE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_coe__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_coe___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_coe__DOT__clk;
        CData/*0:0*/ tb_coe__DOT__rst_n;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__dram_sel;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_alu_op;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_alu_src;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_mem_read;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_mem_write;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_reg_write;
        CData/*1:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_wb_sel;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_branch;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_jal;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_jalr;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_auipc;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_ecall;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_mret;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_csr_op;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_rs1_addr;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_rs2_addr;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_rd_addr;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_alu_op;
        CData/*2:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_mem_funct3;
        CData/*2:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_funct3;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_alu_src;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_mem_read;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_mem_write;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_reg_write;
        CData/*1:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_wb_sel;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_branch;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_jal;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_jalr;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_auipc;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_ecall;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_mret;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_csr_op;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_predicted;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_rd_addr;
        CData/*2:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_mem_funct3;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_mem_read;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_mem_write;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_reg_write;
        CData/*1:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_wb_sel;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__memwb_rd_addr;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__memwb_reg_write;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__ex_stall;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__if_is_jal;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid;
        CData/*1:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state;
        CData/*4:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r;
        CData/*0:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_coe__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_csr_addr;
    };
    struct {
        IData/*31:0*/ tb_coe__DOT__cycle_count;
        IData/*31:0*/ tb_coe__DOT__stable_count;
        IData/*31:0*/ tb_coe__DOT__prev_pc;
        IData/*31:0*/ tb_coe__DOT__dump_registers__Vstatic__rv;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__dram_wdata;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__if_pc;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_plus4;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__ifid_instruction;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__id_imm;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_pc;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_pc_plus4;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_rs1_data;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_rs2_data;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_imm;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__idex_csr_rdata;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__ex_alu_result;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_pc_plus4;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_alu_result;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_rs2_data;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__exmem_fwd_data;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__memwb_write_data;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__jal_target;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_h5af0bf87__0;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_b;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__alu_a;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__alu_b;
        VlWide<3>/*65:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__csr_wd;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem;
        IData/*31:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg;
        IData/*31:0*/ __VactIterCount;
        QData/*32:0*/ tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial;
        VlUnpacked<IData/*31:0*/, 4096> tb_coe__DOT__u_soc__DOT__imem;
        VlUnpacked<IData/*31:0*/, 65536> tb_coe__DOT__u_soc__DOT__dmem;
        VlUnpacked<IData/*31:0*/, 31> tb_coe__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hc3524d36__0;
    VlTriggerScheduler __VtrigSched_hc3524bf7__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_coe__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_coe___024root(Vtb_coe__Syms* symsp, const char* v__name);
    ~Vtb_coe___024root();
    VL_UNCOPYABLE(Vtb_coe___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
