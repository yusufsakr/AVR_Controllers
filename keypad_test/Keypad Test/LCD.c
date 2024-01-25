/*

Code created by "LANKASH"
  @2/10/2021

File Contents : 'LCD' implementation Functions

*/

#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>


static void LCD_send_falling_edge ()
{
	DIO_write_pin(ctrl_port, EN, 1);
	_delay_ms(2);
	DIO_write_pin(ctrl_port, EN, 0);
	_delay_ms(2);
} 

//.......................................................................

void LCD_send_cmd (unsigned char cmd)  
{
  #if defined eight_bit_mode           //@ 8-Bit mode
	DIO_write_port(data_port, cmd);
	DIO_write_pin(ctrl_port, RS, 0);
	LCD_send_falling_edge();

  #elif defined four_bit_mode     //@ 4-Bit mode
	DIO_write_nibble(data_port, cmd>>4, nibble);
	DIO_write_pin(ctrl_port, RS, 0);
	LCD_send_falling_edge();
	
	DIO_write_nibble(data_port, cmd, nibble);
	DIO_write_pin(ctrl_port, RS, 0);
	LCD_send_falling_edge();
	_delay_ms(1);

  #endif
}

//.......................................................................

void LCD_init()     
{
#if defined eight_bit_mode           //@ 8-Bit mode
  _delay_ms(50);
  DIO_set_port_dir(data_port, 1);
  DIO_set_pin_dir(ctrl_port, EN, 1);    //Set the 'ENABLE' Pin as 'O/P'
  DIO_set_pin_dir(ctrl_port, RS, 1);    //Set the 'RESET' Pin as 'O/P'
  DIO_set_pin_dir(ctrl_port, RW, 1);    //Set the 'READ/WRITE' Pin as 'O/P'
  
  DIO_write_pin(ctrl_port, RW, 0);
  
  LCD_send_cmd(eight_bit_mode_2_line_5x7_dot);
  _delay_ms(1);
  
  LCD_send_cmd(disp_on_curs_on_solid);
  _delay_ms(1);

  LCD_send_cmd(clr_disp);
  _delay_ms(10);  

  LCD_send_cmd(entry_DDRAM_inc_dis_right);
  _delay_ms(1);

#elif defined four_bit_mode     //@ 4-Bit mode
  _delay_ms(50);
  DIO_set_pin_dir(data_port, D4, 1);
  DIO_set_pin_dir(data_port, D5, 1);
  DIO_set_pin_dir(data_port, D6, 1);
  DIO_set_pin_dir(data_port, D7, 1);
  DIO_set_pin_dir(ctrl_port, EN, 1);    //Set the 'ENABLE' Pin as 'O/P'
  DIO_set_pin_dir(ctrl_port, RS, 1);    //Set the 'RESET' Pin as 'O/P'
  DIO_set_pin_dir(ctrl_port, RW, 1);    //Set the 'READ/WRITE' Pin as 'O/P'
  
  DIO_write_pin(ctrl_port, RW, 0);
  
  LCD_send_cmd(four_bit_mode_2_line_5x7_dot);
  _delay_ms(1);
  
  LCD_send_cmd(disp_on_curs_on_blink);
  _delay_ms(1);
  
  LCD_send_cmd(clr_disp);
  _delay_ms(10);
  
  LCD_send_cmd(entry_DDRAM_inc_dis_right);
  _delay_ms(1);

#endif
}

//.......................................................................

void LCD_send_char (unsigned char data)  
{
#if defined eight_bit_mode           //@ 8-Bit mode
  DIO_write_port(data_port, data);
  DIO_write_pin(ctrl_port, RS, 1);
  LCD_send_falling_edge();

#elif defined four_bit_mode          //@ 4-Bit mode
  DIO_write_nibble(data_port, data>>4, nibble);   //Low Nibble
  DIO_write_pin(ctrl_port, RS, 1);
  LCD_send_falling_edge();
  
  DIO_write_nibble(data_port, data, nibble);     //Low Nibble
  DIO_write_pin(ctrl_port, RS, 1);
  LCD_send_falling_edge();
  _delay_ms(1);

#endif
}

//.......................................................................

void LCD_send_string (unsigned char *data)
{
  while((*data) != '\0')
  {
	  LCD_send_char(*data);
	  data++;
  }
}

//.......................................................................

void LCD_clear_screen ()
{
  LCD_send_cmd(clr_disp);
  _delay_ms(10);
}

//.......................................................................

void LCD_move_cursor (unsigned char row, unsigned char coloumn)
{
  unsigned char data;
  
  if((row>2) || (row<1) || (coloumn>16) || (coloumn<1))
  {
	  data = 0x80;
  }
  
  else if(1==row)
  {
	  data = 0x80 + (coloumn-1);
  }
  
  else if(2==row)
  {
	  data = 0xc0 + (coloumn-1);
  }
  
  LCD_send_cmd(data);
  _delay_ms(1);
}

//.......................................................................






