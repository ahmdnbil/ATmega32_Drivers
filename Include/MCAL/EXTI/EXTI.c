/**
 * @file EXTI.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
// libraries

#include "./EXTI.h"

static void (*EXTI0_CallBack)(void) = NULLPTR;
static void (*EXTI1_CallBack)(void) = NULLPTR;
static void (*EXTI2_CallBack)(void) = NULLPTR;

void EXTI_voidConfig(ExInterrupSource_t EXTINo, uint8_t A_u8SenseMode)
{
    if (A_u8SenseMode < 4)
    {
        switch (EXTINo)
        {
        case EXTI0:
            MCUCR &= ~(SENSE_MODE_MASK << ISC00); // clearing bits
            MCUCR |= (A_u8SenseMode << ISC00);    // puting values
            break;

        case EXTI1:
            MCUCR &= ~(SENSE_MODE_MASK << ISC10); // clearing bits
            MCUCR |= (A_u8SenseMode << ISC10);    // puting values
            break;

        case EXTI2:
            switch (A_u8SenseMode)
            {
            case FALLING_EDGE:
                CLR_BIT(MCUCSR, ISC2);
                break;
                
                case RISING_EDGE:
                SET_BIT(MCUCSR, ISC2);
                break;
                
                default:
                CLR_BIT(MCUCSR, ISC2);
                break;
            }
            break;

        default:
            break;
        }
    }
}

void EXTI_voidEnable(ExInterrupSource_t EXTINo)
{
    switch (EXTINo)
    {
    case EXTI0:
        SET_BIT(GICR, INT0);
        break;
    case EXTI1:
        SET_BIT(GICR, INT1);
        break;
    case EXTI2:
        SET_BIT(GICR, INT2);
        break;
    }
}

void EXTI_voidDisable(ExInterrupSource_t EXTINo)
{
    switch (EXTINo)
    {
    case EXTI0:
        CLR_BIT(GICR, INT0);
        break;
    case EXTI1:
        CLR_BIT(GICR, INT1);
        break;
    case EXTI2:
        CLR_BIT(GICR, INT2);
        break;
    }
}

void EXTI_voidClearFlag(ExInterrupSource_t EXTINo)
{
    switch (EXTINo)
    {
    case EXTI0:
        SET_BIT(GIFR, INTF0);
        break;
    case EXTI1:
        SET_BIT(GIFR, INTF1);
        break;
    case EXTI2:
        SET_BIT(GIFR, INTF2);
        break;
    }
}

void EXTI_voidSetCallBack(ExInterrupSource_t EXTINo, void (*ptrToFunc)(void))
{
    if (ptrToFunc != NULL)
    {
        switch (EXTINo)
        {
        case EXTI0:
            EXTI0_CallBack = ptrToFunc;
            break;
        case EXTI1:
            EXTI1_CallBack = ptrToFunc;
            break;
        case EXTI2:
            EXTI2_CallBack = ptrToFunc;
            break;
        default:
            break;
        }
    }
}

/*
note1: __vector_No(void): it will shift program counter to ISR and put the ISR location
        in vector table but doesn't make context switch
note2: __attribute__((signal)) will make context switch cause AVR doesn't make context
        switch when interrupt happen so we have to make push and pop the shared registers
        & status register to & from stack
*/

ISR(EXTI0_VECT)
{
    if (EXTI0_CallBack != NULLPTR)
        EXTI0_CallBack();
}

ISR(EXTI1_VECT)
{
    if (EXTI1_CallBack != NULLPTR)
        EXTI1_CallBack();
}

ISR(EXTI2_VECT)
{
    if (EXTI2_CallBack != NULLPTR)
        EXTI2_CallBack();
}