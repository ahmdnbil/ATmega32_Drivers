/*
 * LCD4_Private.h
 *
 *  Created on: Oct 14, 2022
 *      Author: User
 */

#ifndef INCLUDE_HAL_LCD4_LCD4_PRIVATE_H_
#define INCLUDE_HAL_LCD4_LCD4_PRIVATE_H_

#define LCD_ROW1_ADDRESS 127
#define LCD_ROW2_ADDRESS 191

#define FIRST_ROW_ADDRESS  0x00
#define SECOND_ROW_ADDRESS 0x3F

#define RETURN_HOME 0b00000010



#define DOTS_5_7_  0
#define DOTS_5_10_ 1

#define ONE_LINE 0
#define TWO_LINE 1

#define DISPLAY_OFF 0
#define DISPLAY_ON  1

#define CURSOR_OFF 0
#define CURSOR_ON  1

#define CURSOR_BLANK_OFF 0
#define CURSOR_BLANK_ON  1

#define ID_DECREASE 0
#define ID_INCREASE 1

#define SHIFT_DISPLAY_OFF 0
#define SHIFT_DISPLAY_ON  1

#endif /* INCLUDE_HAL_LCD4_LCD4_PRIVATE_H_ */
