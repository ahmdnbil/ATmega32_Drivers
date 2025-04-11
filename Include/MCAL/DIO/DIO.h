/**
 * @file DIO.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _DIO_H_
#define _DIO_H_

#include "./DIO_Config.h"
#include "./../../LIB/STD_TYPES.h"
#include "./../../LIB/BIT_MATH.h"
#include "./../../LIB/mem_map.h"

void DIO_InitPin(uint8_t port, uint8_t pin, uint8_t direction, uint8_t pin_status);
void DIO_WritePin (uint8_t port, uint8_t pin, uint8_t value);
uint8_t DIO_ReadPin (uint8_t port, uint8_t pin);
void DIO_TogglePin (uint8_t port, uint8_t pin);
void DIO_InitPort(uint8_t port, uint8_t direction, uint8_t value);
void DIO_WritePort(uint8_t port, uint8_t value);
uint8_t DIO_ReadPort (uint8_t port);


#endif /* _DIO_H_ */
