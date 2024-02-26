/*

Code created by "LANKASH"
  @2/10/2021

File Contents : 'LCD' implementation Functions

*/

#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_config.h"

#define clr_disp                         0x001    //Clear LCD Display
#define rtn_home                         0x002    //Return Home in LCD

#define entry_DDRAM_inc_dis_left         0x007    //Entry set point: DDRAM increase, Display shift left
#define entry_DDRAM_inc_dis_right        0x006    //Entry set point: DDRAM increase, Display shift right
#define entry_DDRAM_dec_dis_left         0x005    //Entry set point: DDRAM decrease, Display shift left
#define entry_DDRAM_dec_dis_right        0x004    //Entry set point: DDRAM decrease, Display shift right

#define disp_on_curs_on_blink            0x00F    //Display: ON,  Cursor: ON & Blink
#define disp_on_curs_on_solid            0x00E    //Display: ON,  Cursor: ON & Solid
#define disp_on_curs_off_blink           0x00D    //Display: ON,  Cursor: OFF & Blink
#define disp_on_curs_off_solid           0x00C    //Display: ON,  Cursor: OFF & Solid
#define disp_off_curs_on_blink           0x00B    //Display: OFF, Cursor: ON & Blink
#define disp_off_curs_on_solid           0x00A    //Display: OFF, Cursor: ON & Solid
#define disp_off_curs_off_blink          0x009    //Display: OFF, Cursor: OFF & Blink
#define disp_off_curs_off_solid          0x008    //Display: OFF, Cursor: OFF & Solid

#define shift_curs_right                 0x010    //Shift Cursor right 1 location
#define shift_curs_left                  0x014    //Shift Cursor left 1 location
#define shift_disp_right                 0x018    //Shift Display right 1 location
#define shift_disp_left                  0x01C    //Shift Display left 1 location

#define four_bit_mode_1_line_5x7_dot     0x020    //4-Bit Mode + 1 Line Display + 5*10 dot
#define four_bit_mode_1_line_5x10_dot    0x021    //4-Bit Mode + 1 Line Display + 5*7 dot
#define four_bit_mode_2_line_5x7_dot     0x022    //4-Bit Mode + 2 Line Display + 5*10 dot

#define eight_bit_mode_1_line_5x7_dot    0x030    //8-Bit Mode + 1 Line Display + 5*7 dot
#define eight_bit_mode_1_line_5x10_dot   0x031    //8-Bit Mode + 1 Line Display + 5*10 dot
#define eight_bit_mode_2_line_5x7_dot    0x032    //8-Bit Mode + 2 Line Display + 5*7 dot

//..............................................................................................

#define data_port 'A'      //The Data/Command port.
#define D4 0             
#define D5 1
#define D6 2
#define D7 3

#define ctrl_port 'B'     //Control Pins port.
#define EN 0              //Enable Pin.
#define RS 1              //Register Selection Pin.
#define RW 2              //Read/Write Pin.

//.............................................................................................

#define nibble 1 // High Nibble @1, Low Nibble @0.

//.............................................................................................

/*
    Function name         :  LCD_send_cmd
    Function Returns      :  void
    Function Arguments    :  unsigned char.
    Function Description  :  Sends the commands to the LCD.
*/
void LCD_send_cmd (unsigned char cmd);

/*
    Function name         :  LCD_init
    Function Returns      :  void
    Function Arguments    :  
    Function Description  :  Initializes the LCD Connections and Mode (by Macros above).
*/
void LCD_init();

/*
    Function name         :  LCD_send_char
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char data.
    Function Description  :  Type a Character on the LCD.
*/
void LCD_send_char (unsigned char data);

/*
    Function name         :  LCD_send_string
    Function Returns      :  void
    Function Arguments    :  unsigned char *data.
    Function Description  :  Type String on the LCD.
*/
void LCD_send_string (unsigned char* data);


/*
    Function name         :  LCD_clear_screen
    Function Returns      :  void
    Function Arguments    :  
    Function Description  :  Clear the Display on the LCD.
*/
void LCD_clear_screen ();

/*
    Function name         :  LCD_move_cursor
    Function Returns      :  void
    Function Arguments    :  unsigned char row, unsigned char coloumn.
    Function Description  :  Select the Cursor position on the LCD.
*/
void LCD_move_cursor (unsigned char row, unsigned char coloumn);      


#endif /* LCD_H_ */


