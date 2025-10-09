`include "probes.svh"

// Wrapper for our design defined in code/
// The external signals exposed to the outside world are
// clock and reset
module design_wrapper (
    input logic clk,
    input logic reset
);
    // Instantiate TOP_MODULE (pd2) as core
    `TOP_MODULE core (
        .clk(clk),
        .rst(reset)
        // Add probe connections here if required
    );

endmodule
