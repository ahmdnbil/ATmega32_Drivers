/*
 * UART_Interface.h
 *
 *  Created on: Jun 28, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

//initiation UART
void MUSART_voidInit(void);

//Send data
void MUSART_voidSendByteAsynch(u8 A_u8Byte);
void MUSART_voidSendByteSynchBlocking(u8 A_u8Byte);
void MUSART_voidSendByteSynchNonBlocking(u8 A_u8Byte);


//receive data
u8 MUSART_u8ReadByteAsynch(void);
u8 MUSART_u8ReadByteSynchNonBlocking(void);
u8 MUSART_u8ReadByteSynchBlocking(void);

//set call back function for interrupt
void MUSART_voidSetCallRXC(void(*pf)(void));
void MUSART_voidSetCallUDRE(void(*pf)(void));
void MUSART_voidSetCallTXC(void(*pf)(void));

//enable/disable interrupt
void MUSART_voidUDRInterruptDisable(void);
void MUSART_voidUDRInterruptEnable(void);
void MUSART_voidTXCompleteInterruptDisable(void);
void MUSART_voidTXCompleteInterruptEnable(void);
void MUSART_voidRXCompleteInterruptDisable(void);
void MUSART_voidRXCompleteInterruptEnable(void);


#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
