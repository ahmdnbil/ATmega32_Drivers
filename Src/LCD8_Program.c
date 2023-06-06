/*
 * LCD_Program.c
 *
 *  Created on: Oct 13, 2022
 *      Author: User
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

#include <util/delay.h>

#include "../Include/HAL/LCD8/LCD8_Private.h"
#include "../Include/HAL/LCD8/LCD8_Configuration.h"
#include "../Include/HAL/LCD8/LCD8_Interface.h"
#define F_CPU 8000000UL
#include <math.h>
#include <stdlib.h>

void HLCD8_voidSendCommand(u8 A_u8Command)
{
    //RS=0 RW=0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,PIN_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);

    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
}


void HLCD8_voidSendData(u8 A_u8Data)
{
    //RS=1 RW=0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);

    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
}


void HLCD8_voidInit()
{
    _delay_ms(30);
    HLCD8_voidSendCommand(FUNCTION_SET);
    _delay_ms(1);
    HLCD8_voidSendCommand(ON_OFF_CONTROL);
    _delay_ms(1);
    HLCD8_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
    HLCD8_voidSendCommand(ENTRY_MODE_SET);
}

void HLCD8_voidClearDisplay(void)
{
    HLCD8_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
}


void HLCD8_voidSendString(u8 * A_Pu8String)
{
    u8 local_u8Couter=0;
    while (A_Pu8String[local_u8Couter]!='\0')
    {
        HLCD8_voidSendData(A_Pu8String[local_u8Couter]);
        local_u8Couter++;
    }
    
}

void HLCD8_voidGoToPos(u8 A_u8RowNum,u8 A_u8ColNum)
{
    // switch (A_u8RowNum)
    // {
    // case LCD_ROW_ONE:
    // HLCD8_voidSendCommand(LCD_ROW1_ADDRESS+A_u8ColNum);
    //     break;
    
    // case LCD_ROW_TWO:
    // HLCD8_voidSendCommand(LCD_ROW2_ADDRESS+A_u8ColNum);
    //     break;
    // }
    // _delay_ms(1);
    /************************************************************/ 
    //Second method
	u8 local_u8Address;
    switch(A_u8RowNum)
    {
        case LCD_ROW_ONE:
        local_u8Address=FIRST_ROW_ADDRESS + A_u8ColNum -1;
        SET_BIT(local_u8Address,PIN7);
        HLCD8_voidSendCommand(local_u8Address);
        break;

        case LCD_ROW_TWO:
        local_u8Address=SECOND_ROW_ADDRESS + A_u8ColNum;
        SET_BIT(local_u8Address,PIN7);
        HLCD8_voidSendCommand(local_u8Address);
        break;

    }
    _delay_ms(1);

}

void HLCD8_voidDisplayNumber(u32 A_u32Number)
{
    //first method: the shortage of this function, it will not take zeros in account
    //if number is 12309 it will print 123

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
    //     HLCD8_voidSendData(local_u8Rem);
    //     local_u32Rev/=10;
    // }

    //****************************************************//
    // second method: using built in library itoa(number,string,base)
    // u8 local_u8NumToStr[100];
    // itoa(A_u32Number,local_u8NumToStr,10);
    // HLCD8_voidSendString(local_u8NumToStr);
    //****************************************************//
    //third method: it will deal with zero unlike the first method so it's not problem here
    u32 local_u32Number=1;
    if(A_u32Number==0)
    {
        HLCD8_voidSendData('0');
    }   
    while(A_u32Number !=0)
    {
        local_u32Number=((local_u32Number * 10)+(A_u32Number%10));
        A_u32Number=A_u32Number/10;

    }
    while (local_u32Number!=1)
    {
        HLCD8_voidSendData((local_u32Number%10)+48);
        local_u32Number=local_u32Number/10;
    }
}

void HLCD8_voidStoreCustomChar(u8 * A_u8Pattern,u8 A_u8CGRAMIndex)
{
    u8 local_u8Address;
    if(A_u8CGRAMIndex<8)
    {
        A_u8CGRAMIndex=A_u8CGRAMIndex*8;
        SET_BIT(A_u8CGRAMIndex,PIN6);
        CLR_BIT(A_u8CGRAMIndex,PIN7);
        HLCD8_voidSendCommand(A_u8CGRAMIndex);
        for(u8 i=0;i<8;i++)
        {
            HLCD8_voidSendData(A_u8Pattern[i]);
            _delay_us(60);
        }
    }
    HLCD8_voidSendCommand(RETURN_HOME);
    _delay_ms(2);

}

void HLCD8_voidDisplayCustomChar(u8 A_u8CGRAMIndex,u8 A_u8Row,u8 A_u8Col)
{
    HLCD8_voidGoToPos(A_u8Row,A_u8Col);
    HLCD8_voidSendData(A_u8CGRAMIndex);
}