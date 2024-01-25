/*
 * Timer_fast_PWM.c
 *
 * Created: 11/30/2021 4:54:42 AM
 *  Author: Lankash
 */ 


#include <avr/io.h>
#include "Timer.h"


int main(void)
{
	unsigned short pwm_volt = 1;
	Timer0_fastPWM (64, 1024, 1);
	
    while(1)
    {
         
    }
}