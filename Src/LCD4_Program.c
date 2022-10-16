/*
 * LCD4_Program.c
 *
 *  Created on: Oct 14, 2022
 *      Author: User
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

#include <util/delay.h>

#include "../Include/HAL/LCD4/LCD4_Private.h"
#include "../Include/HAL/LCD4/LCD4_Configuration.h"
#include "../Include/HAL/LCD4/LCD4_Interface.h"



static u8 global_u8Init=0;

void HLCD4_voidSendCommand(u8 A_u8Command)
{
    //RS=0 RW=0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,PIN_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);

    //send UPPER Bits (B7 to B4)
    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);


    //pulse HIGH to LOW to ENABLE PIN
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_ms(1);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);

    if(global_u8Init)
    {

        //send LOWR Bits (B3 to B0)
        MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command<<4);

        //pulse HIGH to LOW to ENABLE PIN
        MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
        _delay_ms(1);
        MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
    }
    _delay_ms(2);
}


void HLCD4_voidSendData(u8 A_u8Data)
{
    //RS=1 RW=0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);

	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);


    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_ms(1);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);

    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data<<4);


    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_ms(1);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
    _delay_ms(2);
}



void HLCD4_voidInit()
{
    _delay_ms(30);
    HLCD4_voidSendCommand(FUNCTION_SET1);
    HLCD4_voidSendCommand(FUNCTION_SET2);
    HLCD4_voidSendCommand(FUNCTION_SET3);
    _delay_us(40);
    HLCD4_voidSendCommand(ON_OFF_CONTROL1);
    HLCD4_voidSendCommand(ON_OFF_CONTROL2);
    _delay_us(40);
    HLCD4_voidSendCommand(DISPLAY_CLEAR1);
    HLCD4_voidSendCommand(DISPLAY_CLEAR2);
    _delay_ms(2);
    HLCD4_voidSendCommand(ENTRY_MODE_SET1);
    HLCD4_voidSendCommand(ENTRY_MODE_SET2);
    global_u8Init=1;
} 

void HLCD4_voidClearDisplay(void)
{
    HLCD4_voidSendCommand(DISPLAY_CLEAR1);
    HLCD4_voidSendCommand(DISPLAY_CLEAR2);
    _delay_ms(2);
}

void HLCD4_voidSendString(u8 * A_Pu8String)
{
    u8 local_u8Couter=0;
    while (A_Pu8String[local_u8Couter]!='\0')
    {
        HLCD4_voidSendData(A_Pu8String[local_u8Couter]);
        local_u8Couter++;
    }
    
}

void HLCD4_voidGoToPos(u8 A_u8RowNum,u8 A_u8ColNum)
{
    //First Method
    // switch (A_u8RowNum)
    // {
    // case LCD_ROW_ONE:
    // HLCD4_voidSendCommand(LCD_ROW1_ADDRESS+A_u8ColNum);
    //     break;
    
    // case LCD_ROW_TWO:
    // HLCD4_voidSendCommand(LCD_ROW2_ADDRESS+A_u8ColNum);
    //     break;
    // }
    // _delay_ms(1);

    //*******************************//
    //Second method
	u8 local_u8Address;
    switch(A_u8RowNum)
    {
        case LCD_ROW_ONE:
        local_u8Address=FIRST_ROW_ADDRESS + A_u8ColNum -1;
        SET_BIT(local_u8Address,PIN7);
        HLCD4_voidSendCommand(local_u8Address);
        break;

        case LCD_ROW_TWO:
        local_u8Address=SECOND_ROW_ADDRESS + A_u8ColNum;
        SET_BIT(local_u8Address,PIN7);
        HLCD4_voidSendCommand(local_u8Address);
        break;

    }
    _delay_ms(1);

}

void HLCD4_voidDisplayNumber(u32 A_u32Number)
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
    //     HLCD4_voidSendData(local_u8Rem);
    //     local_u32Rev/=10;
    // }

    //****************************************************//
    // second method: using built in library itoa(number,string,base)
    // u8 local_u8NumToStr[100];
    // itoa(A_u32Number,local_u8NumToStr,10);
    // HLCD4_voidSendString(local_u8NumToStr);
    //****************************************************//
    //third method: it will deal with zero unlike the first method so it's not problem here
    u32 local_u32Number=1;
    if(A_u32Number==0)
    {
        HLCD4_voidSendData('0');
    }   
    while(A_u32Number !=0)
    {
            local_u32Number=((local_u32Number * 10)+(A_u32Number%10));
            A_u32Number=A_u32Number/10;

    }
    while (local_u32Number!=1)
    {
        HLCD4_voidSendData((local_u32Number%10)+48);
        local_u32Number=local_u32Number/10;
    }
}

void HLCD4_voidStoreCustomChar(u8 * A_u8Pattern,u8 A_u8CGRAMIndex)
{
    u8 local_u8Address;
    if(A_u8CGRAMIndex<8)
    {
        A_u8CGRAMIndex=A_u8CGRAMIndex*8;
        SET_BIT(A_u8CGRAMIndex,PIN6);
        CLR_BIT(A_u8CGRAMIndex,PIN7);
        HLCD4_voidSendCommand(A_u8CGRAMIndex);
        for(u8 i=0;i<8;i++)
        {
            HLCD4_voidSendData(A_u8Pattern[i]);
            _delay_us(60);
        }
    }
    HLCD4_voidSendCommand(RETURN_HOME);
    _delay_ms(2);

}

void HLCD4_voidDisplayCustomChar(u8 A_u8CGRAMIndex,u8 A_u8Row,u8 A_u8Col)
{
    HLCD4_voidGoToPos(A_u8Row,A_u8Col);
    HLCD4_voidSendData(A_u8CGRAMIndex);
}