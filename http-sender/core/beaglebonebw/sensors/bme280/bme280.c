#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "bme280.h"

char buffer[100];
char* s;

bool check_bme280()
{
	#ifdef TEST
		return true;
	#endif
    return false;
}

void init_bme280(bool _ft)
{
	;// Not necesary in this case
}
 
void print_bme280()
{   
    if (check_bme280())
		printf("BME280 : OK");
    else
		printf("BME280 : Not detected (Temperat, Humidity, Pressure sensor)");
}

char* get_bme280(int ind) 
{ 
    switch (ind) 
    {	
    	case 0:
		#ifdef TEST
			return "24.31";
		#endif
		return "0";

		case 1:
        #ifdef TEST
			return "42.43";
		#endif
		return "0"; 
		
		case 2:
        #ifdef TEST
			return "923.7";
		#endif
		return "0"; 
    }
    return "0";
}
