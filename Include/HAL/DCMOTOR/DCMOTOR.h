/**
 * @file DCMOTOR.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define INCLUDE_HAL_DCMOTOR_DCMOTOR_INTERFACE_H_

#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "./DCMOTOR_Cfg.h"


void DCMOTOR_voidInit();
//H-bridge using 4npn transistors 2N2222
void DCMOTOR_voidHBridge();

#endif /* INCLUDE_HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
