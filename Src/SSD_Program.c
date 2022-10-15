/*
 * SSD_Program.c
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

//DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"
#include "../Include/MCAL/DIO/DIO_Private.h"

#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/SSD/SSD_Private.h"
#include "../Include/HAL/SSD/SSD_Configuration.h"

#include <util/delay.h>
void HSSD_voidDisplay(u8 A_u8Number,u8 A_u8PortId)
{
	switch(A_u8Number)
	{
	case ZERO:
		MDIO_voidSetPortValue(A_u8PortId,ZERO);
		break;
	case ONE:
		MDIO_voidSetPortValue(A_u8PortId,ONE);
		break;
	case TWO:
		MDIO_voidSetPortValue(A_u8PortId,TWO);
		break;
	case THREE:
		MDIO_voidSetPortValue(A_u8PortId,THREE);
		break;
	case FOUR:
		MDIO_voidSetPortValue(A_u8PortId,FOUR);
		break;
	case FIVE:
		MDIO_voidSetPortValue(A_u8PortId,FIVE);
		break;
	case SIX:
		MDIO_voidSetPortValue(A_u8PortId,SIX);
		break;
	case SEVEN:
		MDIO_voidSetPortValue(A_u8PortId,SEVEN);
		break;
	case EIGHT:
		MDIO_voidSetPortValue(A_u8PortId,EIGHT);
		break;
	case NINE:
		MDIO_voidSetPortValue(A_u8PortId,NINE);
		break;
	}
}

void HSSD_voidDisplayAscending(u8 A_u8PortId)
{
u8 arr[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	for(u8 i=0;i<10;i++)
	{
		HSSD_voidDisplay(arr[i],A_u8PortId);
		_delay_ms(SSD_DELAY);
	}
}

void HSSD_voidDisplayDescending(u8 A_u8PortId)
{
u8 arr[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	for(u8 j=9;j>=0;j--)
	{
		HSSD_voidDisplay(arr[j],A_u8PortId);
		_delay_ms(SSD_DELAY);
	}
}
