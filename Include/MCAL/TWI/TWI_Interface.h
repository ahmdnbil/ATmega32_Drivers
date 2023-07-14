/*
 * TWI_Interface.h
 *
 *  Created on: Jul 5, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TWI_TWI_INTERFACE_H_
#define INCLUDE_MCAL_TWI_TWI_INTERFACE_H_

typedef enum
{
    TWI_OK,
    START_TWI_ERORR,
    TWI_SLA_ACK,
    TWI_DATA_TRANSMITTED_ACK,
    TWI_DATA_RECEIVED_ACK,
    RE_START_ACK_ERORR,
    MR_SLA_ACK_ERROR
} TWI_STATUS;

void MTWI_voidInit(u8 A_u8Slave);
TWI_STATUS MTWI_u8Start(void);
TWI_STATUS MTWI_u8SendSlaveAddWrite(u8 A_u8SlaveAdd);
TWI_STATUS MTWI_u8SendData(u8 A_u8Data);
TWI_STATUS MTWI_u8SendReStart(void);
TWI_STATUS MTWI_u8SendSlaveAddRead(u8 A_u8SlaveAdd);
TWI_STATUS MTWI_u8ReadData(u8 ack, u8 *A_u8data);
void MTWI_voidStop(void);
void MTWI_voidSetCallBack(void (*pf)(void));
void MTWI_voidSetInterruptEnable();
void MTWI_voidSetIntDisable();

#endif /* INCLUDE_MCAL_TWI_TWI_INTERFACE_H_ */
