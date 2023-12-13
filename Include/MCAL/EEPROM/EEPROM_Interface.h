/**
 * @file EEPROM_Interface.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "./../../LIB/STD_TYPES.h"
#include "./../../LIB/BIT_MATH.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/

/*---------------------------------------function declarations--------------------------------*/
void EEPROM_voidWriteByte(u16 address, u8 data);
u8 EEPROM_voidWriteByte(u16 address);
void EEPROM_voidSetCallBackEEPROMReady(void (*pf)(void));

#endif