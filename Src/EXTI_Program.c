/*
 * EXTI_Program.c
 *
 *  Created on: Nov 1, 2022
 *      Author: User
 */


//libraries
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//EXTI
#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Configuration.h"
#include "../Include/MCAL/EXTI/EXTI_Private.h"


void (*EXTI0_CallBack)(void)=NULL;
void (*EXTI1_CallBack)(void)=NULL;
void (*EXTI2_CallBack)(void)=NULL;

void MEXTI_voidConfig(u8 A_u8EXTINo,u8 A_u8SenseMode)
{
    if(A_u8SenseMode <4)
    {
        switch (A_u8EXTINo)
        {
        case EXTI0:
            MCUCR &=~(SENSE_MODE_MASK<<ISC00); //clearing bits
            MCUCR |=(A_u8SenseMode<<ISC00); //puting values
            break;

        case EXTI1:
            MCUCR &=~(SENSE_MODE_MASK<<ISC10); //clearing bits
            MCUCR |=(A_u8SenseMode<<ISC10); //puting values
            break;
        
        case EXTI2:
            switch (A_u8SenseMode)
            {
                case FALLING_EDGE:CLR_BIT(MCUCSR,ISC2);
                break;

                case RISING_EDGE:SET_BIT(MCUCSR,ISC2);
                break;
        
                default:
                break;
            }
            break;
        
        default:
            break;
        }
    }
}

void MEXTI_voidEnable(u8 A_u8EXTI)
{
    switch(A_u8EXTI)
    {
        case EXTI0: SET_BIT(GICR,INT0);
        break;
        case EXTI1: SET_BIT(GICR,INT1);
        break;
        case EXTI2: SET_BIT(GICR,INT2);
        break;
    }
}

void MEXTI_voidDisable(u8 A_u8EXTI)
{
    switch(A_u8EXTI)
    {
        case EXTI0: CLR_BIT(GICR,INT0);
        break;
        case EXTI1: CLR_BIT(GICR,INT1);
        break;
        case EXTI2: CLR_BIT(GICR,INT2);
        break;
    }
}

void MEXTI_voidClearFlag(u8 A_u8EXTI)
{
    switch(A_u8EXTI)
    {
        case EXTI0: SET_BIT(GIFR,INTF0);
        break;
        case EXTI1: SET_BIT(GIFR,INTF1);
        break;
        case EXTI2: SET_BIT(GIFR,INTF2);
        break;
    }
}

void MEXTI_voidSetCallBack(u8 A_u8EXTI,void (*ptrToFunc)(void))
{
    if(ptrToFunc!=NULL)
    {
        switch (A_u8EXTI)
        {
        case EXTI0:EXTI0_CallBack=ptrToFunc;break;
        case EXTI1:EXTI1_CallBack=ptrToFunc;break;
        case EXTI2:EXTI2_CallBack=ptrToFunc;break;
        default:
            break;
        }
    }
}



void __vector_1(void)  __attribute__((signal)); //__attribute__ for linker to recognize as ISR
void __vector_1(void)
{
    if(EXTI0_CallBack!=NULL)
    {
        EXTI0_CallBack();
    }
}

void __vector_2(void)  __attribute__((signal)); //__attribute__ for linker to recognize as ISR
void __vector_2(void)
{
    if(EXTI1_CallBack!=NULL)
    {
        EXTI1_CallBack();
    }
}
void __vector_3(void)  __attribute__((signal)); //__attribute__ for linker to recognize as ISR
void __vector_3(void)
{
    if(EXTI2_CallBack!=NULL)
    {
        EXTI2_CallBack();
    }
}