//this is some book work of how im supposed to find byte
//Do not compile this. It reallt just functions. Mingw and GCC wont run on 64 gotta do 32 and I think you gotta 
//store value in show bytes workin on that part. The Doc is old think from 1 or 2 C updates ago
#include <stdio.h>

typedef unsigned char *byte_pointer;//its pointing at this

void show_bytes(byte_pointer start, size_t len){//this creates a obj. Arg BP idk start is and the len of size_t

	int i;
	for(i = 0 ; i < len ; i++)
			printf(" %.2x", start[i]);//start gotta be what starts a function and store it in BP
	printf("\n");

}

void show_int(int x){

    show_bytes((byte_pointer) &x, sizeof(int));

}

void show_pointer(void *x){

	show_bytes((byte_pointer) &x, sizeof(void *));

}


