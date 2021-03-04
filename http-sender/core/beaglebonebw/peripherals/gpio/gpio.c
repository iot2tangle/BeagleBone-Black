#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <simpleBBB_GPIO.h>
#include "gpio.h"

#define GREEN_LED 60		// GPIO 17 Raspberry Pi 3/4
#define RED_LED 48		// GPIO 2 Raspberry Pi 3/4

void init_LEDs()
{
    // LEDs
	simpleBBB_GPIOset(GREEN_LED, 0);
	simpleBBB_GPIOset(RED_LED, 0);
	
    simpleBBB_GPIOwrite(GREEN_LED, 1);
    simpleBBB_GPIOwrite(RED_LED, 1);
    usleep(1000000);
    simpleBBB_GPIOwrite(GREEN_LED, 0);
    simpleBBB_GPIOwrite(RED_LED, 0);
}

void led_GPIO(int led, int mode)
{
    if (led == 0)
		simpleBBB_GPIOwrite(GREEN_LED, mode);
    else
		simpleBBB_GPIOwrite(RED_LED, mode);
}


bool read_GPIO(int pin)
{
    if (simpleBBB_GPIOread(pin))
		return true;
    else
		return false;
}
