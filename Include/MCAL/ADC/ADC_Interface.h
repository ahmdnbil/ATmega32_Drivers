/*
 * ADC_Interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    AREF,
    AVCC,
    INTERNAL_REF = 3
} REF_Voltage;
/*
    for 8MHz choose prescaler 128 or 64, why?
    in ATmega32, it's mandatory to work between 50kHz and 200kHz
    we can't achieve this criterion except in 128 and 64 Prescaler
*/
typedef enum
{
    ADC_PRESCALER_2,
    ADC_PRESCALER_4 = 2,
    ADC_PRESCALER_8,
    ADC_PRESCALER_16,
    ADC_PRESCALER_32,
    ADC_PRESCALER_64,
    ADC_PRESCALER_128,
} ADC_Prescaler;
typedef enum
{
    ADC0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7
}ADC_Channel;

/*---------------------------------------function declarations--------------------------------*/
void ADC_voidInit(ADC_Prescaler Prescaler, REF_Voltage referance);

// synchrounous funciton
u16 ADC_u16GetDigitalValueBlocking(ADC_Channel channel);

// asynchrounous funciont
void ADC_voidStartConversionAsync(ADC_Channel channel);
u16 ADC_u16GetValueNonBlocking();

void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
void ADC_voidCallBack(void (*ptrToLocal)(void));

// void ADC_Init();
// u16 ADC_read(u8 num_pin);

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
