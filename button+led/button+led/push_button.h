/*

Code Created by "LANKASH" 
  @ 10/9/2021

File Contents : Push Button functions. 

*/

#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_


/*
    Function name         :  BUTTON_init
    Function Returns      :  void
    Function Arguments    :  unsigned char, unsigned pin
    Function Description  :  Initialize 'I/P' on 'pin' of 'port' for the Push Button
*/
void BUTTON_init (unsigned char port, unsigned char pin);


/*
    Function name         :  BUTTON_read
    Function Returns      :  void
    Function Arguments    :  unsigned char, unsigned pin
    Function Description  :  Read the 'I/P' value of the Push Button on the 'pin' of the 'port'
*/
unsigned char BUTTON_read (unsigned char port, unsigned char pin);

#endif