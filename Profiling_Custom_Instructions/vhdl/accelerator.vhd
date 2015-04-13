library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity accelerator is
	port(
		clk           : in  std_logic;
		nReset        : in  std_logic;

		-- Slave
		Address_s     : in  std_logic_vector(1 downto 0);
		ChipSelect_s  : in  std_logic;
		Write_s       : in  std_logic;
		Read_s        : in  std_logic;
		WriteData_s   : in  std_logic_vector(31 downto 0);
		ReadData_s    : out std_logic_vector(31 downto 0);

		-- Master
		ReadData_m    : in  std_logic_vector(31 downto 0);
		WaitRequest_m : in  std_logic;
		Address_m     : out std_logic_vector(31 downto 0);
		ByteEnable_m  : out std_logic_vector(3 downto 0);
		Write_m       : out std_logic;
		Read_m        : out std_logic;
		WriteData_m   : out std_logic_vector(31 downto 0)
	);
end entity accelerator;

architecture behavior of accelerator is
	signal addressStart_reg      : std_logic_vector(31 downto 0);
	signal length_reg            : std_logic_vector(13 downto 0);
	signal data_reg              : std_logic_vector(31 downto 0);
	signal start_reg, finish_reg : std_logic;

	signal addressCurrent_reg : unsigned(31 downto 0);
	signal lengthCurrent_reg  : unsigned(13 downto 0); -- 16384

	type States is (Idle, LoadParam, ReadAcc, WaitRead, WriteData, Ending);

	signal StateMaster : States;

begin
	SlaveWrite : process(clk, nReset)
	begin
		if nReset = '0' then
			addressStart_reg <= (others => '0');
			length_reg       <= (others => '0');
			start_reg        <= '0';
		elsif rising_edge(clk) then
			start_reg <= '0';
			if ChipSelect_s = '1' and Write_s = '1' then
				case Address_s is
					when "00"   => addressStart_reg <= WriteData_s;
					when "01"   => length_reg <= WriteData_s(15 downto 0);
					when "10"   => start_reg <= WriteData_s(0);
					when others => null;
				end case;
			end if;
		end if;
	end process SlaveWrite;

	SlaveRead : process(clk)
	begin
		if rising_edge(clk) then
			if ChipSelect_s = '1' and Read_s = '1' then
				ReadData_s <= (others => '0');
				case Address_s is
					when "00"   => ReadData_s <= std_logic_vector(addressCurrent_reg);
					when "01"   => ReadData_s(13 downto 0) <= std_logic_vector(lengthCurrent_reg);
					when "10"   => ReadData_s(0) <= start_reg;
					when "11"   => ReadData_s(0) <= finish_reg;
					when others => null;
				end case;
			end if;
		end if;
	end process SlaveRead;

	Master : process(clk, nReset)
	begin
		if nReset = '0' then
			finish_reg         <= '0';
			addressCurrent_reg <= (others => '0');
			lengthCurrent_reg  <= (others => '0');
			StateMaster        <= Idle;
		elsif rising_edge(clk) then
			case StateMaster is
				when Idle =>
					Address_m    <= (others => '0');
					ByteEnable_m <= "0000";
					Write_m      <= '0';
					Read_m       <= '0';
					-- Wait until the start bit
					if start_reg = '1' then
						-- Start the accelerator
						StateMaster <= LoadParam;
						finish_reg  <= '0';
					end if;
				when LoadParam =>
					addressCurrent_reg <= unsigned(addressStart_reg) - 4;
					lengthCurrent_reg  <= unsigned(length_reg) + 1;
					StateMaster        <= ReadAcc;
				when ReadAcc =>
					Address_m    <= std_logic_vector(addressCurrent_reg);
					ByteEnable_m <= "1111";
					Read_m       <= '1';
					StateMaster  <= WaitRead;
				when WaitRead =>
					-- Wait until the data is read.

					StateMaster <= WaitRead;
					if WaitRequest_m = '0' then
						data_reg(7 downto 0)   <= ReadData_m(31 downto 24);
						data_reg(31 downto 24) <= ReadData_m(7 downto 0);


						for i in 8 to 23 loop
								 data_reg(i) <= ReadData_m(31 - i);			
						end loop;
				
						Read_m      <= '0';
						StateMaster <= WriteData;
					
						lengthCurrent_reg  <= lengthCurrent_reg - 1;
						addressCurrent_reg <= addressCurrent_reg + 4;
					
					end if ;
						
					when WriteData =>
					
						 StateMaster <= WriteData;
					-- Replace the value by the new one
					Address_m        <= std_logic_vector(addressCurrent_reg);
					ByteEnable_m     <= "1111";
					Write_m          <= '1';
					WriteData_m      <= data_reg;

					--Should we keep reading?
					if lengthcurrent_reg > 1 then
						StateMaster        <= ReadAcc;
					else
						StateMaster <= Ending;
					end if;

				when Ending =>
					StateMaster <= Ending;
					-- Wait for the last write to be done.
					if WaitRequest_m = '0' then
						ByteEnable_m <= "0000";
						Write_m      <= '0';
						finish_reg   <= '1';
						StateMaster  <= Idle;
					end if;
				when others => null;
			end case;
		end if;
	end process Master;
end architecture behavior;
								
								