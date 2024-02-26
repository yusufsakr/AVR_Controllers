/*

Code Created by "LANKASH" 
  @ 11/9/2021

File Contents : 'Relay' Function Prototypes. 

*/

#ifndef RELAY_H_
#define RELAY_H_


/*
    Function name         :  RELAY_init
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin.
    Function Description  :  Set the Pin as 'O/P' for the 'RELAY'.
*/
void RELAY_init(unsigned char port, unsigned char pin);


/*
    Function name         :  RELAY_on
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin.
    Function Description  :  Set the Pin of the 'RELAY' as 'HIGH'.
*/
void RELAY_on(unsigned char port, unsigned char pin);


/*
    Function name         :  RELAY_off
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin.
    Function Description  :  Set the Pin of the 'RELAY' as 'LOW'.
*/
void RELAY_off(unsigned char port, unsigned char pin);


/*
    Function name         :  RELAY_toogle
    Function Returns      :  void
    Function Arguments    :  unsighned char port, unsigned char pin.
    Function Description  :  Toogle the 'O/P'pin of the 'RELAY' from 'HIGH' to 'LOW', and vise versa.
*/
void RELAY_toogle(unsigned char port, unsigned char pin);

#endif