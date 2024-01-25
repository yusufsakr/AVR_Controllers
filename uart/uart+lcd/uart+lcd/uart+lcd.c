/*
 * uart_lcd.c
 *
 * Created: 3/2/2022 10:24:54 PM
 *  Author: "Lankash"
 */ 


#include "UART.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	//LCD_init();
	UART_init(9600);
	
    while(1)
    {
        //x = UART_receive();
		UART_send_char ('A');
		//UART_send_char('\n');   //Print New Line on Serial Monitor
		_delay_ms(1000);
		//UART_send_string("Muhamed Zaghloul");
		//UART_send_char(0x0D);   //Print New Line on Serial Monitor
		//_delay_ms(1000);
		//LCD_send_char(x);
    }
}