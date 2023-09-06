//I want to make an asm version of this
#include <minttypes.h>
#include "MemMap.h"

static void start_app(uint32_t pc, uint32_t sp) __attribute__((naked)){

    __asm("		\n\
	  msr msp, r1
	  bx r0
    ");

}

int main(void){

    uint32_t *app_code = (uint32_t *)__approm_start__;
    uint32_t app_sp = app_code[0];
    uint32_t app_start = app_code[1];
    start_app(app_start, app_sp);
    // not reached
    while (1);

}