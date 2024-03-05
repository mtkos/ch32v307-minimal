MEMORY{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
	RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 64K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS{
  .text :{
    *(.text.prog)
    *(.text*)
    *(.rodata*)
    *(.srodata*)
  } >FLASH

  .sidata :{
    . = ALIGN(4);
     _sidata = .;
  } >FLASH

  .sdata :{
    . = ALIGN(4);
    _sdata = .;
  } >RAM

  .data :{
    . = ALIGN(4);
    *(.data*)
    *(.sdata*)
    _edata = .; 
  } >RAM AT>FLASH

  .bss :{
    . = ALIGN(4);
    _sbss = .; 
    *(.bss*)
    *(.sbss*)
    _ebss = .; 
  } >RAM
}
