#ifndef _SSD_CONFIG_H_
#define _SSD_CONFIG_H_

#include "./../../MCAL/DIO/DIO.h"
#include "./../../LIB/STD_TYPES.h"
#include "./../../LIB/BIT_MATH.h"



// a    b    c    d    e    f    g 
//PD0  PD1  PD2  PD3  PD4  PD5  PD6

#define SSD_DATA_PORT PORTD

#define ZERO 0b00111111
#define ONE 0b00000110
#define TWO 0b01011011
#define THREE 0b01001111
#define FOUR 0b01100110
#define FIVE 0b01101101
#define SIX 0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE 0b01101111

#endif /* _SSD_CONFIG_H_ */
