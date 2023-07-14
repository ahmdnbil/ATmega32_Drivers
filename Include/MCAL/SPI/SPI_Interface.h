/*
 * SPI_Interface.h
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_SPI_SPI_INTERFACE_H_
#define INCLUDE_MCAL_SPI_SPI_INTERFACE_H_

void MSPI_int();
u8 MSPI_u8SendRecieveData(u8 A_u8Send);
void MSPI_voidInterruptEnable();
void MSPI_voidInterruptDisable();
void MSPI_voidSetCallBack(void(*pf)(void));

#endif /* INCLUDE_MCAL_SPI_SPI_INTERFACE_H_ */
