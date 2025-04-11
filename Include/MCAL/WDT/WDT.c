/**
 * @file WDT_Program.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "./WDT.h"

void WDT_voidEnableWDT(void)
{
    WDT_Prescaler_t prescaler = WDT_PRESCALER_2048K;
    WDTCR &= ~(0b111 << WDP0);
    WDTCR |= (prescaler << WDP0);
    SET_BIT(WDTCR, WDE);
    CLR_BIT(WDTCR, WDTOE);
}

void WDT_voidDisableWDT(void)
{
    CLR_BIT(WDTCR, WDE);
    SET_BIT(WDTCR, WDTOE);
}
