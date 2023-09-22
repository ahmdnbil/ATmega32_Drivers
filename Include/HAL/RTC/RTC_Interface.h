/*
 * TWI_Program.c
 *
 *  Created on: Sep 18, 2023
 *      Author: ahmed nabil
 */
#ifndef B7F30907_BF1F_4BC8_9138_163F0BDF94CE
#define B7F30907_BF1F_4BC8_9138_163F0BDF94CE

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
TWI_STATUS RTC_u8SetTime(u8 *TiemPtr, TIME_Format format);
TWI_STATUS RTC_u8SetDate(u8 *datePtr);
TWI_STATUS RTC_u8GetTime(u8 *timePtr);
TWI_STATUS RTC_u8GetDate(u8 *datePtr);

#endif /* B7F30907_BF1F_4BC8_9138_163F0BDF94CE */
