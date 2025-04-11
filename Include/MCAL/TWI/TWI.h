/**
 * @file TWI.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INCLUDE_MCAL_TWI_TWI_INTERFACE_H_
#define INCLUDE_MCAL_TWI_TWI_INTERFACE_H_

/*-------------------------------------section includes---------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/mem_map.h"

#include "./TWI_Cfg.h"

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
void TWI_voidInit(uint8_t A_u8Slave);
TWI_STATUS TWI_u8Start(void);
TWI_STATUS TWI_u8SendSlaveAddWrite(uint8_t A_u8SlaveAdd);
TWI_STATUS TWI_u8SendData(uint8_t A_u8Data);
TWI_STATUS TWI_u8SendReStart(void);
TWI_STATUS TWI_u8SendSlaveAddRead(uint8_t A_u8SlaveAdd);
void TWI_u8ReadData(uint8_t ack, uint8_t *A_u8data);
void TWI_voidStop(void);
void TWI_voidSetCallBack(void (*pf)(void));
void TWI_voidSetInterruptEnable();
void TWI_voidSetIntDisable();

#endif /* INCLUDE_MCAL_TWI_TWI_INTERFACE_H_ */
