//this should access the memory
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(){

    int *p = malloc(sizeof(int));		//a1
    assert(p != NULL);
    printf("(%d) address of p: $08x\n,"
	   "getpid(), (usigned) p");		//a2
    *p = 0;					//a3
    while(1){
	Spin(1);
	*p = *p + 1;
	printf("(%d) p: %d\n", getpid(), *p);	//a4
}
    return 0;
}

