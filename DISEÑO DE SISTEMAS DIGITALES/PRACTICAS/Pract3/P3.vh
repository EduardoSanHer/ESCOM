module reg ( 
	clk,
	clr,
	edcd,
	edci,
	c,
	ed,
	q
	) ;

input  clk;
input  clr;
input  edcd;
input  edci;
input [1:0] c;
input [7:0] ed;
inout [7:0] q;
