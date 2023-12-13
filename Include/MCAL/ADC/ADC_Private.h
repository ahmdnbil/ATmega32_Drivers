/*
 * ADC_Private.h
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "./../../LIB/mem_map.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
#define REFS0 6
#define ADLAR 5
#define MUX0 0
#define TRUE  1
#define FALSE 0
// ADC Enable
#define ADEN  7
// ADC Start Conversion
#define ADCS  6
// ADC Auto Triggering Enable
#define ADATE 5
// ADC Interrupt Flag
#define ADIF  4
// ADC Interrupt Enable
#define ADIE  3
// ADC Prescaler Select bit 0
#define ADPS0 0
// ADC Auto Trigger Source
#define ADTS0 5
#define FREE_RUNNING_MODE 0b000
#define ANALOG_COMPARTOR_TRIGGER 0b001
#define EXTI_REQ_TRIGGER 0b010
#define TIMER0_CTC_TRIGGER 0b011
#define TIMER0_OVF_TRIGGER 0b100
#define TIMER1_CTCB_TRIGGER 0b101
#define TIMER1_OVF_TRIGGER 0b110
#define TIMER1_CAP_TRIGGER 0b111

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
