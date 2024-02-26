/*
 * multiple_interrupts.c
 *
 * Created: 2/19/2022 9:36:58 AM
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

#define led1_port 'C'
#define led1_pin   0
#define led2_port 'C'
#define led2_pin   1
#define led3_port 'C'
#define led3_pin   2

#define but1_port 'D'
#define but1_pin   2
#define but2_port 'D'
#define but2_pin   3
#define but3_port 'B'
#define but3_pin   2

int main(void)
{
	LED_init(led1_port, led1_pin);
	LED_init(led2_port, led2_pin);
	LED_init(led3_port, led3_pin);
	
	BUTTON_init(but1_port, but1_pin);
	BUTTON_init(but2_port, but2_pin);
	BUTTON_init(but3_port, but3_pin);
	
	interr_int0(3);
	interr_int1(3);
	interr_int2(1);
	
    while(1)
    {
        LED_off(led1_port, led1_pin);
        LED_off(led2_port, led2_pin);
        LED_off(led3_port, led3_pin);
    }
}


ISR(INT0_vect)
{
	LED_on(led1_port, led1_pin);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	LED_on(led2_port, led2_pin);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	LED_on(led3_port, led3_pin);
	_delay_ms(1000);
}