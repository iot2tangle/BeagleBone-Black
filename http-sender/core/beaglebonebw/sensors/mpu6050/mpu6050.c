#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "mpu6050.h"

char buffer[100];
char* s;

bool check_mpu6050()
{
	#ifdef TEST
		return true;
	#endif

   	return false;
}

void init_mpu6050(bool _ft)
{
	;
} 

void print_mpu6050()
{
    if (check_mpu6050())
	printf("MPU6050 : OK");
    else
	printf("MPU6050 : Not detected (Accelerometer, Gyroscope sensor)");
}

char* get_mpu6050(int a)
{
  	s = ""; 
    switch (a) 
    {	
    	case 0:	/* Aceler X */
    	#ifdef TEST
			return "0.25";
		#endif
		return "0";
        case 1:	/* Aceler Y */
    	#ifdef TEST
			return "-2.60";
		#endif
		return "0";
        case 2:
    	#ifdef TEST
			return "1.81";
		#endif
		return "0";
        case 3:
    	#ifdef TEST
			return "-4.55";
		#endif
		return "0";
        case 4:
    	#ifdef TEST
			return "0.65";
		#endif
		return "0";
        case 5:
    	#ifdef TEST
			return "5.06";
		#endif
		return "0";
    }
    return "0";
}
