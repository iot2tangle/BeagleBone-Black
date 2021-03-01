#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "acoustic.h"


#define ACOUSTIC_ENABLE 22	// GPIO 23
#define ACOUSTIC_DATA 21 // GPIO 22

char buffer[100];
char* s;

bool check_acoustic()
{
	#ifdef TEST
		return true;
	#endif
    return false;	
}

void init_acoustic(bool ft)
{
	;
} 

void print_acoustic()
{
    if (check_acoustic())
		printf("SOUND Sensor : OK");
    else
		printf("SOUND Sensor : Not detected");
}

char* get_acoustic()
{
    #ifdef TEST
		return "High";
	#endif

    return "Low";
}


