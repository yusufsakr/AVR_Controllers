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
#include "DIO.h"

#define seg_port 'A'
#define seg1      4
#define seg2      5

int main(void)
{
	unsigned char count = 0;
    sevenSEG_init_bcd(seg_port, 0);
	sevenSEG_init_bcd(seg_port, 4);
	//DIO_set_port_dir(seg_port, 0xff);
	
    while(1)
    {
        if (count <= 9)
		{
			DIO_write_pin(seg_port, seg1, 1);
			_delay_ms(5);
			sevenSEG_write_bcd(seg_port, count, 0);
			_delay_ms(5);
			DIO_write_pin(seg_port, seg1, 0);
			
			_delay_ms(20);
			
			DIO_write_pin(seg_port, seg1, 1);
			_delay_ms(5);
			sevenSEG_write_bcd(seg_port, 0, 0);
			_delay_ms(5);
			DIO_write_pin(seg_port, seg2, 0);
			
			_delay_ms(20);
		}
		else if ((count > 9) && (count <= 99))
		{
			DIO_write_pin(seg_port, seg1, 1);
			_delay_ms(5);
			sevenSEG_write_bcd(seg_port, (count%10), 0);
			_delay_ms(5);
			DIO_write_pin(seg_port, seg1, 0);
			
			_delay_ms(20);
			
			DIO_write_pin(seg_port, seg2, 1);
			_delay_ms(5);
			sevenSEG_write_bcd(seg_port, (count/10), 0);
			_delay_ms(5);
			DIO_write_pin(seg_port, seg2, 0);
			
			_delay_ms(20);
		}
		else
		{
			count = -1;
		}
		
		count ++;
	    _delay_ms(1000);
		
    }
}