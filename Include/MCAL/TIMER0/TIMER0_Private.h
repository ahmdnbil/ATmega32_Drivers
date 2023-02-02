/*
 * TIMER0_Private.h
 *
 *  Created on: Dec 4, 2022
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_

/* Timer/Counter Control Register */
#define TCCR0 (*(volatile u8 *) 0x53)
//Force Output Compare
#define FOC0 7
//Waveform Generation bit0
#define WGM00 6
//Waveform Generation bit1
#define WGM01 3
//CLK select
#define CS00 0

/*********************************/

#define TCNT0 (*(volatile u8 *) 0x52)
#define OCR0  (*(volatile u8 *) 0x5C)
#define TIMSK (*(volatile u8 *) 0x59)
#define TIFR  (*(volatile u8 *) 0x58)


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */