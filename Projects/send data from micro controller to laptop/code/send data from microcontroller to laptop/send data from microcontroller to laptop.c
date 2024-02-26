#define F_CPU 8000000UL
#include <util/delay.h>
#include "USART.h"
#include "LCD.h"
int main(void)
{
	UART_vInit(300);
	LCD_vInit();
	char x;
	while(1)
	{
		//UART_vSendData('A');
		//_delay_ms(1000);
		UART_vSendData ('Y');
		_delay_ms(1000);
		UART_vSendData ('u');
		_delay_ms(1000);
		UART_vSendData ('s');
		_delay_ms(1000);
		UART_vSendData ('e');
		_delay_ms(1000);
		UART_vSendData ('f');
		_delay_ms(1000);
		UART_vSendData(0x0D);
		_delay_ms(1000);
	}
}

