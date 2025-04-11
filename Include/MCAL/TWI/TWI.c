/**
 * @file TWI.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "./TWI.h"

static void (*TWI_INT_FUNC)(void) = NULLPTR;

/*
                CPU_FREQ              8MHz
SCL_FREQ= ----------------------- = ------
            16+2*(TWBR)* 4^(TWPS)   16+2*12*4
*/

void TWI_voidInit(uint8_t A_u8Slave)
{
    // enable TWI
    // the follwoing two line of code is to set frequency
    SET_BIT(TWCR, TWEA);
    TWBR = 2;
    TWSR = 0x00;
    // put slave address
    TWAR = A_u8Slave << 1;
    SET_BIT(TWCR, TWEN);
}

TWI_STATUS TWI_u8Start(void)
{
    // 01- Send Start Condition & Clearing Flag & Enabling TWI
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    // Polling untill Start Condition to be snet
    while (GET_BIT(TWCR, TWINT) != 1)
        ;
    if ((TWSR & 0xF8) != START_TWI)
        return START_TWI_ERORR;
    return TWI_OK;
}

TWI_STATUS TWI_u8SendSlaveAddWrite(uint8_t A_u8SlaveAdd)
{

    // 02- sending slave address + writed Operation
    TWDR = A_u8SlaveAdd << 1;
    // Clearing flag & Enabling TWI
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) != 1)
        ;
    if ((TWSR & 0xF8) != MT_SLA_ACK)
        return TWI_SLA_ACK_ERORR;
    return TWI_OK;
}

TWI_STATUS TWI_u8SendData(uint8_t A_u8Data)
{
    // 03- Sending Data
    TWDR = A_u8Data;
    // Clearing flag & Enabling TWI
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) != 1)
        ;
    if ((TWSR & 0xF8) != MT_DATA_ACK)
        return TWI_DATA_TRANS_ACK_ERORR;
    return TWI_OK;
}

TWI_STATUS TWI_u8SendReStart(void)
{
    // 04- Repeated Start
    // Clearing Flag & Enabling TWI & Setting Start Bit
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    // Polling untill flag become one
    while (GET_BIT(TWCR, TWINT) != 1)
        ;
    if ((TWSR & 0xF8) != RE_START_ACK)
        return RE_START_ACK_ERORR;
    return TWI_OK;
}

TWI_STATUS TWI_u8SendSlaveAddRead(uint8_t A_u8SlaveAdd)
{
    // 05- Send Slave address + Read
    TWDR = (A_u8SlaveAdd << 1) | (1 << 0);
    // clearing flag & Enabling TWI
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Polling untill flag become one
    while (GET_BIT(TWCR, TWINT) != 1)
        ;
    if ((TWSR & 0xF8) != MR_SLA_ACK)
        return MR_SLA_ACK_ERROR;
    return TWI_OK;
}

void TWI_u8ReadData(uint8_t ack, uint8_t *A_u8data)
{
    // 06- Read Data from Slave
    /*
        Clear Flag & enabling TWI
        we can set acknolwedge to receive more data
        or clear it to stop the transfer of data
    */
    TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
    while (GET_BIT(TWCR, TWINT) != 1)
        ;
    *A_u8data = TWDR;
}

void TWI_voidStop(void)
{
    // 07- Transmit Stop bit & Clearing Flag & Enabling TWI
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

/******************************interrupt section ****************************/
void TWI_voidSetCallBack(void (*pf)(void))
{
    TWI_INT_FUNC = pf;
}
void TWI_voidSetInterruptEnable()
{
    SET_BIT(TWCR, TWIE);
}
void TWI_voidSetIntDisable()
{
    CLR_BIT(TWCR, TWIE);
}

ISR(TWI_VECT)
{
    if (TWI_INT_FUNC != NULLPTR)
        TWI_INT_FUNC();
}
/****************************************************************************/
