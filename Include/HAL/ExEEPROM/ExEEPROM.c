/**
 * @file ExEEPROM.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "./ExEEPROM.h"

#define F_CPU 8000000UL
#include <util/delay.h>
/*
    assuming we talk to 8k EEPROM
    for 8K memory with lenght of 8bit for each address so we need
    ---------------------------------------------------------------------------------------------------------
    | S | 1 | 0 | 1 | 0 | A2 | P1 | P0 | R/W | A |rest internal Address| A |   send byte  | A | continue ....
    ----------------------------------------------------------------------------------------------------------
    A2: it could be 0 or one if we connect more than memroy to be addressed by hardware
    P1 & P0: they will be addressed using hardware also but to express software address

*/

TWI_STATUS ExEEPROM_voidWriteInit(uint8_t A_u8MemoryNumber, uint16_t A_u8MemoryAdress)
{
    // A_u8MemoryNumber: it could be 0 or 1 only
    // A_u8MemoryAdress: 0b 98 7654 3210
    /*
        0b01010 A2 A1 A0
        A2:HW addressing so shifted by two (memory number)
        A1 & A0: part of memroy address
    */
    TWI_STATUS status = TWI_OK;
    uint8_t local_u8slaveAddress = ExEEPROM_ADD_MASK | (uint8_t)((A_u8MemoryAdress >> 8)) | (A_u8MemoryNumber << 2);

    // 01- Send START condition
    status = TWI_u8Start();
    if (status != TWI_OK)
        return status;

    // 02- Send Slave Address
    status = TWI_u8SendSlaveAddWrite(local_u8slaveAddress); // A2:0 A1:0 A:0
    if (status != TWI_OK)
        return status;

    // 03- send the rest of address
    status = TWI_u8SendData((uint8_t)A_u8MemoryAdress);
    return status;
}

TWI_STATUS ExEEPROM_voidSendData(uint8_t A_u8Data)
{
    // 04- sned byte
    return TWI_u8SendData(A_u8Data);
}

TWI_STATUS ExEEPROM_voidReadInit(uint8_t A_u8MemoryNumber, uint16_t A_u8MemoryAdress)
{
    TWI_STATUS status = TWI_OK;
    uint8_t local_u8slaveAddress = ExEEPROM_ADD_MASK | (uint8_t)((A_u8MemoryAdress >> 8)) | (A_u8MemoryNumber << 2);

    // 01- Send START condition
    status = TWI_u8Start();
    if (status != TWI_OK)
        return status;

    // 02- Send Slave Address
    status = TWI_u8SendSlaveAddWrite(local_u8slaveAddress); // A2:0 A1:0 A:0
    if (status != TWI_OK)
        return status;

    // 03- send the rest of address
    status = TWI_u8SendData((uint8_t)A_u8MemoryAdress);
    if (status != TWI_OK)
        return status;

    // 04-Repeated Start to Initate
    status = TWI_u8SendReStart();
    if (status != TWI_OK)
        return status;

    // 05- send slave address again but with read command
    status = TWI_u8SendSlaveAddRead(local_u8slaveAddress);
    return status;
}

void ExEEPROM_u8ReadData(uint8_t *A_u8Data, uint8_t ack)
{
    // 04- sned byte
    TWI_u8ReadData(ack, A_u8Data);
}

void ExEEPROM_voidSendStop()
{
    TWI_voidStop();
    _delay_ms(10);
}
