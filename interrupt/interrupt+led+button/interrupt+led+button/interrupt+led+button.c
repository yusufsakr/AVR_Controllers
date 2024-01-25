/*
 * interrupt_led_button.c
 *
 * Created: 2/19/2022 8:41:01 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO.h"
#include "led.h"
#include "push_button.h"
#include "interrupt_mcal.h"

#define led_port 'C'
#define led_pin   0
#define but_port 'D'
#define but_pin   2     

int main(void)
{
	
	LED_init(led_port, led_pin);
	BUTTON_init(but_port, but_pin);
	interr_int0(3);
	
    while(1)
    {
        LED_off(led_port, led_pin);
    }
}

ISR(INT0_vect)
{
	LED_on(led_port, led_pin);
	_delay_ms(1000);
}