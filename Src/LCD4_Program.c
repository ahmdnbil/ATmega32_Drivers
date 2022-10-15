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




void HLCD4_voidSendCommand(u8 A_u8Command)
{
    //RS=0 RW=0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);

    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,PIN_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_us(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
    _delay_us(2);

    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command<<4);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_us(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
    _delay_us(2);
}


void HLCD4_voidSendData(u8 A_u8Data)
{
    //RS=1 RW=0
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,PIN_LOW);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_us(10);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
    _delay_us(10);

    MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data<<4);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_HIGH);
    _delay_us(10);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,PIN_LOW);
    _delay_us(10);
}



void HLCD4_voidInit()
{
    _delay_ms(30);
    HLCD4_voidSendCommand(FUNCTION_SET1);
    HLCD4_voidSendCommand(FUNCTION_SET2);
    HLCD4_voidSendCommand(FUNCTION_SET3);
    _delay_ms(1);
    HLCD4_voidSendCommand(ON_OFF_CONTROL1);
    HLCD4_voidSendCommand(ON_OFF_CONTROL2);
    _delay_ms(1);
    HLCD4_voidSendCommand(DISPLAY_CLEAR1);
    HLCD4_voidSendCommand(DISPLAY_CLEAR2);
    _delay_ms(2);
    HLCD4_voidSendCommand(ENTRY_MODE_SET1);
    HLCD4_voidSendCommand(ENTRY_MODE_SET2);
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
