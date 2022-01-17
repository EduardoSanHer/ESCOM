LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.std_logic_ARITH.ALL;
USE IEEE.std_logic_UNSIGNED.ALL;

ENTITY COUNT IS
    PORT (
        CLK,CLR, C: IN STD_LOGIC;
        Q: INOUT STD_LOGIC_VECTOR(7 DOWNTO 0)
    ) ;
END COUNT;

ARCHITECTURE A_COUNT OF COUNT IS
    SIGNAL M: STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
    --MUX: PROCESS(C)
    --BEGIN
        --CASE C IS
            --WHEN '0' =>
                --M(0) <= NOT C;
                --M(1) <= (NOT C) AND M(0);
                --M(2) <= (NOT C) AND M(0) AND M(1);
                --M(3) <= (NOT C) AND M(0) AND M(1) AND M(2);
                --M(4) <= (NOT C) AND M(0) AND M(1) AND M(2) AND M(3);
                --M(5) <= (NOT C) AND M(0) AND M(1) AND M(2) AND M(3) AND M(4);
                --M(6) <= (NOT C) AND M(0) AND M(1) AND M(2) AND M(3) AND M(4) AND M(5);
                --M(7) <= (NOT C) AND M(0) AND M(1) AND M(2) AND M(3) AND M(4) AND M(5) AND M(6);
                --M <= Q+1;
            --WHEN OTHERS => M <= Q;
        --END CASE;
    --END PROCESS MUX;

    PROCESS (CLK,CLR,C)
        BEGIN
            IF (CLR='0') THEN
                Q <= "00000000";
            ELSIF (CLK'EVENT AND CLK='1') THEN
                CASE C IS
                    WHEN '0' =>
                        Q <= Q+1;
                        --Q(0) <= NOT C;
                        --Q(1) <= (NOT C) AND Q(0);
                        --Q(2) <= (NOT C) AND Q(0) AND Q(1);
                        --Q(3) <= (NOT C) AND Q(0) AND Q(1) AND Q(2);
                        --Q(4) <= (NOT C) AND Q(0) AND Q(1) AND Q(2) AND Q(3);
                        --Q(5) <= (NOT C) AND Q(0) AND Q(1) AND Q(2) AND Q(3) AND Q(4);
                        --Q(6) <= (NOT C) AND Q(0) AND Q(1) AND Q(2) AND Q(3) AND Q(4) AND Q(5);
                        --Q(7) <= (NOT C) AND Q(0) AND Q(1) AND Q(2) AND Q(3) AND Q(4) AND Q(5) AND Q(6);
                    WHEN OTHERS => Q <= Q;
                END CASE;
                --Q <= M;
            END IF;
    END PROCESS;
END A_COUNT;