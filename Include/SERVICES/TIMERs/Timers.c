/**
 * @file Timers.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/************* includes ***************/
#include "./Timers.h"

/************* Variables Declaration ***************/
static volatile uint8_t global_u8Flag = 0;
static volatile uint32_t t1,t2,t3;

/************* function prototypes ***************/
static void func_ICU(void);

void PWM_voidInit()
{
    TIMER1_voidInit(TIMER1_FAST_PWM_ICR1,TIMER1_PRESCALER_8,TIMER1_COMPARE_OUTPUT_MODE_A_NON_INVERTING,TIMER1_COMPARE_OUTPUT_MODE_B_NON_INVERTING);
}

void PWM_Freq_KHz(uint16_t Freq)
{
    if(Freq ==0);
    else
    {
        uint16_t Ttotal =1000/Freq; //first frequency in KHz then convert it to microseconds
        if(Ttotal >= 1) TIMER1_voidSetICR1Value(Ttotal-1);
        else TIMER1_voidSetICR1Value(0);
    }
}

void PWM_Freq_Hz(uint16_t Freq)
{
    if(Freq ==0);
    else
    {
        uint16_t Ttotal =1000000/Freq;
        if(Ttotal >= 1) TIMER1_voidSetICR1Value(Ttotal-1);
        else TIMER1_voidSetICR1Value(0);
    }
}

void PWM_voidDutyCycle(uint16_t DutyCycle)
{
    if(DutyCycle <= 100)
    {
        uint16_t Ton = (((uint32_t)DutyCycle * (TIMER1_voidGetICR1()+1)) / 100);
        if(Ton>= 1) TIMER1_voidSetOCR1AValue(Ton-1);
        else TIMER1_voidSetOCR1AValue(0);
    }
}

// Synchronus Function
void PWM_Measure(uint32_t *PFreq,uint8_t *Pduty)
{
    uint16_t Ton,Toff;
    TIMER1_voidSetTCNT1Value(0);
    TIMER1_voidSetCallBackCapture(func_ICU);
    TIMER1_voidInputCaptureEdge(RISING);
    TIMER1_voidCaptureInterruptEnable();
    global_u8Flag = 0;
    /*
    why setting flag=0 ?
    if it configure while it on the rising state already it will get wrong value
    / ----->----                ----------                 _________
    / |        |               ^         ∨                ^         |
    __|        |_______________|         |________________|         |
    /  wrong indicat           t1        t2               t3
    */
    while (global_u8Flag < 3);
    Ton = t2 - t1;
    Toff = t3 - t2;
    *Pduty = (Ton * 100) / (Ton + Toff);
    *PFreq = (uint32_t)1000000 / (Toff + Ton);
}

//this function is used to create interrupt every time in ms you want with call back function
void TIMER1_setInterruptTime_ms(uint16_t time,void (*pf)(void))
{
    time=(time*1000)-1;
    TIMER1_voidSetOCR1AValue(time);
    TIMER1_voidSetCallBackCOMA(pf);
    TIMER1_voidCompareAInterruptEnable();
    TIMER1_voidInit(TIMER1_CTC_OCR1A, TIMER1_PRESCALER_8, TIMER1_COMPARE_OUTPUT_MODE_A_NORMAL, TIMER1_COMPARE_OUTPUT_MODE_B_NORMAL);
}

//this function is used to create interrupt every time in us you want with call back function
void TIMER1_setInterruptTime_us(uint16_t time,void (*pf)(void))
{
    time-=1;
    TIMER1_voidSetOCR1AValue(time);
    TIMER1_voidSetCallBackCOMA(pf);
    TIMER1_voidCompareAInterruptEnable();
    TIMER1_voidInit(TIMER1_CTC_OCR1A, TIMER1_PRESCALER_8, TIMER1_COMPARE_OUTPUT_MODE_A_NORMAL, TIMER1_COMPARE_OUTPUT_MODE_B_NORMAL);
}

/***************** Call Backs ********************/
//ICU call back function
static void func_ICU(void)
{
    if (global_u8Flag == 0)
    {
        t1 = TIMER1_voidGetICR1();
        TIMER1_voidInputCaptureEdge(FALLING);
        global_u8Flag = 1;
    }
    else if (global_u8Flag == 1)
    {
        t2 = TIMER1_voidGetICR1();
        TIMER1_voidInputCaptureEdge(RISING);
        global_u8Flag = 2;
    }
    else if (global_u8Flag == 2)
    {
        t3 = TIMER1_voidGetICR1();
        TIMER1_voidCaptureInterruptDisable();
        global_u8Flag = 3;
    }
}