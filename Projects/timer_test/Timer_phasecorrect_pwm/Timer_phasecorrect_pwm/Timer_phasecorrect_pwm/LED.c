/*

Code created by "LANKASH"
   @11/9/2021

File contents : 'LED' function.

*/

#include "DIO.h"

void LED_init(unsigned char port, unsigned char pin)
{
  DIO_set_pin_dir(port, pin, 1);        //Initialize the 'pin' to the 'LED'
}

void LED_on(unsigned char port, unsigned char pin)
{
  DIO_write_pin(port, pin, 1);         //Turn 'ON' the 'LED' on the 'pin' of 'port' 
}

void LED_off(unsigned char port, unsigned char pin)
{
  DIO_write_pin(port, pin, 0);         //Turn 'OFF' the 'LED' on the 'pin' of 'port' 
}

void LED_toggle(unsigned char port, unsigned char pin)
{
  DIO_toogle(port, pin);              //Toggle the 'LED' on the 'pin' of 'port' 

}
