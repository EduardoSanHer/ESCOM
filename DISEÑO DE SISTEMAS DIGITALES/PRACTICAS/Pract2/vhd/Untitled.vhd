
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: Untitled.vhd

--    Date: Fri Oct 08 18:43:49 2021

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALCE22V10-25PC/PI
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY ffff IS
    PORT (
	                 pre :    in std_logic ;
	                 clr :    in std_logic ;
	                 clk :    in std_logic ;
	                   j :    in std_logic ;
	                   k :    in std_logic ;
	                   s :    in std_logic ;
	                   r :    in std_logic ;
	                   d :    in std_logic ;
	                   t :    in std_logic ;
	            selector :    in std_logic_vector (1 downto 0) ;
	                   q : inout std_logic ;
	                  nq : inout std_logic
    );
END ffff;

-- End of Test Bench Header

ARCHITECTURE DSMB of ffff is

	signal jed_node1	: std_logic:='0' ; -- clk
	signal jed_node2	: std_logic:='0' ; -- t
	signal jed_node3	: std_logic:='0' ; -- selector(1)
	signal jed_node4	: std_logic:='0' ; -- selector(0)
	signal jed_node5	: std_logic:='0' ; -- s
	signal jed_node6	: std_logic:='0' ; -- r
	signal jed_node7	: std_logic:='0' ; -- pre
	signal jed_node8	: std_logic:='0' ; -- k
	signal jed_node9	: std_logic:='0' ; -- j
	signal jed_node10	: std_logic:='0' ; -- d
	signal jed_node11	: std_logic:='0' ; -- clr
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node16	: std_logic:='0' ;
	signal jed_node17	: std_logic:='0' ;
	signal jed_node18	: std_logic:='0' ;
	signal jed_node19	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node21	: std_logic:='0' ;
	signal jed_node22	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of clk:SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of t:SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of selector(1):SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of selector(0):SIGNAL is "0004";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of s:SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of r:SIGNAL is "0006";

SIGNAL  jed_oept_7:std_logic:='0';
--Attribute PIN_NUMBERS of pre:SIGNAL is "0007";

SIGNAL  jed_oept_8:std_logic:='0';
--Attribute PIN_NUMBERS of k:SIGNAL is "0008";

SIGNAL  jed_oept_9:std_logic:='0';
--Attribute PIN_NUMBERS of j:SIGNAL is "0009";

SIGNAL  jed_oept_10:std_logic:='0';
--Attribute PIN_NUMBERS of d:SIGNAL is "0010";

SIGNAL  jed_oept_11:std_logic:='0';
--Attribute PIN_NUMBERS of clr:SIGNAL is "0011";

SIGNAL  jed_oept_14:std_logic:='0';
SIGNAL  jed_sum_14,jed_fb_14:std_logic:='0';
--Attribute PIN_NUMBERS of q:SIGNAL is "0014";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of nq:SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= clk ;
jed_node2 <= t ;
jed_node3 <= selector(1) ;
jed_node4 <= selector(0) ;
jed_node5 <= s ;
jed_node6 <= r ;
jed_node7 <= pre ;
jed_node8 <= k ;
jed_node9 <= j ;
jed_node10 <= d ;
jed_node11 <= clr ;
Mcell_14:c22v10m
generic map(reg,
   ninv,
   xreg,
   	25 ns, --tpd
	25 ns, --tea
	25 ns, --ter
	15 ns, --tco
	18 ns, --ts
	0 ns, --th
	14 ns, --twh
	14 ns, --twl
	13 ns, --tcf
	25 ns, --taw
	25 ns, --tar
	25 ns, --tap
	25 ns  --tspr
)
port map(
     d=>jed_sum_14,
     clk=>jed_node1,
     oe=>jed_oept_14,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q,
     fb=>jed_fb_14
   );

Mcell_23:c22v10m
generic map(reg,
   invt,
   xreg,
   	25 ns, --tpd
	25 ns, --tea
	25 ns, --ter
	15 ns, --tco
	18 ns, --ts
	0 ns, --th
	14 ns, --twh
	14 ns, --twl
	13 ns, --tcf
	25 ns, --taw
	25 ns, --tar
	25 ns, --tap
	25 ns  --tspr
)
port map(
     d=>jed_sum_23,
     clk=>jed_node1,
     oe=>jed_oept_23,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>nq,
     fb=>jed_fb_23
   );

jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_14<=(one);

jed_sum_14<= (((jed_node3) and (jed_node4) and not(jed_node6) and (not(jed_fb_14))
) or
((jed_node2) and (jed_node3) and not(jed_node4) and not(not(jed_fb_14))
) or
(not(jed_node3) and (jed_node4) and not(jed_node8) and (not(jed_fb_14))
) or
(not(jed_node3) and (jed_node4) and (jed_node9) and not(not(jed_fb_14))
) or
(not(jed_node2) and (jed_node3) and not(jed_node4) and (not(jed_fb_14))
) or
((jed_node3) and (jed_node4) and (jed_node5)) or
(not(jed_node3) and not(jed_node4) and (jed_node10)
) or
((jed_node7)));

jed_oept_23<=(one);

jed_sum_23<= (((jed_node3) and (jed_node4) and not(jed_node6) and (not(jed_fb_14))
) or
((jed_node2) and (jed_node3) and not(jed_node4) and not(not(jed_fb_14))
) or
(not(jed_node3) and (jed_node4) and not(jed_node8) and (not(jed_fb_14))
) or
(not(jed_node3) and (jed_node4) and (jed_node9) and not(not(jed_fb_14))
) or
(not(jed_node2) and (jed_node3) and not(jed_node4) and (not(jed_fb_14))
) or
((jed_node3) and (jed_node4) and (jed_node5)) or
(not(jed_node3) and not(jed_node4) and (jed_node10)
) or
((jed_node7)));

jed_sum_25<= ((not(jed_node11)));

end DSMB;
