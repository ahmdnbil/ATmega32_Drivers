/*
 * ADC_Configurations.h
 *
 *  Created on: Nov 26, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_
#define INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_
/*
Chose one of the following as refernce voltage:-
AREF 
AVCC_CAPACTIOR
INTERNAL_REF
*/
#define REF_VOLTAGE AVCC_CAPACTIOR


/*
Chose one of the following for left adjust:-
TRUE
FALSE
*/
#define ADC_LEFT_ADJUST FALSE


/*
Chose one of the following for Channel:-
ADC0_SINGLE
ADC1_SINGLE
ADC2_SINGLE
ADC3_SINGLE
ADC4_SINGLE
ADC5_SINGLE
ADC6_SINGLE
ADC7_SINGLE
*/


/*
Chose one of the following for auto triggering:-
TRUE
FALSE
*/
#define AUTO_TRIGGERING FALSE 


/*
Chose one of the following for auto triggering:-
TRUE
FALSE
*/
#define ADC_INTERRUPT FALSE


/*
Chose one of the following for Prescaler:-
ADC_PRESCALER_2   
ADC_PRESCALER_2   
ADC_PRESCALER_4   
ADC_PRESCALER_8   
ADC_PRESCALER_16  
ADC_PRESCALER_32  
ADC_PRESCALER_64  
ADC_PRESCALER_128 
*/
#define ADC_PRESCALER ADC_PRESCALER_64



#endif /* INCLUDE_MCAL_ADC_ADC_CONFIGURATIONS_H_ */
