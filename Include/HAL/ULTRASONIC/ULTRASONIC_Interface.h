/*
 * ULTRASONIC_Interface.h
 *
 *  Created on: Jun 27, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

u16 ULTRASONIC_u16GetDistance();
void ULTRASONIC_voidInit(void);
void ULTRASONIC_voidStart();
u16 ULTRASONIC_u8GetDistanceNoBlock(u16 *Pdistance);

#endif /* INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
