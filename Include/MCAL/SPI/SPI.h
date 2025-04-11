/**
 * @file SPI.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_SPI_SPI_INTERFACE_H_
#define INCLUDE_MCAL_SPI_SPI_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "./../../LIB/mem_map.h"

#include "./SPI_Cfg.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define SPI_MOSI_PIN 5
#define SPI_MISO_PIN 6
#define SPI_SCK_PIN 7
#define SPI_SS_PIN 4
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
void SPI_voidInit();
uint8_t SPI_u8SendRecieveData(uint8_t A_u8Send);
void SPI_voidInterruptEnable();
void SPI_voidInterruptDisable();
void SPI_voidSetCallBack(void (*pf)(void));

#endif /* INCLUDE_MCAL_SPI_SPI_INTERFACE_H_ */
