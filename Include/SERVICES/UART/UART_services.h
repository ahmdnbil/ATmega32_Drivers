/*
 * UART_services.h
 *
 *  Created on: Jul 2, 2023
 *      Author: User
 */

#ifndef INCLUDE_SERVICES_UART_UART_SERVICES_H_
#define INCLUDE_SERVICES_UART_UART_SERVICES_H_

#include "../../MCAL/UART/UART_Interface.h"

void MUSART_voidSendStringSynchBlocking(u8* A_u8Word);
void MUSART_voidSendStingAsynch(u8 *ptr);

void MUSART_voidReceiveString(u8 *ptr);

void MUSART_voidSendStringMyProtocol(u8 *str);
u8 MUSART_voidReceiveStringMyProtocol(u8 *str);

/*
    this to test received frame
*/
u8 MUSART_u8Frame(u8 *str,u8 *s1,u8 *s2,u8 *pnum1,u8 *pnum2);

#endif /* INCLUDE_SERVICES_UART_UART_SERVICES_H_ */
