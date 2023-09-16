/*
 * ADC_Configurations.h
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_
#define INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_

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
