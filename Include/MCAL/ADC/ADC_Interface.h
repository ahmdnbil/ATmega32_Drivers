/*
 * ADC_Interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

typedef enum
{
    AREF, 
    AVCC,
    INTERNAL_REF=3
}REF_Voltage;
typedef enum
{
    ADC_PRESCALER_2,
    ADC_PRESCALER_4=2,
    ADC_PRESCALER_8,
    ADC_PRESCALER_16,
    ADC_PRESCALER_32,
    ADC_PRESCALER_64,
    ADC_PRESCALER_128,
}ADC_Prescaler;

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

u16 MADC_u16GetDigitalValue(ADC_Channel channel);
void MADC_voidInit(ADC_Prescaler Prescaler,REF_Voltage referance);
void MADC_voidInterruptEnable(void);
void MADC_voidInterruptDisable(void);
void MADC_voidCallBack(void (*ptrToLocal)(void));

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
