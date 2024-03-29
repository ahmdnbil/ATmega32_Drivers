/*
 * UART_Configurations.h
 *
 *  Created on: Jun 28, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_
#define INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------MACRO Declarations-----------------------------------*/
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

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
#endif /* INCLUDE_MCAL_UART_UART_CONFIGURATIONS_H_ */
