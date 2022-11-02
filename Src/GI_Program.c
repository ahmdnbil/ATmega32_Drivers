/*
 * GI_Program.c
 *
 *  Created on: Nov 1, 2022
 *      Author: User
 */


//libraries
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//GI
#include "../Include/MCAL/GI/GI_Private.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/GI/GI_Configuration.h"



void MGI_voidEnable()
{
    SET_BIT(SREG,I_BIT);
}

void MGI_voidDisable()
{
    
    CLR_BIT(SREG,I_BIT);
}