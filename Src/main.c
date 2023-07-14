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

//TIMER0
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"

//TIMER1
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h" 
#include "../Include/MCAL/TIMER1/TIMER1_Private.h" 

//WDT
#include "../Include/MCAL/WDT/WDT_Interface.h"

//UART
#include "../Include/MCAL/UART/UART_Interface.h"
#include "../Include/SERVICES/UART/UART_services.h"

//SPI
#include "../Include/MCAL/SPI/SPI_Interface.h"

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

//Servo Motor
#include "../Include/HAL/SERVOMOTOR/SERVO_Interface.h"

//Ultrasonic sensor
#include "../Include/HAL/ULTRASONIC/ULTRASONIC_Interface.h"

//RTOS
#include "../Include/SERVICES/RTOS/RTOS_Configurations.h"
#include "../Include/SERVICES/RTOS/RTOS_Interface.h"

// EEPROM
#include "../Include/HAL/EEPROM/EEPROM_Interface.h"

#include <util/delay.h>

#define F_CPU 8000000UL 	 	

u16 ton =10;
//void func2();
void main(void)
{
	u8 str[100];
	MDIO_voidInit();
	MGI_voidEnable();
	MUSART_voidInit();
	MUSART_voidSendStingAsynch("Ahmed Nabil");
	//receive variable 
	while(1)
	{
	}
}



