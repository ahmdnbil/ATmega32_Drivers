/**
 * @file ADC_Cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_
#define INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_

//************************MACRO Declarations -------------------------------*/
#define FREE_RUNNING_MODE 0b000
#define ANALOG_COMPARTOR_TRIGGER 0b001
#define EXTI_REQ_TRIGGER 0b010
#define TIMER0_CTC_TRIGGER 0b011
#define TIMER0_OVF_TRIGGER 0b100
#define TIMER1_CTCB_TRIGGER 0b101
#define TIMER1_OVF_TRIGGER 0b110
#define TIMER1_CAP_TRIGGER 0b111
#define TRUE 1
#define FALSE 0
//************************* MACRO Configurations -----------------------*/
/*
choose one of the following for left adjust:-
    TRUE
    FALSE
*/
#define ADC_LEFT_ADJUST FALSE

/*
choose one of the following for auto triggering:-
    TRUE
    FALSE
*/
#define AUTO_TRIGGERING FALSE

/*
choose the auto trigger source:-
    FREE_RUNNING_MODE
    ANALOG_COMPARTOR_TRIGGER
    EXTI_REQ_TRIGGER
    TIMER0_CTC_TRIGGER
    TIMER0_OVF_TRIGGER
    TIMER1_CTCB_TRIGGER
    TIMER1_OVF_TRIGGER
    TIMER1_CAP_TRIGGER
*/
#define TRIGGER_TYPE FREE_RUNNING_MODE
#endif /* INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_ */
