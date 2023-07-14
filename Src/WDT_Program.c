/*
 * WDT_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: User
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"


#include "../Include/MCAL/WDT/WDT_Configurations.h"
#include "../Include/MCAL/WDT/WDT_Interface.h"
#include "../Include/MCAL/WDT/WDT_Private.h"

void MWDT_voidEnableWDT(void)
{
    WDTCR &=~(0b111<<WDP0);
    WDTCR |=(WDT_PRESCALER<<WDP0);
    SET_BIT(WDTCR,WDE);
    CLR_BIT(WDTCR,WDTOE);
}

void MWDT_voidDisableWDT(void)
{
    CLR_BIT(WDTCR,WDE);
    SET_BIT(WDTCR,WDTOE);
}
