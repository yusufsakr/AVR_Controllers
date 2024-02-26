/*
 * EEPROM_led.c
 *
 * Created: 2/22/2022 12:06:57 PM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL
#include <util/delay.h>

#include "led.h"
#include "EEPROM.h"
#include "push_button.h"
#include "interrupt_mcal.h"

#define btn_port 'D'
#define btn_pin   2
#define led_port 'C'
#define led_pin   0
#define led2_port 'D'
#define led2_pin   0

#define addr  0x0030
#define data  0x0050

int main(void)
{
	LED_init(led_port, led_pin);
	LED_init(led2_port, led2_pin);
	BUTTON_init(btn_port, btn_pin);
	
	interr_int0(3);
	
	EEPROM_sei();
	EEPROM_write(addr, data);
	
    while(1)
    {
        LED_off(led_port, led_pin);
		LED_off(led2_port, led2_pin);
    }
}

ISR (INT0_vect)
{
	LED_on(led2_port, led2_pin);
	EEPROM_write(addr, data);
}

ISR (EE_RDY_vect)
{
	LED_on(led_port, led_pin);
	_delay_ms(2000);
	EEPROM_cli();  //CLR_BIT (EECR, EERIE);
}