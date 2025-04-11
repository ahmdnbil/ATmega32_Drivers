/**
 * @file UART_serv.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */


/*-------------------------------------section includes---------------------------------------*/
#include "./UART_serv.h"
/*--------------------------------------------------------------------------------------------*/

/*---------------------------------------Variables Declarations-------------------------------*/
static uint8_t *str_send;
static uint8_t *str_read;
/*--------------------------------------------------------------------------------------------*/


/*---------------------------------------function declarations--------------------------------*/
static void sendAsynch_CallBack();
static void raedAsynch_CallBack();
/*--------------------------------------------------------------------------------------------*/


/*---------------------------------------function definitions---------------------------------*/
void UART_voidSendStringSynch(uint8_t *A_u8String)
{
    while (*A_u8String != '\0')
    {
        UART_voidSendByteSynch(*A_u8String);
        A_u8String++;
    }
}

void UART_voidReadStringSynch(uint8_t *A_u8String)
{
    uint8_t i=0;
    A_u8String[i] = UART_u8ReadByteSynch();
    while (A_u8String[i] != '#')
    {
        i++;
        A_u8String[i] = UART_u8ReadByteSynch();
    }
    A_u8String[i] = '\0'; // null terminate the string
}

void UART_voidSendStringAsynch(uint8_t *A_u8String)
{
    UART_voidSetCallTXC(sendAsynch_CallBack);
    UART_voidTXInterruptEnable();
    UART_voidSendByteNoBlock(A_u8String[0]);
    str_send = A_u8String;
}

void UART_voidReadStringAsynch(uint8_t *A_u8String)
{
    UART_voidSetCallRXC(raedAsynch_CallBack);
    UART_voidRXInterruptEnable();
    str_read=A_u8String;
}

static void raedAsynch_CallBack()
{
    static uint8_t i=0;
    str_read[i]=UART_u8ReadByteNoBlock();
    if(str_read[i]=='#')
    {
        str_read[i]='\0';
        i=0;
    }
    else i++;
}

static void sendAsynch_CallBack()
{
    static uint8_t i=1;
    if (str_send[i] != '\0')
    {
        UART_voidSendByteNoBlock(str_send[i]);
        i++;
    }else
    {
        i=1;
    }
}


/*--------------------------------------------------------------------------------------------*/