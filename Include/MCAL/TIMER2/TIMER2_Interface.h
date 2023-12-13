/*
 * TIMER2_Interface.h
 *
 *  Created on: Jun 22, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
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
    TIMER2_PRESCALER_32,
    TIMER2_PRESCALER_64,
    TIMER2_PRESCALER_128,
    TIMER2_PRESCALER_256,
    TIMER2_PRESCALER_1024,
} TIMER2_Prescaler;

/*---------------------------------------function declarations--------------------------------*/
void TIMER2_voidInit(TIMER2_Mode mode, TIMER2_Compare Compare, TIMER2_Prescaler Prescaler);
void TIMER2_voidSetTCNT2(u8 A_u8Value);
void TIMER2_voidSetOCR2(u8 A_u8Value);

void TIMER2_voidOverFlowInterruptEnable();
void TIMER2_voidOverFlowInterruptDisable();

void TIMER2_voidCompareInterruptEnable();
void TIMER2_voidCompareInterruptDisable();

void TIMER2_voidSetCallBackOVF(void (*pf)());
void TIMER2_voidSetCallBackCTC(void (*pf)());

#endif /* INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_ */
