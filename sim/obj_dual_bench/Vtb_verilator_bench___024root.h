// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_verilator_bench.h for the primary calling header

#ifndef VERILATED_VTB_VERILATOR_BENCH___024ROOT_H_
#define VERILATED_VTB_VERILATOR_BENCH___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_verilator_bench__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_verilator_bench___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_verilator_bench__DOT__clk;
        CData/*0:0*/ tb_verilator_bench__DOT__rst_n;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__perip_mask;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_sel;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_a;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_b_valid;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_op;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_alu_src;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_read;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mem_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_reg_write;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_wb_sel;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_branch;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jal;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_jalr;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_auipc;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_ecall;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_mret;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_csr_op;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_op;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_alu_src;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_read;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_mem_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_reg_write;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_wb_sel;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_auipc;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_addr;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_addr;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rd_addr;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_op;
        CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_funct3;
        CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_funct3;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_alu_src;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_read;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mem_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_reg_write;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_wb_sel;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_branch;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jal;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_jalr;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_auipc;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_ecall;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_mret;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_op;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_valid;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_addr;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_addr;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rd_addr;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_op;
        CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_funct3;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_alu_src;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_read;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_mem_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_reg_write;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_wb_sel;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_auipc;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_taken;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rd_addr;
        CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_funct3;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_read;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_mem_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_reg_write;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_wb_sel;
    };
    struct {
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_valid;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rd_addr;
        CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_funct3;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_read;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_mem_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_reg_write;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_wb_sel;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_rd_addr;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_reg_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_valid;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_rd_addr;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_reg_write;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_stall;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__pipeline_stall;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_redirect;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT____Vcellinp__u_pipe_idex__flush;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_call;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__is_return;
        CData/*2:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras_ptr;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__predict_a;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__can_dual_final;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT____VdfgRegularize_h3bde6552_0_0;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_b_sign;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_start;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_signed;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__div_op_rem;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__is_mul_op;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_valid;
        CData/*1:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__state;
        CData/*4:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__count;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_q;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__sign_r;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__is_rem;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__a_is_mem;
        CData/*0:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__b_is_mem;
        CData/*2:0*/ __Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__funct3;
        CData/*2:0*/ __Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__funct3;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_verilator_bench__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_addr;
        IData/*31:0*/ tb_verilator_bench__DOT__stable_count;
        IData/*31:0*/ tb_verilator_bench__DOT__prev_pc;
        IData/*31:0*/ tb_verilator_bench__DOT__prev2_pc;
        IData/*31:0*/ tb_verilator_bench__DOT__prev3_pc;
        IData/*31:0*/ tb_verilator_bench__DOT__dump_regs__Vstatic__rv;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__perip_addr;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__perip_wdata;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__dram_wdata;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_pc_a;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__if_predicted_target_a;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_a_plus4;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_a;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_predicted_target_a;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_pc_b_plus4;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ifid_inst_b;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_a_imm;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__id_b_imm;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_pc_plus4;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs1_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_rs2_data;
    };
    struct {
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_imm;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_csr_rdata;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_a_predicted_target;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_pc_plus4;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs1_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_rs2_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__idex_b_imm;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_alu_result;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_a_branch_target;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__ex_b_rs2_data_fwd;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_pc_plus4;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_alu_result;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_rs2_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_a_fwd_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_pc_plus4;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_alu_result;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_rs2_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__exmem_b_fwd_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_a;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__mem_read_data_b;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_a_write_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__memwb_b_write_data;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mtvec;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__csr_mepc;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mcause;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mstatus;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mtval;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_csr__DOT__mscratch;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_ha9063eb7__0;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT____Vlvbound_h7b474f3b__0;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__fwd_a2;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_a;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_alu_b;
        VlWide<3>/*65:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__mul_result_r;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__a_csr_wd;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__b_alu_out;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__quo;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__rem;
        IData/*31:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__div_reg;
        IData/*31:0*/ __Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__Vfuncout;
        IData/*31:0*/ __Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__2__rdata;
        IData/*31:0*/ __Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__Vfuncout;
        IData/*31:0*/ __Vfunc_tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_mem__DOT__sign_extend__3__rdata;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_verilator_bench__DOT__cycle_count;
        QData/*63:0*/ tb_verilator_bench__DOT__dual_issue_count;
        QData/*32:0*/ tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_ex__DOT__u_div__DOT__trial;
        VlUnpacked<IData/*31:0*/, 4096> tb_verilator_bench__DOT__u_soc__DOT__imem;
        VlUnpacked<IData/*31:0*/, 65536> tb_verilator_bench__DOT__u_soc__DOT__dmem;
        VlUnpacked<IData/*31:0*/, 8> tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_if__DOT__ras;
        VlUnpacked<IData/*31:0*/, 31> tb_verilator_bench__DOT__u_soc__DOT__u_cpu__DOT__u_stage_id__DOT__regfile;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_verilator_bench__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_verilator_bench___024root(Vtb_verilator_bench__Syms* symsp, const char* v__name);
    ~Vtb_verilator_bench___024root();
    VL_UNCOPYABLE(Vtb_verilator_bench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
