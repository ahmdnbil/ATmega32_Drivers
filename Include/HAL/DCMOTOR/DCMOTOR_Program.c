/*
 * DCMOTOR_Program.c
 *
 *  Created on: Oct 26, 2022
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

// DC_MORTOR
#include "./DCMOTOR_Interface.h"
#include "./DCMOTOR_Configuration.h"

#include <util/delay.h>

// H-bridge using 4npn transistors 2N2222
void DCMOTOR_voidHBridge()
{
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_HIGH);
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, PIN_LOW);
    _delay_ms(INVERSE_MOTOR_DELAY);
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_LOW);
    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, PIN_HIGH);
    _delay_ms(INVERSE_MOTOR_DELAY);
}
