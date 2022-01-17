LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY PI IS
    PORT (
        CLK,CLR,CTR: IN STD_LOGIC;
        --CTR: IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        E: IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        S: INOUT STD_LOGIC_VECTOR(7 DOWNTO 0)
    ) ;
END PI;

ARCHITECTURE A_PI OF PI IS
    SIGNAL M: STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
    MUX: PROCESS(CTR,S)
    BEGIN
        CASE CTR IS
            WHEN '0' => M <= E;
            WHEN OTHERS =>
                M(0) <= '0';
                CICLO: FOR I IN 1 TO 7 LOOP
                    M(I) <= S(I-1);
                END LOOP;
        END CASE;
    END PROCESS MUX;

    PROCESS (CLK,CLR)
        BEGIN
            IF (CLR='0') THEN
                S <= "00000000";
            ELSIF (CLK'EVENT AND CLK='1') THEN
                S <= M;
            END IF;
    END PROCESS;
END A_PI;
