/**
 * @file KEYPAD_Cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

#define KEYPAD_PORT PORTC
#define KEYPAD_SYMBOLS {{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'C','0','=','+'}};
#define ROW_PINS {PIN0,PIN1,PIN2,PIN3}
#define COL_PINS {PIN4,PIN5,PIN6,PIN7}

#define COLS_NUMBER 4
#define ROWS_NUMBER 4

#define DEBOUNCING_DELAY 150
#define KEY_NOT_PRESSED 255

#define FLAG_UP 1
#define FLAG_DOWN 0


#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */
