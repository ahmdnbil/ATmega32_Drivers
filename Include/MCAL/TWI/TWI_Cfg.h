/**
 * @file TWI_Cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_TWI_TWI_CONFIGURATION_H_
#define INCLUDE_MCAL_TWI_TWI_CONFIGURATION_H_

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------MACRO Declarations-----------------------------------*/

// Status register values after any operation
// MT: Master Transmitter
// MR: Master Receiver
// ST: Slave Transmitter
// SR: Slave Receiver

// Sending start
#define START_TWI 0x08
// Sending slave address & Write operation
#define MT_SLA_ACK 0x18
// Sending slave address & Read operation
#define MR_SLA_ACK 0x40
// Sending Data
#define MT_DATA_ACK 0x28
// Received Data
#define MR_DATA_ACK 0x50
// Repeated Start
#define RE_START_ACK 0x10

#define TWI_PRESCALER_1 0b00
#define TWI_PRESCALER_4 0b01
#define TWI_PRESCALER_16 0b10
#define TWI_PRESCALER_64 0b11

/*
Choose Prescaler:
    TWI_PRESCALER_1
    TWI_PRESCALER_4
    TWI_PRESCALER_16
    TWI_PRESCALER_64
*/
#define TWI_PRESCALER TWI_PRESCALER_1

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* INCLUDE_MCAL_TWI_TWI_CONFIGURATION_H_ */
