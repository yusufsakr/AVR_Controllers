/*
 * Timer_wave_nonPWM.c
 *
 * Created: 12/1/2021 5:12:55 PM
 *  Author: Lankash
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Timer.h"
#include "LED.h"

int main(void)
{
	Timer_wave_nonPWM_OC0(78, 1024);
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}