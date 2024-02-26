/*

Code Created by "LANKASH" 
  @ 11/9/2021

File Contents : 'Relay' Functions impelimentation. 

*/

#include "DIO.h"


void RELAY_init (unsigned char port, unsigned char pin)
{
  DIO_set_pin_dir(port, pin, 1);      //Set the Pin as 'O/P' for the 'RELAY'.
}


void RELAY_on (unsigned char port, unsigned char pin)
{
  DIO_write_pin(port, pin, 1);      //Set the Pin of the 'RELAY' as 'HIGH'.
}


void RELAY_off (unsigned char port, unsigned char pin)
{
  DIO_write_pin(port, pin, 0);     //Set the Pin of the 'RELAY' as 'LOW'.
}


void RELAY_toogle (unsigned char port, unsigned char pin)
{
  DIO_toogle(port, pin);          //Toogle the 'O/P'pin of the 'RELAY' from 'HIGH' to 'LOW', and vise versa.
} 


