//this is called main.c

#include <stdio.h>
#include "ipv4_parse.h"

int main(int argc, char *argv[]){

    ipv4_parse_ctx  ctx; //this holds the ip address
    unsigned int  addr = 0;
    int		ret = 0;

    if(argv != 2){

	printf("Usage: %s ip_range\r\n", argv[0]);
	return(1);

    }

//preform inital parsing of ip range
  while(1){
    ret = ipv4_parse_ctx_init(&ctx, argv[1]);
    if(ret<0){
	printf("**** ipv4_parse_ctx_init has failed.\r\n");//I gotta use this bc of the /r
	break;
    }
//prints it out
    printf("ADDR: %d.%d.%d.%d\r\n",
		  (addr >> 0) & 0xFF,
		  (addr >> 8) & 0xFF,
		  (addr >> 16) & 0xFF,
		  (addr >> 24) & 0xFF);

  }
return(0);
}



