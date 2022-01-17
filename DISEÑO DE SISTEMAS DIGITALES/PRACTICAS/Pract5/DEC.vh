module dec ( 
	clk,
	clr,
	s,
	ctr,
	display
	) ;

input  clk;
input  clr;
input [3:0] s;
input [1:0] ctr;
inout [6:0] display;
