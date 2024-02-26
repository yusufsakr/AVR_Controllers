/*
 * Test.c
 *
 * Created: 9/29/2021 8:46:47 PM
 *  Author: LANKASH
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LED.h"
#include "Push Button.h"
#include "seven_SEG.h"

int main(void)
{
	signed char count = 0;
	
	LED_init('D', 5);
	BUTTON_init('D', 6);
	sevenSEG_init('A');
	sevenSEG_write_num('A', count);
	
    while(1)
    {
        if(1 == BUTTON_read('D', 6))
		{
		  	_delay_ms(30);
			  
			  if(1 == BUTTON_read('D', 6))
			  {
				  LED_on('D', 5);
				  sevenSEG_write_num('A', count);
				  count ++;
				  
				  if(count > 9)
				  {
					  count = 0;
				  }
				  
				  while(1 == BUTTON_read('D', 6))
				  {
					  
				  }
				  
			  }
		}
		
		if(0 == BUTTON_read('D', 6))
		{
		  	_delay_ms(30);
			  
			  if(0 == BUTTON_read('D', 6))
			  {
				  LED_off('D', 5);
			  }
		}
    }
}