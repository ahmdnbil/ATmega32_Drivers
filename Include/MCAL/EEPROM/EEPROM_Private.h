/**
 * @file EEPROM_Private.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _EEPROM_PRIVATE_H_
#define _EEPROM_PRIVATE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "./../../LIB/mem_map.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
// EEPROM Ready Interrupt Enable
#define EERIE_BIT 3
// EEPROM Master Write Enable
#define EEMWE_BIT 2
// EEPROM Write Enable
#define EEWE_BIT 1
// EEPROM Read Enable
#define EERE_BIT 0
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
static void (*EEPROM_READY)(void) = NULLPTR;

#endif /* _EEPROM_PRIVATE_H_ */
