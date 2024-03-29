/*
 * DIO_Configuration.h
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_DIO_DIO_CONFIGURATION_H_
#define INCLUDE_MCAL_DIO_DIO_CONFIGURATION_H_

// the following configuration for PORT(A,B,C,D) & DDR(A,B,C,D)
//  and not PIN cause this register we just need to read it not write on it

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------MACRO Declarations-----------------------------------*/

//DIRECTION of PORT
#define PIN_OUTPUT 1
#define PIN_INPUT 0

// in case of being output
#define PIN_LOW 0
#define PIN_HIGH 1

// in case of being input
#define PIN_FLOATING 0
#define PIN_PULLUP 1

#define DDRA_PIN0_DIRECTION PIN_OUTPUT
#define DDRA_PIN1_DIRECTION PIN_OUTPUT
#define DDRA_PIN2_DIRECTION PIN_OUTPUT
#define DDRA_PIN3_DIRECTION PIN_OUTPUT
#define DDRA_PIN4_DIRECTION PIN_OUTPUT
#define DDRA_PIN5_DIRECTION PIN_OUTPUT
#define DDRA_PIN6_DIRECTION PIN_OUTPUT
#define DDRA_PIN7_DIRECTION PIN_OUTPUT

#define DDRB_PIN0_DIRECTION PIN_OUTPUT
#define DDRB_PIN1_DIRECTION PIN_OUTPUT
#define DDRB_PIN2_DIRECTION PIN_OUTPUT
#define DDRB_PIN3_DIRECTION PIN_OUTPUT
#define DDRB_PIN4_DIRECTION PIN_OUTPUT
#define DDRB_PIN5_DIRECTION PIN_OUTPUT
#define DDRB_PIN6_DIRECTION PIN_OUTPUT
#define DDRB_PIN7_DIRECTION PIN_OUTPUT

#define DDRC_PIN0_DIRECTION PIN_OUTPUT
#define DDRC_PIN1_DIRECTION PIN_OUTPUT
#define DDRC_PIN2_DIRECTION PIN_OUTPUT
#define DDRC_PIN3_DIRECTION PIN_OUTPUT
#define DDRC_PIN4_DIRECTION PIN_OUTPUT
#define DDRC_PIN5_DIRECTION PIN_OUTPUT
#define DDRC_PIN6_DIRECTION PIN_OUTPUT
#define DDRC_PIN7_DIRECTION PIN_OUTPUT

#define DDRD_PIN0_DIRECTION PIN_INPUT
#define DDRD_PIN1_DIRECTION PIN_OUTPUT
#define DDRD_PIN2_DIRECTION PIN_OUTPUT
#define DDRD_PIN3_DIRECTION PIN_OUTPUT
#define DDRD_PIN4_DIRECTION PIN_OUTPUT
#define DDRD_PIN5_DIRECTION PIN_OUTPUT
#define DDRD_PIN6_DIRECTION PIN_OUTPUT
#define DDRD_PIN7_DIRECTION PIN_OUTPUT

// ************************************************
//VALUE of PORT

#define PORTA_PIN0_VALUE PIN_LOW
#define PORTA_PIN1_VALUE PIN_LOW
#define PORTA_PIN2_VALUE PIN_LOW
#define PORTA_PIN3_VALUE PIN_LOW
#define PORTA_PIN4_VALUE PIN_LOW
#define PORTA_PIN5_VALUE PIN_LOW
#define PORTA_PIN6_VALUE PIN_LOW
#define PORTA_PIN7_VALUE PIN_LOW

#define PORTB_PIN0_VALUE PIN_LOW
#define PORTB_PIN1_VALUE PIN_LOW
#define PORTB_PIN2_VALUE PIN_LOW
#define PORTB_PIN3_VALUE PIN_LOW
#define PORTB_PIN4_VALUE PIN_LOW
#define PORTB_PIN5_VALUE PIN_LOW
#define PORTB_PIN6_VALUE PIN_LOW
#define PORTB_PIN7_VALUE PIN_LOW

#define PORTC_PIN0_VALUE PIN_LOW
#define PORTC_PIN1_VALUE PIN_LOW
#define PORTC_PIN2_VALUE PIN_LOW
#define PORTC_PIN3_VALUE PIN_LOW
#define PORTC_PIN4_VALUE PIN_LOW
#define PORTC_PIN5_VALUE PIN_LOW
#define PORTC_PIN6_VALUE PIN_LOW
#define PORTC_PIN7_VALUE PIN_LOW

#define PORTD_PIN0_VALUE PIN_FLOATING
#define PORTD_PIN1_VALUE PIN_LOW
#define PORTD_PIN2_VALUE PIN_LOW
#define PORTD_PIN3_VALUE PIN_LOW
#define PORTD_PIN4_VALUE PIN_LOW
#define PORTD_PIN5_VALUE PIN_LOW
#define PORTD_PIN6_VALUE PIN_LOW
#define PORTD_PIN7_VALUE PIN_LOW
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* INCLUDE_MCAL_DIO_DIO_CONFIGURATION_H_ */
