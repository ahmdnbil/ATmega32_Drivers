/*
 * LCD4_Interface.h
 *
 *  Created on: Oct 14, 2022
 *      Author: User
 */

#ifndef INCLUDE_HAL_LCD4_LCD4_INTERFACE_H_
#define INCLUDE_HAL_LCD4_LCD4_INTERFACE_H_

void HLCD4_voidSendData(u8 A_u8Data);
void HLCD4_voidSendCommand(u8 A_u8Command);
void HLCD4_voidInit();
void HLCD4_voidClearDisplay(void);
void HLCD4_voidSendString(u8 * A_Pu8String);
void HLCD4_voidGoToPos(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD4_voidDisplayNumber(u32 A_u32Number);
void HLCD4_voidStoreCustomChar(u8 * A_u8Pattern,u8 A_u8CGRAMIndex);
void HLCD4_voidDisplayCustomChar(u8 A_u8CGRAMIndex,u8 A_u8Row,u8 A_u8Col);



#endif /* INCLUDE_HAL_LCD4_LCD4_INTERFACE_H_ */
