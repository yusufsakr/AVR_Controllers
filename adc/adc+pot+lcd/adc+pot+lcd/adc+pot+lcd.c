/*
 * adc_pot_lcd.c
 *
 * Created: 3/1/2022 1:29:24 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "ADC.h"

#define pot_pin  0

unsigned short dist  = 0;

int main(void)
{
	LCD_init();
	ADC_init();
	
	LCD_send_string("Distance : ");
	
    while(1)
    {
		ADC_pin(pot_pin);
		dist = 0.45 * ADC_read();
		
		if (dist < 10)
		{
			LCD_move_cursor (1, 15);
			LCD_send_char(' ');
			LCD_send_char(' ');
			LCD_move_cursor (1, 12);
			LCD_send_char ((dist%10) + 48);
			LCD_send_string ("mm");
		}
		else if ((dist >= 10) && (dist < 100))
		{
			LCD_move_cursor (1, 16);
			LCD_send_char(' ');
			LCD_move_cursor (1, 12);
			LCD_send_char ((dist/10) + 48);
			LCD_send_char ((dist%10) + 48);
			LCD_send_string ("mm");
		}
		else if (dist >= 100)
		{
			LCD_move_cursor (1, 12);
			LCD_send_char ((dist/100) + 48);
			LCD_send_char (((dist/10)%10) + 48);
			LCD_send_char ((dist%10) + 48);
			LCD_send_string ("mm");
		}
    }
}