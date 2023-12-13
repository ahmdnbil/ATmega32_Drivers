/*
 * TIMER0_Program.c
 *
 *  Created on: Dec 4, 2022
 *      Author: User
 */

// TIMER0
#include "./TIMER0_Interface.h"
#include "./TIMER0_Private.h"
#include "./TIMER0_Configurations.h"

static void (*TIMER0_OVF_CallBack)(void) = NULLPTR;
static void (*TIMER0_CTC_CallBack)(void) = NULLPTR;

void TIMER0_voidInit(TIMER0_Mode mode, TIMER0_Prescaler prescaler, TIMER0_Compare compare)
{
    switch (mode)
    {
    case TIMER0_NORMAL_MODE:
        SET_BIT(TCCR0, FOC0);
        CLR_BIT(TCCR0, WGM00);
        CLR_BIT(TCCR0, WGM01);
        break;

    case TIMER0_PHASE_CORRECT_MODE:
        CLR_BIT(TCCR0, FOC0);
        SET_BIT(TCCR0, WGM00);
        CLR_BIT(TCCR0, WGM01);
        break;

    case TIMER0_CTC_MODE:
        SET_BIT(TCCR0, FOC0);
        CLR_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);
        break;

    case TIMER0_FAST_PWM_MODE:
        CLR_BIT(TCCR0, FOC0);
        SET_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);
        break;
    }

    // note:  prescaler must be the last initalization step
    // because it make circuit to start  working
    // Clk & Compare Output Mode
    TCCR0 &= (~(0b111 << CS00)) & (~(0b11 << COM00));
    TCCR0 |= ((compare << COM00) | (prescaler << CS00));
}

/******************************************/
// Interrupt Enable/Disable
void TIMER0_voidOverFlowInterruptEnable()
{
    SET_BIT(TIMSK, TOIE0);
}
void TIMER0_voidOverFlowInterruptDisable()
{
    CLR_BIT(TIMSK, TOIE0);
}

void TIMER0_voidCompareInterruptEnable()
{
    SET_BIT(TIMSK, OCIE0);
}
void TIMER0_voidCompareInterruptDisable()
{
    CLR_BIT(TIMSK, OCIE0);
}
/******************************************/

void TIMER0_voidSetPreLoad(u8 A_u8PreLoadValue)
{
    TCNT0 = A_u8PreLoadValue;
}

void TIMER0_voidSetOCR0(u8 A_u8OCR0)
{
    OCR0 = A_u8OCR0;
}

/*Interrupt Section*/
void TIMER0_voidOVFSetCallBack(void (*pf)(void))
{
    TIMER0_OVF_CallBack = pf;
}

void TIMER0_voidCTCSetCallBack(void (*pf)(void))
{
    TIMER0_CTC_CallBack = pf;
}

ISR(TIMER0_OVF_VECT)
{
    if (TIMER0_OVF_CallBack != NULLPTR)
        TIMER0_OVF_CallBack();
}

ISR(TIMER0_CTC_VECT)
{
    if (TIMER0_CTC_CallBack != NULLPTR)
        TIMER0_CTC_CallBack();
}