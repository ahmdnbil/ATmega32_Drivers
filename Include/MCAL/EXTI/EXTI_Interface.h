/*
 * EXTI_Interface.h
 *
 *  Created on: Nov 1, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_

#define LOW_LEVEL          0b00 
#define ANY_LOGICAL_CHANGE 0b01
#define FALLING_EDGE       0b10
#define RISING_EDGE        0b11

#define EXTI0 0
#define EXTI1 1
#define EXTI2 2

void MEXTI_voidConfig(u8 A_u8EXTINo,u8 A_u8SenseMode);
void MEXTI_voidEnable(u8 A_u8EXTI);
void MEXTI_voidDisable(u8 A_u8EXTI);
void MEXTI_voidClearFlag(u8 A_u8EXTI);
void MEXTI_voidSetCallBack(u8 A_u8EXTI,void (*ptrToFunc)(void));





#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
