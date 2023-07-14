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
//compare mode select
#define COM00 4



/*********************************/

// Timer/Counter Register
#define TCNT0 (*(volatile u8 *) 0x52)

/*********************************/

// Output Compare Register
#define OCR0  (*(volatile u8 *) 0x5C)

/*********************************/

//Timer/Counter Interrupt Mask
#define TIMSK (*(volatile u8 *) 0x59)
//Timer/Counter0 Output Compare Match Interrupt Enable
#define OCIE0 1
//Timer/Counter0 Overflow Interrupt Enable
#define TOIE0 0

/*********************************/
#define TIFR  (*(volatile u8 *) 0x58)


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
