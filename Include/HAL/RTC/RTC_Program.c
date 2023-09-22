/*
 * TWI_Program.c
 *
 *  Created on: Sep 18, 2023
 *      Author: ahmed nabil
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/TWI/TWI_Interface.h"

#include "./RTC_Interface.h"
#include "./RTC_Private.h"


/*
    Iniate the  control register of DS1307
    | S  | DS1307_ADD | W  | ACK | DS1307_CONTROL_REGISTER | ACK | DS1307_CONTROL_REGISTER_VALUE | ACK |  S |
    |1bit|     7bit   |1bit| 1bit|           8bit          |1bit |              8bit             | 1bit|1bit|

    Send time and date to DS1307

*/


TWI_STATUS RTC_u8ConfigOutSignal(SQWE_signal signal)
{
    u8 controlValue=0;
    switch (signal)
    {
        case _1_HZ:
            SET_BIT(controlValue, SQWE);
            CLR_BIT(controlValue,RS0);
            CLR_BIT(controlValue,RS1);
            break;
        case _4096_HZ:
            SET_BIT(controlValue, SQWE);
            SET_BIT(controlValue,RS0);
            CLR_BIT(controlValue,RS1);
            break;
        case _8192_HZ:
            SET_BIT(controlValue, SQWE);
            CLR_BIT(controlValue,RS0);
            SET_BIT(controlValue,RS1);
            break;
        case _32768_HZ:
            SET_BIT(controlValue, SQWE);
            SET_BIT(controlValue,RS0);
            SET_BIT(controlValue,RS1);
            break;
        case High:
            CLR_BIT(controlValue, SQWE);
            SET_BIT(controlValue,OUTPUT_CONTROL_BIT);
            break;
        case Low:
            CLR_BIT(controlValue,SQWE);
            CLR_BIT(controlValue,OUTPUT_CONTROL_BIT);
            break;
    }
    TWI_STATUS status= TWI_OK;
    //Send start for TWI
    status = TWI_voidStart();
    //send slave address with write command to configure the  DS1307
    status = TWI_u8SendSlaveAddWrite(DS1307_ADD);
    status = TWI_u8SendData(DS1307_CONTROL_REGISTER);
    status = TWI_u8SendData(controlValue);
    TWI_voidStop();
    return status;
}

TWI_STATUS RTC_u8SetTime(u8 *TiemPtr, TIME_Format format)
{
    if ((format == PM) || (format == AM))
    {
            if (TiemPtr[2] > 12)
            {
                TiemPtr[2] -= 12;
            }
            SET_BIT(TiemPtr[2], HOURS_MODE_BIT);
            if (format == PM)
            {
                SET_BIT(TiemPtr[2], _12_HOURSE_MODE_BIT);
            }
            else
            {
                CLR_BIT(TiemPtr[2], _12_HOURSE_MODE_BIT);
            }
    }
    else
    {
            CLR_BIT(TiemPtr[2], HOURS_MODE_BIT);
    }
    /*
        TimePtr[3]={seconds,minutes,hours}
    */
    TWI_STATUS status= TWI_OK;
    //send start bit
    status =TWI_voidStart();
    //send DS1307 address
    status=TWI_u8SendSlaveAddWrite(DS1307_ADD);
    //send first address of DS1307
    status = TWI_u8SendData(DS1307_FIRST_ADD_TIME);
    // set Seconds
    status = TWI_u8SendData(TiemPtr[0]);
    // set Minutes
    status = TWI_u8SendData(TiemPtr[1]);
    // set Hours
    status = TWI_u8SendData(TiemPtr[2]);
    //send stop
    TWI_voidStop();
    return status;
}

TWI_STATUS RTC_u8SetDate(u8 *datePtr)
{
    TWI_STATUS status=TWI_OK;
    //send start
    status=TWI_voidStart();
    //send address of DS1307
    status=TWI_u8SendSlaveAddWrite(DS1307_ADD);
    status=TWI_u8SendData(DS1307_FIRST_ADD_DATE);

    //send day
    status=TWI_u8SendData(datePtr[0]);
    //send date
    status=TWI_u8SendData(datePtr[1]);
    //send Month
    status=TWI_u8SendData(datePtr[2]);
    //send year
    status=TWI_u8SendData(datePtr[3]);
    
    return status;
}

TWI_STATUS RTC_u8GetTime(u8 *timePtr)
{
    // timePtr is an arry iniated at RAM stores 4 places
    // timePtr[0]: seconds
    // timePtr[1]: minutes
    // timePtr[2]: hours
    // timePtr[3]: PM or AM 
    TWI_STATUS status =TWI_OK;
    //send Start Bit
    status = TWI_voidStart();
    //send slave address with write
    status = TWI_u8SendSlaveAddWrite(DS1307_ADD);
    //send first  internal address
    status = TWI_u8SendData(DS1307_FIRST_ADD_TIME);
    //send repeated start
    status = TWI_u8SendReStart();
    //send slave address with read
    status= TWI_u8SendSlaveAddRead(DS1307_ADD);
    //reaad seconds
    TWI_u8ReadData(1, &timePtr[0]);
    //read minutes
    TWI_u8ReadData(1, &timePtr[1]);
    //read hours
    TWI_u8ReadData(0, &timePtr[2]);
    //send stop bit
    TWI_voidStop();  
    /*
        store if it's PM or AM in timePtr[3]
        if it's zero == AM
        if it's one ==  PM
        if it's Two ==  24 mode
    */
    if (GET_BIT(timePtr[2], HOURS_MODE_BIT))
    {
        timePtr[3] = GET_BIT(timePtr[2], _12_HOURSE_MODE_BIT);
        CLR_BIT(timePtr[2], HOURS_MODE_BIT);
        CLR_BIT(timePtr[2], _12_HOURSE_MODE_BIT);
    }
    else
    {
        timePtr[3]=2;
    }
    return status;
}

TWI_STATUS RTC_u8GetDate(u8 *datePtr)
{
    // datePtr is an arry iniated at RAM stores 4 places
    // datePtr[0]: day
    // datePtr[1]: date
    // datePtr[2]: month
    // datePtr[3]: year
    TWI_STATUS status = TWI_OK;
    // send Start Bit
    status = TWI_voidStart();
    // send slave address with write
    status = TWI_u8SendSlaveAddWrite(DS1307_ADD);
    // send first  internal address
    status = TWI_u8SendData(DS1307_FIRST_ADD_DATE);
    // send repeated start
    status = TWI_u8SendReStart();
    // send slave address with read
    status = TWI_u8SendSlaveAddRead(DS1307_ADD);
    // reaad day
    TWI_u8ReadData(1, &datePtr[0]);
    // read date
    TWI_u8ReadData(1, &datePtr[1]);
    // read month
    TWI_u8ReadData(1, &datePtr[2]);
    // read year
    TWI_u8ReadData(0, &datePtr[3]);
    // send stop bit
    TWI_voidStop();
    return status;
}