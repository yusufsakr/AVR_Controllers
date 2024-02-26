/*

Code created by "LANKASH"
  @13/9/2021

File Contents : '7SEG' implementation Functions

*/

#include "DIO.h"
#include "sevenSEG_bcd.h"

void sevenSEG_init_bcd(unsigned char port, unsigned char pin)    //Initializing the 'O/P' pins for the 7SEG-PCD.
{
  DIO_set_pin_dir(port, (pin+0), 1);
  DIO_set_pin_dir(port, (pin+1), 1);
  DIO_set_pin_dir(port, (pin+2), 1);
  DIO_set_pin_dir(port, (pin+3), 1);
}

void sevenSEG_write_bcd(unsigned char port, unsigned char num, unsigned char nibble)
{
    DIO_write_nibble(port, num, nibble);
} 