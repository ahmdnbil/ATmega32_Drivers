/*
 * UART_Program.c
 *
 *  Created on: Jun 28, 2023
 *      Author: User
 */

#include "./UART_Private.h"
#include "./UART_Configurations.h"
#include "./UART_Interface.h"

static void (*USART_RXC_CALL)(void) = NULLPTR;
static void (*USART_UDRE_CALL)(void) = NULLPTR;
static void (*USART_TXC_CALL)(void) = NULLPTR;

void UART_voidInit(void)
{
    u8 UCSRC_var = 0;
    u16 local_u16BaudRateValue = BAUD_RATE_EQN;
    UBRRL = (u8)local_u16BaudRateValue;

    /*
        note: shifting bits firstly then casting
        if you cast firt, the bits from 8 will be zeros
    */
    UBRRH = (u8)((local_u16BaudRateValue) >> 8);

#if USART_SPPED == DOUBLE_SPEED
    SET_BIT(UCSRA, U2X);
#else
    CLR_BIT(UCSRA, U2X);
#endif

    //    UCSRC_var=0b10000110;
    /*
        Register Select
        this first bit must be configured, if you configure any bits before it
        it will not work correctly
    */
    SET_BIT(UCSRC_var, URSEL);

#if CHARACTER_SIZE == CHARACTER_SIZE_5BIT
    CLR_BIT(UCSRB, UCSZ2);
    CLR_BIT(UCSRC_var, UCSZ1);
    CLR_BIT(UCSRC_var, UCSZ0);
#elif CHARACTER_SIZE == CHARACTER_SIZE_6BIT
    CLR_BIT(UCSRB, UCSZ2);
    CLR_BIT(UCSRC_var, UCSZ1);
    SET_BIT(UCSRC_var, UCSZ0);
#elif CHARACTER_SIZE == CHARACTER_SIZE_7BIT
    CLR_BIT(UCSRB, UCSZ2);
    SET_BIT(UCSRC_var, UCSZ1);
    CLR_BIT(UCSRC_var, UCSZ0);
#elif CHARACTER_SIZE == CHARACTER_SIZE_8BIT
    CLR_BIT(UCSRB, UCSZ2);
    SET_BIT(UCSRC_var, UCSZ1);
    SET_BIT(UCSRC_var, UCSZ0);
#elif CHARACTER_SIZE == CHARACTER_SIZE_9BIT
    SET_BIT(UCSRB, UCSZ2);
    SET_BIT(UCSRC_var, UCSZ1);
    SET_BIT(UCSRC_var, UCSZ0);
#endif
    // Enabling Receiver
    SET_BIT(UCSRB, RXEN);
    // Enabling Transmitter
    SET_BIT(UCSRB, TXEN);

#if USART_MODE == SYNCH_OPERATION
    SET_BIT(UCSRC_var, UMSEL);
#else
    CLR_BIT(UCSRC_var, UMSEL);
#endif

#if PARITY_MODE == PARITY_DISABLED
    UCSRC_var &= ~(0b11 << UPM0);
    UCSRC_var |= (PARITY_DISABLED << UPM0);
#elif PARITY_MODE == PARITY_EN_EVEN
    UCSRC_var &= ~(0b11 << UPM0);
    UCSRC_var |= (PARITY_EN_EVEN << UPM0);
#elif PARITY_MODE == PARITY_EN_ODD
    UCSRC_var &= ~(0b11 << UPM0);
    UCSRC_var |= (PARITY_EN_ODD << UPM0);
#endif

#if STOP_BIT_SLECT == ONE_STOP_BIT
    CLR_BIT(UCSRC_var, USBS);
#else
    SET(UCSRC_var, USBS);
#endif

#if CLK_POLARITY == RISING_THEN_FALLING_UART
    CLR_BIT(UCSRC_var, UCPOL);
#else
    SET_BIT(UCSRC_var, UCPOL);
#endif

    /*
        to set all bits once
    */
    UCSRC = UCSRC_var;
}

void UART_voidSendByteSynchNonBlocking(u8 A_u8Byte)
{
    u32 local_u32TimeOut = 0;
    while (GET_BIT(UCSRA, UDRE) == 0)
    {
        local_u32TimeOut++;
        if (local_u32TimeOut == TIME_OUT)
            break;
    }

    if (local_u32TimeOut != TIME_OUT)
    {
        local_u32TimeOut = 0;
        UDR = A_u8Byte;
        while (GET_BIT(UCSRA, UDRE) == 0)
        {
            local_u32TimeOut++;
            if (local_u32TimeOut == TIME_OUT)
                break;
        }
    }

    // set the flag by one to be cleared
    // you can skip this step cause it's already cleared automatically
    SET_BIT(UCSRA, TXC);
}

void UART_voidSendByteSynchBlocking(u8 A_u8Byte)
{
    while (GET_BIT(UCSRA, UDRE) == 0)
        ;
    UDR = A_u8Byte;
}

void UART_voidSendByteAsynch(u8 A_u8Byte)
{
    UDR = A_u8Byte;
}

u8 UART_u8ReadByteSynchBlocking(void)
{
    while (GET_BIT(UCSRA, RXC) == 0)
        ;
    return UDR;
}
u8 UART_u8ReadByteSynchNonBlocking(void)
{
    u32 local_u32TimeOut = 0;
    while (GET_BIT(UCSRA, RXC) == 0)
    {
        local_u32TimeOut++;
        if (local_u32TimeOut == TIME_OUT)
            break;
    }
    if (local_u32TimeOut != TIME_OUT)
        return UDR;
    return DUMMY_DATA;
}

u8 UART_u8ReadByteAsynch(void)
{
    return UDR;
}

/*****************************************************************************/
/* Interrupt Section */
void UART_voidRXCompleteInterruptEnable(void)
{
    SET_BIT(UCSRB, RXCIE);
}

void UART_voidRXCompleteInterruptDisable(void)
{
    CLR_BIT(UCSRB, RXCIE);
}

void UART_voidTXCompleteInterruptEnable(void)
{
    SET_BIT(UCSRB, TXCIE);
}

void UART_voidTXCompleteInterruptDisable(void)
{
    CLR_BIT(UCSRB, TXCIE);
}

void UART_voidUDRInterruptEnable(void)
{
    SET_BIT(UCSRB, UDRIE);
}

void UART_voidUDRInterruptDisable(void)
{
    CLR_BIT(UCSRB, UDRIE);
}
/*****************************************************************************/

/*****************************************************************************/
/* Callback Section */
void UART_voidSetCallRXC(void (*pf)(void))
{
    USART_RXC_CALL = pf;
}

void UART_voidSetCallUDRE(void (*pf)(void))
{
    USART_UDRE_CALL = pf;
}

void UART_voidSetCallTXC(void (*pf)(void))
{
    USART_TXC_CALL = pf;
}
/*****************************************************************************/

ISR(USART_RXC_VECT)
{
    if (USART_RXC_CALL != NULLPTR)
        USART_RXC_CALL();
}

ISR(USART_UDRE_VECT)
{
    if (USART_UDRE_CALL != NULLPTR)
        USART_UDRE_CALL();
}

ISR(USART_TXC_VECT)
{
    if (USART_TXC_CALL != NULLPTR)
        USART_TXC_CALL();
}
