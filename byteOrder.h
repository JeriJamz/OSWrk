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

void inplace_swap(int *a, int *b){

    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y; //this is alot mo simple LMAOOOO

}

void reverse_array(int c[], int cnt){

    int first, last;
    for(first = 0, last = cnt-1; first <= last;first++, last--){
	 inplace_swap(&c[first], &c[last]);

    }
}

#endif //_BYTE_ORDER_


