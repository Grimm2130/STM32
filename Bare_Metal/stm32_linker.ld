ENTRY(Reset_Handler)

MEMORY
{
    FLASH(RX) :ORIGIN =0x08000000, LENGTH =1024K
    SRAM(RWX) :ORIGIN =0x20000000, LENGTH =128K
}

SECTIONS
{
    .text :
    {
        _stext = .;
        *(.startup_sec)
        *(.text)
        *(.rodata)
        _etext = .;
    }> FLASH

    .data :
    {
        _sdata = .;
        *(.data)
        _edata = .;
    }> SRAM AT> FLASH

    .bss :
    {
        _sbss = .;
        *(.bss)
        _ebss = .;
    }> SRAM
}