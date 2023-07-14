/*
 * TIMER2_Interface.h
 *
 *  Created on: Jun 22, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_

typedef enum
{
    TIMER2_NORMAL_MODE,   
    TIMER2_PHASE_CORRECT_MODE,     
    TIMER2_CTC_MODE,
    TIMER2_FAST_PWM_MODE 
}TIMER2_Mode;

typedef enum
{
    TIMER2_COM_NORMAL,
    TIMER2_COM_TOGGLE,
    TIMER2_COM_NON_INVERTING,
    TIMER2_COM_INVERTING,
}TIMER2_Compare;

typedef enum
{
    TIMER2_NO_CLK,          
    TIMER2_NO_PRESCALER,    
    TIMER2_PRESCALER_8,   
    TIMER2_PRESCALER_64,    
    TIMER2_PRESCALER_256,   
    TIMER2_PRESCALER_1024,  
    TIMER2_EXT_CLK_FALLING, 
    TIMER2_EXT_CLK_RISING  
}TIMER2_Prescaler;

void MTIMER2_voidInit(TIMER2_Mode mode,TIMER2_Compare Compare,TIMER2_Prescaler Prescaler);

void MTIMER2_voidSetTCNT2(u8 A_u8Value);
void MTIMER2_voidSetOCR2(u8 A_u8Value);

void MTIMER2_voidOverFlowInterruptEnable();
void MTIMER2_voidOverFlowInterruptDisable();

void MTIMER2_voidCompareInterruptEnable();
void MTIMER2_voidCompareInterruptDisable();

void MTIMER2_voidSetCallBackOVF(void (*pf)());
void MTIMER2_voidSetCallBackCTC(void (*pf)());



#endif /* INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_ */
