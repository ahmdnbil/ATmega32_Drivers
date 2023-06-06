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

//RTOS
#include "../Include/SERVICES/RTOS/RTOS_Configurations.h"
#include "../Include/SERVICES/RTOS/RTOS_Interface.h"

//freeRTOS
#include "../OS/FreeRTOS.h"
#include "../OS/task.h"
#include "../OS/semphr.h"

#define F_CPU 8000000UL 	 	
#include <util/delay.h>

//for RTOS
// void toggleLED1(void);
// void toggleLED2(void); 
// void toggleLED3(void);

//for FreeRTOS
void AppTask1(void*copy_VP);
void AppTask2(void*copy_VP);
void AppTask3(void*copy_VP);

void main(void)
{
    MDIO_voidInit();
    MGI_voidEnable();

	xTaskCreate(AppTask1,NULL,200,NULL,4,NULL);
	xTaskCreate(AppTask2,NULL,200,NULL,3,NULL);
	xTaskCreate(AppTask3,NULL,200,NULL,2,NULL);
	vTaskStartScheduler();
	while(1)
    {
    }
}

// void toggleLED1(void)
// {
// 	static u8 local_u8Flag=0;
// 	if(local_u8Flag)
// 	{
// 		local_u8Flag=0;
// 		MDIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
// 	}else
// 	{
// 		local_u8Flag=1;
// 		MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
// 	}
// }
// void toggleLED2(void)
// {
// 	static u8 local_u8Flag=0;
// 	if(local_u8Flag)
// 	{
// 		local_u8Flag=0;
// 		MDIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);
// 	}else
// 	{
// 		local_u8Flag=1;
// 		MDIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
// 	}
// }
// void toggleLED3(void)
// {
// 	static u8 local_u8Flag=0;
// 	if(local_u8Flag)
// 	{
// 		local_u8Flag=0;
// 		MDIO_voidSetPinValue(PORTA,PIN2,PIN_HIGH);
// 	}else
// 	{
// 		local_u8Flag=1;
// 		MDIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);
// 	}
// }

void AppTask1(void*copy_VP)
{
	static u8 flag=0;
	while(1)
	{
		if(!flag)
		{
			MDIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
			flag=1;
		}
		else
		{
			MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
			flag=0;
		}
		vTaskDelay(1000);
	}
}
void AppTask2(void*copy_VP)
{
	static u8 flag=0;
	while(1)
	{
		if(!flag)
		{
			MDIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);
			flag=1;
		}
		else
		{
			MDIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
			flag=0;
		}
		vTaskDelay(1000);
	}
}
void AppTask3(void*copy_VP)
{
	static u8 flag=0;
	while(1)
	{
		if(!flag)
		{
			MDIO_voidSetPinValue(PORTA,PIN2,PIN_HIGH);
			flag=1;
		}
		else
		{
			MDIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);
			flag=0;
		}
		vTaskDelay(1000);
	}
}