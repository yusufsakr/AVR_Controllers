/*
 * ADC_Test.c
 *
 * Created: 10/15/2021 9:00:02 AM
 *  Author: Lankash
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "LED.h"
#include "DIO.h"
#include "my_macros.h"

#define LED_port 'D'
#define led_port2 'C'

int main(void)
{
	LED_init(LED_port, 0);
	LED_init(LED_port, 1);
	LED_init(LED_port, 2);
	LED_init(LED_port, 3);
	LED_init(LED_port, 4);
	LED_init(LED_port, 5);
	LED_init(LED_port, 6);
	LED_init(LED_port, 7);
	DIO_set_pin_dir(led_port2, 6, 1);
	DIO_set_pin_dir(led_port2, 7, 1);
	
	ADC_init();
	
	ADC_pin(2);
	
    while(1)
    {
        PORTD = ADC_read()>>2;
		DIO_write_pin(led_port2, 7, (ADC_read()<<14)>>15);
		DIO_write_pin(led_port2, 6, (ADC_read()<<15)>>15);
    }
}