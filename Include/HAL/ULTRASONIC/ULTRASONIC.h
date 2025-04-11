/**
 * @file ULTRASONIC.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _ULTRSONIC_H_
#define _ULTRSONIC_H_

#define F_CPU 8000000UL
//libraries
#include <util/delay.h>
#include "./../../MCAL/DIO/DIO.h"
#include "./../../MCAL/TIMER1/TIMER1.h"

//functions prototypes
void ULTRASONIC_voidInit(uint8_t A_u8Port, uint8_t A_u8Pin);
uint16_t ULTRASONIC_u16SynchReadDistance(uint8_t A_u8Port, uint8_t A_u8Pin);
void ULTRASONIC_voidStart(uint8_t A_u8Port, uint8_t A_u8Pin);
uint8_t ULTRASONIC_u8AsynchReadDistance(uint16_t *distance);

#endif /* _ULTRSONIC_H_ */
