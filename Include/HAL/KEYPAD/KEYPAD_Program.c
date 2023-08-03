/*
 * KEYPAD_Program.c
 *
 *  Created on: Oct 22, 2022
 *      Author: User
 */

// Libraries
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
// MCAL layer
#include "../../MCAL/DIO/DIO_Configuration.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
// Keypad
#include "./KEYPAD_Interface.h"
#include "./KEYPAD_Configuration.h"

#define F_CPU 8000000UL
#include <util/delay.h>

u8 KeypadArr[COLS_NUMBER][ROWS_NUMBER] = KEYPAD_SYMBOLS;
u8 keypadRow[ROWS_NUMBER] = ROW_PINS;
u8 keypadCol[COLS_NUMBER] = COL_PINS;

u8 KEYPAD_u8GetPressedKey()
{
    u8 local_u8RowCounter, local_u8ColCounter, local_u8Flag = FLAG_DOWN, local_u8PressedKey = KEY_NOT_PRESSED;

    for (local_u8RowCounter = 0; local_u8RowCounter < ROWS_NUMBER; local_u8RowCounter++)
    {
        DIO_voidSetPinValue(KEYPAD_PORT, keypadRow[local_u8RowCounter], PIN_LOW);
        for (local_u8ColCounter = 0; local_u8ColCounter < COLS_NUMBER; local_u8ColCounter++)
        {
            if (DIO_u8GetPinValue(KEYPAD_PORT, keypadCol[local_u8ColCounter]) == PIN_LOW)
            {
                // to avoid "debounce effect"
                _delay_ms(DEBOUNCING_DELAY);
                local_u8Flag = FLAG_UP;
                // to make sure it will not print the character more than once if the user still press the button
                while (DIO_u8GetPinValue(KEYPAD_PORT, keypadCol[local_u8ColCounter]) == PIN_LOW)
                    ;
                local_u8PressedKey = KeypadArr[local_u8RowCounter][local_u8ColCounter];
                break;
            }
        }
        DIO_voidSetPinValue(KEYPAD_PORT, keypadRow[local_u8RowCounter], PIN_HIGH);
        if (local_u8Flag)
        {
            break;
        }
    }
    return local_u8PressedKey;
}
