module helloworldfpga(

	input  wire x,
	input  wire y,
	output wire A,
    );
   assign x=0;
   assign y=0;
   assign A=0;
    
    always @(*)
    begin
    f=(x&!y)|(!x&y);
    end
    endmodule
