/*
 * LCD_Test.c
 *
 * Created: 10/1/2021 4:10:41 PM
 *  Author: LANKASH
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"


int main(void)
{
	LCD_init();
	/*
	LCD_send_char('K');
	_delay_ms(1000);
    
	LCD_send_char('h');
	_delay_ms(1000);
	
	LCD_send_char('a');
	_delay_ms(1000);
	
	LCD_send_char('l');
	_delay_ms(1000);
	
	LCD_send_char('e');
	_delay_ms(1000);
	
	LCD_send_char('d');
	_delay_ms(1000);
	
	LCD_move_cursor(2, 1);
	*/
	LCD_send_char('O');
	_delay_ms(1000);
	
	LCD_send_char('m');
	_delay_ms(1000);
	
	LCD_move_cursor(1, 4);
	
	LCD_send_char('G');
	_delay_ms(1000);
	
	LCD_send_char('A');
	_delay_ms(1000);
	
	LCD_send_char('L');
	_delay_ms(1000);
	
	LCD_send_char('A');
	_delay_ms(1000);
	
	LCD_send_char('L');
	_delay_ms(1000);
	
	while (1)
	{
		
	}
}