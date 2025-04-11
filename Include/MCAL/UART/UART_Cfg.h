/**
 * @file UART_Cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_
#define INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------MACRO Declarations-----------------------------------*/

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

/*
choose mode:
    SYNCH_OPERATION
    ASYNCH_OPERATION
*/
#define USART_MODE ASYNCH_OPERATION

/*
Choose Speed:
    DOUBLE_SPEED
    NORMAL_SPEED
*/
#define USART_SPPED NORMAL_SPEED

/*
Choose Parity Mode:
    PARITY_DISABLED
    PARITY_EN_EVEN  
    PARITY_EN_ODD 
*/
#define PARITY_MODE PARITY_DISABLED

/*
Choose Charcter Size:
    CHARACTER_SIZE_5BIT
    CHARACTER_SIZE_6BIT
    CHARACTER_SIZE_7BIT
    CHARACTER_SIZE_8BIT
    CHARACTER_SIZE_9BIT
*/
#define CHARACTER_SIZE CHARACTER_SIZE_8BIT

/*
choose CLK polarity:
    RISING_THEN_FALLING_UART
    FALLING_THEN_RISING_UART
*/
#define CLK_POLARITY RISING_THEN_FALLING_UART

/*
choose stop bit mode:
    ONE_STOP_BIT
    TWO_STOP_BIT
*/
#define STOP_BIT_SLECT ONE_STOP_BIT

#define F_CPU 8000000UL
#define BAUD_RATE 9600

#define DUMMY_DATA 255
#define TIME_OUT 500000

/*---------------------------------------MACRO function declarations--------------------------*/
#define BAUD_RATE_EQN (F_CPU / 16 / BAUD_RATE - 1)

/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
#endif /* INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_ */
