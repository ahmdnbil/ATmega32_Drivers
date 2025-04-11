/**
 * @file DCMOTOR.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "./DCMOTOR.h"



void DCMOTOR_voidInit()
{
    DIO_InitPin(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(DC_MOTOR_PORT, DC_MOTOR_PIN2, PIN_OUTPUT, PIN_LOW);
}

// H-bridge using 4npn transistors 2N2222
void DCMOTOR_voidHBridge()
{
    DIO_WritePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_HIGH);
    DIO_WritePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, PIN_LOW);
    _delay_ms(INVERSE_MOTOR_DELAY);
    DIO_WritePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_LOW);
    DIO_WritePin(DC_MOTOR_PORT, DC_MOTOR_PIN2, PIN_HIGH);
    _delay_ms(INVERSE_MOTOR_DELAY);
}
