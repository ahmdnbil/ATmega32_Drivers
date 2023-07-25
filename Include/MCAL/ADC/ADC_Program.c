/*
 * ADC_Program.c
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "./ADC_Interface.h"
#include "./ADC_Private.h"
#include "./ADC_Configurations.h"

static void (*ADC_CallBack)(void) = NULLPTR;

void ADC_voidInit(ADC_Prescaler Prescaler, REF_Voltage referance)
{

    // prescaler division factor
    ADCSRA &= ~(0b111 << ADPS0);
    ADCSRA |= (Prescaler << ADPS0);

    // reference selection
    ADMUX &= ~(0b11 << REFS0);
    ADMUX |= (referance << REFS0);

// left or right adjust
#if ADC_LEFT_ADJUST == TRUE
    SET_BIT(ADMUX, ADLAR);
#else
    CLR_BIT(ADMUX, ADLAR);
#endif

    // Making ADC enable
    SET_BIT(ADCSRA, ADEN);

// auto triggering
#if AUTO_TRIGGERING == TRUE
    SET_BIT(ADCSRA, ADATE);
#else
    CLR_BIT(ADCSRA, ADATE);
#endif
}

u16 ADC_u16GetDigitalValueBlocking(ADC_Channel channel)
{

    u16 local_u16DigitalValue = 0;

    // chosing channel
    ADMUX &= ~(0b11111 << MUX0);
    ADMUX |= (channel << MUX0);

    // starting conversion
    SET_BIT(ADCSRA, ADCS);

    // polling on flag until the conversion is finished
    while (GET_BIT(ADCSRA, ADIF) == 0)
        ;
    // Read value
    local_u16DigitalValue = ((u16)ADCL) | ((u16)(ADCH << 8));

    return local_u16DigitalValue;
}

void ADC_voidStartConversionAsync(ADC_Channel channel)
{
    // chosing channel
    ADMUX &= ~(0b11111 << MUX0);
    ADMUX |= (channel << MUX0);
    // starting conversion
    SET_BIT(ADCSRA, ADCS);
}

u16 ADC_u16GetValueNonBlocking()
{
    if (GET_BIT(ADCSRA, ADIF))
    {
        return (u16)(ADCL) | ((u16)(ADCH << 8));
    }
    return 0;
}

/****************************interrupt section******************************/
void ADC_voidInterruptEnable(void)
{
    SET_BIT(ADCSRA, ADIE);
}

void ADC_voidInterruptDisable(void)
{
    CLR_BIT(ADCSRA, ADIE);
}

void ADC_voidCallBack(void (*ptrToLocal)(void))
{
    ADC_CallBack = ptrToLocal;
}

ISR(ADC_VECT)
{
    if (ADC_CallBack != NULLPTR)
        ADC_CallBack();
}