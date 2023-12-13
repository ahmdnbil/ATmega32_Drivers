/**
 * @file EEPROM_Program.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./EEPROM_Interface.h"
#include "./EEPROM_Private.h"

void EEPROM_voidWriteByte(u16 address, u8 data)
{
    // wait unitl this bit become zero
    while (GET_BIT(EECR, EEWE_BIT))
        ;

    // masking with 0x03 to make sure the other bits are equal zero
    EEARH = (u8)((address >> 8) & 0x03);

    EEARL = (u8)address;

    SET_BIT(EECR, EEMWE_BIT);
    SET_BIT(EECR, EEWE_BIT);
}

u8 EEPROM_voidWriteByte(u16 address)
{
    // wait unitl this bit become zero
    while (GET_BIT(EECR, EEWE_BIT))
        ;

    // masking with 0x03 to make sure the other bits are equal zero
    EEARH = (u8)((address >> 8) & 0x03);

    EEARL = (u8)address;

    SET_BIT(EECR, EERE_BIT);

    return EEDR;
}

void EEPROM_voidSetCallBackEEPROMReady(void (*pf)(void))
{
    EEPROM_READY = pf;
}

ISR(EE_RDY_VECT)
{
    if (NULLPTR != EEPROM_READY)
    {
        EEPROM_READY();
    }
}