/*This is some book working im working on making a bootreader*/
/*This is ARM Link to the article below*/
MEMORY
{

  bootrom  (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00000000/*Why I though it was 55ah...*/
  approm   (rx)  : ORIGIN = 0x00004000, LENGTH = 0x0003C000
  ram	   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000

}

__bootrom_start__ = ORIGIN(bootrom);
__bootrom_size__  = LENGTH(bootrom);
__approm_start__  = ORIGIN(approm);
__approm_size__   = LENGTH(approm);

/*AYOOOO Also shouts out to Chris Chandler. Great guy he helped put me on the right track for OS work*/
/*The Link

https://interrupt.memfault.com/blog/how-to-write-a-bootloader-from-scratch
*/