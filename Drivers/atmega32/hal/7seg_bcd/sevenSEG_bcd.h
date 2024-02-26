/*

Code Created by "LANKASH" 
  @ 13/9/2021

File Contents : BCD to 7SEG Functions Implemintation. 

*/

#ifndef SEVENSEG_BCD_H_
#define SEVENSEG_BCD_H_

//................................................................................

#define  BCD_pin      0    //Defining The Pins of BCD_7SEG.
#define  BCD_nibble   0    //Defining the Nibble Value for Writing on the BCD_7SEG.

//................................................................................

/*
    Function name         :  sevenSEG_init_bcd
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin.
    Function Description  :  Set a specific 4 'PINS' as 'O/P' for the BCD to 7SEG.
*/
void sevenSEG_init_bcd(unsigned char port, unsigned char pin);

/*
    Function name         :  sevenSEG_write_bcd
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char num, unsigned char nibble
    Function Description  :  Send the value of the 'NUMBER' to the BCD.
*/
void sevenSEG_write_bcd(unsigned char port, unsigned char num, unsigned char nibble);

#endif