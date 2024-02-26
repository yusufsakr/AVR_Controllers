/*

Code created by "LANKASH"
   @11/9/2021

File contents : 'EEPROM' functions Implementation.

*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "my_macros.h"

//#define EEARL *((volatile unsigned char*)(0x3E))    //Write in 'EEARL' REG.
//#define EEARH *((volatile unsigned char*)(0x3f))    //Write in 'EEARH' REG.

//#define EEAR *((volatile unsigned short*)(0x3E))    //Write in the two REGs ('EEARL' & 'EEARH') @ the same time.



void EEPROM_write(unsigned short address, unsigned char data)
{
    unsigned char I = 0;
    EEARL = (char)address;        //Put the Low nibble 'ADDRESS' on 'EEARL' REG. 
    EEARH = (char)(address>>8);   //Put the high nibble 'ADDRESS' on 'EEARH' REG.

    EEDR = data;                  //Write  'DATA'(10-bit) on 'EEARL' & 'EEARH' REGs.   

    if (1 == READ_BIT(SREG, 7))
    {
	    I = 1;
	    cli();
    }

    SET_BIT(EECR, EEMWE);         //Enable the 'MASTER WRITE ENABLE' bit in 'CONTROL REG'.
    SET_BIT(EECR, EEWE);          //Enable the 'WRITE ENABLE' bit in 'CONTROL REG'.

    while(1 == (READ_BIT(EECR, EEWE)));   //To make shure that the data has been written Successfully.

    if(1 == I)
    {
	    sei();
    }
}


unsigned char EEPROM_read(unsigned short address)
{
	unsigned char I = 0;
	
    EEARL = (char)address;         //Put the Low nibble 'ADDRESS' on 'EEARL' REG. 
    EEARH = (char)(address>>8);    //Put the High nibble 'ADDRESS' on 'EEARH' REG. 

    if (1 == READ_BIT(SREG, 7))    //Check if Global Interrupt Bit is set to 1.
    {
	    I = 1;
	    cli();                     //Disable Global Interrupt, if it was SET.
    }

    SET_BIT(EECR, EERE);           //Enable the 'READ ENABLE' bit in 'CONTROL REG'.

    if(1 == I)
    {
	    sei();                     //Enable Global Interrupt, if it was SET.
    }

    return EEDR;                   //Return the read value from the 'EEPROM'.
}


void EEPROM_sei (void)
{
	sei();
	SET_BIT (EECR, EERIE);    //Enable EEPROM Read Interrupt
}

void EEPROM_cli (void)
{
	CLR_BIT (EECR, EERIE);    //Disable EEPROM Read Interrupt
}