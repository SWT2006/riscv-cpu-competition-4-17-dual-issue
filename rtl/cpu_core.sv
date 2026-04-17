`timescale 1ns/1ps
// 2-wide superscalar in-order pipelined RV32IM CPU core.
//
// Pipeline:  IF(2) → ID(2) → EX(2-pipe) → MEM(shared) → WB(2)
//
// Pipe A: Full ALU, branch, mul/div, CSR, ECALL/MRET, load/store.
// Pipe B: Simple ALU, load/store.
//
// Interface matches the fixed top-level contract, with an additional
// irom_data_1 port for 2-wide instruction fetch.
module cpu_core (
    input  wire        cpu_clk,
    input  wire        cpu_rst,
    // IROM — 2-wide fetch
    output wire [31:0] irom_addr,
    input  wire [31:0] irom_data_0,    // instruction at PC
    input  wire [31:0] irom_data_1,    // instruction at PC+4
    // Peripheral bus (DRAM + MMIO via perip_bridge)
    output wire [31:0] perip_addr,
    output wire        perip_wen,
    output wire [1:0]  perip_mask,
    output wire [31:0] perip_wdata,
    input  wire [31:0] perip_rdata
);

    // =================================================================
    // IF outputs
    // =================================================================
    wire [31:0] if_pc_a, if_pc_a_plus4, if_pc_b, if_pc_b_plus4;
    wire [31:0] if_inst_a, if_inst_b;
    wire        if_b_valid;
    wire        if_predicted_a;
    wire [31:0] if_predicted_target_a;
    wire        if_predicted_b;
    wire [31:0] if_predicted_target_b;

    // =================================================================
    // IF/ID register outputs
    // =================================================================
    wire [31:0] ifid_pc_a, ifid_pc_a_plus4, ifid_inst_a;
    wire        ifid_predicted_a;
    wire [31:0] ifid_predicted_target_a;
    wire [31:0] ifid_pc_b, ifid_pc_b_plus4, ifid_inst_b;
    wire        ifid_b_valid;
    wire        ifid_predicted_b;
    wire [31:0] ifid_predicted_target_b;

    // =================================================================
    // ID outputs
    // =================================================================
    // Slot A
    wire [31:0] id_a_rs1_data, id_a_rs2_data, id_a_imm, id_a_csr_rdata;
    wire [4:0]  id_a_rs1_addr, id_a_rs2_addr, id_a_rd_addr, id_a_alu_op;
    wire [2:0]  id_a_mem_funct3;
    wire [11:0] id_a_csr_addr;
    wire        id_a_alu_src, id_a_mem_read, id_a_mem_write, id_a_reg_write;
    wire [1:0]  id_a_wb_sel;
    wire        id_a_branch, id_a_jal, id_a_jalr, id_a_auipc;
    wire        id_a_ecall, id_a_mret, id_a_csr_op;
    // Slot B
    wire [31:0] id_b_rs1_data, id_b_rs2_data, id_b_imm;
    wire [4:0]  id_b_rs1_addr, id_b_rs2_addr, id_b_rd_addr, id_b_alu_op;
    wire [2:0]  id_b_mem_funct3;
    wire        id_b_alu_src, id_b_mem_read, id_b_mem_write, id_b_reg_write;
    wire [1:0]  id_b_wb_sel;
    wire        id_b_branch, id_b_jal, id_b_jalr, id_b_auipc;
    wire        id_b_ecall, id_b_mret, id_b_csr_op;

    // =================================================================
    // ID/EX register outputs
    // =================================================================
    // Slot A
    wire [31:0] idex_a_pc, idex_a_pc_plus4;
    wire [31:0] idex_a_rs1_data, idex_a_rs2_data, idex_a_imm;
    wire [4:0]  idex_a_rs1_addr, idex_a_rs2_addr, idex_a_rd_addr, idex_a_alu_op;
    wire [2:0]  idex_a_mem_funct3, idex_a_funct3;
    wire [11:0] idex_a_csr_addr;
    wire [31:0] idex_a_csr_rdata;
    wire        idex_a_alu_src, idex_a_mem_read, idex_a_mem_write, idex_a_reg_write;
    wire [1:0]  idex_a_wb_sel;
    wire        idex_a_branch, idex_a_jal, idex_a_jalr, idex_a_auipc;
    wire        idex_a_ecall, idex_a_mret, idex_a_csr_op;
    wire        idex_a_predicted;
    wire [31:0] idex_a_predicted_target;
    // Slot B
    wire        idex_b_valid;
    wire [31:0] idex_b_pc, idex_b_pc_plus4;
    wire [31:0] idex_b_rs1_data, idex_b_rs2_data, idex_b_imm;
    wire [4:0]  idex_b_rs1_addr, idex_b_rs2_addr, idex_b_rd_addr, idex_b_alu_op;
    wire [2:0]  idex_b_mem_funct3;
    wire        idex_b_alu_src, idex_b_mem_read, idex_b_mem_write, idex_b_reg_write;
    wire [1:0]  idex_b_wb_sel;
    wire        idex_b_auipc;

    // =================================================================
    // EX outputs
    // =================================================================
    wire [31:0] ex_a_alu_result, ex_a_rs2_data_fwd;
    wire        ex_a_branch_taken;
    wire [31:0] ex_a_branch_target;
    wire        ex_a_trap_valid;
    wire [31:0] ex_a_trap_epc, ex_a_trap_mcause;
    wire        ex_a_csr_wen;
    wire [11:0] ex_a_csr_waddr;
    wire [31:0] ex_a_csr_wdata;
    wire        div_stall, mul_stall;
    wire [31:0] ex_b_alu_result, ex_b_rs2_data_fwd;

    // =================================================================
    // EX/MEM register outputs
    // =================================================================
    // Pipe A
    wire [31:0] exmem_a_pc_plus4, exmem_a_alu_result, exmem_a_rs2_data;
    wire [4:0]  exmem_a_rd_addr;
    wire [2:0]  exmem_a_mem_funct3;
    wire        exmem_a_mem_read, exmem_a_mem_write, exmem_a_reg_write;
    wire [1:0]  exmem_a_wb_sel;
    wire [31:0] exmem_a_fwd_data;
    // Pipe B
    wire        exmem_b_valid;
    wire [31:0] exmem_b_pc_plus4, exmem_b_alu_result, exmem_b_rs2_data;
    wire [4:0]  exmem_b_rd_addr;
    wire [2:0]  exmem_b_mem_funct3;
    wire        exmem_b_mem_read, exmem_b_mem_write, exmem_b_reg_write;
    wire [1:0]  exmem_b_wb_sel;
    wire [31:0] exmem_b_fwd_data;

    // =================================================================
    // MEM outputs
    // =================================================================
    wire [31:0] mem_read_data_a, mem_read_data_b;

    // =================================================================
    // MEM/WB register outputs
    // =================================================================
    wire [4:0]  memwb_a_rd_addr;
    wire        memwb_a_reg_write;
    wire [31:0] memwb_a_write_data;
    wire        memwb_b_valid;
    wire [4:0]  memwb_b_rd_addr;
    wire        memwb_b_reg_write;
    wire [31:0] memwb_b_write_data;

    // =================================================================
    // Forwarding & hazard signals
    // =================================================================
    wire        hz_stall;
    wire [2:0]  fwd_a_rs1, fwd_a_rs2, fwd_b_rs1, fwd_b_rs2;

    // CSR interface
    wire [31:0] csr_mtvec, csr_mepc;
    wire [31:0] id_a_csr_rdata_raw;

    // =================================================================
    // Pipeline control
    // =================================================================
    wire ex_stall       = div_stall | mul_stall;
    wire pipeline_stall = hz_stall | ex_stall;

    // -----------------------------------------------------------------
    // Mispredict detection (Pipe A only — slot B never has branches)
    // -----------------------------------------------------------------
    wire direction_mismatch = ex_a_branch_taken ^ idex_a_predicted;
    wire target_mismatch    = idex_a_predicted & ex_a_branch_taken & idex_a_jalr
                            & (ex_a_branch_target != idex_a_predicted_target);
    wire ex_redirect        = direction_mismatch | target_mismatch;

    wire [31:0] ex_redirect_target = (idex_a_predicted & ~ex_a_branch_taken)
                                   ? idex_a_pc_plus4 : ex_a_branch_target;

    wire flush = ex_redirect;

    // =================================================================
    // Stage 1: IF (2-wide fetch)
    // =================================================================
    stage_if u_if (
        .clk              (cpu_clk),
        .cpu_rst          (cpu_rst),
        .stall            (pipeline_stall),
        .branch_taken     (ex_redirect),
        .branch_target    (ex_redirect_target),
        .irom_addr        (irom_addr),
        .irom_data_0      (irom_data_0),
        .irom_data_1      (irom_data_1),
        .pc_out           (if_pc_a),
        .pc_a_plus4       (if_pc_a_plus4),
        .pc_b             (if_pc_b),
        .pc_b_plus4       (if_pc_b_plus4),
        .inst_a           (if_inst_a),
        .inst_b           (if_inst_b),
        .b_valid          (if_b_valid),
        .predicted_a      (if_predicted_a),
        .predicted_target_a(if_predicted_target_a),
        .predicted_b      (if_predicted_b),
        .predicted_target_b(if_predicted_target_b)
    );

    // =================================================================
    // IF/ID register
    // =================================================================
    pipe_ifid u_pipe_ifid (
        .clk                    (cpu_clk),
        .cpu_rst                (cpu_rst),
        .stall                  (pipeline_stall),
        .flush                  (flush),
        .if_pc_a                (if_pc_a),
        .if_pc_a_plus4          (if_pc_a_plus4),
        .if_inst_a              (if_inst_a),
        .if_predicted_a         (if_predicted_a),
        .if_predicted_target_a  (if_predicted_target_a),
        .if_pc_b                (if_pc_b),
        .if_pc_b_plus4          (if_pc_b_plus4),
        .if_inst_b              (if_inst_b),
        .if_b_valid             (if_b_valid),
        .if_predicted_b         (if_predicted_b),
        .if_predicted_target_b  (if_predicted_target_b),
        .ifid_pc_a              (ifid_pc_a),
        .ifid_pc_a_plus4        (ifid_pc_a_plus4),
        .ifid_inst_a            (ifid_inst_a),
        .ifid_predicted_a       (ifid_predicted_a),
        .ifid_predicted_target_a(ifid_predicted_target_a),
        .ifid_pc_b              (ifid_pc_b),
        .ifid_pc_b_plus4        (ifid_pc_b_plus4),
        .ifid_inst_b            (ifid_inst_b),
        .ifid_b_valid           (ifid_b_valid),
        .ifid_predicted_b       (ifid_predicted_b),
        .ifid_predicted_target_b(ifid_predicted_target_b)
    );

    // =================================================================
    // CSR unit
    // =================================================================
    csr_unit u_csr (
        .clk         (cpu_clk),
        .cpu_rst     (cpu_rst),
        .csr_raddr   (ifid_inst_a[31:20]),
        .csr_rdata   (id_a_csr_rdata_raw),
        .csr_wen     (ex_a_csr_wen),
        .csr_waddr   (ex_a_csr_waddr),
        .csr_wdata   (ex_a_csr_wdata),
        .trap_valid  (ex_a_trap_valid),
        .trap_epc    (ex_a_trap_epc),
        .trap_mcause (ex_a_trap_mcause),
        .mtvec       (csr_mtvec),
        .mepc        (csr_mepc)
    );

    // CSR EX→ID forwarding (slot A only)
    wire [31:0] id_a_csr_rdata_fwd =
        (ex_a_csr_wen && (ex_a_csr_waddr == ifid_inst_a[31:20]))
            ? ex_a_csr_wdata
            : id_a_csr_rdata_raw;

    // =================================================================
    // Stage 2: ID (2-wide decode)
    // =================================================================
    stage_id u_stage_id (
        .clk            (cpu_clk),
        .cpu_rst        (cpu_rst),
        .inst_a         (ifid_inst_a),
        .inst_b         (ifid_inst_b),
        .b_valid        (ifid_b_valid),
        .wb_reg_write_a (memwb_a_reg_write),
        .wb_rd_addr_a   (memwb_a_rd_addr),
        .wb_write_data_a(memwb_a_write_data),
        .wb_reg_write_b (memwb_b_reg_write),
        .wb_rd_addr_b   (memwb_b_rd_addr),
        .wb_write_data_b(memwb_b_write_data),
        .csr_rdata      (id_a_csr_rdata_fwd),
        // Slot A outputs
        .a_rs1_data     (id_a_rs1_data),
        .a_rs2_data     (id_a_rs2_data),
        .a_imm          (id_a_imm),
        .a_rs1_addr     (id_a_rs1_addr),
        .a_rs2_addr     (id_a_rs2_addr),
        .a_rd_addr      (id_a_rd_addr),
        .a_csr_addr     (id_a_csr_addr),
        .a_csr_rdata_out(id_a_csr_rdata),
        .a_alu_op       (id_a_alu_op),
        .a_alu_src      (id_a_alu_src),
        .a_mem_read     (id_a_mem_read),
        .a_mem_write    (id_a_mem_write),
        .a_mem_funct3   (id_a_mem_funct3),
        .a_reg_write    (id_a_reg_write),
        .a_wb_sel       (id_a_wb_sel),
        .a_branch       (id_a_branch),
        .a_jal          (id_a_jal),
        .a_jalr         (id_a_jalr),
        .a_auipc        (id_a_auipc),
        .a_ecall        (id_a_ecall),
        .a_mret         (id_a_mret),
        .a_csr_op       (id_a_csr_op),
        // Slot B outputs
        .b_rs1_data     (id_b_rs1_data),
        .b_rs2_data     (id_b_rs2_data),
        .b_imm          (id_b_imm),
        .b_rs1_addr     (id_b_rs1_addr),
        .b_rs2_addr     (id_b_rs2_addr),
        .b_rd_addr      (id_b_rd_addr),
        .b_alu_op       (id_b_alu_op),
        .b_alu_src      (id_b_alu_src),
        .b_mem_read     (id_b_mem_read),
        .b_mem_write    (id_b_mem_write),
        .b_mem_funct3   (id_b_mem_funct3),
        .b_reg_write    (id_b_reg_write),
        .b_wb_sel       (id_b_wb_sel),
        .b_branch       (id_b_branch),
        .b_jal          (id_b_jal),
        .b_jalr         (id_b_jalr),
        .b_auipc        (id_b_auipc),
        .b_ecall        (id_b_ecall),
        .b_mret         (id_b_mret),
        .b_csr_op       (id_b_csr_op)
    );

    // =================================================================
    // Hazard detection
    // =================================================================
    hazard_unit u_hazard (
        .idex_a_mem_read  (idex_a_mem_read),
        .idex_a_rd_addr   (idex_a_rd_addr),
        .idex_b_valid     (idex_b_valid),
        .idex_b_mem_read  (idex_b_mem_read),
        .idex_b_rd_addr   (idex_b_rd_addr),
        .ifid_a_rs1_addr  (ifid_inst_a[19:15]),
        .ifid_a_rs2_addr  (ifid_inst_a[24:20]),
        .ifid_b_valid     (ifid_b_valid),
        .ifid_b_rs1_addr  (ifid_inst_b[19:15]),
        .ifid_b_rs2_addr  (ifid_inst_b[24:20]),
        .stall            (hz_stall)
    );

    // =================================================================
    // ID/EX register
    // =================================================================
    pipe_idex u_pipe_idex (
        .clk              (cpu_clk),
        .cpu_rst          (cpu_rst),
        .flush            (hz_stall | flush),
        .hold             (ex_stall),
        // Slot A
        .id_a_pc          (ifid_pc_a),
        .id_a_pc_plus4    (ifid_pc_a_plus4),
        .id_a_rs1_data    (id_a_rs1_data),
        .id_a_rs2_data    (id_a_rs2_data),
        .id_a_imm         (id_a_imm),
        .id_a_rs1_addr    (id_a_rs1_addr),
        .id_a_rs2_addr    (id_a_rs2_addr),
        .id_a_rd_addr     (id_a_rd_addr),
        .id_a_alu_op      (id_a_alu_op),
        .id_a_alu_src     (id_a_alu_src),
        .id_a_mem_read    (id_a_mem_read),
        .id_a_mem_write   (id_a_mem_write),
        .id_a_mem_funct3  (id_a_mem_funct3),
        .id_a_reg_write   (id_a_reg_write),
        .id_a_wb_sel      (id_a_wb_sel),
        .id_a_branch      (id_a_branch),
        .id_a_jal         (id_a_jal),
        .id_a_jalr        (id_a_jalr),
        .id_a_auipc       (id_a_auipc),
        .id_a_funct3      (ifid_inst_a[14:12]),
        .id_a_ecall       (id_a_ecall),
        .id_a_mret        (id_a_mret),
        .id_a_csr_op      (id_a_csr_op),
        .id_a_csr_rdata   (id_a_csr_rdata),
        .id_a_csr_addr    (id_a_csr_addr),
        .id_a_predicted        (ifid_predicted_a),
        .id_a_predicted_target (ifid_predicted_target_a),
        // Slot B
        .id_b_valid       (ifid_b_valid),
        .id_b_pc          (ifid_pc_b),
        .id_b_pc_plus4    (ifid_pc_b_plus4),
        .id_b_rs1_data    (id_b_rs1_data),
        .id_b_rs2_data    (id_b_rs2_data),
        .id_b_imm         (id_b_imm),
        .id_b_rs1_addr    (id_b_rs1_addr),
        .id_b_rs2_addr    (id_b_rs2_addr),
        .id_b_rd_addr     (id_b_rd_addr),
        .id_b_alu_op      (id_b_alu_op),
        .id_b_alu_src     (id_b_alu_src),
        .id_b_mem_read    (id_b_mem_read),
        .id_b_mem_write   (id_b_mem_write),
        .id_b_mem_funct3  (id_b_mem_funct3),
        .id_b_reg_write   (id_b_reg_write),
        .id_b_wb_sel      (id_b_wb_sel),
        .id_b_auipc       (id_b_auipc),
        // Slot A outputs
        .idex_a_pc             (idex_a_pc),
        .idex_a_pc_plus4       (idex_a_pc_plus4),
        .idex_a_rs1_data       (idex_a_rs1_data),
        .idex_a_rs2_data       (idex_a_rs2_data),
        .idex_a_imm            (idex_a_imm),
        .idex_a_rs1_addr       (idex_a_rs1_addr),
        .idex_a_rs2_addr       (idex_a_rs2_addr),
        .idex_a_rd_addr        (idex_a_rd_addr),
        .idex_a_alu_op         (idex_a_alu_op),
        .idex_a_alu_src        (idex_a_alu_src),
        .idex_a_mem_read       (idex_a_mem_read),
        .idex_a_mem_write      (idex_a_mem_write),
        .idex_a_mem_funct3     (idex_a_mem_funct3),
        .idex_a_reg_write      (idex_a_reg_write),
        .idex_a_wb_sel         (idex_a_wb_sel),
        .idex_a_branch         (idex_a_branch),
        .idex_a_jal            (idex_a_jal),
        .idex_a_jalr           (idex_a_jalr),
        .idex_a_auipc          (idex_a_auipc),
        .idex_a_funct3         (idex_a_funct3),
        .idex_a_ecall          (idex_a_ecall),
        .idex_a_mret           (idex_a_mret),
        .idex_a_csr_op         (idex_a_csr_op),
        .idex_a_csr_rdata      (idex_a_csr_rdata),
        .idex_a_csr_addr       (idex_a_csr_addr),
        .idex_a_predicted      (idex_a_predicted),
        .idex_a_predicted_target(idex_a_predicted_target),
        // Slot B outputs
        .idex_b_valid          (idex_b_valid),
        .idex_b_pc             (idex_b_pc),
        .idex_b_pc_plus4       (idex_b_pc_plus4),
        .idex_b_rs1_data       (idex_b_rs1_data),
        .idex_b_rs2_data       (idex_b_rs2_data),
        .idex_b_imm            (idex_b_imm),
        .idex_b_rs1_addr       (idex_b_rs1_addr),
        .idex_b_rs2_addr       (idex_b_rs2_addr),
        .idex_b_rd_addr        (idex_b_rd_addr),
        .idex_b_alu_op         (idex_b_alu_op),
        .idex_b_alu_src        (idex_b_alu_src),
        .idex_b_mem_read       (idex_b_mem_read),
        .idex_b_mem_write      (idex_b_mem_write),
        .idex_b_mem_funct3     (idex_b_mem_funct3),
        .idex_b_reg_write      (idex_b_reg_write),
        .idex_b_wb_sel         (idex_b_wb_sel),
        .idex_b_auipc          (idex_b_auipc)
    );

    // =================================================================
    // Forwarding unit
    // =================================================================
    forwarding_unit u_fwd (
        .idex_a_rs1_addr  (idex_a_rs1_addr),
        .idex_a_rs2_addr  (idex_a_rs2_addr),
        .idex_b_rs1_addr  (idex_b_rs1_addr),
        .idex_b_rs2_addr  (idex_b_rs2_addr),
        .idex_b_valid     (idex_b_valid),
        .exmem_a_rd_addr  (exmem_a_rd_addr),
        .exmem_a_reg_write(exmem_a_reg_write),
        .exmem_b_rd_addr  (exmem_b_rd_addr),
        .exmem_b_reg_write(exmem_b_reg_write),
        .exmem_b_valid    (exmem_b_valid),
        .memwb_a_rd_addr  (memwb_a_rd_addr),
        .memwb_a_reg_write(memwb_a_reg_write),
        .memwb_b_rd_addr  (memwb_b_rd_addr),
        .memwb_b_reg_write(memwb_b_reg_write),
        .memwb_b_valid    (memwb_b_valid),
        .fwd_a_rs1        (fwd_a_rs1),
        .fwd_a_rs2        (fwd_a_rs2),
        .fwd_b_rs1        (fwd_b_rs1),
        .fwd_b_rs2        (fwd_b_rs2)
    );

    // =================================================================
    // Stage 3: EX (dual pipes)
    // =================================================================
    stage_ex u_ex (
        .clk               (cpu_clk),
        .cpu_rst           (cpu_rst),
        // Pipe A
        .idex_a_pc         (idex_a_pc),
        .idex_a_pc_plus4   (idex_a_pc_plus4),
        .idex_a_rs1_data   (idex_a_rs1_data),
        .idex_a_rs2_data   (idex_a_rs2_data),
        .idex_a_imm        (idex_a_imm),
        .idex_a_rs1_addr   (idex_a_rs1_addr),
        .idex_a_rs2_addr   (idex_a_rs2_addr),
        .idex_a_alu_op     (idex_a_alu_op),
        .idex_a_alu_src    (idex_a_alu_src),
        .idex_a_branch     (idex_a_branch),
        .idex_a_jal        (idex_a_jal),
        .idex_a_jalr       (idex_a_jalr),
        .idex_a_auipc      (idex_a_auipc),
        .idex_a_funct3     (idex_a_funct3),
        .idex_a_ecall      (idex_a_ecall),
        .idex_a_mret       (idex_a_mret),
        .idex_a_csr_op     (idex_a_csr_op),
        .idex_a_csr_rdata  (idex_a_csr_rdata),
        .idex_a_csr_addr   (idex_a_csr_addr),
        .csr_mtvec         (csr_mtvec),
        .csr_mepc          (csr_mepc),
        // Pipe B
        .idex_b_valid      (idex_b_valid),
        .idex_b_pc         (idex_b_pc),
        .idex_b_rs1_data   (idex_b_rs1_data),
        .idex_b_rs2_data   (idex_b_rs2_data),
        .idex_b_imm        (idex_b_imm),
        .idex_b_alu_op     (idex_b_alu_op),
        .idex_b_alu_src    (idex_b_alu_src),
        .idex_b_auipc      (idex_b_auipc),
        // Intra-group A→B forwarding
        .idex_a_rd_addr    (idex_a_rd_addr),
        .idex_a_reg_write  (idex_a_reg_write),
        .idex_b_rs1_addr   (idex_b_rs1_addr),
        .idex_b_rs2_addr   (idex_b_rs2_addr),
        // Forwarding
        .fwd_a_rs1         (fwd_a_rs1),
        .fwd_a_rs2         (fwd_a_rs2),
        .fwd_b_rs1         (fwd_b_rs1),
        .fwd_b_rs2         (fwd_b_rs2),
        .exmem_a_fwd_data  (exmem_a_fwd_data),
        .exmem_b_fwd_data  (exmem_b_fwd_data),
        .memwb_a_write_data(memwb_a_write_data),
        .memwb_b_write_data(memwb_b_write_data),
        // Pipe A outputs
        .a_alu_result      (ex_a_alu_result),
        .a_rs2_data_fwd    (ex_a_rs2_data_fwd),
        .a_branch_taken    (ex_a_branch_taken),
        .a_branch_target   (ex_a_branch_target),
        .a_trap_valid      (ex_a_trap_valid),
        .a_trap_epc        (ex_a_trap_epc),
        .a_trap_mcause     (ex_a_trap_mcause),
        .a_csr_wen         (ex_a_csr_wen),
        .a_csr_waddr       (ex_a_csr_waddr),
        .a_csr_wdata       (ex_a_csr_wdata),
        .div_stall         (div_stall),
        .mul_stall         (mul_stall),
        // Pipe B outputs
        .b_alu_result      (ex_b_alu_result),
        .b_rs2_data_fwd    (ex_b_rs2_data_fwd)
    );

    // =================================================================
    // EX/MEM register
    // =================================================================
    pipe_exmem u_pipe_exmem (
        .clk               (cpu_clk),
        .cpu_rst           (cpu_rst),
        .flush_all         (ex_stall),
        .flush_b           (flush),
        // Pipe A
        .ex_a_pc_plus4     (idex_a_pc_plus4),
        .ex_a_alu_result   (ex_a_alu_result),
        .ex_a_rs2_data     (ex_a_rs2_data_fwd),
        .ex_a_rd_addr      (idex_a_rd_addr),
        .ex_a_mem_read     (idex_a_mem_read),
        .ex_a_mem_write    (idex_a_mem_write),
        .ex_a_mem_funct3   (idex_a_mem_funct3),
        .ex_a_reg_write    (idex_a_reg_write),
        .ex_a_wb_sel       (idex_a_wb_sel),
        // Pipe B
        .ex_b_valid        (idex_b_valid),
        .ex_b_pc_plus4     (idex_b_pc_plus4),
        .ex_b_alu_result   (ex_b_alu_result),
        .ex_b_rs2_data     (ex_b_rs2_data_fwd),
        .ex_b_rd_addr      (idex_b_rd_addr),
        .ex_b_mem_read     (idex_b_mem_read),
        .ex_b_mem_write    (idex_b_mem_write),
        .ex_b_mem_funct3   (idex_b_mem_funct3),
        .ex_b_reg_write    (idex_b_reg_write),
        .ex_b_wb_sel       (idex_b_wb_sel),
        // Outputs
        .exmem_a_pc_plus4  (exmem_a_pc_plus4),
        .exmem_a_alu_result(exmem_a_alu_result),
        .exmem_a_rs2_data  (exmem_a_rs2_data),
        .exmem_a_rd_addr   (exmem_a_rd_addr),
        .exmem_a_mem_read  (exmem_a_mem_read),
        .exmem_a_mem_write (exmem_a_mem_write),
        .exmem_a_mem_funct3(exmem_a_mem_funct3),
        .exmem_a_reg_write (exmem_a_reg_write),
        .exmem_a_wb_sel    (exmem_a_wb_sel),
        .exmem_a_fwd_data  (exmem_a_fwd_data),
        .exmem_b_valid     (exmem_b_valid),
        .exmem_b_pc_plus4  (exmem_b_pc_plus4),
        .exmem_b_alu_result(exmem_b_alu_result),
        .exmem_b_rs2_data  (exmem_b_rs2_data),
        .exmem_b_rd_addr   (exmem_b_rd_addr),
        .exmem_b_mem_read  (exmem_b_mem_read),
        .exmem_b_mem_write (exmem_b_mem_write),
        .exmem_b_mem_funct3(exmem_b_mem_funct3),
        .exmem_b_reg_write (exmem_b_reg_write),
        .exmem_b_wb_sel    (exmem_b_wb_sel),
        .exmem_b_fwd_data  (exmem_b_fwd_data)
    );

    // =================================================================
    // Stage 4: MEM (shared memory port)
    // =================================================================
    stage_mem u_mem (
        .exmem_a_alu_result (exmem_a_alu_result),
        .exmem_a_rs2_data   (exmem_a_rs2_data),
        .exmem_a_mem_read   (exmem_a_mem_read),
        .exmem_a_mem_write  (exmem_a_mem_write),
        .exmem_a_mem_funct3 (exmem_a_mem_funct3),
        .exmem_b_valid      (exmem_b_valid),
        .exmem_b_alu_result (exmem_b_alu_result),
        .exmem_b_rs2_data   (exmem_b_rs2_data),
        .exmem_b_mem_read   (exmem_b_mem_read),
        .exmem_b_mem_write  (exmem_b_mem_write),
        .exmem_b_mem_funct3 (exmem_b_mem_funct3),
        .perip_addr         (perip_addr),
        .perip_wen          (perip_wen),
        .perip_mask         (perip_mask),
        .perip_wdata        (perip_wdata),
        .perip_rdata        (perip_rdata),
        .mem_read_data_a    (mem_read_data_a),
        .mem_read_data_b    (mem_read_data_b)
    );

    // =================================================================
    // MEM/WB register
    // =================================================================
    pipe_memwb u_pipe_memwb (
        .clk               (cpu_clk),
        .cpu_rst           (cpu_rst),
        // Pipe A
        .mem_a_pc_plus4    (exmem_a_pc_plus4),
        .mem_a_alu_result  (exmem_a_alu_result),
        .mem_a_read_data   (mem_read_data_a),
        .mem_a_rd_addr     (exmem_a_rd_addr),
        .mem_a_reg_write   (exmem_a_reg_write),
        .mem_a_wb_sel      (exmem_a_wb_sel),
        // Pipe B
        .mem_b_valid       (exmem_b_valid),
        .mem_b_pc_plus4    (exmem_b_pc_plus4),
        .mem_b_alu_result  (exmem_b_alu_result),
        .mem_b_read_data   (mem_read_data_b),
        .mem_b_rd_addr     (exmem_b_rd_addr),
        .mem_b_reg_write   (exmem_b_reg_write),
        .mem_b_wb_sel      (exmem_b_wb_sel),
        // Outputs
        .memwb_a_rd_addr   (memwb_a_rd_addr),
        .memwb_a_reg_write (memwb_a_reg_write),
        .memwb_a_write_data(memwb_a_write_data),
        .memwb_b_valid     (memwb_b_valid),
        .memwb_b_rd_addr   (memwb_b_rd_addr),
        .memwb_b_reg_write (memwb_b_reg_write),
        .memwb_b_write_data(memwb_b_write_data)
    );

    // =================================================================
    // Stage 5: WB — pre-computed in pipe_memwb.
    // Register file writes happen in stage_id (2 write ports).
    // =================================================================

endmodule
