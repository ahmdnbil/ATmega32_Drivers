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
#include "../Include/MCAL/DIO/DIO_Configuration.h"

//EXTI
#include "../Include/MCAL/EXTI/EXTI_Interface.h"

//GI
#include "../Include/MCAL/GI/GI_Interface.h"

//ADC
#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/MCAL/ADC/ADC_Private.h"
#include "../Include/MCAL/ADC/ADC_Configurations.h"

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
    // MEXTI_voidConfig(EXTI0,FALLING_EDGE);
    // MEXTI_voidSetCallBack(EXTI0,toggleLED);
    // MEXTI_voidEnable(EXTI0);

	MADC_voidInit();
    HLCD4_voidInit();
    //LCD
//    HLCD4_voidGoToPos(1,1);
//    HLCD4_voidSendString("Ahmed");
//    u8 calmChar[] = {0b01110,0b01010,0b01110,0b00100,0b01110,0b10101,0b00100,0b11111};
//    HLCD4_voidStoreCustomChar(calmChar,0);
//    HLCD4_voidDisplayCustomChar(0,1,6);
//    HLCD4_voidGoToPos(2,1);
    
	u16 lcoal_u16Digital=0;
	u16 lcoal_u16Analog=0;


	while(1)
    {
		lcoal_u16Digital=MADC_u16GetDigitalValue(ADC0_SINGLE);
		lcoal_u16Analog=(u16)((lcoal_u16Digital*5000UL)/1024);
		lcoal_u16Analog/=10;
		HLCD4_voidSendString("Temp:");
		HLCD4_voidDisplayNumber(lcoal_u16Analog);

		_delay_ms(1000);
		HLCD4_voidClearDisplay();
		// if(lcoal_u16Analog<=1500)
		// {
		// 	MDIO_voidSetPinValue(PORTC,PIN0,PIN_HIGH);
		// 	MDIO_voidSetPinValue(PORTC,PIN1,PIN_LOW);
		// 	MDIO_voidSetPinValue(PORTC,PIN2,PIN_LOW);
		// }
		// else if(lcoal_u16Analog >1500 && lcoal_u16Analog<=3000)
		// {

		// 	MDIO_voidSetPinValue(PORTC,PIN0,PIN_HIGH);
		// 	MDIO_voidSetPinValue(PORTC,PIN1,PIN_HIGH);
		// 	MDIO_voidSetPinValue(PORTC,PIN2,PIN_LOW);
		// }
		// else if(lcoal_u16Analog>3000)
		// {
		// 	MDIO_voidSetPinValue(PORTC,PIN0,PIN_HIGH);
		// 	MDIO_voidSetPinValue(PORTC,PIN1,PIN_HIGH);
		// 	MDIO_voidSetPinValue(PORTC,PIN2,PIN_HIGH);
		// }

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
