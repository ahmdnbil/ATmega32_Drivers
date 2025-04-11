/**
 * @file ExEEPROM.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_
#define INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_

#include "../../MCAL/TWI/TWI.h"

// MACRO DEFINITION
#define ExEEPROM_ADD_MASK 0b1010000

TWI_STATUS ExEEPROM_voidWriteInit(uint8_t A_u8MemoryNumber, uint16_t A_u8MemoryAdress);
TWI_STATUS ExEEPROM_voidSendData(uint8_t A_u8Data);
TWI_STATUS ExEEPROM_voidReadInit(uint8_t A_u8MemoryNumber, uint16_t A_u8MemoryAdress);
void ExEEPROM_u8ReadData(uint8_t *A_u8Data, uint8_t ack);
void ExEEPROM_voidSendStop();

#endif /* INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_ */
