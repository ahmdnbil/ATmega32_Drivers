/*
 * EEPROM_Program.c
 *
 *  Created on: Jul 11, 2023
 *      Author: User
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/TWI/TWI_Private.h"
#include "../Include/MCAL/TWI/TWI_Configuration.h"
#include "../Include/MCAL/TWI/TWI_Interface.h"

#include "../Include/HAL/EEPROM/EEPROM_Private.h"
#include "../Include/HAL/EEPROM/EEPROM_Interface.h"
#include "../Include/HAL/EEPROM/EEPROM_Configurations.h"

#include <util/delay.h>
/*
    assuming we talk to 8k EEPROM
    for 8K memory with lenght of 8bit for each address so we need
    ---------------------------------------------------------------------------------------------------------
    | S | 1 | 0 | 1 | 0 | A2 | A1 | A0 | R/W | A |rest internal Address| A |   send byte  | A | continue ....
    ----------------------------------------------------------------------------------------------------------
    A2: it could be 0 or one if we connect more than memroy to be addressed by hardware
    A1 & A0: they will be addressed using hardware also but to express software address

*/

TWI_STATUS HEEPROM_voidWriteInit(u8 A_u8MemoryNumber, u16 A_u8MemoryAdress)
{
    // A_u8MemoryNumber: it could be 0 or 1 only
    // A_u8MemoryAdress: 0b 98 7654 3210
    /*
        0b01010 A2 A1 A0
        A2:HW addressing so shifted by two (memory number)
        A1 & A0: part of memroy address
    */
    TWI_STATUS status = TWI_OK;
    u8 local_u8slaveAddress = EEPROM_ADD_MASK | (u8)((A_u8MemoryAdress >> 8)) | (A_u8MemoryNumber << 2);

    // 01- Send START condition
    status = MTWI_u8Start();
    if (status != TWI_OK)
        return status;

    // 02- Send Slave Address
    status = MTWI_u8SendSlaveAddWrite(local_u8slaveAddress); // A2:0 A1:0 A:0
    if (status != TWI_OK)
        return status;

    // 03- send the rest of address
    status = MTWI_u8SendData((u8)A_u8MemoryAdress);
    return status;
}

TWI_STATUS HEEPROM_voidSendData(u8 A_u8Data)
{
    // 04- sned byte
    return MTWI_u8SendData(A_u8Data);
}

TWI_STATUS HEEPROM_voidReadInit(u8 A_u8MemoryNumber, u16 A_u8MemoryAdress)
{
    TWI_STATUS status = TWI_OK;
    u8 local_u8slaveAddress = EEPROM_ADD_MASK | (u8)((A_u8MemoryAdress >> 8)) | (A_u8MemoryNumber << 2);

    // 01- Send START condition
    status = MTWI_u8Start();
    if (status != TWI_OK)
        return status;

    // 02- Send Slave Address
    status = MTWI_u8SendSlaveAddWrite(local_u8slaveAddress); // A2:0 A1:0 A:0
    if (status != TWI_OK)
        return status;

    // 03- send the rest of address
    status = MTWI_u8SendData((u8)A_u8MemoryAdress);
    if (status != TWI_OK)
        return status;

    // 04-Repeated Start to Initate
    status = MTWI_u8SendReStart();
    if (status != TWI_OK)
        return status;

    // 05- send slave address again but with read command
    status = MTWI_u8SendSlaveAddRead(local_u8slaveAddress);
    return status;
}

void HEEPROM_u8ReadData(u8 *A_u8Data, u8 ack)
{
    // 04- sned byte
    MTWI_u8ReadData(ack, A_u8Data);
}

void HEEPROM_voidSendStop()
{
    MTWI_voidStop();
    _delay_ms(10);
}