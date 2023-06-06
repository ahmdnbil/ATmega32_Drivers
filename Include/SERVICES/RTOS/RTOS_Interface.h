/*
 * RTOS_Interface.h
 *
 *  Created on: Jun 2, 2023
 *      Author: User
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_

void RTOS_voidInit(void);
void RTOS_voidInitArrayFunctions();
void RTOS_voidCreateTask(u8 A_u8Priority,u16 A_u16Periodicty,u16 A_u16FirstDelay,void(*pf)(void));
void RTOS_voidScheduler(void);

#endif /* INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_ */
