/*
 * ADC_Private.h
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

/************************************/
//ADC Multiplexer Selection Register
#define ADMUX (*(volatile u8 *) 0x27)
#define REFS0 6
#define  AREF          0b00
#define AVCC_CAPACTIOR 0b01
#define INTERNAL_REF   0b11

#define ADLAR 5
#define TRUE  1
#define FALSE 0

#define MUX0 0
#define ADC0_SINGLE 0b00000
#define ADC1_SINGLE 0b00001
#define ADC2_SINGLE 0b00010
#define ADC3_SINGLE 0b00011
#define ADC4_SINGLE 0b00100
#define ADC5_SINGLE 0b00101
#define ADC6_SINGLE 0b00110
#define ADC7_SINGLE 0b00111
/************************************/

/************************************/
//ADC Control Status Register A
#define ADCSRA (*(volatile u8 *) 0x26)
//ADC Enable
#define ADEN  7
//ADC Start Conversion
#define ADCS  6
//ADC Auto Triggering Enable
#define ADATE 5
//ADC Interrupt Flag
#define ADIF  4
//ADC Interrupt Enable
#define ADIE  3
//ADC Prescaler Select bit 0
#define ADPS0 0

#define ADC_PRESCALER_2   0b000
#define ADC_PRESCALER_2   0b001
#define ADC_PRESCALER_4   0b010
#define ADC_PRESCALER_8   0b011
#define ADC_PRESCALER_16  0b100
#define ADC_PRESCALER_32  0b101
#define ADC_PRESCALER_64  0b110
#define ADC_PRESCALER_128 0b111



/************************************/
#define ADCH (*(volatile u8 *) 0x25)
#define ADCL (*(volatile u8 *) 0x24)
#define ADCLH (*(volatile u16 *) 0x24)
/************************************/

#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
