/*
 * TWI_Program.c
 *
 *  Created on: Sep 18, 2023
 *      Author: ahmed nabil
 */

#ifndef C3223708_AB76_4C37_B428_D95E6459E02C
#define C3223708_AB76_4C37_B428_D95E6459E02C

#define DS1307_ADD             0b1101000
#define DS1307_FIRST_ADD_TIME  0x00
#define DS1307_FIRST_ADD_DATE  0x03

/***********************************************/
#define DS1307_CONTROL_REGISTER 0x07
#define OUTPUT_CONTROL_BIT 7
#define SQWE               4
#define RS1                1
#define RS0                0
/***********************************************/
//for hourse register to select between 12 & 24 mode, and for 12 mode choose between PM & AM

#define HOURS_MODE_BIT 6
#define _12_HOURSE_MODE_BIT 5
/***********************************************/
#endif /* C3223708_AB76_4C37_B428_D95E6459E02C */
