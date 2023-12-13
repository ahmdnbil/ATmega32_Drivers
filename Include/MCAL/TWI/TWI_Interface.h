/*
 * TWI_Interface.h
 *
 *  Created on: Jul 5, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TWI_TWI_INTERFACE_H_
#define INCLUDE_MCAL_TWI_TWI_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    TWI_OK,
    START_TWI_ERORR,
    TWI_SLA_ACK_ERORR,
    TWI_DATA_TRANS_ACK_ERORR,
    TWI_DATA_RECEIVED_ACK_ERORR,
    RE_START_ACK_ERORR,
    MR_SLA_ACK_ERROR
} TWI_STATUS;

/*---------------------------------------function declarations--------------------------------*/
void TWI_voidInit(u8 A_u8Slave);
TWI_STATUS TWI_u8Start(void);
TWI_STATUS TWI_u8SendSlaveAddWrite(u8 A_u8SlaveAdd);
TWI_STATUS TWI_u8SendData(u8 A_u8Data);
TWI_STATUS TWI_u8SendReStart(void);
TWI_STATUS TWI_u8SendSlaveAddRead(u8 A_u8SlaveAdd);
void TWI_u8ReadData(u8 ack, u8 *A_u8data);
void TWI_voidStop(void);
void TWI_voidSetCallBack(void (*pf)(void));
void TWI_voidSetInterruptEnable();
void TWI_voidSetIntDisable();

#endif /* INCLUDE_MCAL_TWI_TWI_INTERFACE_H_ */
