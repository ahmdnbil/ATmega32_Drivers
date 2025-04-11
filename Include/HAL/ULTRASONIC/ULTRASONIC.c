/**
 * @file ULTRASONIC.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "./ULTRASONIC.h"

// variables
static volatile uint16_t noOVF= 0;
static volatile uint8_t flag = 0;
static volatile uint32_t t1 = 0, t2 = 0;

// function prototypes
static void OVF_counter(void);
static void ICU_func(void);

void ULTRASONIC_voidInit(uint8_t A_u8Port, uint8_t A_u8Pin)
{
    // DIO initialization
    DIO_InitPin(A_u8Port, A_u8Pin, PIN_OUTPUT, PIN_LOW);
    DIO_InitPin(PORTD, PIN6, PIN_INPUT, PIN_FLOATING); // echo pin
    // ovferflow interrupt initialization
    TIMER1_voidSetCallBackCapture(ICU_func); //set input capture callback function
    TIMER1_voidSetCallBackOVF(OVF_counter);
    TIMER1_voidOverFlowInterruptEnable(); //enable overflow interrupt
    TIMER1_voidInit(TIMER1_NORMAL_MODE, TIMER1_PRESCALER_8, TIMER1_COMPARE_OUTPUT_MODE_A_NORMAL, TIMER1_COMPARE_OUTPUT_MODE_B_NORMAL);
}
uint16_t ULTRASONIC_u16SynchReadDistance(uint8_t A_u8Port, uint8_t A_u8Pin)
{
    uint16_t distance = 0;
    uint16_t time;
    noOVF = 0;
    flag=0;
    //generate trigger pulse
    DIO_WritePin(A_u8Port,A_u8Pin,PIN_HIGH); //set trigger pin high
    _delay_us(10); //wait for 10us
    DIO_WritePin(A_u8Port, A_u8Pin, PIN_LOW); // set trigger pin low
    TIMER1_voidInputCaptureEdge(RISING); //set input capture edge to rising
    TIMER1_voidCaptureInterruptEnable(); //enable input capture interrupt
    while (flag < 2);
    time=t2-t1+((uint32_t)noOVF * 65536 ); //calculate the time in microseconds
    distance=time/58; //distance in cm
    return distance;
}

void ULTRASONIC_voidStart(uint8_t A_u8Port, uint8_t A_u8Pin)
{
    if(flag==0)
    {
        DIO_WritePin(A_u8Port, A_u8Pin, PIN_HIGH); // set trigger pin high
        _delay_us(10);                             // wait for 10us
        DIO_WritePin(A_u8Port, A_u8Pin, PIN_LOW);  // set trigger pin low
        TIMER1_voidInputCaptureEdge(RISING);       // set input capture edge to rising
        TIMER1_voidCaptureInterruptEnable();       // enable input capture interrupt
    }
}

uint8_t ULTRASONIC_u8AsynchReadDistance(uint16_t *distance) 
{
    uint16_t time;
    if(flag==2)
    {
        time=t2-t1+((uint32_t)noOVF*65536); //calculate the time in microseconds
        *distance=time/58; //distance in cm
        flag=0; //reset the flag to 0
        noOVF=0; //reset the overflow counter to 0
        return 1; //return 1 to indicate that the distance is ready
    }
    return 0; //return 0 to indicate that the distance is not ready
}

/********************* Call backs *********************************/
static void ICU_func(void)
{
    if(flag==0)
    {
        noOVF = 0;
        t1=TIMER1_voidGetICR1(); //read the first value of ICR1
        flag=1; //set the flag to 1
        TIMER1_voidInputCaptureEdge(FALLING); //set input capture edge to falling
    }else if(flag==1)
    {
        t2 = TIMER1_voidGetICR1(); //read the second value of ICR1
        flag=2; //set the flag to 2
        TIMER1_voidCaptureInterruptDisable(); //disable input capture interrupt 
    }
}
static void OVF_counter(void)
{
    noOVF++;
}
