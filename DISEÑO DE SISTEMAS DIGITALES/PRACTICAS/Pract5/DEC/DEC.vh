module dec ( 
	clk,
	clr,
	ctr,
	s,
	display
	) ;

input  clk;
input  clr;
input [1:0] ctr;
input [3:0] s;
inout [6:0] display;
