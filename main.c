/*
 * main.c
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

// libraries
#include "./Include/LIB/BIT_MATH.h"
#include "./Include/LIB/STD_TYPES.h"

// MCAL layer
//  DIO
#include "./Include/MCAL/DIO/DIO_Interface.h"
// EXTI
#include "./Include/MCAL/EXTI/EXTI_Interface.h"
// ADC
#include "./Include/MCAL/ADC/ADC_Interface.h"
// TIMER0
#include "./Include/MCAL/TIMER0/TIMER0_Interface.h"
// TIMER1
#include "./Include/MCAL/TIMER1/TIMER1_Interface.h"
// WDT
#include "./Include/MCAL/WDT/WDT_Interface.h"
// UART
#include "./Include/MCAL/UART/UART_Interface.h"
#include "./Include/SERVICES/UART/UART_services.h"
// SPI
#include "./Include/MCAL/SPI/SPI_Interface.h"

// HAL layer
//  SSD
#include "./Include/HAL/SSD/SSD_Interface.h"
// LCD
#include "./Include/HAL/LCD/LCD_Interface.h"
// keypad
#include "./Include/HAL/KEYPAD/KEYPAD_Interface.h"
// DC_MORTOR
#include "./Include/HAL/DCMOTOR/DCMOTOR_Interface.h"
// Stepper_Motor
#include "./Include/HAL/STEPPER/STEPPER_Interface.h"
// Servo Motor
#include "./Include/HAL/SERVOMOTOR/SERVO_Interface.h"
// Ultrasonic sensor
#include "./Include/HAL/ULTRASONIC/ULTRASONIC_Interface.h"
// EEPROM
#include "./Include/HAL/EEPROM/EEPROM_Interface.h"

// RTOS
#include "./Include/SERVICES/RTOS/RTOS_Interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>


u16 ton = 10;
// void func2();
void main(void)
{
	//	u8 str[100];
	DIO_voidInit();
	// LCD_voidInit();
	// LCD_voidSendString("Ahmd nabasdil :)");
	//	sei();
	//	UART_voidInit();
	//	UART_voidSendStingAsynch("Ahmed Nabil");
	// receive variable
	SSD_voidDisplay(5, PORTA);
	while (1)
	{
	}
}
