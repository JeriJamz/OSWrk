/*app.ld*/
INCLUDE MemMap.ld

SECTIONS
{

  .text :
  {

    KEEP(*(.vectors .vectors.*))
    *(.text*)
    *(.rodata*)
    _etext = .;

  }>approm

}