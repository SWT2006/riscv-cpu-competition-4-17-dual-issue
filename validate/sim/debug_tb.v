`timescale 1ns/1ps
module tinyriscv_soc_tb;
    reg clk;
    reg rst_n;
    initial clk = 0;
    always  #10 clk = ~clk;
    initial begin rst_n = 0; #200; rst_n = 1; end

    wire [31:0] gpio_out, gpio_in, seg_display;
    wire uart_tx; wire [7:0] leds;
    assign gpio_in = 32'b0;

    riscv_soc u_soc(
        .clk(clk), .rst_n(rst_n), .gpio_out(gpio_out), .gpio_in(gpio_in),
        .seg_display(seg_display), .uart_tx(uart_tx), .uart_rx(1'b1), .leds(leds)
    );

    initial begin
        #1;
        $readmemh("inst.data", u_soc.u_imem.mem);
        $readmemh("inst.data", u_soc.u_dmem.mem);
    end

    integer cc; initial cc = 0;
    always @(posedge clk) begin
        if (rst_n) begin
            cc = cc + 1;
            // Print PC every cycle for first 600 cycles
            if (cc < 600) begin
                $display("CYC=%0d PC=%08h INSTR=%08h x26=%0d x27=%0d x3=%0d",
                    cc,
                    u_soc.u_cpu.u_stage_id.regfile[1], // PC isn't directly accessible, use x1 as proxy
                    32'h0,
                    u_soc.u_cpu.u_stage_id.regfile[26],
                    u_soc.u_cpu.u_stage_id.regfile[27],
                    u_soc.u_cpu.u_stage_id.regfile[3]);
            end
            if (u_soc.u_cpu.u_stage_id.regfile[26] == 32'd1) begin
                $display("DETECTED: x26=1 x27=%0d x3=%0d at cycle %0d",
                    u_soc.u_cpu.u_stage_id.regfile[27],
                    u_soc.u_cpu.u_stage_id.regfile[3], cc);
                $finish;
            end
            if (cc > 1000) begin $display("TIMEOUT"); $finish; end
        end
    end
endmodule
