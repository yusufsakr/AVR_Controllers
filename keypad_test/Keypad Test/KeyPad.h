/*
 * Keypad_Test.c
 *
 * Created: 10/13/2021 11:44:07 AM
 *  Author: Lankash
 */ 

#ifndef KEYPAD_
#define KEYPAD_

#include "DIO.h"

//#define NOTPRESSED 0xFF

//..................................................................................

/*
    Function name         :  keypad_init
    Function Returns      :  void
    Function Arguments    :  unsigned char port.
    Function Description  :  Set the four Columns as 'I/P', & the four Rows as 'O/P'.
*/
void keypad_init (unsigned char port);


/*
    Function name         :  keypad_read
    Function Returns      :  unsigned char
    Function Arguments    :  unsigned char port.
    Function Description  :  Read the pressed button on the key pad.
*/
unsigned char keypad_read (unsigned char port);

//..................................................................................

#endif