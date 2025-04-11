#define F_CPU 8000000UL
#include <util/delay.h>

// Libraries
#include "./Include/LIB/BIT_MATH.h"
#include "./Include/LIB/STD_TYPES.h"

// MCAL
#include "./Include/MCAL/DIO/DIO.h"
#include "./Include/MCAL/EXTI/EXTI.h"
#include "./Include/MCAL/ADC/ADC.h"
#include "./Include/MCAL/TIMER0/TIMER0.h"
#include "./Include/MCAL/TIMER1/TIMER1.h"
#include "./Include/MCAL/TIMER2/TIMER2.h"
#include "./Include/MCAL/WDT/WDT.h"
#include "./Include/MCAL/UART/UART.h"
#include "./Include/MCAL/SPI/SPI.h"
#include "./Include/MCAL/TWI/TWI.h"

// HAL
#include "./Include/HAL/SSD/SSD.h"
#include "./Include/HAL/LCD/LCD.h"
#include "./Include/HAL/KEYPAD/KEYPAD.h"
#include "./Include/HAL/SERVO/SERVO.h"
#include "./Include/HAL/ULTRASONIC/ULTRASONIC.h"
#include "./Include/HAL/RTC/RTC.h"
#include "./Include/HAL/ExEEPROM/ExEEPROM.h"

// services
#include "./Include/SERVICES/TIMERs/Timers.h"
#include "./Include/SERVICES/UART/UART_serv.h"

void main()
{
    uint8_t day[4];
    uint8_t timeZone[3];
    uint8_t data[4]={0x01, 0x18,0x11,0x09};
    uint8_t time[4]={0x00,0x00,0x15};
    sei();
    LCD_voidInit();
    TWI_voidInit(0x55);
    TWI_STATUS status =TWI_OK;
    SQWE_signal signal =_1_HZ;
    status = RTC_u8ConfigOutSignal(signal);
    status = RTC_u8SetDate(data);
    // status = RTC_u8SetDate();
    status = RTC_u8SetTime(time,PM);
    while (1)
    {
        status = RTC_u8GetDate(data,day);
        status = RTC_u8GetTime(time,timeZone);
        LCD_voidGoToPos(1,1);
        LCD_voidSendString("Data:");
        LCD_voidSendString(day);
        LCD_voidSendData(':');
        LCD_voidDisplayNumber(data[1]);
        LCD_voidSendData(':');
        LCD_voidDisplayNumber(data[2]);
        LCD_voidSendData(':');
        LCD_voidDisplayNumber(data[3]);
        LCD_voidGoToPos(2,1);
        LCD_voidSendString("Time:");
        LCD_voidDisplayNumber(time[2]);
        LCD_voidSendData(':');
        LCD_voidDisplayNumber(time[1]);
        LCD_voidSendData(':');
        LCD_voidDisplayNumber(time[0]);
        LCD_voidSendString("  ");
        LCD_voidSendString(timeZone);
        
    }
}

