/*
 * single_7seg.c
 *
 * Created: 2/16/2022 8:00:14 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>

#include "sevenSEG_bcd.h"

#define seg1_port 'A'
#define seg2_port 'A'

int main(void)
{
	unsigned char count = 0;
	sevenSEG_init_bcd(seg1_port, 0);
	sevenSEG_init_bcd(seg2_port, 4);
	
    while(1)
    {
        if (count <= 9)
		{
			sevenSEG_write_bcd(seg1_port, count, 0);
			sevenSEG_write_bcd(seg2_port,     0, 1);
		}
		else if ((count > 9) && (count <= 99))
		{
			sevenSEG_write_bcd(seg1_port, (count%10), 0);
			sevenSEG_write_bcd(seg2_port, (count/10), 1);
		}
		else
		{
			count = -1;
		}
		
		count ++;
	    _delay_ms(1000);
		
    }
}