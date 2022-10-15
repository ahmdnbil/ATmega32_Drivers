/*
 * main.c
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

//SSD
#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/SSD/SSD_Configuration.h"


//LCD8
#include "../Include/HAL/LCD8/LCD8_Interface.h"
#include "../Include/HAL/LCD8/LCD8_Configuration.h"

//LCD4
#include "../Include/HAL/LCD4/LCD4_Configuration.h"
#include "../Include/HAL/LCD4/LCD4_Interface.h"

void main(void)
{
    MDIO_voidInit();
    HLCD8_voidInit();
    HLCD8_voidDisplayNumber(5534);

    while(1)
    {


    }
}
