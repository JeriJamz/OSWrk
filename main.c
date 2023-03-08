//this is called main.c

#include <stdio.h>
#include "ipv4_parse.h"

int main(int argc, char *argv[]){

    ipv4_parse_ctx  ctx;
    unsigned int  addr = 0;
    int		ret = 0;

    if(argv != 2){

	printf("Usage: %s ip_range\r\n", argv[0]);
	return(1);

    }

//preform inital parsing of ip range
    ret = ipv4_parse_ctx_init

}



