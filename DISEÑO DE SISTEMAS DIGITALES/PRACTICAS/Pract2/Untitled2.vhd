LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY TITULO IS

    PORT(
        CLK, SET, RESET: IN STD_LOGIC;
        J,K,S,R,D,T: IN STD_LOGIC;
        SELECTOR: IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        Q,QN: OUT STD_LOGIC
    );
END ENTITY;

ARCHITECTURE SUBTITULO OF TITULO IS
    SIGNAL AUXJK, AUXT, AUXD, AUXSR: STD_LOGIC := '0';
BEGIN
    PROCESS(CLK,RESET,SET)
    BEGIN
        IF RESET = '1' THEN
            AUXJK <= '0';
            AUXD <= '0';
            AUXT <= '0';
            AUXSR <= '0';
        ELSIF SET = '1' THEN
            AUXJK <= '1';
            AUXD <= '1';
            AUXT <= '1';
            AUXSR <= '1';
        --ELSIF RISING_EDGE(CLK) THEN
        ELSIF (CLK'EVENT AND CLK='1') THEN
            --FF JK
            AUXJK <= ((J AND NOT AUXJK) OR (NOT K AND AUXJK));
            --FF D
            AUXD <= D;
            --FF SR
            IF S='0' AND R='1' THEN
                AUXSR <= '0';
            ELSIF S='0' AND R='0' THEN
                AUXSR <= AUXSR;
            ELSIF S='1' AND R='0' THEN
                AUXSR <= '1';
            ELSE 
                AUXSR <= '-';
            END IF;
            --FF T
            IF T='0' THEN
                AUXT <= AUXT;
            ELSE
                AUXT <= NOT AUXT;
            END IF;
        END IF;
    END PROCESS;

--MULTIPLEXOR
    PROCESS(RESET,SET,SELECTOR,AUXD,AUXSR,AUXT,AUXJK)
    BEGIN
        IF RESET = '1' THEN
            Q <= '0';
            QN <= '0';
        ELSIF SET = '1' THEN
            Q <= '1';
            QN <= '1';
        ELSE 
            IF SELECTOR = "00" THEN
                Q <= AUXSR;
                QN <= NOT AUXSR;
            ELSIF SELECTOR = "01" THEN
                Q <= AUXD;
                QN <= AUXD;
            ELSIF SELECTOR = "10" THEN
                Q <= AUXT;
                QN <= NOT AUXT;
            ELSE 
                Q <= AUXJK;
                QN <= NOT AUXJK;
            END IF;
        END IF;
    END PROCESS;
END architecture;



--xddd

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
