/**
 * @file LCD.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#define F_CPU 8000000UL
#include "./LCD.h"


#if LCD_MODE == _8_BIT_MODE
void LCD_voidSendCommand(uint8_t A_u8Command)
{
    // RS=0 RW=0
    DIO_WritePin(LCD_CONTROL_PORT, RS_PIN, PIN_LOW);
    DIO_WritePin(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    DIO_WritePort(LCD_DATA_PORT, A_u8Command);
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(2);
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
}

void LCD_voidSendData(uint8_t A_u8Data)
{
    // RS=1 RW=0
    DIO_WritePin(LCD_CONTROL_PORT, RS_PIN, PIN_HIGH);
    DIO_WritePin(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    DIO_WritePort(LCD_DATA_PORT, A_u8Data);

    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(2);
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
}

void LCD_voidInit()
{
    
    // iniate the LCD_DATA_PORT as output
    DIO_InitPort(LCD_DATA_PORT, PIN_OUTPUT, DIO_PORT_OUTPUT, DIO_PORT_LOW);
    
    // iniate the LCD_CTRL_PORT as output
    DIO_InitPin(LCD_CONTROL_PORT, RS_PIN, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(LCD_CONTROL_PORT, RW_PIN, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(LCD_CONTROL_PORT, E_PIN, PIN_OUTPUT, PIN_LOW);

    _delay_ms(30);
    LCD_voidSendCommand(FUNCTION_SET);
    _delay_ms(1);
    LCD_voidSendCommand(ON_OFF_CONTROL);
    _delay_ms(1);
    LCD_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
    LCD_voidSendCommand(ENTRY_MODE_SET);
}
#else
static uint8_t global_u8Init = 0;
void LCD_voidSendCommand(uint8_t A_u8Command)
{
    // RS=0 RW=0
    DIO_WritePin(LCD_CONTROL_PORT, RS_PIN, PIN_LOW);
    DIO_WritePin(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    // send UPPER Bits (B7 to B4)
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN0, GET_BIT(A_u8Command, PIN4));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN1, GET_BIT(A_u8Command, PIN5));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN2, GET_BIT(A_u8Command, PIN6));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN3, GET_BIT(A_u8Command, PIN7));

    // pulse HIGH to LOW to ENABLE PIN
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(1);
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_LOW);

    if (global_u8Init)
    {

        // send LOWR Bits (B3 to B0)
        A_u8Command = A_u8Command << 4;
        DIO_WritePin(LCD_DATA_PORT, LCD_PIN0, GET_BIT(A_u8Command, PIN4));
        DIO_WritePin(LCD_DATA_PORT, LCD_PIN1, GET_BIT(A_u8Command, PIN5));
        DIO_WritePin(LCD_DATA_PORT, LCD_PIN2, GET_BIT(A_u8Command, PIN6));
        DIO_WritePin(LCD_DATA_PORT, LCD_PIN3, GET_BIT(A_u8Command, PIN7));

        // pulse HIGH to LOW to ENABLE PIN
        DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
        _delay_ms(1);
        DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
    }
    _delay_ms(2);
}

void LCD_voidSendData(uint8_t A_u8Data)
{
    // RS=1 RW=0
    DIO_WritePin(LCD_CONTROL_PORT, RS_PIN, PIN_HIGH);
    DIO_WritePin(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    DIO_WritePin(LCD_DATA_PORT, LCD_PIN0, GET_BIT(A_u8Data, PIN4));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN1, GET_BIT(A_u8Data, PIN5));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN2, GET_BIT(A_u8Data, PIN6));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN3, GET_BIT(A_u8Data, PIN7));
    
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(1);
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
    A_u8Data = A_u8Data << 4;
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN0, GET_BIT(A_u8Data, PIN4));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN1, GET_BIT(A_u8Data, PIN5));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN2, GET_BIT(A_u8Data, PIN6));
    DIO_WritePin(LCD_DATA_PORT, LCD_PIN3, GET_BIT(A_u8Data, PIN7));

    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_HIGH);
    _delay_ms(1);
    DIO_WritePin(LCD_CONTROL_PORT, E_PIN, PIN_LOW);
    _delay_ms(2);
}
void LCD_voidInit()
{
    //iniate the LCD_DATA_PORT as output
    DIO_InitPin(LCD_DATA_PORT, LCD_PIN0, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(LCD_DATA_PORT, LCD_PIN1, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(LCD_DATA_PORT, LCD_PIN2, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(LCD_DATA_PORT, LCD_PIN3, PIN_OUTPUT, PIN_LOW);
    //iniate the LCD_CTRL_PORT as output
    DIO_InitPin(LCD_CONTROL_PORT, RS_PIN, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(LCD_CONTROL_PORT, RW_PIN, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(LCD_CONTROL_PORT, E_PIN, PIN_OUTPUT, PIN_LOW);

    _delay_ms(30);
    LCD_voidSendCommand(FUNCTION_SET1);
    LCD_voidSendCommand(FUNCTION_SET2);
    LCD_voidSendCommand(FUNCTION_SET3);
    _delay_us(40);
    LCD_voidSendCommand(ON_OFF_CONTROL1);
    LCD_voidSendCommand(ON_OFF_CONTROL2);
    _delay_us(40);
    LCD_voidSendCommand(DISPLAY_CLEAR1);
    LCD_voidSendCommand(DISPLAY_CLEAR2);
    _delay_ms(2);
    LCD_voidSendCommand(ENTRY_MODE_SET1);
    LCD_voidSendCommand(ENTRY_MODE_SET2);
    global_u8Init = 1;
}
#endif

/******************the following functinos is valid for both 8bit & 4bit mode******************/
void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
}

void LCD_voidSendString(uint8_t *A_Pu8String)
{
    uint8_t local_u8Couter = 0;
    while (A_Pu8String[local_u8Couter] != '\0')
    {
        LCD_voidSendData(A_Pu8String[local_u8Couter]);
        local_u8Couter++;
    }
}

void LCD_voidGoToPos(uint8_t A_u8RowNum, uint8_t A_u8ColNum)
{
    // switch (A_u8RowNum)
    // {
    // case LCD_ROW_ONE:
    // LCD_voidSendCommand(LCD_ROW1_ADDRESS+A_u8ColNum);
    //     break;

    // case LCD_ROW_TWO:
    // LCD_voidSendCommand(LCD_ROW2_ADDRESS+A_u8ColNum);
    //     break;
    // }
    // _delay_ms(1);
    /************************************************************/
    // Second method
    uint8_t local_u8Address;
    switch (A_u8RowNum)
    {
    case LCD_ROW_ONE:
        local_u8Address = FIRST_ROW_ADDRESS + A_u8ColNum - 1;
        SET_BIT(local_u8Address, PIN7);
        LCD_voidSendCommand(local_u8Address);
        break;

    case LCD_ROW_TWO:
        local_u8Address = SECOND_ROW_ADDRESS + A_u8ColNum;
        SET_BIT(local_u8Address, PIN7);
        LCD_voidSendCommand(local_u8Address);
        break;
    }
    _delay_ms(1);
}

void LCD_voidDisplayNumber(uint32_t A_u32Number)
{
    // first method: the shortage of this function, it will not take zeros in account
    // if number is 12309 it will print 123

    // uint32_t local_u32Rev=0;
    // uint8_t local_u8Rem;
    // while(A_u32Number!=0)
    // {
    //     local_u8Rem=A_u32Number%10;
    //     local_u32Rev=local_u32Rev*10+local_u8Rem;
    //     A_u32Number/=10;
    // }
    // while(local_u32Rev!=0)
    // {
    //     local_u8Rem=local_u32Rev%10;
    //     local_u8Rem+=48;
    //     LCD_voidSendData(local_u8Rem);
    //     local_u32Rev/=10;
    // }

    //****************************************************//
    // second method: using built in library itoa(number,string,base)
    // uint8_t local_u8NumToStr[100];
    // itoa(A_u32Number,local_u8NumToStr,10);
    // LCD_voidSendString(local_u8NumToStr);
    //****************************************************//
    // third method: it will deal with zero unlike the first method so it's not problem here
    uint32_t local_u32Number = 1;
    if (A_u32Number == 0)
    {
        LCD_voidSendData('0');
    }
    while (A_u32Number != 0)
    {
        local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
        A_u32Number = A_u32Number / 10;
    }
    while (local_u32Number != 1)
    {
        LCD_voidSendData((local_u32Number % 10) + 48);
        local_u32Number = local_u32Number / 10;
    }
}

void LCD_voidStoreCustomChar(uint8_t *A_u8Pattern, uint8_t A_u8CGRAMIndex)
{
    if (A_u8CGRAMIndex < 8)
    {
        A_u8CGRAMIndex = A_u8CGRAMIndex * 8;
        SET_BIT(A_u8CGRAMIndex, PIN6);
        CLR_BIT(A_u8CGRAMIndex, PIN7);
        LCD_voidSendCommand(A_u8CGRAMIndex);
        for (uint8_t i = 0; i < 8; i++)
        {
            LCD_voidSendData(A_u8Pattern[i]);
            _delay_us(60);
        }
    }
    LCD_voidSendCommand(RETURN_HOME);
    _delay_ms(2);
}

void LCD_voidDisplayCustomChar(uint8_t A_u8CGRAMIndex, uint8_t A_u8Row, uint8_t A_u8Col)
{
    LCD_voidGoToPos(A_u8Row, A_u8Col);
    LCD_voidSendData(A_u8CGRAMIndex);
}
/*****************************************************************************/
