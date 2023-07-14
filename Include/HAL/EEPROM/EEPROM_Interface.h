/*
 * EEPROM_Interface.h
 *
 *  Created on: Jul 11, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_
#define INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_

#include "../../MCAL/TWI/TWI_Interface.h"

TWI_STATUS HEEPROM_voidWriteInit(u8 A_u8MemoryNumber, u16 A_u8MemoryAdress);
TWI_STATUS HEEPROM_voidSendData(u8 A_u8Data);
TWI_STATUS HEEPROM_voidReadInit(u8 A_u8MemoryNumber, u16 A_u8MemoryAdress);
TWI_STATUS HEEPROM_u8ReadData(u8 *A_u8Data, u8 ack);
void HEEPROM_voidSendStop();

#endif /* INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_ */
