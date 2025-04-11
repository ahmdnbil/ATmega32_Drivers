/**
 * @file SPI_Cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef INCLUDE_MCAL_SPI_SPI_CONFIGURATIONS_H_
#define INCLUDE_MCAL_SPI_SPI_CONFIGURATIONS_H_

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------MACRO Declarations-----------------------------------*/
#define SPI_CLK_OVER_2 0
#define SPI_CLK_OVER_4 1
#define SPI_CLK_OVER_8 2
#define SPI_CLK_OVER_16 3
#define SPI_CLK_OVER_32 4
#define SPI_CLK_OVER_64 5
#define SPI_CLK_OVER_128 6
#define SPI2X 0
#define SPIF 7

#define SPI_LSB_FIRST 1
#define SPI_MSB_FIRST 0

#define SPI_MASTER 1
#define SPI_SLAVE 0

#define RISING_THEN_FALLING_SPI 1
#define FALLING_THEN_RISING_SPI 0

#define SAMPLE_THEN_SETUP_SPI 1
#define SETUP_THEN_SAMPLE_SPI 0

/*
Choose Data Order
    SPI_LSB_FIRST
    SPI_MSB_FIRST
*/
#define SPI_DATA_ORDER SPI_LSB_FIRST

/*
Choose SPI mode:
    SPI_MASTER
    SPI_SLAVE
*/
#define SPI_MODE_SELECT SPI_MASTER

/*
Choose CLK Polarity:
    RISING_THEN_FALLING_SPI
    FALLING_THEN_RISING_SPI
*/
#define CLK_POLARITY_SPI RISING_THEN_FALLING_SPI

/*
Choose CLK Phase:
    SAMPLE_THEN_SETUP_SPI
    SETUP_THEN_SAMPLE_SPI
*/
#define CLK_PHASE_SPI SETUP_THEN_SAMPLE_SPI

/*
Choose SPI CLK Rate:
    SPI_CLK_OVER_2   
    SPI_CLK_OVER_4   
    SPI_CLK_OVER_8   
    SPI_CLK_OVER_16  
    SPI_CLK_OVER_32  
    SPI_CLK_OVER_64  
    SPI_CLK_OVER_128 
*/
#define SPI_CLK_RATE SPI_CLK_OVER_16

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* INCLUDE_MCAL_SPI_SPI_CONFIGURATIONS_H_ */
