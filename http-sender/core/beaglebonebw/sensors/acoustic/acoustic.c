#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <simpleBBB_GPIO.h>
#include "acoustic.h"

#define ACOUSTIC_ENABLE 66	// GPIO66 BBB
#define ACOUSTIC_DATA 67	// GPIO67 BBB

char buffer[100];
char* s;

bool check_acoustic()
{
    if (!simpleBBB_GPIOread(ACOUSTIC_ENABLE))
		return true;
    else
		return false;
}

void init_acoustic(bool ft)
{
	if (ft)
	{
		simpleBBB_GPIOset(ACOUSTIC_ENABLE, 1);
		simpleBBB_GPIOset(ACOUSTIC_DATA, 1);
	}
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
    s = " ";

    if (simpleBBB_GPIOread(ACOUSTIC_DATA))
		sprintf(buffer, "High");
    else
		sprintf(buffer, "Low");

    s=buffer;
    return s;
}


