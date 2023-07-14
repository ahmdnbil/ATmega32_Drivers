/*
 * TIMER1_Interface.h
 *
 *  Created on: Jun 19, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_

typedef enum
{
    TIMER1_NORMAL_MODE,
    TIMER1_PHASE_CORRECT_8BIT,
    TIMER1_PHASE_CORRECT_9BIT,
    TIMER1_PHASE_CORRECT_10BIT,
    TIMER1_CTC_OCR1A,
    TIMER1_FAST_PWM_8BIT,
    TIMER1_FAST_PWM_9BIT,
    TIMER1_FAST_PWM_10BIT,
    TIMER1_PHASE_AND_FREQUENCY_CORRECT_ICR1,
    TIMER1_PHASE_AND_FREQUENCY_CORRECT_OCRA1,
    TIMER1_PHASE_CORRECT_ICR1,
    TIMER1_PHASE_CORRECT_OCRA1,
    TIMER1_CTC_ICR1,
    TIMER1_FAST_PWM_ICR1,
    TIMER1_FAST_PWM_OCRA1
}TIMER1_Mode;

typedef enum
{
    TIMER1_NO_CLK,          
    TIMER1_NO_PRESCALER,    
    TIMER1_PRESCALER_8,     
    TIMER1_PRESCALER_64,    
    TIMER1_PRESCALER_256,   
    TIMER1_PRESCALER_1024,  
    TIMER1_EXT_CLK_FALLING, 
    TIMER1_EXT_CLK_RISING  

}TIMER1_Prescaler;

typedef enum
{
    TIMER1_COMPARE_OUTPUT_MODE_A_NORMAL, 
    TIMER1_COMPARE_OUTPUT_MODE_A_TOGGLE,
    TIMER1_COMPARE_OUTPUT_MODE_A_NON_INVERTING, 
    TIMER1_COMPARE_OUTPUT_MODE_A_INVERTING    

}TIMER1_CompareA;


typedef enum
{
    TIMER1_COMPARE_OUTPUT_MODE_B_NORMAL, 
    TIMER1_COMPARE_OUTPUT_MODE_B_TOGGLE, 
    TIMER1_COMPARE_OUTPUT_MODE_B_NON_INVERTING, 
    TIMER1_COMPARE_OUTPUT_MODE_B_INVERTING    
}TIMER1_CompareB;

typedef enum
{
    RISING,
    FALLING
}ICU_Edge_type;


void MTIMER1_voidInit(TIMER1_Mode mode,TIMER1_Prescaler prescaler,TIMER1_CompareA compareA,TIMER1_CompareB compareB);

void MTIMER1_voidInputCaptureEdge(ICU_Edge_type edge);
void MTIMER1_voidMeasurePWM(u32 *Pfreq,u8*Pduty);

void MTIMER1_voidCaptureInterruptEnable(void);
void MTIMER1_voidCaptureInterruptDisable(void);
void MTIMER1_voidCompareAInterruptEnable(void);
void MTIMER1_voidCompareAInterruptDisable(void);
void MTIMER1_voidCompareBInterruptEnable(void);
void MTIMER1_voidCompareBInterruptDisable(void);
void MTIMER1_voidOverFlowInterruptEnable(void);
void MTIMER1_voidOverFlowInterruptDisable(void);


void MTIMER1_voidSetTCNT1Value(u16 A_u16TCNT1Value);
void MTIMER1_voidSetICR1Value(u16 A_u16ICR1Value);
void MTIMER1_voidSetOCR1AValue(u16 A_u16OCR1AValue);
void MTIMER1_voidSetOCR1BValue(u16 A_u16OCR1AValue);

void MTIMER1_voidSetCallBackCapture(void(*pf)(void));
void MTIMER1_voidSetCallBackCOMA(void(*pf)(void));
void MTIMER1_voidSetCallBackCOMB(void(*pf)(void));
void MTIMER1_voidSetCallBackOVF(void(*pf)(void));

u16 MTIMER1_voidGetICR1(void);

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
