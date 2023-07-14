/*
 * TIMER2_Private.h
 *
 *  Created on: Jun 22, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_

#define TCCR2 (*(volatile u8*) 0x45)

//wave generation mode
#define WGM20 6
#define WGM21 3
//compare on match bit
#define COM20 4
//prescaler bit
#define CS20  0

#define TCNT2 (*(volatile u8*) 0x44)
#define OCR2 (*(volatile u8*) 0x43)
#define ASSR (*(volatile u8*) 0x42)
#define TIFR (*(volatile u8*) 0x58)

// Timer/Counter Interrupt Mask Register
#define TIMSK (*(volatile u8 *) 0x59)
//overflow interrupt
#define TOIE  6
//output compare match interrupt
#define OCIE2 7


#endif /* INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_ */
