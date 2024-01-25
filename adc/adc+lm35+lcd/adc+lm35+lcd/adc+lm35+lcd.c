/*
 * adc_lm35_lcd.c
 *
 * Created: 3/1/2022 1:29:24 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "ADC.h"

#define lm35_pin 1

signed short temp = 0;

int main(void)
{
	LCD_init();
	ADC_init();
	
	LCD_send_string("Temp : ");
	
    while(1)
    {
		ADC_pin(lm35_pin);
		temp = 0.25 * ADC_read();
		if (temp < 10)
		{
			LCD_move_cursor (1, 11);
			LCD_send_char(' ');
			LCD_send_char(' ');
			LCD_move_cursor (1, 8);
			LCD_send_char (temp + 48);
			LCD_send_char (0xDF);
			LCD_send_char ('C');
		}
		else if((temp >= 10) && (temp < 100))
		{
			LCD_move_cursor (1, 12);
			LCD_send_char(' ');
			LCD_move_cursor (1, 8);
			LCD_send_char((temp/10) + 48);
			LCD_send_char((temp%10) + 48);
			LCD_send_char (0xDF);
			LCD_send_char ('C');
		}
		else if (temp >= 100)
		{
			LCD_move_cursor (1, 8);
			LCD_send_char((temp/100) + 48);
			LCD_send_char(()temp/10)%10) + 48);
			LCD_send_char((temp%10) + 48);
			LCD_send_char (0xDF);
			LCD_send_char ('C');
		}
    }
}