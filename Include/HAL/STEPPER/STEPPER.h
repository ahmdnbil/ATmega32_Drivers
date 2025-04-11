/*
 * STEPPER_interface.h
 *
 *  Created on: Oct 28, 2022
 *      Author: User
 */

#ifndef INCLUDE_HAL_STEPPER_STEPPER_INTERFACE_H_
#define INCLUDE_HAL_STEPPER_STEPPER_INTERFACE_H_

#define F_CPU 8000000UL
#include <util/delay.h>

// libraries
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

// DIO
#include "../../MCAL/DIO/DIO.h"

// Stepper_Motor
#include "./STEPPER_Cfg.h"

//Fucntions Declaration

void STEP_voidFullStep();
void STEP_voidMotorAngle(uint32_t A_u32Angle);

#endif /* INCLUDE_HAL_STEPPER_STEPPER_INTERFACE_H_ */
