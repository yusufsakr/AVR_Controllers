/*
 * spi_lcd_slave.c
 *
 * Created: 3/8/2022 11:01:53 PM
 *  Author: Lankash
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "SPI.h"
#include "LCD.h"

int main(void)
{
	SPI_slave_init();
	LCD_init();
	
	unsigned char x = 0;
	
	/*
	unsigned char x = 0;
	unsigned char z = 0;
	*/
    while(1)
    {
		//z = SPI_slave_receive_char(x + 48);
		//LCD_send_char(z);
		//x++;
		x = SPI_slave_receive_char(x);
		
		if (1 == x)
		  LCD_send_string("Yusuf");
		else if (2 == x)
		  LCD_send_string("Youssef");
		else if (3 == x)
		  LCD_send_string("Zozza");
		else if (4 == x)
		  LCD_send_string("Galal");
		else if (5 == x)
		  LCD_send_string("Sakr");
		else if (6 == x)
		  LCD_send_char(32);    // Sending Space
		else if (7 == x)
		  LCD_move_cursor(2, 1);
    }
}