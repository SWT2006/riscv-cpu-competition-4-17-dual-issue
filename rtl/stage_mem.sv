`timescale 1ns/1ps
// 2-wide MEM stage: shared memory port with pipe MUX.
//
// Only one pipe can access memory per cycle (guaranteed by the issue unit).
// The memory port is driven by whichever pipe has a load/store.
// If pipe A has a memory op, it drives the port and receives the load data.
// If pipe B has a memory op, it drives the port and receives the load data.
// If neither, the port is idle.
//
// Sign extension is applied based on funct3 (same as original).
module stage_mem (
    // Pipe A from EX/MEM
    input  wire [31:0] exmem_a_alu_result,
    input  wire [31:0] exmem_a_rs2_data,
    input  wire        exmem_a_mem_read,
    input  wire        exmem_a_mem_write,
    input  wire [2:0]  exmem_a_mem_funct3,
    // Pipe B from EX/MEM
    input  wire        exmem_b_valid,
    input  wire [31:0] exmem_b_alu_result,
    input  wire [31:0] exmem_b_rs2_data,
    input  wire        exmem_b_mem_read,
    input  wire        exmem_b_mem_write,
    input  wire [2:0]  exmem_b_mem_funct3,
    // Peripheral bus (single port, shared)
    output wire [31:0] perip_addr,
    output wire        perip_wen,
    output wire [1:0]  perip_mask,
    output wire [31:0] perip_wdata,
    input  wire [31:0] perip_rdata,
    // Load results to each pipe (only one is valid per cycle)
    output reg  [31:0] mem_read_data_a,
    output reg  [31:0] mem_read_data_b
);

    // Which pipe drives memory this cycle?
    wire a_is_mem = exmem_a_mem_read | exmem_a_mem_write;
    wire b_is_mem = exmem_b_valid & (exmem_b_mem_read | exmem_b_mem_write);

    // MUX: pipe B takes precedence if both are active (should not happen
    // due to issue check, but safe default).  pipe A otherwise.
    wire use_b = b_is_mem;

    wire [31:0] mem_addr   = use_b ? exmem_b_alu_result  : exmem_a_alu_result;
    wire [31:0] mem_wdata  = use_b ? exmem_b_rs2_data    : exmem_a_rs2_data;
    wire        mem_wen    = use_b ? exmem_b_mem_write    : exmem_a_mem_write;
    wire [2:0]  mem_funct3 = use_b ? exmem_b_mem_funct3   : exmem_a_mem_funct3;

    assign perip_addr  = mem_addr;
    assign perip_wen   = (a_is_mem | b_is_mem) ? mem_wen : 1'b0;
    assign perip_mask  = mem_funct3[1:0];
    assign perip_wdata = mem_wdata;

    // Sign extension helper
    function [31:0] sign_extend;
        input [2:0]  funct3;
        input [31:0] rdata;
        begin
            case (funct3)
                3'b000:  sign_extend = {{24{rdata[7]}},  rdata[7:0]};   // LB
                3'b001:  sign_extend = {{16{rdata[15]}}, rdata[15:0]};  // LH
                3'b010:  sign_extend = rdata;                            // LW
                3'b100:  sign_extend = {24'b0, rdata[7:0]};             // LBU
                3'b101:  sign_extend = {16'b0, rdata[15:0]};            // LHU
                default: sign_extend = rdata;
            endcase
        end
    endfunction

    // Route load data to the originating pipe
    always @(*) begin
        mem_read_data_a = 32'b0;
        mem_read_data_b = 32'b0;
        if (a_is_mem && !use_b && exmem_a_mem_read)
            mem_read_data_a = sign_extend(exmem_a_mem_funct3, perip_rdata);
        if (b_is_mem && use_b && exmem_b_mem_read)
            mem_read_data_b = sign_extend(exmem_b_mem_funct3, perip_rdata);
    end

endmodule
