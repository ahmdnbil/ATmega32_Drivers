/**
 * @file DIO.c
 * @author AhmedNabil (AhmedNabil@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "DIO.h"

void DIO_InitPin(uint8_t port, uint8_t pin, uint8_t direction, uint8_t pin_status)
{
    switch(port)
    {
        case PORTA:
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(DDRA_REG, pin);
                if(pin_status == PIN_HIGH)
                {
                    SET_BIT(PORTA_REG, pin);
                }
                else
                {
                    CLR_BIT(PORTA_REG, pin);
                }
            }
            else
            {
                CLR_BIT(DDRA_REG, pin);
                if (pin_status == PIN_PULL_UP)
                {
                    SET_BIT(PORTA_REG, pin);
                }
                else if(pin_status == PIN_FLOATING)
                {
                    CLR_BIT(PORTA_REG, pin);
                }
            }
            break;
        case PORTB:
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(DDRB_REG, pin);
                if(pin_status == PIN_HIGH)
                {
                    SET_BIT(PORTB_REG, pin);
                }
                else
                {
                    CLR_BIT(PORTB_REG, pin);
                }
            }
            else
            {
                CLR_BIT(DDRB_REG, pin);
                if (pin_status == PIN_PULL_UP)
                {
                    SET_BIT(PORTB_REG, pin);
                }
                else if (pin_status == PIN_FLOATING)
                {
                    CLR_BIT(PORTB_REG, pin);
                }
            }
            break;
        case PORTC:
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(DDRC_REG, pin);
                if(pin_status == PIN_HIGH)
                {
                    SET_BIT(PORTC_REG, pin);
                }
                else
                {
                    CLR_BIT(PORTC_REG, pin);
                }
            }
            else
            {
                CLR_BIT(DDRC_REG, pin);
                if (pin_status == PIN_PULL_UP)
                {
                    SET_BIT(PORTC_REG, pin);
                }
                else if (pin_status == PIN_FLOATING)
                {
                    CLR_BIT(PORTC_REG, pin);
                }
            }
            break;
        case PORTD:
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(DDRD_REG, pin);
                if(pin_status == PIN_HIGH)
                {
                    SET_BIT(PORTD_REG, pin);
                }
                else
                {
                    CLR_BIT(PORTD_REG, pin);
                }
            }
            else
            {
                CLR_BIT(DDRD_REG, pin);
                if (pin_status == PIN_PULL_UP)
                {
                    SET_BIT(PORTD_REG, pin);
                }
                else if (pin_status == PIN_FLOATING)
                {
                    CLR_BIT(PORTD_REG, pin);
                }
            }
            break;
    }
}
void DIO_WritePin(uint8_t port, uint8_t pin, uint8_t value)
{
    switch(port)
    {
        case PORTA:
            if(value == PIN_HIGH)
            {
                SET_BIT(PORTA_REG, pin);
            }
            else
            {
                CLR_BIT(PORTA_REG, pin);
            }
            break;
            case PORTB:
            if(value == PIN_HIGH)
            {
                SET_BIT(PORTB_REG, pin);
            }
            else
            {
                CLR_BIT(PORTB_REG, pin);
            }
            break;
            case PORTC:
            if(value == PIN_HIGH)
            {
                SET_BIT(PORTC_REG, pin);
            }
            else
            {
                CLR_BIT(PORTC_REG, pin);
            }
            break;
            case PORTD:
            if(value == PIN_HIGH)
            {
                SET_BIT(PORTD_REG, pin);
            }
            else
            {
                CLR_BIT(PORTD_REG, pin);
            }
            break;
    }
}
uint8_t DIO_ReadPin(uint8_t port, uint8_t pin)
{
    uint8_t value = 0;
    switch(port)
    {
        case PORTA:
            value = GET_BIT(PINA_REG, pin);
            break;
        case PORTB:
            value = GET_BIT(PINB_REG, pin);
            break;
        case PORTC:
            value = GET_BIT(PINC_REG, pin);
            break;
        case PORTD:
            value = GET_BIT(PIND_REG, pin);
            break;
    }

    return value;
}
void DIO_TogglePin(uint8_t port, uint8_t pin)
{
    switch(port)
    {
        case PORTA:
            TOG_BIT(PORTA_REG, pin);
            break;
        case PORTB:
            TOG_BIT(PORTB_REG, pin);
            break;
        case PORTC:
            TOG_BIT(PORTC_REG, pin);
            break;
        case PORTD:
            TOG_BIT(PORTD_REG, pin);
            break;
    }
}
void DIO_InitPort(uint8_t port, uint8_t direction,uint8_t value)
{
    switch(port)
    {
        case PORTA:
            DDRA_REG = direction;
            PORTA_REG=value;
            break;
            case PORTB:
            DDRB_REG = direction;
            PORTB_REG=value;
            break;
            case PORTC:
            DDRC_REG = direction;
            PORTC_REG=value;
            break;
            case PORTD:
            DDRD_REG = direction;
            PORTD_REG=value;
            break;
    }
}
void DIO_WritePort(uint8_t port, uint8_t value)
{
    switch(port)
    {
        case PORTA:
            PORTA_REG = value;
            break;
        case PORTB:
            PORTB_REG = value;
            break;
        case PORTC:
            PORTC_REG = value;
            break;
        case PORTD:
            PORTD_REG = value;
            break;
    }
}

uint8_t DIO_ReadPort(uint8_t port)
{
    uint8_t value = 0;
    switch(port)
    {
        case PORTA:
            value = PINA_REG;
            break;
        case PORTB:
            value = PINB_REG;
            break;
        case PORTC:
            value = PINC_REG;
            break;
        case PORTD:
            value = PIND_REG;
            break;
    }

    return value;
}
