// old_sim_soc.v — Simulation SoC wrapper for the OLD single-issue cpu_core.
// Used by tb_compare.v for side-by-side comparison with the new 2-wide design.
`timescale 1ns/1ps

module old_sim_soc (
    input  wire clk,
    input  wire rst_n
);
    wire cpu_rst = ~rst_n;

    wire [31:0] irom_addr;
    wire [31:0] irom_data;

    wire [31:0] perip_addr;
    wire        perip_wen;
    wire [1:0]  perip_mask;
    wire [31:0] perip_wdata;
    wire [31:0] perip_rdata;

    old_cpu_core u_cpu (
        .cpu_clk    (clk),
        .cpu_rst    (cpu_rst),
        .irom_addr  (irom_addr),
        .irom_data  (irom_data),
        .perip_addr (perip_addr),
        .perip_wen  (perip_wen),
        .perip_mask (perip_mask),
        .perip_wdata(perip_wdata),
        .perip_rdata(perip_rdata)
    );

    // Instruction ROM: single-port read (old design)
    reg [31:0] imem [0:4095];
    assign irom_data = imem[irom_addr[13:2]];

    // Data RAM: same as sim_soc.v
    localparam [31:0] DRAM_BASE = 32'h8010_0000;
    localparam [31:0] DRAM_END  = 32'h8014_0000;

    reg [31:0] dmem [0:65535];

    wire        dram_sel       = (perip_addr >= DRAM_BASE) && (perip_addr < DRAM_END);
    wire [15:0] dram_word_addr = perip_addr[17:2];
    wire [1:0]  dram_offset    = perip_addr[1:0];

    wire [31:0] dram_cur = dmem[dram_word_addr];

    reg [31:0] dram_rdata;
    always @(*) begin
        dram_rdata = 32'b0;
        if (dram_sel) begin
            case (perip_mask)
                2'b00: begin
                    case (dram_offset)
                        2'b00: dram_rdata = {24'b0, dram_cur[ 7: 0]};
                        2'b01: dram_rdata = {24'b0, dram_cur[15: 8]};
                        2'b10: dram_rdata = {24'b0, dram_cur[23:16]};
                        2'b11: dram_rdata = {24'b0, dram_cur[31:24]};
                    endcase
                end
                2'b01: begin
                    case (dram_offset[1])
                        1'b0: dram_rdata = {16'b0, dram_cur[15: 0]};
                        1'b1: dram_rdata = {16'b0, dram_cur[31:16]};
                    endcase
                end
                default: dram_rdata = dram_cur;
            endcase
        end
    end

    assign perip_rdata = dram_rdata;

    reg [31:0] dram_wdata;
    always @(*) begin
        dram_wdata = perip_wdata;
        case (perip_mask)
            2'b00: begin
                case (dram_offset)
                    2'b00: dram_wdata = {dram_cur[31: 8], perip_wdata[7:0]};
                    2'b01: dram_wdata = {dram_cur[31:16], perip_wdata[7:0], dram_cur[ 7:0]};
                    2'b10: dram_wdata = {dram_cur[31:24], perip_wdata[7:0], dram_cur[15:0]};
                    2'b11: dram_wdata = {perip_wdata[7:0], dram_cur[23:0]};
                endcase
            end
            2'b01: begin
                case (dram_offset[1])
                    1'b0: dram_wdata = {dram_cur[31:16], perip_wdata[15:0]};
                    1'b1: dram_wdata = {perip_wdata[15:0], dram_cur[15:0]};
                endcase
            end
            default: dram_wdata = perip_wdata;
        endcase
    end

    always @(posedge clk) begin
        if (perip_wen && dram_sel)
            dmem[dram_word_addr] <= dram_wdata;
    end
endmodule
