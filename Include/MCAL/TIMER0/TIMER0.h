/**
 * @file TIMER0.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/mem_map.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/

/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    TIMER0_NORMAL_MODE,
    TIMER0_PHASE_CORRECT_MODE,
    TIMER0_CTC_MODE,
    TIMER0_FAST_PWM_MODE
}TIMER0_Mode;

typedef enum
{
    TIMER0_NO_CLK,          
    TIMER0_NO_PRESCALER,    
    TIMER0_PRESCALER_8,     
    TIMER0_PRESCALER_64,    
    TIMER0_PRESCALER_256,   
    TIMER0_PRESCALER_1024,  
    TIMER0_EXT_CLK_FALLING, 
    TIMER0_EXT_CLK_RISING  

}TIMER0_Prescaler;

typedef enum
{
    TIMER0_COMPARE_OUTPUT_MODE_NORMAL,
    TIMER0_COMPARE_OUTPUT_MODE_TOGGLE,
    TIMER0_COMPARE_OUTPUT_MODE_NON_INVERTING,
    TIMER0_COMPARE_OUTPUT_MODE_INVERTING

}TIMER0_Compare;

/*---------------------------------------function declarations--------------------------------*/
void TIMER0_voidInit(TIMER0_Mode mode, TIMER0_Prescaler prescaler, TIMER0_Compare compare);
void TIMER0_voidStopTimer();
void TIMER0_voidOverFlowInterruptEnable();
void TIMER0_voidOverFlowInterruptDisable();
void TIMER0_voidCompareInterruptEnable();
void TIMER0_voidCompareInterruptDisable();

void TIMER0_voidSetPreLoad(uint8_t A_u8PreLoadValue);

void TIMER0_voidCTCSetCallBack(void (*pf)(void));
void TIMER0_voidOVFSetCallBack(void (*pf)(void));
void TIMER0_voidSetOCR0(uint8_t A_u8OCR0);

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
