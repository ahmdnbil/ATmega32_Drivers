/*
 * TIMER1_Private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "./../../LIB/mem_map.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
// Compare Output Mode for Compare uint A pin0
#define COM1A0 6
// Compare Output Mode for Compare uint B pin0
#define COM1B0 4
// Wave Generator Mode first Two bits
#define WGM10 0
// Wave Generator Mode second Two bits
#define WGM12 3
// Prescaler
#define CS10 0
// edge select for ICU
#define ICES1 6
#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1 2
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
