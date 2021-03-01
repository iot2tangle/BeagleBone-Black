#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "bh1750.h"

char buffer[100];
char* s;

bool check_bh1750()
{
	#ifdef TEST
		return true;
	#endif
    	return false;
}

void init_bh1750(bool _ft)
{
	;// Not necesary in this case
}
 
void print_bh1750()
{   
    if (check_bh1750())
		printf("BH1750 : OK");
    else
		printf("BH1750 : Not detected (Light sensor)");
}

char* get_bh1750()
{
    #ifdef TEST
		return "182";
	#endif
 
    return "0";
}
