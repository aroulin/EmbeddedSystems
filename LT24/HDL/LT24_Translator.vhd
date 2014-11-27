library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity LT24_Translator is
	port(
		clk      : in  std_logic;
		reset_n  : in  std_logic;

		start    : in  std_logic;
		cmd      : in  std_logic;
		data_in  : in  std_logic_vector(15 downto 0);
		busy     : out std_logic;

		csx      : out std_logic;
		dcx      : out std_logic;
		wrx      : out std_logic;
		rdx      : out std_logic;
		data_out : out std_logic_vector(15 downto 0)
	);
end entity LT24_Translator;

architecture RTL of LT24_Translator is
	type state_type is (IDLE, WRITE_CMD, WRITE_DATA);
	signal state_reg, state_next     : state_type;
	signal counter_reg, counter_next : integer;

	signal busy_reg, busy_next : std_logic;

	signal csx_reg, csx_next   : std_logic;
	signal dcx_reg, dcx_next   : std_logic;
	signal wrx_reg, wrx_next   : std_logic;
	signal rdx_reg, rdx_next   : std_logic;
	signal data_reg, data_next : std_logic_vector(15 downto 0);
begin
	state_machine : process(busy_reg, cmd, counter_reg, csx_reg, data_in, data_reg, dcx_reg, rdx_reg, start, state_reg, wrx_reg) is
	begin
		state_next   <= state_reg;
		counter_next <= counter_reg;
		busy_next    <= busy_reg;
		csx_next     <= csx_reg;
		dcx_next     <= dcx_reg;
		wrx_next     <= wrx_reg;
		rdx_next     <= rdx_reg;
		data_next    <= data_reg;

		case state_reg is
			when IDLE =>
				if start = '1' then
					data_next <= data_in;
					busy_next <= '1';
					if cmd = '1' then
						state_next <= WRITE_CMD;
					else
						state_next <= WRITE_DATA;
					end if;
				end if;
			when WRITE_CMD =>
				counter_next <= counter_reg + 1;
				case counter_reg is
					when 0 => dcx_next <= '0';
					when 1 => csx_next <= '0';
					when 2 => wrx_next <= '0';
					when 3 => wrx_next <= '1';
					when 4 => csx_next <= '1';
					when 5 =>
						dcx_next     <= '1';
						state_next   <= IDLE;
						counter_next <= 0;
						busy_next    <= '0';
						data_next    <= (others => '0');
					when others => null;
				end case;
			when WRITE_DATA =>
				counter_next <= counter_reg + 1;
				case counter_reg is
					when 0 => csx_next <= '0';
								 wrx_next <= '0';
					when 1 => wrx_next <= '1';
					when 2 =>
						csx_next     <= '1';
						state_next   <= IDLE;
						counter_next <= 0;
						busy_next    <= '0';
						data_next    <= (others => '0');
					when others => null;
				end case;
		end case;
	end process state_machine;

	output_process : process(busy_reg, csx_reg, data_reg, dcx_reg, rdx_reg, wrx_reg) is
	begin
		busy     <= busy_reg;
		csx      <= csx_reg;
		dcx      <= dcx_reg;
		wrx      <= wrx_reg;
		rdx      <= rdx_reg;
		data_out <= data_reg;
	end process output_process;

	reg_process : process(clk, reset_n) is
	begin
		if reset_n = '0' then
			state_reg   <= IDLE;
			counter_reg <= 0;
			busy_reg    <= '0';
			csx_reg     <= '1';
			dcx_reg     <= '1';
			wrx_reg     <= '1';
			rdx_reg     <= '1';
			data_reg    <= (others => '0');
		elsif rising_edge(clk) then
			state_reg   <= state_next;
			counter_reg <= counter_next;
			busy_reg    <= busy_next;
			csx_reg     <= csx_next;
			dcx_reg     <= dcx_next;
			wrx_reg     <= wrx_next;
			rdx_reg     <= rdx_next;
			data_reg    <= data_next;
		end if;
	end process reg_process;

end architecture RTL;
