/*
 * Timer_traffic_light.c
 *
 * Created: 5/17/2023 12:15:17 AM
 *  Author: Yusuf Sakr
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
//#define F_CPU  8000000UL
//#include <util/delay.h>

#include "Timer.h"
#include "LED.h"

#define green_time  500
#define yellow_time 200
#define red_time    500

volatile unsigned int counter   = 0;

int main(void)
{
	unsigned char mode      = 1; //1->red, 2->yellow, 3->green, 4->yellow
	unsigned char mode_prev = 0;
	
	LED_init ('A', 0);  //Red Light
	LED_init ('A', 1);  //Yellow Light
	LED_init ('A', 2);  //Green Light
	
	LED_off ('A', 0);   //Red Light
	LED_off ('A', 1);   //Yellow Light
	LED_off ('A', 2);   //Green Light
	
	Timer_CTC_init_interrupt (79, 1024);  //CTC_time = 10 mSec
	
    while(1)
    {
		while (1 == mode){
			if ((1 == mode) && (mode != mode_prev)){
				LED_on  ('A', 0);   //Red Light
				LED_off ('A', 1);   //Yellow Light
				LED_off ('A', 2);   //Green Light
				mode_prev = mode;
			}
			
			if (counter >= 1000){
				counter = 0;
				mode = 2;
			}
		}
		
		while (2 == mode){
			if ((2 == mode) && (mode != mode_prev)){
				LED_off ('A', 0);   //Red Light
				LED_on  ('A', 1);   //Yellow Light
				LED_off ('A', 2);   //Green Light
				mode_prev = mode;
			}
			
			if (counter >= 300){
				counter = 0;
				mode = 3;
			}
		}
		
		while (3 == mode){
			if ((3 == mode) && (mode != mode_prev)){
				LED_off ('A', 0);   //Red Light
				LED_off ('A', 1);   //Yellow Light
				LED_on  ('A', 2);   //Green Light
				mode_prev = mode;
			}
			
			if (counter >= 1000){
				counter = 0;
				mode = 4;
			}
		}
		while (4 == mode){
			if ((4 == mode) && (mode != mode_prev)){
				LED_off ('A', 0);   //Red Light
				LED_on  ('A', 1);   //Yellow Light
				LED_off ('A', 2);   //Green Light
				
				mode_prev = mode;
			}
			
			if (counter >= 300){
				counter = 0;
				mode = 1;
			}
		}
		
    }
}

ISR (TIMER0_COMP_vect){
	counter++;
}