/*

Code created by "LANKASH"
   @11/9/2021

File contents : 'LED' function.

*/

#ifndef LED_H_
#define LED_H_


/*
    Function name         :  LED_init
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned pin
    Function Description  :  Initialize the 'pin' of 'port' to the 'LED'
*/
void LED_init(unsigned char port, unsigned char pin);


/*
    Function name         :  LED_on
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned pin
    Function Description  :  Turn 'ON' the 'LED' on the 'pin' of 'port'
*/
void LED_on(unsigned char port, unsigned char pin);


/*
    Function name         :  LED_off
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned pin
    Function Description  :  Turn 'OFF' the 'LED' on the 'pin' of 'port'
*/
void LED_off(unsigned char port, unsigned char pin);


/*
    Function name         :  LED_toogle
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned pin
    Function Description  :  Toggle the 'LED' on the 'pin' of 'port' 
*/
void LED_toggle(unsigned char port, unsigned char pin);

#endif
















