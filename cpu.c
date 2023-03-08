#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h"

int main(){

    if (argc != 2){
	fprintf(stderr, "usage: cpu<string>\n");
	exit(1);
 }
    char *str = argv[1];
    while(1){
	Spin(1);
	printf("%s\n", str);
 }