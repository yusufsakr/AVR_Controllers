/*

Code created by "LANKASH"
  @13/9/2021

File Contents : '7SEG' implimentation Functions

*/

#include "DIO.h"

void sevenSEG_init (unsigned char port)
{
  DIO_set_port_dir(port, 0xff);      //Set 'PORT' as 'O/P'.
}


void sevenSEG_write_num (unsigned char port, unsigned char num)    //Function types 'NUMBERS' on the 7SEG.
{
  switch (num)
  {
    case 0:
    DIO_write_port(port, 0x3F);    //Type '0' on the 7SEG.
    break;

    case 1:
    DIO_write_port(port, 0x06);    //Type '1' on the 7SEG.
    break;

    case 2:
    DIO_write_port(port, 0x5B);    //Type '2' on the 7SEG.
    break;

    case 3:
    DIO_write_port(port, 0x4F);    //Type '3' on the 7SEG.
    break;

    case 4:
    DIO_write_port(port, 0x66);    //Type '4' on the 7SEG.
    break;

    case 5:
    DIO_write_port(port, 0x6D);    //Type '5' on the 7SEG.
    break;

    case 6:
    DIO_write_port(port, 0x7D);    //Type '6' on the 7SEG.
    break;

    case 7:
    DIO_write_port(port, 0x47);    //Type '7' on the 7SEG.
    break;

    case 8:
    DIO_write_port(port, 0x7F);    //Type '8' on the 7SEG.
    break;

    case 9:
    DIO_write_port(port, 0x6F);    //Type '9' on the 7SEG.
    break;

    default:
    break;    
  }
}


void sevenSEG_write_alpha (unsigned char port, unsigned char alpha)    //Function to write Letters on the 7SEG.
{
  switch (alpha)
  {
    case 'A':
    DIO_write_port(port, 0x77);    //Type 'A' on the 7SEG.
    break;

    case 'a':
    DIO_write_port(port, 0x5E);    //Type 'a' on the 7SEG.
    break;

    case 'B':
    DIO_write_port(port, 0x7F);    //Type 'B' on the 7SEG.
    break;

    case 'b':
    DIO_write_port(port, 0x7C);    //Type 'b' on the 7SEG.
    break;

    case 'C':
    DIO_write_port(port, 0x58);    //Type 'C' on the 7SEG.
    break;

    case 'c':
    DIO_write_port(port, 0x58);    //Type 'c' on the 7SEG.
    break;

    case 'D':
    case 'd':
    DIO_write_port(port, 0x5E);    //Type 'd' on the 7SEG.
    break;

    case 'E':
    DIO_write_port(port, 0x79);    //Type '' on the 7SEG.
    break;

    case 'e':
    DIO_write_port(port, 0x7B);    //Type 'e' on the 7SEG.
    break;

    case 'F':
    case 'f':
    DIO_write_port(port, 0x71);    //Type 'f' on the 7SEG.
    break;

    case 'G':
    DIO_write_port(port, 0x3D);    //Type 'G' on the 7SEG.
    break;

    case 'g':
    DIO_write_port(port, 0x71);    //Type 'g' on the 7SEG.
    break;

    case 'H':
    DIO_write_port(port, 0x76);    //Type 'H' on the 7SEG.
    break;

    case 'h':
    DIO_write_port(port, 0x7C);    //Type 'h' on the 7SEG.
    break;

    case 'I':
    case 'i':
    DIO_write_port(port, 0x06);    //Type 'i' on the 7SEG.
    break;

    case 'J':
    DIO_write_port(port, 0x5F);    //Type 'J' on the 7SEG.
    break;

    case 'j':
    DIO_write_port(port, 0x5E);    //Type 'j' on the 7SEG.
    break;

    case 'K':
    case 'k':
    DIO_write_port(port, 0x7A);    //Type 'k' on the 7SEG.
    break;

    case 'L':
    case 'l':
    DIO_write_port(port, 0x38);    //Type 'l' on the 7SEG.
    break;

    case 'N':
    case 'n':
    DIO_write_port(port, 0x45);    //Type 'n' on the 7SEG.
    break;

    case 'O':
    DIO_write_port(port, 0x3F);    //Type 'O' on the 7SEG.
    break;

    case 'o':
    DIO_write_port(port, 0x9A);    //Type 'o' on the 7SEG.
    break;

    case 'P':
    case 'p':
    DIO_write_port(port, 0x37);    //Type 'p' on the 7SEG.
    break;

    case 'Q':
    DIO_write_port(port, 0xbF);    //Type 'Q' on the 7SEG.
    break;

    case 'q':
    DIO_write_port(port, 0x67);    //Type 'q' on the 7SEG.
    break;

    case 'R':
    DIO_write_port(port, 0x77);    //Type 'R' on the 7SEG.
    break;

    case 'r':
    DIO_write_port(port, 0x31);    //Type 'r' on the 7SEG.
    break;

    case 'S':
    case 's':
    DIO_write_port(port, 0x6B);    //Type 's' on the 7SEG.
    break;

    case 'T':
    case 't':
    DIO_write_port(port, 0x78);    //Type 't' on the 7SEG.
    break;

    case 'U':
    DIO_write_port(port, 0x3B);    //Type 'U' on the 7SEG.
    break;

    case 'u':
    DIO_write_port(port, 0x66);    //Type 'u' on the 7SEG.
    break;

    case 'Y':
    case 'y':
    DIO_write_port(port, 0x6F);    //Type 'y' on the 7SEG.
    break;

    case 'Z':
    case 'z':
    DIO_write_port(port, 0x5B);    //Type 'z' on the 7SEG.
    break;

    default:
    break;
}
}
