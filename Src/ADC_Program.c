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

void MADC_voidInit()
{
    //reference selection
    ADMUX&=~(0b11<<REFS0);
    ADMUX|=(REF_VOLTAGE<<REFS0);

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
    
    
    //interrupt enable
    #if ADC_INTERRUPT == TRUE
    SET_BIT(ADCSRA,ADIE);
    #else
    CLR_BIT(ADCSRA,ADIE);
    #endif

    //prescaler division factor
    ADCSRA&=~(0b111<<ADPS0);
    ADCSRA|=(ADC_PRESCALER<<ADPS0);

}

u16 MADC_u16GetDigitalValue(u8 A_u8Channel)
{

    u16 local_u16DigitalValue=0;
    
    if (A_u8Channel <=32)
    {
        //chosing channel
        ADMUX&=~(0b11111<< MUX0);
        ADMUX|=(A_u8Channel<< MUX0);

        //starting conversion
        SET_BIT(ADCSRA,ADCS);

        //polling on flag until the conversion is finished
        while(GET_BIT(ADCSRA,ADIF)==0);
        //writing one to clear the flag
        SET_BIT(ADCSRA,ADIF);
        //Read value
        local_u16DigitalValue=ADCLH;
    }

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