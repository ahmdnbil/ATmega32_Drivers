/*
 * ULTRASONIC_Program.c
 *
 *  Created on: Jun 27, 2023
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/TIMER1/TIMER1_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "./ULTRASONIC_Configurations.h"
#include "./ULTRASONIC_Interface.h"
#include "./ULTRASONIC_Private.h"

#include <util/delay.h>

static void Func_OVF();
static void Func_ICU();
u8 global_u8Flag = 0, noOVF = 0;
u16 t1, t2;

void ULTRASONIC_voidInit(void)
{
    TIMER1_voidInit(TIMER1_NORMAL_MODE, TIMER1_PRESCALER_8, TIMER1_COMPARE_OUTPUT_MODE_A_NORMAL, TIMER1_COMPARE_OUTPUT_MODE_B_NORMAL);
    TIMER1_voidSetCallBackOVF(Func_OVF);
    TIMER1_voidSetCallBackCapture(Func_ICU);
}

u16 ULTRASONIC_u16GetDistance()
{
    u16 distance;
    u16 time;
    /*
        this line not be valid if we use timer in another application
        but for simplicity we consider the timer register equal to zero
    */
    TIMER1_voidSetTCNT1Value(0);
    // making number of overflow equal to zero to remove its time from calculation, cause
    // it happens before we gave trigger to ultrasonic
    noOVF = 0;
    global_u8Flag = 0;
    DIO_voidSetPinValue(ULTRSONIC_PORT, ULTRSONIC_PIN, PIN_HIGH);
    _delay_us(10);
    DIO_voidSetPinValue(ULTRSONIC_PORT, ULTRSONIC_PIN, PIN_LOW);
    TIMER1_voidInputCaptureEdge(RISING);
    TIMER1_voidCaptureInterruptEnable();
    while (global_u8Flag < 2)
        ;
    time = t2 - t1 + ((u32)noOVF * 65535);
    distance = time / 58;
    TIMER1_voidCaptureInterruptDisable();
    return distance;
}

/*
    the following method is called periodic check
    it will not be polling on the flag waiting for ultrasonic to finish measurement, No it will
    just give the trigger to ultrasonic and get distance at any time
*/
void ULTRASONIC_voidStart()
{
    if (global_u8Flag == 0)
    {
        DIO_voidSetPinValue(ULTRSONIC_PORT, ULTRSONIC_PIN, PIN_HIGH);
        _delay_us(10);
        DIO_voidSetPinValue(ULTRSONIC_PORT, ULTRSONIC_PIN, PIN_LOW);
        TIMER1_voidInputCaptureEdge(RISING);
        TIMER1_voidCaptureInterruptEnable();
        TIMER1_voidOverFlowInterruptEnable();
    }
}
u16 ULTRASONIC_u8GetDistanceNoBlock(u16 *Pdistance)
{
    u16 distance;
    u16 time;
    if (global_u8Flag == 2)
    {
        time = t2 - t1 + ((u32)noOVF * 65535);
        distance = time / 58;
        *Pdistance = distance;
        TIMER1_voidOverFlowInterruptEnable();
        global_u8Flag = 0;
        return 1;
    }
    return 0;
}

static void Func_ICU(void)
{
    if (global_u8Flag == 0)
    {
        noOVF = 0;
        t1 = TIMER1_voidGetICR1();
        global_u8Flag = 1;
        TIMER1_voidInputCaptureEdge(FALLING);
    }
    else if (global_u8Flag == 1)
    {
        t2 = TIMER1_voidGetICR1();
        global_u8Flag = 2;
        TIMER1_voidInputCaptureEdge(RISING);
        TIMER1_voidOverFlowInterruptDisable();
        TIMER1_voidCaptureInterruptDisable();
    }
}

static void Func_OVF(void)
{
    noOVF++;
}
