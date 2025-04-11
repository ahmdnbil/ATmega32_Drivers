/**
 * @file KEYPAD.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#define F_CPU 8000000UL
#include "./KEYPAD.h"

uint8_t KeypadArr[COLS_NUMBER][ROWS_NUMBER] = KEYPAD_SYMBOLS;
uint8_t keypadRow[ROWS_NUMBER] = ROW_PINS;
uint8_t keypadCol[COLS_NUMBER] = COL_PINS;

void KEYPAD_voidInit()
{
    //Set Row PINs as output and high
    DIO_InitPin(KEYPAD_PORT,keypadRow[PIN0],PIN_OUTPUT,PIN_HIGH);
    DIO_InitPin(KEYPAD_PORT,keypadRow[PIN1],PIN_OUTPUT,PIN_HIGH);
    DIO_InitPin(KEYPAD_PORT,keypadRow[PIN2],PIN_OUTPUT,PIN_HIGH);
    DIO_InitPin(KEYPAD_PORT,keypadRow[PIN3],PIN_OUTPUT,PIN_HIGH);
    //Set Column PINs as output and high
    DIO_InitPin(KEYPAD_PORT, keypadCol[PIN0], PIN_INPUT, PIN_PULL_UP);
    DIO_InitPin(KEYPAD_PORT, keypadCol[PIN1], PIN_INPUT, PIN_PULL_UP);
    DIO_InitPin(KEYPAD_PORT, keypadCol[PIN2], PIN_INPUT, PIN_PULL_UP);
    DIO_InitPin(KEYPAD_PORT, keypadCol[PIN3], PIN_INPUT, PIN_PULL_UP);
}
uint8_t KEYPAD_u8GetPressedKey()
{
    uint8_t local_u8RowCounter, local_u8ColCounter, local_u8Flag = FLAG_DOWN, local_u8PressedKey = KEY_NOT_PRESSED;

    for (local_u8RowCounter = 0; local_u8RowCounter < ROWS_NUMBER; local_u8RowCounter++)
    {
        DIO_WritePin(KEYPAD_PORT, keypadRow[local_u8RowCounter], PIN_LOW);
        for (local_u8ColCounter = 0; local_u8ColCounter < COLS_NUMBER; local_u8ColCounter++)
        {
            if (DIO_ReadPin(KEYPAD_PORT, keypadCol[local_u8ColCounter]) == PIN_LOW)
            {
                // to avoid "debounce effect"
                _delay_ms(DEBOUNCING_DELAY);
                local_u8Flag = FLAG_UP;
                // to make sure it will not print the character more than once if the user still press the button
                while (DIO_ReadPin(KEYPAD_PORT, keypadCol[local_u8ColCounter]) == PIN_LOW)
                    ;
                local_u8PressedKey = KeypadArr[local_u8RowCounter][local_u8ColCounter];
                break;
            }
        }
        DIO_WritePin(KEYPAD_PORT, keypadRow[local_u8RowCounter], PIN_HIGH);
        if (local_u8Flag)
        {
            break;
        }
    }
    return local_u8PressedKey;
}
