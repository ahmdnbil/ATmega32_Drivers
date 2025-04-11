/**
 * @file EXTI.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "./../../LIB/mem_map.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define LOW_LEVEL          0b00 
#define ANY_LOGICAL_CHANGE 0b01
#define FALLING_EDGE       0b10
#define RISING_EDGE        0b11


#define ISC00 0
#define ISC10 2
#define ISC2 6
#define INT0 6
#define INT1 7
#define INT2 5
#define INTF0 6
#define INTF1 7
#define INTF2 5

#define SENSE_MODE_MASK 0b11

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/

typedef enum{
    EXTI0=0,
    EXTI1,
    EXTI2
}ExInterrupSource_t;
/*---------------------------------------function declarations--------------------------------*/

void EXTI_voidConfig(ExInterrupSource_t EXTINo, uint8_t A_u8SenseMode);
void EXTI_voidEnable(ExInterrupSource_t EXTINo);
void EXTI_voidDisable(ExInterrupSource_t EXTINo);
void EXTI_voidClearFlag(ExInterrupSource_t EXTINo);
void EXTI_voidSetCallBack(ExInterrupSource_t EXTINo, void (*ptrToFunc)(void));

#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
