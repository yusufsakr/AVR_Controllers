/*
 * spi_lcd.c
 *
 * Created: 3/8/2022 10:14:22 PM
 *  Author: Lankash
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "SPI.h"

int main(void)
{
	LCD_init();
	SPI_master_init();
	
	SPI_master_send_char(1);
	_delay_ms(300);
	SPI_master_send_char(6);
	_delay_ms(300);
	SPI_master_send_char(5);
	_delay_ms(300);
	SPI_master_send_char(7);
	_delay_ms(300);
	SPI_master_send_char(3);
	/*
	unsigned char counter_1 = 0;
	unsigned char counter_2 = 0;
	
    while(counter_1 < 10)
    {
        counter_2 = SPI_master_send_char(counter_1 + 48);
		_delay_ms(300);  //Least time to avoid over run in because of LCD functions
		LCD_send_char(counter_2);
		counter_1++;
		
    }*/
}