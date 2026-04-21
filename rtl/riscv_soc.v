// =============================================================================
// riscv_soc.v  –  Simulation-only SoC wrapper for the ISA regression tests.
//
// Provides the module hierarchy expected by tb/tinyriscv_soc_tb.v:
//   u_soc.u_imem.mem[]          – instruction memory (word-addressed, 8 K words)
//   u_soc.u_dmem.mem[]          – data memory      (word-addressed, 8 K words)
//   u_soc.u_cpu.u_stage_id.regfile[] – register file inside the pipeline
//
// Memory map (ISA test flat binary loaded at word 0):
//   Instruction fetch : irom_addr[14:2] (= pc[14:2]) indexes u_imem.mem
//   Data load/store   : byte_addr[14:2] indexes u_dmem.mem
//
// To support fence_i (self-modifying code), data stores are mirrored into
// u_imem.mem as well, so the CPU always fetches the latest value.
//
// The testbench loads the same flat binary into both arrays via:
//   $readmemh("inst.data", u_soc.u_imem.mem);
//   $readmemh("inst.data", u_soc.u_dmem.mem);
// =============================================================================
`timescale 1ns/1ps

// ---------------------------------------------------------------------------
// Instruction memory – combinatorial read, optional write port for fence.i.
// Instance name must be u_imem; array name must be mem[].
// ---------------------------------------------------------------------------
module sim_imem (
    input  wire        clk,
    input  wire [12:0] raddr,   // word address (combinational next-fetch from stage_if)
    output reg  [31:0] rdata_0, // instruction at captured address (slot A)
    output reg  [31:0] rdata_1, // instruction at captured address+1 (slot B)
    // Write port (mirrors data stores so self-modifying code works)
    input  wire        wen,
    input  wire [12:0] waddr,
    input  wire [31:0] wdata_w, // full-word merged value to write
    input  wire        wword    // 1 = perform the write this cycle
);
    reg [31:0] mem [0:8191];   // 8192 words = 32 KB

    // Posedge-registered read — matches irom_driver BRAM behaviour.
    // irom_addr is a combinational next-fetch address from stage_if;
    // the register here breaks the loop and provides the instruction
    // after clk-to-out, consistent with synthesis.
    always @(posedge clk) begin
        rdata_0 <= mem[raddr];
        rdata_1 <= mem[raddr + 13'd1];
    end

    always @(posedge clk) begin
        if (wen && wword)
            mem[waddr] <= wdata_w;
    end
endmodule

// ---------------------------------------------------------------------------
// Data memory – byte-enable write, combinatorial read.
// Instance name must be u_dmem; array name must be mem[].
// Byte offset: addr[1:0], word addr: addr[14:2]
// ---------------------------------------------------------------------------
module sim_dmem (
    input  wire        clk,
    input  wire [31:0] byte_addr,
    input  wire [31:0] wdata,
    input  wire        wen,
    input  wire [1:0]  mask,    // 00=byte, 01=halfword, 10=word
    input  wire [12:0] raddr_early, // early read word-address from EX stage
    output wire [31:0] rdata,
    // Expose merged write value and word address so sim_imem can mirror
    output wire [12:0] waddr_out,
    output wire [31:0] merged_out,
    output wire        wword_out  // high when a full merged word was written
);
    reg [31:0] mem [0:8191];   // 8192 words = 32 KB

    wire [12:0] word_addr = byte_addr[14:2];
    wire [1:0]  offset    = byte_addr[1:0];

    // Posedge-registered read using early address from EX stage
    reg [31:0] rdata_raw;
    always @(posedge clk) begin
        rdata_raw <= mem[raddr_early];
    end

    // Store-load bypass: when write and read hit the same word at the same
    // posedge, forward the written value.
    reg         bypass_hit;
    reg  [31:0] bypass_merged;
    always @(posedge clk) begin
        bypass_hit    <= wen & (word_addr == raddr_early);
        bypass_merged <= merged;
    end

    wire [31:0] rdata_resolved = bypass_hit ? bypass_merged : rdata_raw;

    // Byte/halfword extraction (combinatorial)
    reg [31:0] rout;
    always @(*) begin
        rout = 32'b0;
        case (mask)
            2'b00: begin // byte read
                case (offset)
                    2'b00: rout = {24'b0, rdata_resolved[ 7: 0]};
                    2'b01: rout = {24'b0, rdata_resolved[15: 8]};
                    2'b10: rout = {24'b0, rdata_resolved[23:16]};
                    2'b11: rout = {24'b0, rdata_resolved[31:24]};
                endcase
            end
            2'b01: begin // halfword read
                case (offset[1])
                    1'b0: rout = {16'b0, rdata_resolved[15: 0]};
                    1'b1: rout = {16'b0, rdata_resolved[31:16]};
                endcase
            end
            default: rout = rdata_resolved; // word read
        endcase
    end
    assign rdata = rout;

    // Compute merged write word (combinatorial, for imem mirroring)
    wire [31:0] cur = mem[word_addr];
    reg [31:0] merged;
    always @(*) begin
        merged = wdata; // default word write
        case (mask)
            2'b00: begin // SB merge
                case (offset)
                    2'b00: merged = {cur[31:8],  wdata[7:0]};
                    2'b01: merged = {cur[31:16], wdata[7:0], cur[7:0]};
                    2'b10: merged = {cur[31:24], wdata[7:0], cur[15:0]};
                    2'b11: merged = {wdata[7:0], cur[23:0]};
                endcase
            end
            2'b01: begin // SH merge
                case (offset[1])
                    1'b0: merged = {cur[31:16], wdata[15:0]};
                    1'b1: merged = {wdata[15:0], cur[15:0]};
                endcase
            end
            default: merged = wdata;
        endcase
    end

    assign waddr_out  = word_addr;
    assign merged_out = merged;
    assign wword_out  = wen;

    // Write path
    always @(posedge clk) begin
        if (wen) begin
            mem[word_addr] <= merged;
        end
    end
endmodule

// ---------------------------------------------------------------------------
// riscv_soc  –  Top-level SoC for the ISA test harness.
// ---------------------------------------------------------------------------
module riscv_soc (
    input  wire        clk,
    input  wire        rst_n,       // active-low reset from testbench

    // GPIO (unused in ISA tests but present for port compatibility)
    output wire [31:0] gpio_out,
    input  wire [31:0] gpio_in,

    // Extra ports expected by tinyriscv_soc_tb.v
    output wire [31:0] seg_display,
    output wire        uart_tx,
    input  wire        uart_rx,
    output wire [ 7:0] leds
);
    // -----------------------------------------------------------------------
    // Convert active-low reset to active-high for cpu_core
    // -----------------------------------------------------------------------
    wire cpu_rst = ~rst_n;

    // -----------------------------------------------------------------------
    // CPU ↔ memory wires
    // -----------------------------------------------------------------------
    wire [31:0] irom_addr;   // full 32-bit PC from cpu_core; sim uses irom_addr[14:2]
    wire [31:0] irom_data_0; // instruction at PC
    wire [31:0] irom_data_1; // instruction at PC+4

    wire [31:0] perip_addr;
    wire        perip_wen;
    wire [1:0]  perip_mask;
    wire [31:0] perip_wdata;
    wire [31:0] perip_rdata;
    wire [31:0] dram_raddr;

    // -----------------------------------------------------------------------
    // CPU core (2-wide superscalar pipeline)
    // u_cpu must contain u_stage_id  (renamed in cpu_core.sv)
    // -----------------------------------------------------------------------
    cpu_core u_cpu (
        .cpu_clk    (clk),
        .cpu_rst    (cpu_rst),
        .irom_addr  (irom_addr),
        .irom_data_0(irom_data_0),
        .irom_data_1(irom_data_1),
        .perip_addr (perip_addr),
        .perip_wen  (perip_wen),
        .perip_mask (perip_mask),
        .perip_wdata(perip_wdata),
        .perip_rdata(perip_rdata),
        .dram_raddr (dram_raddr)
    );

    // -----------------------------------------------------------------------
    // Mirroring wires from dmem to imem
    // -----------------------------------------------------------------------
    wire [12:0] dmem_waddr;
    wire [31:0] dmem_merged;
    wire        dmem_wword;

    // -----------------------------------------------------------------------
    // Instruction memory (u_imem)
    // irom_addr is now the full 32-bit PC; pc[14:2] gives the 13-bit word
    // address for sim_imem (8 K words = 32 KB).
    // -----------------------------------------------------------------------
    sim_imem u_imem (
        .clk    (clk),
        .raddr  (irom_addr[14:2]),
        .rdata_0(irom_data_0),
        .rdata_1(irom_data_1),
        .wen    (perip_wen),
        .waddr  (dmem_waddr),
        .wdata_w(dmem_merged),
        .wword  (dmem_wword)
    );

    // -----------------------------------------------------------------------
    // Data memory (u_dmem)
    // ISA tests use flat byte addresses 0x0000–0x1FFF for data.
    // -----------------------------------------------------------------------
    sim_dmem u_dmem (
        .clk        (clk),
        .byte_addr  (perip_addr),
        .wdata      (perip_wdata),
        .wen        (perip_wen),
        .mask       (perip_mask),
        .raddr_early(dram_raddr[14:2]),
        .rdata      (perip_rdata),
        .waddr_out  (dmem_waddr),
        .merged_out (dmem_merged),
        .wword_out  (dmem_wword)
    );

    // -----------------------------------------------------------------------
    // Expose dmem signals for compliance testbench probing
    // (u_soc.dmem_wen and u_soc.dmem_addr used by compliance_test/tinyriscv_soc_tb.v)
    // -----------------------------------------------------------------------
    wire        dmem_wen  = perip_wen;
    wire [31:0] dmem_addr = perip_addr;

    // -----------------------------------------------------------------------
    // Tie off unused outputs
    // -----------------------------------------------------------------------
    assign gpio_out    = 32'b0;
    assign seg_display = 32'b0;
    assign uart_tx     = 1'b1;
    assign leds        = 8'b0;

endmodule
