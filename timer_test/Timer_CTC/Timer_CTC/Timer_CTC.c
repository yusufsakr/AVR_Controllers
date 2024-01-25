/*
 * Timer_test.c
 *
 * Created: 11/16/2021 6:10:09 PM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
//#define F_CPU  8000000UL
//#include <util/delay.h>

#include "Timer.h"
#include "LED.h"

volatile unsigned char  counter_1 = 0; //@=100 -> 1 sec.
volatile unsigned char  counter_2 = 0; //@=200 -> 2 sec.
volatile unsigned short counter_3 = 0; //@=300 -> 3 sec.

int main(void)
{
	/*
	 * CTC_time = OCR0_val * (N / freq_mcu)
	 * counter  = required_time / CTC_time  
	 */
	Timer_CTC_init_interrupt(78, 1024);  //CTC_time = OCR0_val * (N / freq_mcu)
	
	LED_init('A', 0);     //LED (1)
	LED_init('A', 1);     //LED (2)
	LED_init('A', 2);     //LED (3)
	
    while(1)
    {
		if (counter_1 >= 100)
		{
		    LED_toggle('A', 0);
		    counter_1 = 0;	
		}  
		
		if (counter_2 >= 200)
		{
			LED_toggle('A', 1);
			counter_2 = 0;
		}
		
		if (counter_3 >= 300)
		{
			LED_toggle('A', 2);
			counter_3 = 0;
		}
    }
}


ISR (TIMER0_COMP_vect)
{
	counter_1++;
	counter_2++;
	counter_3++;
}