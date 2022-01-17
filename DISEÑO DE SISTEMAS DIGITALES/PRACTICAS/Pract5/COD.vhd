LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.std_logic_ARITH.ALL;
USE IEEE.std_logic_UNSIGNED.ALL;

ENTITY COD IS
    PORT (
        --I0,I1,I2,I3,I4,I5,I6,I7,I8,I9: IN STD_LOGIC;
        I: IN STD_LOGIC_VECTOR(9 DOWNTO 0);
        Q: IN STD_LOGIC_VECTOR(3 DOWNTO 0)
    ) ;
END COD;

ARCHITECTURE A_COD OF COD IS
    --SIGNAL P: STD_LOGIC;
BEGIN
    --PROCESS (I,Q)
        --BEGIN
            Q <= "1001" WHEN I(9)='1' ELSE
                 "1000" WHEN I(8)='1' ELSE
                 "0111" WHEN I(7)='1' ELSE
                 "0110" WHEN I(6)='1' ELSE
                 "0101" WHEN I(5)='1' ELSE
                 "0100" WHEN I(4)='1' ELSE
                 "0011" WHEN I(3)='1' ELSE
                 "0010" WHEN I(2)='1' ELSE
                 "0001" WHEN I(1)='1' ELSE
                 "0000";
    --END PROCESS;
END A_COD;