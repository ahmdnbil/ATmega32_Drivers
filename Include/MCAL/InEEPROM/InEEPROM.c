/**
 * @file InEEPROM.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "./InEEPROM.h"

static void (*EEPROM_READY)(void) = NULLPTR;

void InEEPROM_voidWriteByte(uint16_t address, uint8_t data)
{
    // wait unitl this bit become zero
    while (GET_BIT(EECR, EEWE))
        ;

    // masking with 0x03 to make sure the other bits are equal zero
    EEARH = (uint8_t)((address >> 8) & 0x03);

    EEARL = (uint8_t)address;

    SET_BIT(EECR, EEMWE);
    SET_BIT(EECR, EEWE);
}

uint8_t InEEPROM_voidReadByte(uint16_t address)
{
    // wait unitl this bit become zero
    while (GET_BIT(EECR, EEWE))
        ;

    // masking with 0x03 to make sure the other bits are equal zero
    EEARH = (uint8_t)((address >> 8) & 0x03);

    EEARL = (uint8_t)address;

    SET_BIT(EECR, EERE);

    return EEDR;
}

void InEEPROM_voidSetCallBackEEPROMReady(void (*pf)(void))
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