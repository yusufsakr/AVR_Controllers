/*

Code Created by "LANKASH" 
  @ 10/9/2021

File Contents : Buzzer Function Prototypes. 

*/

#ifndef BUZZER_H_
#define BUZZER_H_


/*
    Function name         :  BUZZER_init
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin
    Function Description  :  Function to initialize the ports to the Buzzer as 'O/P'
*/
void BUZZER_init (unsigned char port, unsigned char pin);


/*
    Function name         :  BUZZER_on
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin
    Function Description  :  Function to set the Buzzer 'PIN' as 'HIGH'
*/
void BUZZER_on (unsigned char port, unsigned char pin);

#endif


