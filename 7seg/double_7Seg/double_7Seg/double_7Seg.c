/*
 * single_7seg.c
 *
 * Created: 2/16/2022 8:00:14 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "seven_SEG.h"

#define seg1_port 'A'
#define seg2_port 'D'

int main(void)
{
	unsigned char count = 0;
	sevenSEG_init(seg1_port);
	sevenSEG_init(seg2_port);
	
    while(1)
    {
        if (count <= 9)
		{
			sevenSEG_write_num(seg1_port, count);
			sevenSEG_write_num(seg2_port, 0);
		}
		else if ((count > 9) && (count <= 99))
		{
			sevenSEG_write_num(seg1_port, (count%10));
			sevenSEG_write_num(seg2_port, (count/10));
		}
		else
		{
			count = -1;
		}
		
		count ++;
	    _delay_ms(1000);
		
    }
}