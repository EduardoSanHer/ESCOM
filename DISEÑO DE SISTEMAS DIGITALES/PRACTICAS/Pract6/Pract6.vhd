LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.std_logic_ARITH.ALL;
USE IEEE.std_logic_UNSIGNED.ALL;

ENTITY CR IS
    PORT (
        CLK,CLR,CI,CD: IN STD_LOGIC;
        E: IN STD_LOGIC_VECTOR(6 DOWNTO 0);
        CTR: IN STD_LOGIC_VECTOR(2 DOWNTO 0);
        Q: INOUT STD_LOGIC_VECTOR(6 DOWNTO 0)
    ) ;
END CR;

ARCHITECTURE A_CR OF CR IS
    BEGIN
        PROCESS(CLK,CLR,CTR,Q)
		BEGIN
        IF(CLR='0') THEN
            Q <= "0000000";
        ELSIF(CLK'EVENT AND CLK='1') THEN
                CASE CTR IS 
                    WHEN "000" => Q <= E;
                    WHEN "001" => Q <= Q;
                    WHEN "010" =>
                        Q <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) SRL 1);
                        Q(6) <= CD;
                    WHEN "011" =>
                        Q <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) SLL 1);
                        Q(0) <= CI;
                    WHEN "100" => Q <= Q+1;
                    WHEN "101" => Q <= Q-1;
                    WHEN "110" =>
                        Q <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) ROR 1);
                    WHEN OTHERS =>
                        Q <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) ROL 1);
                END CASE;
        END IF;
        END PROCESS;
END A_CR;