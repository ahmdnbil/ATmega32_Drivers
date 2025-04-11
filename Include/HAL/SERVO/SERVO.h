/**
 * @file SERVO.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_HAL_SERVOMOTOR_SERVO_INTERFACE_H_
#define INCLUDE_HAL_SERVOMOTOR_SERVO_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/TIMER1/TIMER1.h"

void SERVO_voidInit(void);
void SERVO_voidSetServoAngle(uint8_t A_u8Angle);
void SERVO_voidADCReading(uint16_t reading);

#endif /* INCLUDE_HAL_SERVOMOTOR_SERVO_INTERFACE_H_ */
