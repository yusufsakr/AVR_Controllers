/*
 * Keypad_Test.c
 *
 * Created: 10/13/2021 11:44:07 AM
 *  Author: Lankash
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "KeyPad.h"

//...............................................

#define key_port 'C'

//...............................................

int main(void)
{
	unsigned char x = 0;
	
	keypad_init(key_port);
	LCD_init();
	
    while(1)
    {
        x = keypad_read(key_port);
		
		if (0xff != x) 
		{
		  LCD_send_char(x);
		}
		
		_delay_ms(100);
		
    }
}