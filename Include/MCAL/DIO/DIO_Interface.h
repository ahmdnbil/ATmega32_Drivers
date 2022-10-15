/*
 * DIO_Interface.h
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

void MDIO_voidInit();
void MDIO_voidSetPinValue(u8 A_u8Port,u8 A_u8Pin, u8 A_u8Value);
u8 MDIO_u8GetPinValue(u8 A_u8Port,u8 A_u8Pin);
void MDIO_voidSetPortValue(u8 A_u8Port,u8 A_u8Value);
void MDIO_voidSetPortDirection(u8 A_u8Port,u8 A_u8Value);


#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
