/*
 * lcd_4bit_mode.c
 *
 * Created: 2/28/2022 12:29:54 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "LCD_config.h"
#include "DIO.h"

int main(void)
{
	/*LCD_init();
	
	LCD_send_string("Lankash is Back");
	
	LCD_char_ar(yeh);  //0
	LCD_char_ar(waw);  //1
	LCD_char_ar(sen);  //2
	LCD_char_ar(feh);  //3
	LCD_char_ar(sad);  //4
	LCD_char_ar(kaf);  //5
	LCD_char_ar(reh);  //6
	
	LCD_move_cursor(2, 16);
	LCD_send_char(0);
	
	LCD_move_cursor(2, 15);
	LCD_send_char(1);
	
	LCD_move_cursor(2, 14);
	LCD_send_char(2);
	
	LCD_move_cursor(2, 13);
	LCD_send_char(3);
	
	LCD_move_cursor(2, 11);
	LCD_send_char(4);
	
	LCD_move_cursor(2, 10);
	LCD_send_char(5);
	
	LCD_move_cursor(2, 9);
	LCD_send_char(6);
	*/
	
	DIO_set_pin_dir('D', 0, 1);
	
    while(1)
    {
		DIO_write_pin('D', 0, 1);
		_delay_ms(1000);
		DIO_write_pin('D', 0, 0);
		_delay_ms(1000);
		
        
    }
}