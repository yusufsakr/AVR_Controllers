/*
 * reset.c
 *
 * Created: 2/19/2022 10:31:23 AM
 *  Author: "Lankash
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "led.h"

#define led1_port 'C'
#define led1_pin   0
#define led2_port 'C'
#define led2_pin   1
#define led3_port 'C'
#define led3_pin   2

int main(void)
{
	
	LED_init(led1_port, led1_pin);
	LED_init(led2_port, led2_pin);
	LED_init(led3_port, led3_pin);
	
    while(1)
    {
        LED_on(led1_port, led1_pin);
		_delay_ms(1000);
		LED_off(led1_port, led1_pin);
		
		LED_on(led2_port, led2_pin);
		_delay_ms(1000);
		LED_off(led2_port, led2_pin);
		
		LED_on(led3_port, led3_pin);
		_delay_ms(1000);
		LED_off(led3_port, led3_pin);
    }
}