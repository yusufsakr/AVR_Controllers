/*
 * Keypad_Test.c
 *
 * Created: 10/13/2021 11:44:07 AM
 *  Author: Lankash
 */ 

#include "KeyPad.h"

void keypad_init (unsigned char port)
{
	DIO_set_pin_dir(port, 0,1);      //Set Column (1) as 'O/P'.
	DIO_set_pin_dir(port, 1, 1);     //Set Column (2) as 'O/P'.
	DIO_set_pin_dir(port, 2, 1);     //Set Column (3) as 'O/P'.
	DIO_set_pin_dir(port, 3, 1);     //Set Column (4) as 'O/P'.
	
	DIO_set_pin_dir(port, 4, 0);      //Set Row (1) as 'I/P'.
	DIO_set_pin_dir(port, 5, 0);      //Set Row (2) as 'I/P'.
	DIO_set_pin_dir(port, 6, 0);      //Set Row (3) as 'I/P'.
	DIO_set_pin_dir(port, 7, 0);      //Set Row (4) as 'I/P'.
	
	DIO_connect_pullup(port, 4, 1);   //Connect Internal Pull-Up on 'I/P' pin of Row (1).
	DIO_connect_pullup(port, 5, 1);   //Connect Internal Pull-Up on 'I/P' pin of Row (2).
	DIO_connect_pullup(port, 6, 1);   //Connect Internal Pull-Up on 'I/P' pin of Row (3).
	DIO_connect_pullup(port, 7, 1);   //Connect Internal Pull-Up on 'I/P' pin of Row (4).
	
}

//.....................................................................................

unsigned char keypad_read (unsigned char port)
{
	unsigned char key[4][4] = {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'A', '0', '=', '+'}};
	unsigned char row, coloumn, x;
	unsigned char Key_value = 0xFF;
	
	for (row=0; row<4; row++)
	{
		DIO_write_pin(port, 0, 1);    //Write 'High' on Coloumn (1).
		DIO_write_pin(port, 1, 1);    //Write 'High' on Coloumn (2).
		DIO_write_pin(port, 2, 1);    //Write 'High' on Coloumn (3).
		DIO_write_pin(port, 3, 1);    //Write 'High' on Coloumn (4).
		
		DIO_write_pin(port, row, 0);  //Write 'Low' on specific Colomn.
	    
	    for (coloumn=0; coloumn<4; coloumn++)
		{
			x = DIO_read_pin(port, (coloumn+4));
			
			if (0==x)
			{
				Key_value = key[row][coloumn];
				break;
			}
		}
		
		if (0==x)
		{
			break;
		}
	}
	
	return Key_value;
	
}

//..................................................................................