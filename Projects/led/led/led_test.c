/*
 * led_test.c
 *
 * Created: 2/16/2022 3:41:07 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul    //Define the speed of the M.C = 8 MHz
#include <util/delay.h>

#define led_port 'A'      //Define the LED port
#define led_pin 0         //Define the LED pin

int main(void)
{
	
	LED_init(led_port, led_pin);    //Initialize the LED on the M>C
	
    while(1)
    {
        LED_toggle(led_port, led_pin);   //Toggle the LED status
		_delay_ms (1000);                //Wait 1 sec
    }
}