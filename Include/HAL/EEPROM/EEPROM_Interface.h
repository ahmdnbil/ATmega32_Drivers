/*
 * EEPROM_Interface.h
 *
 *  Created on: Jul 11, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_
#define INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_

#include "../../MCAL/TWI/TWI_Interface.h"

TWI_STATUS EEPROM_voidWriteInit(u8 A_u8MemoryNumber, u16 A_u8MemoryAdress);
TWI_STATUS EEPROM_voidSendData(u8 A_u8Data);
TWI_STATUS EEPROM_voidReadInit(u8 A_u8MemoryNumber, u16 A_u8MemoryAdress);
void EEPROM_u8ReadData(u8 *A_u8Data, u8 ack);
void EEPROM_voidSendStop();

#endif /* INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_ */
