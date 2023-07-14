/*
 * TWI_Private.h
 *
 *  Created on: Jul 5, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TWI_TWI_PRIVATE_H_
#define INCLUDE_MCAL_TWI_TWI_PRIVATE_H_

//TWI Bit Rate Register
#define TWBR (*(volatile u8*)0x20)
//TWI Control Register
#define TWCR (*(volatile u8*)0x56)
// TWI Interrupt Flag
#define TWINT 7
// TWI Enable Acknowledge bit
#define TWEA 6
// TWI Start Condtion Bit
#define TWSTA 5
// TWI Stop Condtion Bit
#define TWSTO 4
// TWI Enable Bit
#define TWEN 2
// TWI interrupt Enable
#define TWIE 0
// TWI Status Register
#define TWSR (*(volatile u8 *)0x21)
// TWI Prescaler Bits
#define TWPS0 0
// TWI Data Register
#define TWDR (*(volatile u8 *)0x23)
// TWI Slave Address Register
#define TWAR (*(volatile u8 *)0x22)
// TWI General Call Recognition Enable Bit
#define TWGCE 0

#define TWI_PRESCALER_1 0b00
#define TWI_PRESCALER_4 0b01
#define TWI_PRESCALER_16 0b10
#define TWI_PRESCALER_64 0b11

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
#endif /* INCLUDE_MCAL_TWI_TWI_PRIVATE_H_ */
