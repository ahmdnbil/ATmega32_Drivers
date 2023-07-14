/*
 * ADC_Program.c
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/MCAL/ADC/ADC_Private.h"
#include "../Include/MCAL/ADC/ADC_Configurations.h"

static void (*ADC_CallBack)(void)=NULLPTR;

void MADC_voidInit(ADC_Prescaler Prescaler,REF_Voltage referance)
{
    //reference selection
    ADMUX&=~(0b11<<REFS0);
    ADMUX|=(referance<<REFS0);

    //left or right adjust
    #if ADC_LEFT_ADJUST==TRUE
    SET_BIT(ADMUX,ADLAR);
    #else
    CLR_BIT(ADMUX,ADLAR);
    #endif

    //Making ADC enable
    SET_BIT(ADCSRA,ADEN);

    
    //auto triggering
    #if AUTO_TRIGGERING == TRUE
    SET_BIT(ADCSRA,ADATE);
    #else
    CLR_BIT(ADCSRA,ADATE);
    #endif
    

    //prescaler division factor
    ADCSRA&=~(0b111<<ADPS0);
    ADCSRA|=(Prescaler<<ADPS0);

}

void MADC_voidInterruptEnable(void)
{
    SET_BIT(ADCSRA,ADIE);
}

void MADC_voidInterruptDisable(void)
{
    CLR_BIT(ADCSRA,ADIE);
}

u16 MADC_u16GetDigitalValue(ADC_Channel channel)
{

    u16 local_u16DigitalValue=0;
    
    
    //chosing channel
    ADMUX&=~(0b11111<< MUX0);
    ADMUX|=(channel<< MUX0);

    //starting conversion
    SET_BIT(ADCSRA,ADCS);

    //polling on flag until the conversion is finished
    while(GET_BIT(ADCSRA,ADIF)==0);
    //writing one to clear the flag
    SET_BIT(ADCSRA,ADIF);
    //Read value
    local_u16DigitalValue=ADCLH;
    

    return local_u16DigitalValue;
}

void MADC_voidCallBack(void (*ptrToLocal)(void))
{
    ADC_CallBack=ptrToLocal;
}
ISR(ADC_VECT)
{
    if(ADC_CallBack != NULLPTR) ADC_CallBack();
}