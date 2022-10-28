/*
 * STEPPER_Program.c
 *
 *  Created on: Oct 28, 2022
 *      Author: User
 */


//libraries
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

//Stepper_Motor
#include "../Include/HAL/STEPPER/STEPPER_Interface.h"
#include "../Include/HAL/STEPPER/STEPPER_Configuration.h"
#include "../Include/HAL/STEPPER/STEPPER_Private.h"

#include <util/delay.h>

void HSTEP_voidFullStep()
{
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_LOW);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_HIGH);
    _delay_ms(10);
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_LOW);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_HIGH);
    _delay_ms(10);
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_LOW);
    _delay_ms(10);
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_LOW);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_HIGH);
    _delay_ms(10);
}

void HSTEP_voidMotorAngle(u32 A_u32Angle)
{
    u32 local_u32Angle=((NO_OF_STEPS_FOR_360*A_u32Angle)/CIRCLE_ANGLE);
    u32 local_u32Steps=local_u32Angle/NO_OF_COILS; 
    for(u16 i =0;i<local_u32Steps;i++)
	{
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_LOW);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_HIGH);
    _delay_ms(10);
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_LOW);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_HIGH);
    _delay_ms(10);
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_LOW);
    _delay_ms(10);
    MDIO_voidSetPinValue(STEPPER_PORT,BLUE_COIL_PIN,PIN_LOW);
    MDIO_voidSetPinValue(STEPPER_PORT,PINK_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,YELLOW_COIL_PIN,PIN_HIGH);
    MDIO_voidSetPinValue(STEPPER_PORT,ORANGE_COIL_PIN,PIN_HIGH);
    _delay_ms(10);
    }
}