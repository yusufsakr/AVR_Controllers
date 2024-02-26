/*

Code Created by "LANKASH" 
  @ 10/9/2021

File Contents : Push Button functions
*/

#include "DIO.h"
#include <util/delay.h>


void BUTTON_init(unsigned char port, unsigned char pin)    //Initialize 'I/P' on 'pin' of 'port'
{
  DIO_set_pin_dir (port, pin, 0);
}


unsigned char BUTTON_read(unsigned char port, unsigned char pin)  //Read the 'I/P' value of the Push Button
{
  unsigned char value = 0;
  value = DIO_read_pin (port, pin);
  
  /*NOTE :- (Condition to be written @main function)
  if (1 == value)
  {
	  _delay_ms(30);   //waiting for button read stability (Switch bouncing)
	  if ( 1 == value)
	  {
		  //write your condition here
	  }
  }  
  */
  
  return value;
}