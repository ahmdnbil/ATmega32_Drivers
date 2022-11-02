/*
 * main.c
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

//libraries
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

//EXTI
#include "../Include/MCAL/EXTI/EXTI_Interface.h"

//GI
#include "../Include/MCAL/GI/GI_Interface.h"
//SSD
#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/SSD/SSD_Configuration.h"


//LCD8
#include "../Include/HAL/LCD8/LCD8_Interface.h"
#include "../Include/HAL/LCD8/LCD8_Configuration.h"

//LCD4
#include "../Include/HAL/LCD4/LCD4_Configuration.h"
#include "../Include/HAL/LCD4/LCD4_Interface.h"

//keypad
#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Configuration.h"

//DC_MORTOR
#include "../Include/HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "../Include/HAL/DCMOTOR/DCMOTOR_Configuration.h"

//Stepper_Motor
#include "../Include/HAL/STEPPER/STEPPER_Interface.h"
#include "../Include/HAL/STEPPER/STEPPER_Configuration.h"

#include <util/delay.h>

void toggleLED(void);
void main(void)
{
    u8 local_u8PressedKey;
    MDIO_voidInit();
    MGI_voidEnable();
    MEXTI_voidConfig(EXTI0,FALLING_EDGE);
    MEXTI_voidSetCallBack(EXTI0,toggleLED);
    MEXTI_voidEnable(EXTI0);

//    HLCD4_voidInit();
    //LCD
//    HLCD4_voidGoToPos(1,1);
//    HLCD4_voidSendString("Ahmed");
//    u8 calmChar[] = {0b01110,0b01010,0b01110,0b00100,0b01110,0b10101,0b00100,0b11111};
//    HLCD4_voidStoreCustomChar(calmChar,0);
//    HLCD4_voidDisplayCustomChar(0,1,6);
//    HLCD4_voidGoToPos(2,1);
    while(1)
    {


    }
}

void toggleLED(void)
{
	static u8 local_u8Flag=0;
	if(local_u8Flag)
	{
		local_u8Flag=0;
		MDIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
		_delay_ms(100);
	}else
	{
		local_u8Flag=1;
		MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
		_delay_ms(100);
	}
}
