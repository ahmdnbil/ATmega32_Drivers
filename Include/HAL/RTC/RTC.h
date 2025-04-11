/**
 * @file RTC.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef B7F30907_BF1F_4BC8_9138_163F0BDF94CE
#define B7F30907_BF1F_4BC8_9138_163F0BDF94CE



/*************** LIB includes ******************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/TWI/TWI.h"
#include <string.h>

/***********************************************/

/************* MACRO Declarations **************/
#define DS1307_ADD 0b1101000
#define DS1307_FIRST_ADD_TIME 0x00
#define DS1307_FIRST_ADD_DATE 0x03

#define DS1307_CONTROL_REGISTER 0x07
#define OUTPUT_CONTROL_BIT 7
#define SQWE 4
#define RS1 1
#define RS0 0
// for hourse register to select between 12 & 24 mode, and for 12 mode choose between PM & AM

#define HOURS_MODE_BIT 6
#define _12_HOURSE_MODE_BIT 5
/***********************************************/

typedef enum
{
    _1_HZ,
    _4096_HZ,
    _8192_HZ,
    _32768_HZ,
    High,
    Low
}SQWE_signal;

typedef enum
{
    PM,
    AM,
    _24_MODE
} TIME_Format;

TWI_STATUS RTC_u8ConfigOutSignal(SQWE_signal signal);
TWI_STATUS RTC_u8SetTime(uint8_t *TiemPtr, TIME_Format format);
TWI_STATUS RTC_u8SetDate(uint8_t *datePtr);
TWI_STATUS RTC_u8GetTime(uint8_t *timePtr , uint8_t * Pzone);
TWI_STATUS RTC_u8GetDate(uint8_t *datePtr, uint8_t *dayPtr);

#endif /* B7F30907_BF1F_4BC8_9138_163F0BDF94CE */
