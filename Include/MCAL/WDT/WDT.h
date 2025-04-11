/**
 * @file WDT.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_WDT_WDT_INTERFACE_H_
#define INCLUDE_MCAL_WDT_WDT_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "./../../LIB/mem_map.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/


typedef enum
{
    WDT_PRESCALER_16K = 0,
    WDT_PRESCALER_32K,
    WDT_PRESCALER_64K,
    WDT_PRESCALER_128K,
    WDT_PRESCALER_256K,
    WDT_PRESCALER_512K,
    WDT_PRESCALER_1024K,
    WDT_PRESCALER_2048K,
} WDT_Prescaler_t;




/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
void WDT_voidEnableWDT(void);
void WDT_voidDisableWDT(void);

#endif /* INCLUDE_MCAL_WDT_WDT_INTERFACE_H_ */
