LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY REG IS
    PORT (
        CLK,CLR,EDCD,EDCI: IN STD_LOGIC;
        C: IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        ED: IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        Q: INOUT STD_LOGIC_VECTOR(7 DOWNTO 0)
    ) ;
END REG;

ARCHITECTURE A_REG OF REG IS
    SIGNAL M: STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
    MUX: PROCESS(C)
    BEGIN
        CASE C IS
            WHEN "00" => M <= ED;
            WHEN "01" => 
                --M <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) SRL 1);
                M(0) <= EDCD;
                CICLO: FOR I IN 1 TO 7 LOOP
                    M(I) <= Q(I-1);
                END LOOP;
            WHEN "10" => 
                --M <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) SLL 1);
                M(7) <= EDCI;
                CICLO2: FOR I IN 0 TO 6 LOOP
                    M(I) <= Q(I+1);
                END LOOP;
            WHEN OTHERS => M <= Q;
        END CASE;
    END PROCESS MUX;

    PROCESS (CLK,CLR)
        BEGIN
            IF (CLR='0') THEN
                Q <= "00000000";
            ELSIF (CLK'EVENT AND CLK='1') THEN
                Q <= M;
            END IF;
    END PROCESS;
END A_REG;
