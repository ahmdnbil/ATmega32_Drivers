/*
 * RTOS_Program.c
 *
 *  Created on: Jun 2, 2023
 *      Author: User
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/TIMER0/TIMER0_Configurations.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"

#include "../Include/SERVICES/RTOS/RTOS_Configurations.h"
#include "../Include/SERVICES/RTOS/RTOS_Interface.h"
#include "../Include/SERVICES/RTOS/RTOS_Private.h"


RTOS_TCB RTOS_AOfTasks[RTOS_MAX_NUMBER_OF_TASKS];

void RTOS_voidInit(void)
{
    //set callback function for timer0 ctc mode
    MTIMER0_voidSetCallBackCTC(RTOS_voidScheduler);
    MTIMER0_voidInit();
}

void RTOS_voidInitArrayFunctions()
{
    u8 local_u8Counter=0;   
    for(;local_u8Counter<RTOS_MAX_NUMBER_OF_TASKS;local_u8Counter++)
    {
        RTOS_AOfTasks[local_u8Counter].pf=NULL;
    }
}

void RTOS_voidCreateTask(u8 A_u8Priority,u16 A_u16Periodicty,u16 A_u16FirstDelay,void(*pf)(void))
{
    if(A_u8Priority<RTOS_MAX_NUMBER_OF_TASKS && pf!=NULL)
    {
        RTOS_AOfTasks[A_u8Priority].FirstDelay=A_u16FirstDelay;
        RTOS_AOfTasks[A_u8Priority].Periodicty=A_u16Periodicty;
        RTOS_AOfTasks[A_u8Priority].pf=pf;
    }
}



void RTOS_voidScheduler(void)
{
    u8 local_u8TaskCounter=0;
    for(;local_u8TaskCounter<RTOS_MAX_NUMBER_OF_TASKS;local_u8TaskCounter++)
    {
        if(RTOS_AOfTasks[local_u8TaskCounter].FirstDelay == 0)
        {
            if(RTOS_AOfTasks[local_u8TaskCounter].pf !=NULL)
            {
                RTOS_AOfTasks[local_u8TaskCounter].pf();
            }
            RTOS_AOfTasks[local_u8TaskCounter].FirstDelay = RTOS_AOfTasks[local_u8TaskCounter].Periodicty-1;
        }
        else
        {
            RTOS_AOfTasks[local_u8TaskCounter].FirstDelay--;
        }
    }
}

