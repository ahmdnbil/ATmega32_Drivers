/**
 * @file RTC.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "./RTC.h"

static uint8_t decToBcd(uint8_t dec);
static uint8_t bcdToDec(uint8_t val);

/*
    Iniate the  control register of DS1307
    | S  | DS1307_ADD | W  | ACK | DS1307_CONTROL_REGISTER | ACK | DS1307_CONTROL_REGISTER_VALUE | ACK |  S |
    |1bit|     7bit   |1bit| 1bit|           8bit          |1bit |              8bit             | 1bit|1bit|

    Send time and date to DS1307

*/


TWI_STATUS RTC_u8ConfigOutSignal(SQWE_signal signal)
{
    uint8_t controlValue=0;
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
    status = TWI_u8SendReStart();
    //send slave address with write command to configure the  DS1307
    status = TWI_u8SendSlaveAddWrite(DS1307_ADD);
    status = TWI_u8SendData(DS1307_CONTROL_REGISTER);
    status = TWI_u8SendData(controlValue);
    TWI_voidStop();
    return status;
}


TWI_STATUS RTC_u8SetTime(uint8_t *TiemPtr, TIME_Format format)
{
    uint8_t hours = TiemPtr[2]; // Assume this is in BCD
    
    if ((format == PM) || (format == AM))
    {
        // Convert BCD to decimal
        hours = (hours >> 4) * 10 + (hours & 0x0F);
        
        // 24-hour → 12-hour conversion
        if (hours == 0)
        {
            hours = 12;
            format = AM;
        }
        else if (hours == 12)
        {
            format = PM; // keep as-is
        }
        else if (hours > 12)
        {
            hours -= 12;
            format = PM;
        }
        
        // Now encode back to BCD
        uint8_t hour_bcd = decToBcd(hours);
        
        // Set 12-hour format bit
        SET_BIT(hour_bcd, HOURS_MODE_BIT); // 12-hour mode
        
        // Set AM/PM bit
        if (format == PM)
        SET_BIT(hour_bcd, _12_HOURSE_MODE_BIT);
        else
        CLR_BIT(hour_bcd, _12_HOURSE_MODE_BIT);
        
        TiemPtr[2] = hour_bcd; // Final result
    }
    
    /*
    TiemPtr[0] = seconds (BCD)
    TiemPtr[1] = minutes (BCD)
    TiemPtr[2] = hours   (final BCD format with mode bits)
    */
   TWI_STATUS status = TWI_OK;
   status = TWI_u8Start();
   status = TWI_u8SendSlaveAddWrite(DS1307_ADD);
   status = TWI_u8SendData(DS1307_FIRST_ADD_TIME);
   status = TWI_u8SendData(TiemPtr[0]); // seconds
   status = TWI_u8SendData(TiemPtr[1]); // minutes
   status = TWI_u8SendData(TiemPtr[2]); // hours
   TWI_voidStop();
   
   return status;
}

TWI_STATUS RTC_u8SetDate(uint8_t *datePtr)
{
    TWI_STATUS status=TWI_OK;
    //send start
    status = TWI_u8Start();
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
    //send stop bit
    TWI_voidStop();
    return status;
}

TWI_STATUS RTC_u8GetTime(uint8_t *timePtr , uint8_t *Pzone)
{
    TWI_STATUS status = TWI_OK;

    // Send start + write address
    status = TWI_u8SendReStart();
    status = TWI_u8SendSlaveAddWrite(DS1307_ADD);
    status = TWI_u8SendData(DS1307_FIRST_ADD_TIME);

    // Repeated start + read
    status = TWI_u8SendReStart();
    status = TWI_u8SendSlaveAddRead(DS1307_ADD);

    // Read time registers
    TWI_u8ReadData(1, &timePtr[0]); // seconds
    TWI_u8ReadData(1, &timePtr[1]); // minutes
    TWI_u8ReadData(0, &timePtr[2]); // hours

    TWI_voidStop();

    // Extract and store AM/PM/24 mode
    uint8_t rawHour = timePtr[2];
    if (GET_BIT(rawHour, HOURS_MODE_BIT))
    {
        timePtr[3] = GET_BIT(rawHour, _12_HOURSE_MODE_BIT); // 0 = AM, 1 = PM
        if(GET_BIT(rawHour, _12_HOURSE_MODE_BIT)) strcpy((char *)Pzone, "PM");
        else strcpy((char *)Pzone, "AM");
        rawHour &= ~(1 << HOURS_MODE_BIT);
        rawHour &= ~(1 << _12_HOURSE_MODE_BIT);
    }
    else
    {
        timePtr[3] = 2; // 24-hour mode
    }

    // Convert from BCD to decimal
    timePtr[0] = bcdToDec(timePtr[0]); // seconds
    timePtr[1] = bcdToDec(timePtr[1]); // minutes
    timePtr[2] = bcdToDec(rawHour);    // hours (cleaned)

    return status;
}

TWI_STATUS RTC_u8GetDate(uint8_t *datePtr,uint8_t *dayPtr)
{
    // datePtr is an arry iniated at RAM stores 4 places
    // datePtr[0]: day
    // datePtr[1]: date
    // datePtr[2]: month
    // datePtr[3]: year
    TWI_STATUS status = TWI_OK;
    // send Start Bit
    status = TWI_u8SendReStart();
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
    datePtr[0] = bcdToDec(datePtr[0]);
    switch (datePtr[0])
    {
        case 1:
        strcpy((char *)dayPtr, "Sun");
        break;
        case 2:
        strcpy((char *)dayPtr, "Mon");
        break;
        case 3:
        strcpy((char *)dayPtr, "Tue");
        break;
        case 4:
        strcpy((char *)dayPtr, "Wed");
        break;
        case 5:
        strcpy((char *)dayPtr, "Thu");
        break;
        case 6:
        strcpy((char *)dayPtr, "Fri");
        break;
    case 7:
        strcpy((char *)dayPtr, "Sat");
        break;
        default:
        strcpy((char *)dayPtr, "---");
        break; // fallback in case of invalid value
    }
    // read date
    TWI_u8ReadData(1, &datePtr[1]);
    datePtr[1] = bcdToDec(datePtr[1]);
    // read month
    TWI_u8ReadData(1, &datePtr[2]);
    datePtr[2] = bcdToDec(datePtr[2]);
    // read year
    TWI_u8ReadData(0, &datePtr[3]);
    datePtr[3] = bcdToDec(datePtr[3]);
    // send stop bit
    TWI_voidStop();
    return status;
}

static uint8_t decToBcd(uint8_t dec)
{
    return ((dec / 10) << 4) | (dec % 10);
}

static uint8_t bcdToDec(uint8_t val)
{
    return ((val >> 4) * 10) + (val & 0x0F);
}