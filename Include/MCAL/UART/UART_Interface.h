/*
 * UART_Interface.h
 *
 *  Created on: Jun 28, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
// initiation UART
void UART_voidInit(void);

//Send data
void UART_voidSendByteAsynch(u8 A_u8Byte);
void UART_voidSendByteSynchBlocking(u8 A_u8Byte);
void UART_voidSendByteSynchNonBlocking(u8 A_u8Byte);

// receive data
u8 UART_u8ReadByteAsynch(void);
u8 UART_u8ReadByteSynchNonBlocking(void);
u8 UART_u8ReadByteSynchBlocking(void);

// set call back function for interrupt
void UART_voidSetCallRXC(void (*pf)(void));
void UART_voidSetCallUDRE(void (*pf)(void));
void UART_voidSetCallTXC(void (*pf)(void));

//enable/disable interrupt
void UART_voidUDRInterruptDisable(void);
void UART_voidUDRInterruptEnable(void);
void UART_voidTXCompleteInterruptDisable(void);
void UART_voidTXCompleteInterruptEnable(void);
void UART_voidRXCompleteInterruptDisable(void);
void UART_voidRXCompleteInterruptEnable(void);

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
