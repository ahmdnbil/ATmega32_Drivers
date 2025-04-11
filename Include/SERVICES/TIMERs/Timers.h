/**
 * @file Timers.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _TIMERS_SERVICES_H_
#define _TIMERS_SERVICES_H_


/************* includes ***************/
#include "./../../MCAL/TIMER1/TIMER1.h"

/************* macros ***************/

/************* typedefs ***************/

/************* function prototypes ***************/
void PWM_voidInit();
void PWM_Freq_KHz(uint16_t Freq);
void PWM_Freq_Hz(uint16_t Freq);
void PWM_voidDutyCycle(uint16_t DutyCycle);
void PWM_Measure(uint32_t *PFreq, uint8_t *Pduty);

#endif /* _TIMERS_SERVICES_H_ */
