/*
 * TIMER2_Program.c
 *
 *  Created on: Jun 22, 2023
 *      Author: User
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/TIMER2/TIMER2_Configurations.h"
#include "../Include/MCAL/TIMER2/TIMER2_Interface.h"
#include "../Include/MCAL/TIMER2/TIMER2_Private.h"

static void (*TIMER2_OVF_CALL)(void)=NULLPTR;
static void (*TIMER2_CTC_CALL)(void)=NULLPTR;

void MTIMER2_voidInit(TIMER2_Mode mode,TIMER2_Compare Compare,TIMER2_Prescaler Prescaler)
{
    switch (mode)
    {
        case TIMER2_NORMAL_MODE:
        CLR_BIT(TCCR2,WGM20);
        CLR_BIT(TCCR2,WGM21);
        break;

        case TIMER2_PHASE_CORRECT_MODE:
        SET_BIT(TCCR2,WGM20);
        CLR_BIT(TCCR2,WGM21);
        break;

        case TIMER2_CTC_MODE:
        CLR_BIT(TCCR2,WGM20);
        SET_BIT(TCCR2,WGM21);
        break;

        case TIMER2_FAST_PWM_MODE:
        SET_BIT(TCCR2,WGM20);
        SET_BIT(TCCR2,WGM21);
        break;
    
        default:
        break;
    }

    TCCR2&=(~(0b11<<COM20)) & (~(0b111<<CS20));
    TCCR2|=(Compare<<COM20) | (Prescaler<<CS20);

}

void MTIMER2_voidSetTCNT2(u8 A_u8Value)
{
    TCNT2=A_u8Value;
}

void MTIMER2_voidSetOCR2(u8 A_u8Value)
{
    OCR2=A_u8Value;
}

//Interrupt Section




void MTIMER2_voidOverFlowInterruptEnable()
{
    SET_BIT(TIMSK,TOIE);
}

void MTIMER2_voidOverFlowInterruptDisable()
{
    CLR_BIT(TIMSK,TOIE);
}

void MTIMER2_voidCompareInterruptEnable()
{
    SET_BIT(TIMSK,OCIE2);
}
void MTIMER2_voidCompareInterruptDisable()
{
    CLR_BIT(TIMSK,OCIE2);
}

void MTIMER2_voidSetCallBackOVF(void (*pf)())
{
    TIMER2_OVF_CALL=pf;
}

void MTIMER2_voidSetCallBackCTC(void (*pf)())
{
    TIMER2_CTC_CALL=pf;
}

ISR(TIMER2_OVF_VECT)
{
    if(TIMER2_OVF_CALL != NULLPTR) TIMER2_OVF_CALL();
}

ISR(TIMER2_CTC_VECT)
{
    if(TIMER2_CTC_CALL != NULLPTR) TIMER2_CTC_CALL();
}