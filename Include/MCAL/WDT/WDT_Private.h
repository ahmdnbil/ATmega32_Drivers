/*
 * WDT_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_WDT_WDT_PRIVATE_H_
#define INCLUDE_MCAL_WDT_WDT_PRIVATE_H_

// Watchdog Timer Control Register
#define WDTCR (*(volatile u8*) 0x41)

#define WDP0   0
#define WDE    3
#define WDTOE  4

#define WDT_PRESCALER_16K    0
#define WDT_PRESCALER_32K    1
#define WDT_PRESCALER_64K    2
#define WDT_PRESCALER_128K   3
#define WDT_PRESCALER_256K   4
#define WDT_PRESCALER_512K   5
#define WDT_PRESCALER_1024K  6
#define WDT_PRESCALER_2048K  7

#endif /* INCLUDE_MCAL_WDT_WDT_PRIVATE_H_ */
