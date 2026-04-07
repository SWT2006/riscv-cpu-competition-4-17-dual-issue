module instruction_memory #(
    parameter MEM_SIZE  = 4096,    // Number of 32-bit words
    parameter INIT_FILE = ""       // Empty = no auto-load; testbench loads via $readmemh
)(
    input  wire        clk,
    input  wire [31:0] addr,
    output wire [31:0] rdata,
    // Write port for FENCE.I support (stores to imem range update instructions)
    input  wire        wen,
    input  wire [31:0] waddr,
    input  wire [31:0] wdata,
    input  wire [ 3:0] wmask
);

    reg [31:0] mem [0:MEM_SIZE-1];

    integer i;
    initial begin
        for (i = 0; i < MEM_SIZE; i = i + 1)
            mem[i] = 32'h0000_0013;  // NOP (ADDI x0,x0,0)
        if (INIT_FILE != "")
            $readmemh(INIT_FILE, mem);
    end

    assign rdata = mem[addr[31:2]];  // Word-addressed read

    // Byte-masked write (allows stores into instruction memory region)
    always @(posedge clk) begin
        if (wen && (waddr[31:2] < MEM_SIZE)) begin
            if (wmask[0]) mem[waddr[31:2]][ 7: 0] <= wdata[ 7: 0];
            if (wmask[1]) mem[waddr[31:2]][15: 8] <= wdata[15: 8];
            if (wmask[2]) mem[waddr[31:2]][23:16] <= wdata[23:16];
            if (wmask[3]) mem[waddr[31:2]][31:24] <= wdata[31:24];
        end
    end

endmodule
