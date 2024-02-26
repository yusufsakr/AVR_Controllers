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
#include "my_macros.h"

#define lm35_pin 1

signed int temp = 0;
unsigned int volt = 0;

int main(void)
{
	LCD_init();
	ADC_init();
	
	CLR_BIT(ADMUX, MUX0);
	CLR_BIT(ADMUX, MUX1);
	CLR_BIT(ADMUX, MUX2);
	CLR_BIT(ADMUX, MUX3);
	SET_BIT(ADMUX, MUX4);
	
	LCD_send_string("Temp : ");
	
    while(1)
    {
		volt = 2.5 * ADC_read();
		
		if (volt >= 1000) 
		{
			temp = (volt - 1000)/10;
		    if (temp < 10)
		    {
				LCD_move_cursor (1, 7);
				LCD_send_char(' ');
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
				LCD_move_cursor (1, 7);
				LCD_send_char(' ');
    			LCD_move_cursor (1, 12);
	    		LCD_send_char(' ');
		    	LCD_move_cursor (1, 8);
			    LCD_send_char(((temp/10)%10) + 48);
    			LCD_send_char((temp%10) + 48);
	    		LCD_send_char (0xDF);
		    	LCD_send_char ('C');
		    }
    		else if (temp >= 100)
    		{
				LCD_move_cursor (1, 7);
				LCD_send_char(' ');
    			LCD_move_cursor (1, 8);
    			LCD_send_char(((temp/100)%10) + 48);
    			LCD_send_char(((temp/10)%10) + 48);
    			LCD_send_char((temp%10) + 48);
	    		LCD_send_char (0xDF);
	    		LCD_send_char ('C');
		    }
		}
		else //if (volt < 1000)
		{
			temp = (1000 - volt)/10;
			
			if (temp < 10)
			{
			    LCD_move_cursor (1, 7);
			    LCD_send_char('-');
			    LCD_send_char (temp + 48);
			    LCD_send_char (0xDF);
			    LCD_send_char ('C');
			}
			else if((temp >= 10) && (temp < 100))
			{
				LCD_move_cursor (1, 7);
				LCD_send_char('-');
				LCD_send_char((temp/10) + 48);
				LCD_send_char((temp%10) + 48);
				LCD_send_char (0xDF);
				LCD_send_char ('C');
			}
		}
    }
}