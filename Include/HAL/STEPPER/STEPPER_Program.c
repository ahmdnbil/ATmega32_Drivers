/*
 * STEPPER_Program.c
 *
 *  Created on: Oct 28, 2022
 *      Author: User
 */

// libraries
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

// DIO
#include "../../MCAL/DIO/DIO_Interface.h"

// Stepper_Motor
#include "./STEPPER_Interface.h"
#include "./STEPPER_Configuration.h"

#include <util/delay.h>

void STEP_voidFullStep()
{
    DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_HIGH);
    _delay_ms(10);
    DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_HIGH);
    _delay_ms(10);
    DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_LOW);
    _delay_ms(10);
    DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_LOW);
    DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_HIGH);
    DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_HIGH);
    _delay_ms(10);
}

void STEP_voidMotorAngle(u32 A_u32Angle)
{
    u32 local_u32Angle = ((NO_OF_STEPS_FOR_360 * A_u32Angle) / CIRCLE_ANGLE);
    u32 local_u32Steps = local_u32Angle / NO_OF_COILS;
    for (u16 i = 0; i < local_u32Steps; i++)
    {
        DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_LOW);
        DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_HIGH);
        _delay_ms(10);
        DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_LOW);
        DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_HIGH);
        _delay_ms(10);
        DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_LOW);
        _delay_ms(10);
        DIO_voidSetPinValue(STEPPER_PORT, BLUE_COIL_PIN, PIN_LOW);
        DIO_voidSetPinValue(STEPPER_PORT, PINK_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, YELLOW_COIL_PIN, PIN_HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, ORANGE_COIL_PIN, PIN_HIGH);
        _delay_ms(10);
    }
}