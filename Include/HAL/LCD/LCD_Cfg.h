/**
 * @file LCD_Configuration.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_

#include "./../../MCAL/DIO/DIO.h"
#include "./../../LIB/STD_TYPES.h"
#include "./../../LIB/BIT_MATH.h"


#define LCD_CONTROL_PORT PORTA
#define LCD_DATA_PORT PORTA

#define RS_PIN PIN0
#define RW_PIN PIN1
#define E_PIN PIN2

//for 4-bit mode choose the data pins
#define LCD_PIN0 PIN3
#define LCD_PIN1 PIN4
#define LCD_PIN2 PIN5
#define LCD_PIN3 PIN6

#define LCD_ROW_ONE 1
#define LCD_ROW_TWO 2

/*
Options:-
    _4_BIT_MODE
    _8_BIT_MODE
*/
#define LCD_MODE _4_BIT_MODE

/*
Options:-
    ONE_LINE
    TWO_LINE
*/
#define LCD_LINE_NO TWO_LINE

/*
Options:-
    DOTS_5_7
    DOTS_5_10
*/
#define LCD_FONT DOTS_5_7

/*
Options:-           (FOR DD RAM)
    DISPLAY_OFF
    DISPLAY_ON
*/
#define DISPLAY_STATUS DISPLAY_ON

/*
Options:-
    CURSOR_OFF
    CURSOR_ON
*/
#define CURSOR_STATUS CURSOR_OFF

/*
Options:-
    CURSOR_BLANK_OFF
    CURSOR_BLANK_ON
*/
#define CURSOR_BLANK_STATUS CURSOR_BLANK_OFF

/*
Options:-
    ID_DECREASE
    ID_INCREASE
*/
#define ID_STATUS ID_INCREASE

/*
Options:-
    SHIFT_DISPLAY_OFF
    SHIFT_DISPLAY_ON
*/
#define SHIFT_DISPLAY SHIFT_DISPLAY_OFF


// intiaion
#define FUNCTION_SET CONC_BIT(0, 0, 1, 1, LCD_LINE_NO, LCD_FONT, 0, 0)
#define ON_OFF_CONTROL CONC_BIT(0, 0, 0, 0, 1, DISPLAY_STATUS, CURSOR_STATUS, CURSOR_BLANK_STATUS)
#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET CONC_BIT(0, 0, 0, 0, 0, 1, ID_STATUS, SHIFT_DISPLAY)

//for 4-bit mode

#define FUNCTION_SET1 0b00100000
#define FUNCTION_SET2 0b00100000
#define FUNCTION_SET3 CONC_BIT(LCD_LINE_NO, LCD_FONT, 0, 0, 0, 0, 0, 0)
#define ON_OFF_CONTROL1 0b00000000
#define ON_OFF_CONTROL2 CONC_BIT(1, DISPLAY_STATUS, CURSOR_STATUS, CURSOR_BLANK_STATUS, 0, 0, 0, 0)
#define DISPLAY_CLEAR1 0b00000000
#define DISPLAY_CLEAR2 0b00010000
#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET1 0b00000000
#define ENTRY_MODE_SET2 CONC_BIT(0, 1, ID_STATUS, SHIFT_DISPLAY, 0, 0, 0, 0)


#endif /* INCLUDE_HAL_LCD8_LCD8_CONFIGURATION_H_ */
