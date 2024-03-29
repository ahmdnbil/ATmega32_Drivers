/*
 * SERVO_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/TIMER1/TIMER1_Interface.h"

#include "./SERVO_Configurations.h"
#include "./SERVO_Interface.h"

void SERVO_voidInit(void)
{
    TIMER1_voidInit(TIMER1_FAST_PWM_ICR1, TIMER1_PRESCALER_8, TIMER1_COMPARE_OUTPUT_MODE_A_NON_INVERTING, TIMER1_COMPARE_OUTPUT_MODE_B_NON_INVERTING);
    TIMER1_voidSetICR1Value(19999);
    /*
        making frequecny equal to 50Hz, how?
        CPU_freq=8MHz       &  prescaler = 8
        so TIMER_Freq= 1MHz &  tick_time= 1 usec
        time = 1/50 hz = 20msec =20000usec
        so setting value of ICR1 to be 19999 cause it takes another step from 19999 to 0
        By varing the duty cycle between 999 to 1999 we get 0 to 180

    */
}

/*
0   -----> 999
180 -----> 1999
so it's a linear relation

OCRA_value - 999    1999  -  999                                             Angle*1000
----------------  = ------------     so desired Angel =====> OCRA_value =  (------------) + 999
Angle      -  0      180  -  0                                                   180
*/

void SERVO_voidSetServoAngle(u8 A_u8Angle)
{
    u16 local_u16OCRAValue = (((u64)A_u8Angle * 1000) / 180) + 999;
    TIMER1_voidSetOCR1AValue(local_u16OCRAValue);
}
