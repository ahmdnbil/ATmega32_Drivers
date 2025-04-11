/**
 * @file TIMER1.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "./TIMER1.h"

static void (*TIMER1_CAPTURE)(void) = NULLPTR;
static void (*TIMER1_COMA)(void) = NULLPTR;
static void (*TIMER1_COMB)(void) = NULLPTR;
static void (*TIMER1_OVF)(void) = NULLPTR;


void TIMER1_voidInit(TIMER1_Mode mode, TIMER1_Prescaler prescaler, TIMER1_CompareA compareA, TIMER1_CompareB compareB)
{
    switch (mode)
    {
    case TIMER1_NORMAL_MODE:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b00 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b00 << WGM12);
        break;

    case TIMER1_PHASE_CORRECT_8BIT:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b01 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b00 << WGM12);
        break;

    case TIMER1_PHASE_CORRECT_9BIT:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b10 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b00 << WGM12);
        break;

    case TIMER1_PHASE_CORRECT_10BIT:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b11 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b00 << WGM12);
        break;

    case TIMER1_CTC_OCR1A:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b00 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b01 << WGM12);
        break;

    case TIMER1_FAST_PWM_8BIT:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b01 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b01 << WGM12);
        break;

    case TIMER1_FAST_PWM_9BIT:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b10 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b01 << WGM12);
        break;

    case TIMER1_FAST_PWM_10BIT:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b11 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b01 << WGM12);
        break;

    case TIMER1_PHASE_AND_FREQUENCY_CORRECT_ICR1:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b00 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b10 << WGM12);
        break;

    case TIMER1_PHASE_AND_FREQUENCY_CORRECT_OCRA1:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b01 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b10 << WGM12);
        break;

    case TIMER1_PHASE_CORRECT_ICR1:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b10 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b10 << WGM12);
        break;

    case TIMER1_PHASE_CORRECT_OCRA1:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b11 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b10 << WGM12);
        break;

    case TIMER1_CTC_ICR1:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b00 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b11 << WGM12);
        break;

    case TIMER1_FAST_PWM_ICR1:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b10 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b11 << WGM12);
        break;

    case TIMER1_FAST_PWM_OCRA1:
        TCCR1A &= ~(0b11 << WGM10);
        TCCR1A |= (0b11 << WGM10);
        TCCR1B &= ~(0b11 << WGM12);
        TCCR1B |= (0b11 << WGM12);
        break;
    }

    // Mode of Compare output mdoe for OC1A & OC1B
    TCCR1A &= (~(0b11 << COM1A0)) & (~(0b11 << COM1B0));
    TCCR1A |= ((compareA << COM1A0) | (compareB << COM1B0));

    // prescaler
    TCCR1B &= ~(0b111 << CS10);
    TCCR1B |= (prescaler << CS10);
}

void TIMER1_voidDisable(void)
{
    TCCR1B &= ~(0b111 << CS10);
}


uint16_t TIMER1_u16ReadTCNT1(void)
{
    return TCNT1;
}

void TIMER1_voidClearTCNT1(void)
{
    TCNT1 = 0;
}

void TIMER1_voidInputCaptureEdge(ICU_Edge_type edge)
{
    if (edge == RISING)
        SET_BIT(TCCR1B, ICES1);
    else if (edge == FALLING)
        CLR_BIT(TCCR1B, ICES1);
}

uint16_t TIMER1_voidGetICR1(void)
{
    return ICR1;
}

/**********************************************/
// interrupt Enable/Disable
void TIMER1_voidCaptureInterruptEnable(void)
{
    SET_BIT(TIMSK, TICIE1);
}

void TIMER1_voidCaptureInterruptDisable(void)
{
    CLR_BIT(TIMSK, TICIE1);
}

void TIMER1_voidCompareAInterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1A);
}

void TIMER1_voidCompareAInterruptDisable(void)
{
    CLR_BIT(TIMSK, OCIE1A);
}

void TIMER1_voidCompareBInterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1B);
}

void TIMER1_voidCompareBInterruptDisable(void)
{
    CLR_BIT(TIMSK, OCIE1B);
}

void TIMER1_voidOverFlowInterruptEnable(void)
{
    SET_BIT(TIMSK, TOIE1);
}

void TIMER1_voidOverFlowInterruptDisable(void)
{
    CLR_BIT(TIMSK, TOIE1);
}
/**********************************************/

void TIMER1_voidSetICR1Value(uint16_t A_u16ICR1Value)
{
    ICR1 = A_u16ICR1Value;
}

void TIMER1_voidSetOCR1AValue(uint16_t A_u16OCR1AValue)
{
    OCR1A = A_u16OCR1AValue;
}

void TIMER1_voidSetOCR1BValue(uint16_t A_u16OCR1AValue)
{
    OCR1B = A_u16OCR1AValue;
}

// Set Preload Value in TCNT1
void TIMER1_voidSetTCNT1Value(uint16_t A_u16TCNT1Value)
{
    TCNT1 = A_u16TCNT1Value;
}

// interrupt section

void TIMER1_voidSetCallBackCapture(void (*pf)(void))
{
    TIMER1_CAPTURE = pf;
}
void TIMER1_voidSetCallBackCOMA(void (*pf)(void))
{
    TIMER1_COMA = pf;
}
void TIMER1_voidSetCallBackCOMB(void (*pf)(void))
{
    TIMER1_COMB = pf;
}

void TIMER1_voidSetCallBackOVF(void (*pf)(void))
{
    TIMER1_OVF = pf;
}

// ISR section
ISR(TIMER1_CAPT_VECT)
{
    if (TIMER1_CAPTURE != NULLPTR)
        TIMER1_CAPTURE();
}
ISR(TIMER1_COMA_VECT)
{
    if (TIMER1_COMA != NULLPTR)
        TIMER1_COMA();
}
ISR(TIMER1_COMB_VECT)
{
    if (TIMER1_COMB != NULLPTR)
        TIMER1_COMB();
}
ISR(TIMER1_OVF_VECT)
{
    if (TIMER1_OVF != NULLPTR)
        TIMER1_OVF();
}

