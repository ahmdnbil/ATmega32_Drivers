/*
 * SPI_Interface.h
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_SPI_SPI_INTERFACE_H_
#define INCLUDE_MCAL_SPI_SPI_INTERFACE_H_

void SPI_voidInit();
u8 SPI_u8SendRecieveData(u8 A_u8Send);
void SPI_voidInterruptEnable();
void SPI_voidInterruptDisable();
void SPI_voidSetCallBack(void (*pf)(void));

#endif /* INCLUDE_MCAL_SPI_SPI_INTERFACE_H_ */
