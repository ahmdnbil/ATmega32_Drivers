/*
 * TIMER0_Private.h
 *
 *  Created on: Dec 4, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "./../../LIB/mem_map.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
// Force Output Compare
#define FOC0 7
// Waveform Generation bit0
#define WGM00 6
// Waveform Generation bit1
#define WGM01 3
// CLK select
#define CS00 0
// compare mode select
#define COM00 4
// Timer/Counter0 Output Compare Match Interrupt Enable
#define OCIE0 1
// Timer/Counter0 Overflow Interrupt Enable
#define TOIE0 0

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
