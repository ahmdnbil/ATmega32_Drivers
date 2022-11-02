/*
 * EXTI_Private.h
 *
 *  Created on: Nov 1, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_
#define INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_

/***************************************/
//MCU Control Register
#define MCUCR (*(volatile u8 *) 0x55) 
#define ISC00 0
#define ISC10 2
/***************************************/


/***************************************/
//MCU Control & Status Register
#define MCUCSR (*(volatile u8 *) 0x54) 
#define ISC2 6
/***************************************/


/***************************************/
//General Interrupt Control Register
#define GICR (*(volatile u8 *) 0x5B) 
#define INT0 6
#define INT1 7
#define INT2 5
/***************************************/


/***************************************/
//General Interrupt Flag Register
#define GIFR (*(volatile u8 *) 0x5A) 
#define INTF0 6
#define INTF1 7
#define INTF2 5
/***************************************/

#endif /* INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_ */
