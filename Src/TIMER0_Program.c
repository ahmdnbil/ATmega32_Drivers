/*
 * TIMER0_Program.c
 *
 *  Created on: Dec 4, 2022
 *      Author: User
 */


//libraries
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//TIMER0
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configurations.h"


#define TIMER0_NORMAL_MODE   0
#define TIMER0_PWM_MODE      1
#define TIMER0_CTC_MODE      2
#define TIMER0_FAST_PWM_MODE 3

#define TIMER0_MODE TIMER0_NORMAL_MODE 

#define TIMER0_NO_CLK          0
#define TIMER0_NO_PRESCALER    1
#define TIMER0_PRESCALER_8     2
#define TIMER0_PRESCALER_64    3
#define TIMER0_PRESCALER_256   4
#define TIMER0_PRESCALER_1024  5
#define TIMER0_EXT_CLK_FALLING 6
#define TIMER0_EXT_CLK_RISING  7

#define TIMER0_CLK_MODE TIMER0_PRESCALER_8

#define TIMER0_CLOCK_PRESCALER 
void MTIMER0_voidInit()
{
    #if TIMER0_MODE == TIMER0_NORMAL_MODE
    SET_BIT(TCCR0,FOC0);
    CLR_BIT(TCCR0,WGM00);
    CLR_BIT(TCCR0,WGM01);

    #elif TIMER0_MODE == TIMER0_PWM_MODE
    CLR_BIT(TCCR0,FOC0);
    SET_BIT(TCCR0,WGM00);
    CLR_BIT(TCCR0,WGM01);

    #elif TIMER0_MODE == TIMER0_CTC_MODE
    SET_BIT(TCCR0,FOC0);
    CLR_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);

    #elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
    CLR_BIT(TCCR0,FOC0);
    SET_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);
    #endif

    //Clk 
    TCCR0&=~(0b111<<CS00);
    TCCR0|=(TIMER0_CLK_MODE<<CS00);

}