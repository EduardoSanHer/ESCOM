LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;


ENTITY FFFF IS
    PORT(
        PRE, CLR, CLK: IN STD_LOGIC;
        J,K,S,R,D,T: IN STD_LOGIC;
        SELECTOR: IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        Q,NQ: OUT STD_LOGIC
    );
END ENTITY;

ARCHITECTURE A_FFFF OF FFFF IS
    SIGNAL QAUX, NQAUX: STD_LOGIC;
BEGIN
    WITH SELECTOR SELECT
    QAUX <= D WHEN "00",
        ((J AND NOT Q) OR (NOT K AND Q)) WHEN "01",
        ((T AND NOT Q) OR (NOT T AND Q)) WHEN "10",
        (S OR (NOT R AND Q)) WHEN OTHERS;
    NQAUX <= NOT QAUX;

    PROCESS(CLR,PRE,CLK)
    BEGIN
        IF(CLR='0') THEN
            Q <= '0';
            NQ <= '1';
        ELSIF(CLK'EVENT AND CLK='1') THEN
            IF(PRE='1') THEN
                Q <= '1';
                NQ <= '0';
            ELSE
                Q <= QAUX;
                NQ <= NQAUX;
            END IF;
        END IF;
    END PROCESS;
END A_FFFF;
