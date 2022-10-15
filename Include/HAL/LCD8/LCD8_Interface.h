/*
 * LCD_Interface.h
 *
 *  Created on: Oct 13, 2022
 *      Author: User
 */

#ifndef INCLUDE_HAL_LCD8_LCD8_INTERFACE_H_
#define INCLUDE_HAL_LCD8_LCD8_INTERFACE_H_

void HLCD8_voidSendCommand(u8 A_u8Command);
void HLCD8_voidInit(void);
void HLCD8_voidSendData(u8 A_u8Data);
void HLCD8_voidClearDisplay(void);
void HLCD8_voidSendString(u8 *A_Pu8String);
void HLCD8_voidGoToPos(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD8_voidDisplayNumber(u32 A_u32Number);
//void HLCD8_voidSendSpecialCharacter(u8 *copy_pu8CharArr, u8 copy_u8PatternNum,u8 copy_u8LineNum, u8 copy_ColNum);

#endif /* INCLUDE_HAL_LCD8_LCD8_INTERFACE_H_ */
