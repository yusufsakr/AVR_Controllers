/*
 * Timer_phasecorrect_pwm.c
 *
 * Created: 12/2/2021 6:06:09 PM
 *  Author: Lankash
 */ 


#include <avr/io.h>
#include "Timer.h"

int main(void)
{
	
	Timer_wave_phasecorrectPWM_OC0 (64, 1024, 0);

    while(1)
    {
        //TODO:: Please write your application code 
    }
}