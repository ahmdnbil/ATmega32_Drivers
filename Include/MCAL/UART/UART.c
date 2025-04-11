/**
 * @file UART.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/*-------------------------------------section includes---------------------------------------*/
#include "./UART.h"
/*--------------------------------------------------------------------------------------------*/


static void (*USART_RXC_CALL)(void) = NULLPTR;
static void (*USART_UDRE_CALL)(void) = NULLPTR;
static void (*USART_TXC_CALL)(void) = NULLPTR;

void UART_voidInit(void)
{
    uint8_t UCSRC_var = 0;
    uint16_t local_u16BaudRateValue = BAUD_RATE_EQN;
    UBRRL = (uint8_t)local_u16BaudRateValue;

    /*
        note: shifting bits firstly then casting
        if you cast firt, the bits from 8 will be zeros
    */
    UBRRH = (uint8_t)((local_u16BaudRateValue) >> 8);

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


/***************************** Synch Blocking Func***********************************/
void UART_voidSendByteSynch(uint8_t A_u8Byte)
{
    while (GET_BIT(UCSRA, UDRE) == 0)
    ;
    UDR = A_u8Byte;
}

uint8_t UART_u8ReadByteSynch(void)
{
    while (GET_BIT(UCSRA, RXC) == 0)
    ;
    return UDR;
}
/************************************************************************************/

void UART_voidSendByteNoBlock(uint8_t A_u8Byte)
{
    UDR = A_u8Byte;
}

uint8_t UART_u8ReadByteNoBlock(void)
{
    return UDR;
}

uint8_t UART_u8ReadByteAsynch(uint8_t *Pdata)
{
    if(GET_BIT(UCSRA, RXC))
    {
        *Pdata = UDR;   
        return 1;
    }
    else return 0;
}


/*****************************************************************************/
/* Interrupt Section */
void UART_voidRXInterruptEnable(void)
{
    SET_BIT(UCSRB, RXCIE);
}

void UART_voidRXInterruptDisable(void)
{
    CLR_BIT(UCSRB, RXCIE);
}

void UART_voidTXInterruptEnable(void)
{
    SET_BIT(UCSRB, TXCIE);
}

void UART_voidTXInterruptDisable(void)
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
