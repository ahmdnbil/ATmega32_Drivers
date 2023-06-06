/*
 * RTOS_Private.h
 *
 *  Created on: Jun 2, 2023
 *      Author: User
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_

typedef struct
{
    u16 FirstDelay;
    u16 Periodicty;
    void (*pf)(void);
}RTOS_TCB;


#endif /* INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_ */
