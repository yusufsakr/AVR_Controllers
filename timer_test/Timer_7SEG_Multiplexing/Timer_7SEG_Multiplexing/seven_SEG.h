/*

Code created by "LANKASH"
  @13/9/2021

File Contents : '7SEG' implemintation Functions

*/

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_


/*
    Function name         :  sevenSEG_init
    Function Returns      :  void
    Function Arguments    :  unsigned char port.
    Function Description  :  Set the 'O/P' port for the 7SEG.
*/
void sevenSEG_init (unsigned char port);


/*
    Function name         :  sevenSEG_write_num
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char num.
    Function Description  :  Write 'NUMBERS' on the 7SEG.
*/
void sevenSEG_write_num (unsigned char port, unsigned char num);

/*
    Function name         :  sevenSEG_write
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char alpha.
    Function Description  :  Write 'LETTERS' on the 7SEG.
*/
void sevenSEG_write_alpha (unsigned char port, unsigned char alpha);


#endif 