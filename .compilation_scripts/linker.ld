ENTRY(ResetIntHandler)
MEMORY
{
	FLASH(RX) : ORIGIN = 0x00000000, LENGTH = 0x40000
	SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 0x8000
}	

SECTIONS
{
	.text :
	{
		_start_text = .;
        KEEP(*(.isr_vector))
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_end_text = .;
	}> FLASH

	.data :
	{
		_start_data = .;
		KEEP(*(.data*))
		*(.data*)
		. = ALIGN(4);
		_end_data = .;
	}> SRAM AT> FLASH

	.bss :
	{
		_start_bss = .;
		KEEP(*(.bss*))
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		_end_bss = .;
	}> SRAM

}