
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: Pract6.vhd

--    Date: Fri Dec 10 15:04:16 2021

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALCE22V10-25PC/PI
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY cr IS
    PORT (
	                 clk :    in std_logic ;
	                 clr :    in std_logic ;
	                  ci :    in std_logic ;
	                  cd :    in std_logic ;
	                   e :    in std_logic_vector (6 downto 0) ;
	                 ctr :    in std_logic_vector (2 downto 0) ;
	                   q : inout std_logic_vector (6 downto 0)
    );
END cr;

-- End of Test Bench Header

ARCHITECTURE DSMB of cr is

	signal jed_node1	: std_logic:='0' ; -- clk
	signal jed_node2	: std_logic:='0' ; -- e(6)
	signal jed_node3	: std_logic:='0' ; -- cd
	signal jed_node4	: std_logic:='0' ; -- e(5)
	signal jed_node5	: std_logic:='0' ; -- e(4)
	signal jed_node6	: std_logic:='0' ; -- e(3)
	signal jed_node7	: std_logic:='0' ; -- e(2)
	signal jed_node8	: std_logic:='0' ; -- e(1)
	signal jed_node9	: std_logic:='0' ; -- e(0)
	signal jed_node10	: std_logic:='0' ; -- ctr(2)
	signal jed_node11	: std_logic:='0' ; -- ctr(1)
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ; -- ctr(0)
	signal jed_node18	: std_logic:='0' ; -- clr
	signal jed_node19	: std_logic:='0' ; -- ci
	signal jed_node20	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of clk:SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of e(6):SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of cd:SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of e(5):SIGNAL is "0004";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of e(4):SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of e(3):SIGNAL is "0006";

SIGNAL  jed_oept_7:std_logic:='0';
--Attribute PIN_NUMBERS of e(2):SIGNAL is "0007";

SIGNAL  jed_oept_8:std_logic:='0';
--Attribute PIN_NUMBERS of e(1):SIGNAL is "0008";

SIGNAL  jed_oept_9:std_logic:='0';
--Attribute PIN_NUMBERS of e(0):SIGNAL is "0009";

SIGNAL  jed_oept_10:std_logic:='0';
--Attribute PIN_NUMBERS of ctr(2):SIGNAL is "0010";

SIGNAL  jed_oept_11:std_logic:='0';
--Attribute PIN_NUMBERS of ctr(1):SIGNAL is "0011";

SIGNAL  jed_oept_13:std_logic:='0';
--Attribute PIN_NUMBERS of ctr(0):SIGNAL is "0013";

SIGNAL  jed_oept_14:std_logic:='0';
SIGNAL  jed_sum_14,jed_fb_14:std_logic:='0';
--Attribute PIN_NUMBERS of q(1):SIGNAL is "0014";

SIGNAL  jed_oept_15:std_logic:='0';
SIGNAL  jed_sum_15,jed_fb_15:std_logic:='0';
--Attribute PIN_NUMBERS of q(3):SIGNAL is "0015";

SIGNAL  jed_oept_16:std_logic:='0';
SIGNAL  jed_sum_16,jed_fb_16:std_logic:='0';
--Attribute PIN_NUMBERS of q(5):SIGNAL is "0016";

SIGNAL  jed_oept_17:std_logic:='0';
SIGNAL  jed_sum_17,jed_fb_17:std_logic:='0';
--Attribute PIN_NUMBERS of q(6):SIGNAL is "0017";

SIGNAL  jed_oept_18:std_logic:='0';
SIGNAL  jed_sum_18,jed_fb_18:std_logic:='0';
--Attribute PIN_NUMBERS of clr:SIGNAL is "0018";

SIGNAL  jed_oept_19:std_logic:='0';
SIGNAL  jed_sum_19,jed_fb_19:std_logic:='0';
--Attribute PIN_NUMBERS of ci:SIGNAL is "0019";

SIGNAL  jed_oept_21:std_logic:='0';
SIGNAL  jed_sum_21,jed_fb_21:std_logic:='0';
--Attribute PIN_NUMBERS of q(4):SIGNAL is "0021";

SIGNAL  jed_oept_22:std_logic:='0';
SIGNAL  jed_sum_22,jed_fb_22:std_logic:='0';
--Attribute PIN_NUMBERS of q(2):SIGNAL is "0022";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of q(0):SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= clk ;
jed_node2 <= e(6) ;
jed_node3 <= cd ;
jed_node4 <= e(5) ;
jed_node5 <= e(4) ;
jed_node6 <= e(3) ;
jed_node7 <= e(2) ;
jed_node8 <= e(1) ;
jed_node9 <= e(0) ;
jed_node10 <= ctr(2) ;
jed_node11 <= ctr(1) ;
jed_node13 <= ctr(0) ;
jed_node18 <= clr ;
jed_node19 <= ci ;
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
     y=>q(1),
     fb=>jed_fb_14
   );

Mcell_15:c22v10m
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
     d=>jed_sum_15,
     clk=>jed_node1,
     oe=>jed_oept_15,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q(3),
     fb=>jed_fb_15
   );

Mcell_16:c22v10m
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
     d=>jed_sum_16,
     clk=>jed_node1,
     oe=>jed_oept_16,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q(5),
     fb=>jed_fb_16
   );

Mcell_17:c22v10m
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
     d=>jed_sum_17,
     clk=>jed_node1,
     oe=>jed_oept_17,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q(6),
     fb=>jed_fb_17
   );

Mcell_18:c22v10m
generic map(comb,
   invt,
   xpin,
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
     d=>jed_sum_18,
     clk=>jed_node1,
     oe=>jed_oept_18,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node18,
     fb=>jed_fb_18
   );

Mcell_19:c22v10m
generic map(comb,
   invt,
   xpin,
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
     d=>jed_sum_19,
     clk=>jed_node1,
     oe=>jed_oept_19,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node19,
     fb=>jed_fb_19
   );

Mcell_21:c22v10m
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
     d=>jed_sum_21,
     clk=>jed_node1,
     oe=>jed_oept_21,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q(4),
     fb=>jed_fb_21
   );

Mcell_22:c22v10m
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
     d=>jed_sum_22,
     clk=>jed_node1,
     oe=>jed_oept_22,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q(2),
     fb=>jed_fb_22
   );

Mcell_23:c22v10m
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
     d=>jed_sum_23,
     clk=>jed_node1,
     oe=>jed_oept_23,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>q(0),
     fb=>jed_fb_23
   );

jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_14<=(one);

jed_sum_14<= ((not(not(jed_fb_23)) and (jed_node10) and (not(jed_fb_14))
 and not(jed_node11) and not(jed_node13)) or
((not(jed_fb_23)) and (jed_node10) and not(not(jed_fb_14))
 and not(jed_node11) and not(jed_node13)) or
(not(not(jed_fb_23)) and (jed_node10) and not(not(jed_fb_14))
 and not(jed_node11) and (jed_node13)) or
(not(jed_node10) and (not(jed_fb_14)) and not(jed_node11)
 and (jed_node13)) or
((jed_node8) and not(jed_node10) and not(jed_node11)
 and not(jed_node13)) or
((not(jed_fb_23)) and (not(jed_fb_14)) and (jed_node13)
) or
((not(jed_fb_23)) and (jed_node11) and (jed_node13)
) or
((not(jed_fb_22)) and (jed_node11) and not(jed_node13)
));

jed_oept_15<=(one);

jed_sum_15<= (((not(jed_fb_23)) and (not(jed_fb_22)) and not(not(jed_fb_15))
 and (jed_node10) and (not(jed_fb_14)) and not(jed_node11)
 and not(jed_node13)) or
(not(not(jed_fb_23)) and not(not(jed_fb_22)) and not(not(jed_fb_15))
 and (jed_node10) and not(not(jed_fb_14)) and not(jed_node11)
 and (jed_node13)) or
(not(not(jed_fb_23)) and (not(jed_fb_15)) and (jed_node10)
 and not(jed_node11) and not(jed_node13)) or
((not(jed_fb_22)) and (not(jed_fb_15)) and (jed_node10)
 and not(not(jed_fb_14)) and not(jed_node11)) or
((not(jed_fb_23)) and not(not(jed_fb_22)) and (not(jed_fb_15))
 and (jed_node10) and not(jed_node11)) or
((not(jed_fb_15)) and (not(jed_fb_14)) and not(jed_node11)
 and (jed_node13)) or
((not(jed_fb_15)) and not(jed_node10) and not(jed_node11)
 and (jed_node13)) or
((jed_node6) and not(jed_node10) and not(jed_node11)
 and not(jed_node13)) or
((not(jed_fb_22)) and (jed_node11) and (jed_node13)
) or
((not(jed_fb_21)) and (jed_node11) and not(jed_node13)
));

jed_oept_16<=(one);

jed_sum_16<= (((not(jed_fb_23)) and (not(jed_fb_22)) and (not(jed_fb_21))
 and not(not(jed_fb_16)) and (not(jed_fb_15)) and (jed_node10)
 and (not(jed_fb_14)) and not(jed_node11) and not(jed_node13)
) or
(not(not(jed_fb_23)) and not(not(jed_fb_22)) and not(not(jed_fb_21))
 and not(not(jed_fb_16)) and not(not(jed_fb_15)) and (jed_node10)
 and not(not(jed_fb_14)) and not(jed_node11) and (jed_node13)
) or
(not(not(jed_fb_23)) and (not(jed_fb_21)) and (not(jed_fb_16))
 and (jed_node10) and not(jed_node11)) or
((not(jed_fb_23)) and (not(jed_fb_16)) and (jed_node10)
 and not(not(jed_fb_14)) and not(jed_node11)) or
(not(not(jed_fb_22)) and (not(jed_fb_16)) and (jed_node10)
 and (not(jed_fb_14)) and not(jed_node11)) or
((not(jed_fb_22)) and (not(jed_fb_16)) and not(not(jed_fb_15))
 and (jed_node10) and not(jed_node11)) or
(not(not(jed_fb_21)) and (not(jed_fb_16)) and (jed_node10)
 and not(jed_node11) and not(jed_node13)) or
((not(jed_fb_16)) and (not(jed_fb_15)) and not(jed_node11)
 and (jed_node13)) or
((not(jed_fb_16)) and not(jed_node10) and not(jed_node11)
 and (jed_node13)) or
((jed_node4) and not(jed_node10) and not(jed_node11)
 and not(jed_node13)) or
((not(jed_fb_21)) and (jed_node11) and (jed_node13)
) or
((not(jed_fb_17)) and (jed_node11) and not(jed_node13)
));

jed_oept_17<=(one);

jed_sum_17<= ((not(not(jed_fb_23)) and not(not(jed_fb_22)) and not(not(jed_fb_21))
 and not(not(jed_fb_17)) and not(not(jed_fb_16)) and not(not(jed_fb_15))
 and (jed_node10) and not(not(jed_fb_14)) and not(jed_node11)
 and (jed_node13)) or
((not(jed_fb_23)) and (not(jed_fb_22)) and (not(jed_fb_21))
 and not(not(jed_fb_17)) and (not(jed_fb_16)) and (not(jed_fb_15))
 and (jed_node10) and (not(jed_fb_14)) and not(jed_node13)
) or
(not(not(jed_fb_23)) and (not(jed_fb_17)) and (not(jed_fb_16))
 and (jed_node10) and not(jed_node11)) or
((not(jed_fb_22)) and (not(jed_fb_17)) and (jed_node10)
 and not(not(jed_fb_14)) and not(jed_node11)) or
((not(jed_fb_23)) and not(not(jed_fb_22)) and (not(jed_fb_17))
 and (jed_node10) and not(jed_node11)) or
((not(jed_fb_21)) and (not(jed_fb_17)) and not(not(jed_fb_15))
 and (jed_node10) and not(jed_node11)) or
(not(not(jed_fb_21)) and (not(jed_fb_17)) and (jed_node10)
 and (not(jed_fb_14)) and not(jed_node11)) or
((not(jed_fb_17)) and not(not(jed_fb_16)) and (jed_node10)
 and not(jed_node11) and not(jed_node13)) or
((not(jed_fb_23)) and (jed_node10) and (jed_node11)
 and not(jed_node13)) or
((not(jed_fb_17)) and (not(jed_fb_15)) and not(jed_node11)
 and (jed_node13)) or
((jed_node3) and not(jed_node10) and (jed_node11) and not(jed_node13)
) or
((not(jed_fb_17)) and not(jed_node10) and not(jed_node11)
 and (jed_node13)) or
((jed_node2) and not(jed_node10) and not(jed_node11)
 and not(jed_node13)) or
((not(jed_fb_16)) and (jed_node11) and (jed_node13)
));

jed_oept_21<=(one);

jed_sum_21<= (((not(jed_fb_23)) and (not(jed_fb_22)) and not(not(jed_fb_21))
 and (not(jed_fb_15)) and (jed_node10) and (not(jed_fb_14))
 and not(jed_node11) and not(jed_node13)) or
(not(not(jed_fb_23)) and not(not(jed_fb_22)) and not(not(jed_fb_21))
 and not(not(jed_fb_15)) and (jed_node10) and not(not(jed_fb_14))
 and not(jed_node11) and (jed_node13)) or
(not(not(jed_fb_23)) and (not(jed_fb_21)) and (jed_node10)
 and not(jed_node11) and not(jed_node13)) or
((not(jed_fb_23)) and (not(jed_fb_21)) and (jed_node10)
 and not(not(jed_fb_14)) and not(jed_node11)) or
(not(not(jed_fb_22)) and (not(jed_fb_21)) and (not(jed_fb_15))
 and (jed_node10) and not(jed_node11)) or
((not(jed_fb_21)) and not(not(jed_fb_15)) and (jed_node10)
 and (not(jed_fb_14)) and not(jed_node11)) or
((not(jed_fb_22)) and (not(jed_fb_21)) and not(jed_node11)
 and (jed_node13)) or
((not(jed_fb_21)) and not(jed_node10) and not(jed_node11)
 and (jed_node13)) or
((jed_node5) and not(jed_node10) and not(jed_node11)
 and not(jed_node13)) or
((not(jed_fb_15)) and (jed_node11) and (jed_node13)
) or
((not(jed_fb_16)) and (jed_node11) and not(jed_node13)
));

jed_oept_22<=(one);

jed_sum_22<= (((not(jed_fb_23)) and not(not(jed_fb_22)) and (jed_node10)
 and (not(jed_fb_14)) and not(jed_node11) and not(jed_node13)
) or
(not(not(jed_fb_23)) and not(not(jed_fb_22)) and (jed_node10)
 and not(not(jed_fb_14)) and not(jed_node11) and (jed_node13)
) or
(not(not(jed_fb_23)) and (not(jed_fb_22)) and (jed_node10)
 and (not(jed_fb_14)) and not(jed_node11)) or
((not(jed_fb_22)) and (jed_node10) and not(not(jed_fb_14))
 and not(jed_node11) and not(jed_node13)) or
((not(jed_fb_23)) and (not(jed_fb_22)) and not(jed_node11)
 and (jed_node13)) or
((not(jed_fb_22)) and not(jed_node10) and not(jed_node11)
 and (jed_node13)) or
((jed_node7) and not(jed_node10) and not(jed_node11)
 and not(jed_node13)) or
((not(jed_fb_14)) and (jed_node11) and (jed_node13)
) or
((not(jed_fb_15)) and (jed_node11) and not(jed_node13)
));

jed_oept_23<=(one);

jed_sum_23<= (((not(jed_fb_17)) and (jed_node10) and (jed_node11)
 and (jed_node13)) or
((jed_fb_19) and not(jed_node10) and (jed_node11) and (jed_node13)
) or
((not(jed_fb_23)) and not(jed_node10) and not(jed_node11)
 and (jed_node13)) or
((jed_node9) and not(jed_node10) and not(jed_node11)
 and not(jed_node13)) or
((not(jed_fb_14)) and (jed_node11) and not(jed_node13)
) or
(not(not(jed_fb_23)) and (jed_node10) and not(jed_node11)
));

jed_sum_25<= ((not(jed_fb_18)));

end DSMB;
