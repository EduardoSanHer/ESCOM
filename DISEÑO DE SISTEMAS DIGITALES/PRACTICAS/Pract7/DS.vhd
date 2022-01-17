LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.std_logic_ARITH.ALL;
USE IEEE.std_logic_UNSIGNED.ALL;

ENTITY DS IS
    PORT (
        CLK,X: IN STD_LOGIC;
        DISPLAY: OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
        Z: OUT STD_LOGIC
    ) ;
END DS;

ARCHITECTURE A_DS OF DS IS
    TYPE ESTADOS IS (A,B,C,D,E);
    SIGNAL EDO_PRESENTE, EDO_FUTURO: ESTADOS;
    CONSTANT DIG0 : STD_LOGIC_VECTOR(6 DOWNTO 0):="0000001";
    CONSTANT DIG1 : STD_LOGIC_VECTOR(6 DOWNTO 0):="1001111";
    BEGIN
    DE: PROCESS (X,EDO_PRESENTE,DISPLAY)
        BEGIN
        --Z <= '0';
        --DISPLAY <= DIG0;
            CASE EDO_PRESENTE IS
                WHEN A =>
                    DISPLAY <= "0000001";
                    IF (X='0') THEN
                        EDO_FUTURO <= A;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    ELSE
                        EDO_FUTURO <= B;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    END IF;
                WHEN B =>
                    IF (X='0') THEN
                        EDO_FUTURO <= A;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    ELSE
                        EDO_FUTURO <= C;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    END IF;
                WHEN C =>
                    IF (X='0') THEN
                        EDO_FUTURO <= A;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    ELSE
                        EDO_FUTURO <= D;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    END IF;
                WHEN D =>
                    IF (X='0') THEN
                        EDO_FUTURO <= A;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    ELSE
                        EDO_FUTURO <= E;
                        Z <= '1';
                        DISPLAY <= DIG1;
                    END IF;
                WHEN E =>
                    IF (X='0') THEN
                        EDO_FUTURO <= A;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    ELSE
                        EDO_FUTURO <= B;
                        Z <= '0';
                        DISPLAY <= DIG0;
                    END IF;
                WHEN OTHERS =>
                    Z <= '0';
                    DISPLAY <= DIG0;
                    EDO_FUTURO <= A;
            END CASE;
    END PROCESS DE;

    PROCESS(CLK)
        BEGIN
            IF(CLK'EVENT AND CLK='1') THEN
                EDO_PRESENTE <= EDO_FUTURO;
            END IF;
    END PROCESS;


END A_DS;