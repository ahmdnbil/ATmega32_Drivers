#include "./SSD.h"

void SSD_Init(void)
{
    DIO_InitPort(SSD_DATA_PORT, DIO_PORT_OUTPUT,DIO_PORT_LOW);
}

void SSD_Write(uint8_t u8Data)
{
    DIO_WritePort(SSD_DATA_PORT, u8Data);
}