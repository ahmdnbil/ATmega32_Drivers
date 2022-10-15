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
void HLCD8_voidClearDisplay(void);
void HLCD4_voidSendString(u8 * A_Pu8String);


#endif /* INCLUDE_HAL_LCD4_LCD4_INTERFACE_H_ */
