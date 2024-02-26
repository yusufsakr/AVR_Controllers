/*
 * Timer_7SEG_Multiplexing.c
 *
 * Created: 12/2/2021 12:08:45 AM
 *  Author: Lankash
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
//#include <util/delay.h>
#include "Timer.h"
#include "seven_SEG.h"
#include "my_macros.h"
#include "DIO.h"

volatile unsigned char counter_1 = 0;      //Increased by 1 every time to ISR.
volatile unsigned char counter_2 = 0;      //Value to be displayed on 7SEG.
volatile unsigned char counter_3 = 0;      // =1 when ISR.

int main(void)
{
	
	sevenSEG_init('A');
	DIO_set_pin_dir('C',0 , 1);                 //Port 'C' as O/P.
	DIO_set_pin_dir('C',1 , 1);
	Timer_CTC_init_interrupt(80, 1024);       //ISR every 10 mSec.
	
    while(1)
    {
        SET_BIT(DDRC, 0);
		CLR_BIT(DDRC, 1);
		sevenSEG_write_num('A', counter_2 % 10);
		
		while (counter_3 == 0);
		counter_3 = 0;
		
		CLR_BIT(DDRC, 0);
		SET_BIT(DDRC, 1);
		sevenSEG_write_num('A', counter_2 / 10);
		
		while (counter_3 == 0);
		counter_3 = 0;
		
		if (1000 >= counter_1)
		{
			counter_1 = 0;
			counter_2++;
		
		    if (counter_2 == 21)     //Maximum value displayed = 20.
		    {
			    counter_2 = 0;
		    }
		}	
    }
}


ISR(TIMER0_COMP_vect)
{
	counter_1 ++;
	counter_3 = 1;
}