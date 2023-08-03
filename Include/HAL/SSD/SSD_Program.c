/*
 * SSD_Program.c
 *
 *  Created on: Oct 12, 2022
 *      Author: User
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "./SSD_Interface.h"
#include "./SSD_Private.h"

#define F_CPU 8000000UL
#include <util/delay.h>
void SSD_voidDisplay(u8 A_u8Number, u8 A_u8PortId)
{
	switch (A_u8Number)
	{
	case 0:
		DIO_voidSetPortValue(A_u8PortId, ZERO_SSD);
		break;
	case 1:
		DIO_voidSetPortValue(A_u8PortId, ONE_SSD);
		break;
	case 2:
		DIO_voidSetPortValue(A_u8PortId, TWO_SSD);
		break;
	case 3:
		DIO_voidSetPortValue(A_u8PortId, THREE_SSD);
		break;
	case 4:
		DIO_voidSetPortValue(A_u8PortId, FOUR_SSD);
		break;
	case 5:
		DIO_voidSetPortValue(A_u8PortId, FIVE_SSD);
		break;
	case 6:
		DIO_voidSetPortValue(A_u8PortId, SIX_SSD);
		break;
	case 7:
		DIO_voidSetPortValue(A_u8PortId, SEVEN_SSD);
		break;
	case 8:
		DIO_voidSetPortValue(A_u8PortId, EIGHT_SSD);
		break;
	case 9:
		DIO_voidSetPortValue(A_u8PortId, NINE_SSD);
		break;
	}
}

void SSD_voidDisplayAscending(u8 A_u8PortId, u16 A_u16Delayms)
{
	u8 arr[] = {ZERO_SSD, ONE_SSD, TWO_SSD, THREE_SSD, FOUR_SSD, FIVE_SSD, SIX_SSD, SEVEN_SSD, EIGHT_SSD, NINE_SSD};
	for (u8 i = 0; i < 10; i++)
	{
		SSD_voidDisplay(arr[i], A_u8PortId);
		_delay_ms(A_u16Delayms);
	}
}

void SSD_voidDisplayDescending(u8 A_u8PortId, u16 A_u16Delayms)
{
	u8 arr[] = {ZERO_SSD, ONE_SSD, TWO_SSD, THREE_SSD, FOUR_SSD, FIVE_SSD, SIX_SSD, SEVEN_SSD, EIGHT_SSD, NINE_SSD};
	for (u8 j = 9; j >= 0; j--)
	{
		SSD_voidDisplay(arr[j], A_u8PortId);
		_delay_ms(A_u16Delayms);
	}
}
