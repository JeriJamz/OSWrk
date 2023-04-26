//this is for the byte order
#ifndef _BYTE_ORDER_
#define _BYTE_ORDER_

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){

	int i;
	for(i = 0; i < len; i++)
			printf(" %.2x", start[1]);
	printf("\n");

}

void show_int(int x){

	show_bytes((byte_pointer) &x, sizeof(int));

}

void show_float(float x){

	show_bytes((byte_pointer) &x, sizeof(int));

}

void show_pointers(void *x){

	show_bytes((byte_pointer) &x, sizeof(void *));

}

void test_show_bytes(int val){

	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_float(fval);
	show_pointer(pval);

}


