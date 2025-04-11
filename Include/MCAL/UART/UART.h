/**
 * @file UART.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "./../../LIB/mem_map.h"

#include "./UART_Cfg.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
// initiation UART
void UART_voidInit(void);

//Send data
void UART_voidSendByteSynch(uint8_t A_u8Byte);
void UART_voidSendByteNoBlock(uint8_t A_u8Byte);

// receive data
uint8_t UART_u8ReadByteSynch(void);
uint8_t UART_u8ReadByteNoBlock(void);
uint8_t UART_u8ReadByteAsynch(uint8_t *Pdata);

// set call back function for interrupt
void UART_voidSetCallRXC(void (*pf)(void));
void UART_voidSetCallUDRE(void (*pf)(void));
void UART_voidSetCallTXC(void (*pf)(void));

//enable/disable interrupt
void UART_voidUDRInterruptDisable(void);
void UART_voidUDRInterruptEnable(void);
void UART_voidTXInterruptDisable(void);
void UART_voidTXInterruptEnable(void);
void UART_voidRXInterruptDisable(void);
void UART_voidRXInterruptEnable(void);

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
