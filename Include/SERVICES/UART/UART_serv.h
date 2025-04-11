#ifndef _UART_SERV_H
#define _UART_SERV_H

/*-------------------------------------section includes---------------------------------------*/
#include "./../../MCAL/UART/UART.h"
/*--------------------------------------------------------------------------------------------*/

void UART_voidSendStringSynch(uint8_t *A_u8String);
void UART_voidReadStringSynch(uint8_t *A_u8String);
void UART_voidSendStringAsynch(uint8_t *A_u8String);
void UART_voidReadStringAsynch(uint8_t *A_u8String);

#endif /* _UART_SERV_H */


