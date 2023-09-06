/*bootloader linker*/
INCLUDE MemMap.ld

/*Section Definitons*/
SECTIONS
{

  .text :
  {
    KEEP(*(.vectors .vectors.*))
    *(.text*)
    *(.rodata*)
    _etext = .;
  }> bootrom

}
