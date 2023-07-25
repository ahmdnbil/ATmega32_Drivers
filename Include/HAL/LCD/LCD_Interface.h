/*
 * LCD_Interface.h
 *
 *  Created on: Oct 13, 2022
 *      Author: User
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

void LCD_voidSendData(u8 A_u8Data);
void LCD_voidSendCommand(u8 A_u8Command);
void LCD_voidInit(void);
void LCD_voidClearDisplay(void);
void LCD_voidSendString(u8 *A_Pu8String);
void LCD_voidGoToPos(u8 A_u8RowNum, u8 A_u8ColNum);
void LCD_voidDisplayNumber(u32 A_u32Number);
void LCD_voidStoreCustomChar(u8 *A_u8Pattern, u8 A_u8CGRAMIndex);
void LCD_voidDisplayCustomChar(u8 A_u8CGRAMIndex, u8 A_u8Row, u8 A_u8Col);

#endif /* INCLUDE_HAL_LCD8_LCD8_INTERFACE_H_ */
