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

#define seg_port 'A'

int main(void)
{
	unsigned char count = 0;
	sevenSEG_init(seg_port);
	
    while(1)
    {
        sevenSEG_write_num(seg_port, count);	
		_delay_ms(1000);
		count ++;
		
		if (count >= 10)
		{
			count = 0;
		}
    }
}