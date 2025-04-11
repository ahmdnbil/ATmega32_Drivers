/**
 * @file LCD.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

//Libraries
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//MCAL Libraries
#include "../../MCAL/DIO/DIO.h"

//HAL libraries
#include "./LCD_Private.h"
#include "./LCD_Cfg.h"

//Built in libraries
#include <math.h>
#include <stdlib.h>
#include <util/delay.h>


void LCD_voidSendData(uint8_t A_u8Data);
void LCD_voidSendCommand(uint8_t A_u8Command);
void LCD_voidInit(void);
void LCD_voidClearDisplay(void);
void LCD_voidSendString(uint8_t *A_Pu8String);
void LCD_voidGoToPos(uint8_t A_u8RowNum, uint8_t A_u8ColNum);
void LCD_voidDisplayNumber(uint32_t A_u32Number);
void LCD_voidStoreCustomChar(uint8_t *A_u8Pattern, uint8_t A_u8CGRAMIndex);
void LCD_voidDisplayCustomChar(uint8_t A_u8CGRAMIndex, uint8_t A_u8Row, uint8_t A_u8Col);

#endif /* INCLUDE_HAL_LCD8_LCD8_INTERFACE_H_ */
