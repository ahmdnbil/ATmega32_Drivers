/*
 * DCMOTOR_Program.c
 *
 *  Created on: Oct 26, 2022
 *      Author: User
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

//DC_MORTOR
#include "../Include/HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "../Include/HAL/DCMOTOR/DCMOTOR_Configuration.h"
#include "../Include/HAL/DCMOTOR/DCMOTOR_Private.h"

#include <util/delay.h>

//H-bridge using 4npn transistors 2N2222
void HDCMOTOR_voidHBridge()
{
    MDIO_voidSetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,PIN_HIGH);
    MDIO_voidSetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN2,PIN_LOW);
    _delay_ms(INVERSE_MOTOR_DELAY);
    MDIO_voidSetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,PIN_LOW);
    MDIO_voidSetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN2,PIN_HIGH);
    _delay_ms(INVERSE_MOTOR_DELAY);
    
}

