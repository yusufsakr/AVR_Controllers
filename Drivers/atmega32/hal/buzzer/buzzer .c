/*

Code Created by "LANKASH" 
  @ 10/9/2021

File Contents : Buzzer functions. 

*/


# include "DIO.h"

void BUZZER_init (unsigned char port, unsigned char pin)    //Function to initialize the ports to the Buzzer
{
  DIO_set_pin_dir(port, pin, 1);    //Set 'PIN' in 'PORT' as 'O/P'
}


void BUZZER_on (unsigned char port, unsigned char pin)      //Function to set the Buzzer 'ON'
{
  DIO_write_pin(port, pin, 1);     //Set 'PIN' in 'PORT' as 'HIGH'
}

