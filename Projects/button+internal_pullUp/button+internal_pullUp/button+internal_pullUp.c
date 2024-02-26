/*
 * button_internal_pullUp.c
 *
 * Created: 2/16/2022 4:35:14 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "led.h"
#include "DIO.h"
#include "push_button.h"

#define led_port    'A'   //Define the LED port.
#define led_pin      0    //Define the LED pin.
#define button_port 'A'   //Define the Button port.
#define button_pin   1    //Define the Button pin.


int main(void)
{
	LED_init(led_port, led_pin);                     //Initialize the LED on the M.C
	BUTTON_init(button_port, button_pin);            //Initialize the Button on the M.C
	DIO_connect_pullup(button_port, button_pin, 1);  //Connect M.C internal Pull-Up to the Button pin.
	
    while(1)
    {
        if (0 == BUTTON_read(button_port, button_pin))      //Condition if the Button is Pressed (Pull-Up)
        {
	        _delay_ms(30);
	        if (0 == BUTTON_read(button_port, button_pin))  //Button bouncing protection.
	        {
		        LED_on(led_port, led_pin);      //LED on if button is pressed
	        }
        }
        else
        {
	        LED_off(led_port, led_pin);        //LED off if button is not pressed.
        }
    }
}