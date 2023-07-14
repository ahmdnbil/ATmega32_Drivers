/*
 * ULTRASONIC_Interface.h
 *
 *  Created on: Jun 27, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

u16 HULTRSONIC_u16GetDistance();
void HULTRASONIC_voidInit(void);
void HULTRASONIC_voidStart();
u16 HULTRASONIC_u8GetDistanceNoBlock(u16*Pdistance);


#endif /* INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
