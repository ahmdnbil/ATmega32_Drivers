/**
 * @file InEEPROM.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "./../../LIB/STD_TYPES.h"
#include "./../../LIB/BIT_MATH.h"
#include "./../../LIB/mem_map.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/

/*---------------------------------------function declarations--------------------------------*/
void InEEPROM_voidWriteByte(uint16_t address, uint8_t data);
uint8_t InEEPROM_voidReadByte(uint16_t address);
void InEEPROM_voidSetCallBackEEPROMReady(void (*pf)(void));

#endif