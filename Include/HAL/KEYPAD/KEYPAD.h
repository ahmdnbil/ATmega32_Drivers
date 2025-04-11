/**
 * @file KEYPAD.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_

// Libraries
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
// MCAL layer
#include "../../MCAL/DIO/DIO.h"
// Keypad
#include "./KEYPAD_Cfg.h"

void KEYPAD_voidInit();
uint8_t KEYPAD_u8GetPressedKey();

#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
