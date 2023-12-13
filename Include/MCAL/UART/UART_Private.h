/*
 * UART_Private.h
 *
 *  Created on: Jun 28, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "./../../LIB/mem_map.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
// USART Receive Complete Flag
#define RXC  7
// USART Transmit Complete
#define TXC  6
// USART Data Register Empty Flag
#define UDRE 5
// Frame Error
#define FE   4
// Data OverRun
#define DOR  3
// Parity Error
#define PE   2
// Double the USART  Transmission Speed
#define U2X  1
// Multi-processor Communication Mode
#define MPCM 0
// RX Complete Interrupt Enable
#define RXCIE 7
// TX Complete Interrupt Enable
#define TXCIE 6
// USAER Data Register Empty Interrupt Enable
#define UDRIE 5
// Reciever Enable
#define RXEN  4
// Transmitter Enable
#define TXEN  3
// Character Size
#define UCSZ2 2
// Receive Data Bit8
#define RXB8 1
// Transmit Data Bit8
#define TXB8 0
// Register Select
#define URSEL 7
// USART Mode Select
#define UMSEL 6
// Parity select bits
#define UPM0  4
// Stop Bit Select
#define USBS  3
// Character Size bit1
#define UCSZ1 2
// Character Size bit0
#define UCSZ0 1
// Clock polarity
#define UCPOL 0

#define DOUBLE_SPEED 1
#define NORMAL_SPEED 0

#define SYNCH_OPERATION 1
#define ASYNCH_OPERATION 0

#define PARITY_DISABLED 0
#define PARITY_EN_EVEN 2
#define PARITY_EN_ODD 3

#define CHARACTER_SIZE_5BIT 0
#define CHARACTER_SIZE_6BIT 1
#define CHARACTER_SIZE_7BIT 2
#define CHARACTER_SIZE_8BIT 3
#define CHARACTER_SIZE_9BIT 4

#define RISING_THEN_FALLING_UART 0
#define FALLING_THEN_RISING_UART 1

#define ONE_STOP_BIT 0
#define TWO_STOP_BIT 1

// Register Select
#define URSEL 7

#define DUMMY_DATA 255
#define TIME_OUT 500000
/*---------------------------------------MACRO function declarations--------------------------*/
#define BAUD_RATE_EQN (F_CPU / 16 / BAUD_RATE - 1)

/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
