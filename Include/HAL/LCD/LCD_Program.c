/*
 * LCD_Program.c
 *
 *  Created on: Oct 13, 2022
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "./LCD_Configuration.h"
#include "./LCD_Interface.h"
#include "./LCD_Private.h"

#include <math.h>
#include <stdlib.h>

#define F_CPU 8000000UL
#include <util/delay.h>

#if LCD_MODE == _8_BIT_MODE
void LCD_voidSendCommand(u8 A_u8Command)
{
    // RS=0 RW=0
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    DIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
}

void LCD_voidSendData(u8 A_u8Data)
{
    // RS=1 RW=0
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_HIGH);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    DIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
}

void LCD_voidInit()
{
    _delay_ms(30);
    LCD_voidSendCommand(FUNCTION_SET);
    _delay_ms(1);
    LCD_voidSendCommand(ON_OFF_CONTROL);
    _delay_ms(1);
    LCD_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
    LCD_voidSendCommand(ENTRY_MODE_SET);
}
#else
static u8 global_u8Init = 0;
void LCD_voidSendCommand(u8 A_u8Command)
{
    // RS=0 RW=0
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    // send UPPER Bits (B7 to B4)
    DIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);

    // pulse HIGH to LOW to ENABLE PIN
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);

    if (global_u8Init)
    {

        // send LOWR Bits (B3 to B0)
        DIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command << 4);

        // pulse HIGH to LOW to ENABLE PIN
        DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
        _delay_ms(1);
        DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
    }
    _delay_ms(2);
}

void LCD_voidSendData(u8 A_u8Data)
{
    // RS=1 RW=0
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_HIGH);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    DIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);

    DIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data << 4);

    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
    _delay_ms(2);
}
void LCD_voidInit()
{
    _delay_ms(30);
    LCD_voidSendCommand(FUNCTION_SET1);
    LCD_voidSendCommand(FUNCTION_SET2);
    LCD_voidSendCommand(FUNCTION_SET3);
    _delay_us(40);
    LCD_voidSendCommand(ON_OFF_CONTROL1);
    LCD_voidSendCommand(ON_OFF_CONTROL2);
    _delay_us(40);
    LCD_voidSendCommand(DISPLAY_CLEAR1);
    LCD_voidSendCommand(DISPLAY_CLEAR2);
    _delay_ms(2);
    LCD_voidSendCommand(ENTRY_MODE_SET1);
    LCD_voidSendCommand(ENTRY_MODE_SET2);
    global_u8Init = 1;
}
#endif

/******************the following functinos is valid for both 8bit & 4bit mode******************/
void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
}

void LCD_voidSendString(u8 *A_Pu8String)
{
    u8 local_u8Couter = 0;
    while (A_Pu8String[local_u8Couter] != '\0')
    {
        LCD_voidSendData(A_Pu8String[local_u8Couter]);
        local_u8Couter++;
    }
}

void LCD_voidGoToPos(u8 A_u8RowNum, u8 A_u8ColNum)
{
    // switch (A_u8RowNum)
    // {
    // case LCD_ROW_ONE:
    // LCD_voidSendCommand(LCD_ROW1_ADDRESS+A_u8ColNum);
    //     break;

    // case LCD_ROW_TWO:
    // LCD_voidSendCommand(LCD_ROW2_ADDRESS+A_u8ColNum);
    //     break;
    // }
    // _delay_ms(1);
    /************************************************************/
    // Second method
    u8 local_u8Address;
    switch (A_u8RowNum)
    {
    case LCD_ROW_ONE:
        local_u8Address = FIRST_ROW_ADDRESS + A_u8ColNum - 1;
        SET_BIT(local_u8Address, PIN7);
        LCD_voidSendCommand(local_u8Address);
        break;

    case LCD_ROW_TWO:
        local_u8Address = SECOND_ROW_ADDRESS + A_u8ColNum;
        SET_BIT(local_u8Address, PIN7);
        LCD_voidSendCommand(local_u8Address);
        break;
    }
    _delay_ms(1);
}

void LCD_voidDisplayNumber(u32 A_u32Number)
{
    // first method: the shortage of this function, it will not take zeros in account
    // if number is 12309 it will print 123

    // u32 local_u32Rev=0;
    // u8 local_u8Rem;
    // while(A_u32Number!=0)
    // {
    //     local_u8Rem=A_u32Number%10;
    //     local_u32Rev=local_u32Rev*10+local_u8Rem;
    //     A_u32Number/=10;
    // }
    // while(local_u32Rev!=0)
    // {
    //     local_u8Rem=local_u32Rev%10;
    //     local_u8Rem+=48;
    //     LCD_voidSendData(local_u8Rem);
    //     local_u32Rev/=10;
    // }

    //****************************************************//
    // second method: using built in library itoa(number,string,base)
    // u8 local_u8NumToStr[100];
    // itoa(A_u32Number,local_u8NumToStr,10);
    // LCD_voidSendString(local_u8NumToStr);
    //****************************************************//
    // third method: it will deal with zero unlike the first method so it's not problem here
    u32 local_u32Number = 1;
    if (A_u32Number == 0)
    {
        LCD_voidSendData('0');
    }
    while (A_u32Number != 0)
    {
        local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
        A_u32Number = A_u32Number / 10;
    }
    while (local_u32Number != 1)
    {
        LCD_voidSendData((local_u32Number % 10) + 48);
        local_u32Number = local_u32Number / 10;
    }
}

void LCD_voidStoreCustomChar(u8 *A_u8Pattern, u8 A_u8CGRAMIndex)
{
    if (A_u8CGRAMIndex < 8)
    {
        A_u8CGRAMIndex = A_u8CGRAMIndex * 8;
        SET_BIT(A_u8CGRAMIndex, PIN6);
        CLR_BIT(A_u8CGRAMIndex, PIN7);
        LCD_voidSendCommand(A_u8CGRAMIndex);
        for (u8 i = 0; i < 8; i++)
        {
            LCD_voidSendData(A_u8Pattern[i]);
            _delay_us(60);
        }
    }
    LCD_voidSendCommand(RETURN_HOME);
    _delay_ms(2);
}

void LCD_voidDisplayCustomChar(u8 A_u8CGRAMIndex, u8 A_u8Row, u8 A_u8Col)
{
    LCD_voidGoToPos(A_u8Row, A_u8Col);
    LCD_voidSendData(A_u8CGRAMIndex);
}
/*****************************************************************************/
