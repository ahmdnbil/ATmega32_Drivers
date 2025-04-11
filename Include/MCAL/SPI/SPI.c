/**
 * @file SPI.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */


// libraries
#include "./SPI.h"

static void (*SPI_INT)(void) = NULLPTR;

void SPI_voidInit()
{
    //Master/Slave Selection
#if (SPI_MODE_SELECT == SPI_MASTER)
    SET_BIT(SPCR, MSTR);
#else
    CLR_BIT(SPCR, MSTR);
#endif

// Clock Phase
#if (CLK_PHASE_SPI == SAMPLE_THEN_SETUP_SPI)
    CLR_BIT(SPCR, CPHA);
#else
    SET_BIT(SPCR, CPHA);
#endif

// Clock Polarity
#if (CLK_POLARITY_SPI == RISING_THEN_FALLING_SPI)
    CLR_BIT(SPCR, CPOL);
#else
    SET_BIT(SPCR, CPOL)
#endif

// Data Order
#if (SPI_DATA_ORDER == SPI_LSB_FIRST)
    SET_BIT(SPCR, DORD);
#else
    CLR_BIT(SPCR, DORD);
#endif

// SPI clock rate
#if (SPI_CLK_RATE == SPI_CLK_OVER_2)
    CLR_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
#elif (SPI_CLK_RATE == SPI_CLK_OVER_4)
    CLR_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    CLR_BIT(SPSR, SPI2X);
#elif (SPI_CLK_RATE == SPI_CLK_OVER_8)
    SET_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
#elif (SPI_CLK_RATE == SPI_CLK_OVER_16)
    SET_BIT(SPCR, SPR0);
    CLR_BIT(SPCR, SPR1);
    CLR_BIT(SPSR, SPI2X);
#elif (SPI_CLK_RATE == SPI_CLK_OVER_32)
    CLR_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
#elif (SPI_CLK_RATE == SPI_CLK_OVER_64)
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);
    SET_BIT(SPSR, SPI2X);
#elif (SPI_CLK_RATE == SPI_CLK_OVER_128)
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);
    CLR_BIT(SPSR, SPI2X);
#endif

    /*
        it must be done after any initialization step
        or do it in the last step like here
    */
    SET_BIT(SPCR, SPE);
}

uint8_t SPI_u8SendRecieveData(uint8_t A_u8Send)
{
    SPDR = A_u8Send;
    // polling until the register to be shifted in slave/master
    while (GET_BIT(SPSR, SPIF) == 0)
        ;
    return SPDR;
}
/******************************************Interrupt Section*********************************/
void SPI_voidInterruptEnable()
{
    SET_BIT(SPCR, SPIE);
}

void SPI_voidInterruptDisable()
{
    CLR_BIT(SPCR, SPIE);
}

void SPI_voidSetCallBack(void (*pf)(void))
{
    SPI_INT = pf;
}

ISR(SPI_VECT)
{
    if (SPI_INT != NULLPTR)
        SPI_INT();
}
/*******************************************************************************************/
