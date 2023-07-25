/*
 * WDT_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "./WDT_Configurations.h"
#include "./WDT_Interface.h"
#include "./WDT_Private.h"

void WDT_voidEnableWDT(void)
{
    WDTCR &= ~(0b111 << WDP0);
    WDTCR |= (WDT_PRESCALER << WDP0);
    SET_BIT(WDTCR, WDE);
    CLR_BIT(WDTCR, WDTOE);
}

void WDT_voidDisableWDT(void)
{
    CLR_BIT(WDTCR, WDE);
    SET_BIT(WDTCR, WDTOE);
}
