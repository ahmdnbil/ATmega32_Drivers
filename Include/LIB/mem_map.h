/**
 * @file mem_map.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _MEM_MAP_H_
#define _MEM_MAP_H_


#define SREG (*(volatile uint8_t *)0x5F)

#define OCR0 (*(volatile uint8_t *)0x5C)

#define GICR (*(volatile uint8_t *)0x5B)

#define GIFR (*(volatile uint8_t *)0x5A)

#define TIMSK (*(volatile uint8_t *)0x59)
#define OCIE2  7
#define TOIE2  6
#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2
#define OCIE0  1
#define TOIE0  0

#define TWCR (*(volatile uint8_t *)0x56)
// TWI Interrupt Flag
#define TWINT 7
// TWI Enable Acknowledge bit
#define TWEA  6
// TWI Start Condtion Bit
#define TWSTA 5
// TWI Stop Condtion Bit
#define TWSTO 4
// TWI Write Bit
#define TWWC  3
// TWI Enable Bit
#define TWEN  2
// TWI interrupt Enable
#define TWIE  0


#define MCUCR (*(volatile uint8_t *)0x55)

#define MCUCSR (*(volatile uint8_t *)0x54)

// Timer/Counter Control Register
#define TCCR0 (*(volatile uint8_t *)0x53)
#define FOC0  7
#define WGM00 6
#define COM00 4
#define WGM01 3
#define CS00  0

#define TCNT0 (*(volatile uint8_t *)0x52)

#define SFIOR (*(volatile uint8_t *)0x50)
#define ADTS0  5

#define TCCR1A (*(volatile uint8_t *)0x4F)
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define WGM11  1
#define WGM10  0

#define TCCR1B (*(volatile uint8_t *)0x4E)
#define ICNC1 7
#define ICES1 6

#define WGM13 4 
#define WGM12 3
#define CS12  2
#define CS11  1
#define CS10  0

#define TCNT1H (*(volatile uint8_t *)0x4D)
#define TCNT1L (*(volatile uint8_t *)0x4C)
#define TCNT1 (*(volatile uint16_t *)0x4C)

#define OCR1AH (*(volatile uint8_t *)0x4B)
#define OCR1AL (*(volatile uint8_t *)0x4A)
#define OCR1A (*(volatile uint16_t *)0x4A)

#define OCR1BH (*(volatile uint8_t *)0x49)
#define OCR1BL (*(volatile uint8_t *)0x48)
#define OCR1B (*(volatile uint16_t *)0x48)

#define ICR1H (*(volatile uint8_t *)0x47)
#define ICR1L (*(volatile uint8_t *)0x46)
#define ICR1 (*(volatile uint16_t *)0x46)

#define TCCR2 (*(volatile uint8_t *)0x45)
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22  2
#define CS21  1
#define CS20  0

#define TCNT2 (*(volatile uint8_t *)0x44)

#define OCR2 (*(volatile uint8_t *)0x43)

#define WDTCR (*(volatile uint8_t *)0x41)
#define WDTOE 4
#define WDE   3
#define WDP2  2
#define WDP1  1
#define WDP0  0

#define UBRRH (*(volatile uint8_t *)0x40)

#define UCSRC (*(volatile uint8_t *)0x40)
// Register Select
#define URSEL 7
// USART Mode Select
#define UMSEL 6
// Parity select bits
#define UPM1 5
#define UPM0 4
// Stop Bit Select
#define USBS 3
// Character Size bit1
#define UCSZ1 2
// Character Size bit0
#define UCSZ0 1
// Clock polarity
#define UCPOL 0

#define EEARH (*(volatile uint8_t *)0x3F)

#define EEARL (*(volatile uint8_t *)0x3E)

#define EEDR (*(volatile uint8_t *)0x3D)

#define EECR (*(volatile uint8_t *)0x3C)
// EEPROM Ready Interrupt Enable
#define EERIE 3
// EEPROM Master Write Enable
#define EEMWE 2
// EEPROM Write Enable
#define EEWE 1
// EEPROM Read Enable
#define EERE 0

#define PORTA_REG (*(volatile uint8_t *)0x3B)

#define DDRA_REG (*(volatile uint8_t *)0x3A)

#define PINA_REG (*(volatile uint8_t *)0x39)

#define PORTB_REG (*(volatile uint8_t *)0x38)

#define DDRB_REG (*(volatile uint8_t *)0x37)

#define PINB_REG (*(volatile uint8_t *)0x36)

#define PORTC_REG (*(volatile uint8_t *)0x35)

#define DDRC_REG (*(volatile uint8_t *)0x34)

#define PINC_REG (*(volatile uint8_t *)0x33)

#define PORTD_REG (*(volatile uint8_t *)0x32)

#define DDRD_REG (*(volatile uint8_t *)0x31)

#define PIND_REG (*(volatile uint8_t *)0x30)

#define SPDR (*(volatile uint8_t *)0x2F)

#define SPSR (*(volatile uint8_t *)0x2E)

#define SPCR (*(volatile uint8_t *)0x2D)
// SPI Interrupt Enable
#define SPIE 7
// SPI Enable
#define SPE 6
// Data Order
#define DORD 5
// Master/Slave Select
#define MSTR 4
// Clock Polarity
#define CPOL 3
// Clock Phase
#define CPHA 2
// SPI CLK Rate Select bit1
#define SPR1 1
// SPI CLK Rate Select bit0
#define SPR0 0

#define UDR (*(volatile uint8_t *)0x2C)

#define UCSRA (*(volatile uint8_t *)0x2B)
// USART Receive Complete Flag
#define RXC 7
// USART Transmit Complete
#define TXC 6
// USART Data Register Empty Flag
#define UDRE 5
// Frame Error
#define FE 4
// Data OverRun
#define DOR 3
// Parity Error
#define PE 2
// Double the USART  Transmission Speed
#define U2X 1
// Multi-processor Communication Mode
#define MPCM 0

#define UCSRB (*(volatile uint8_t *)0x2A)
// RX Complete Interrupt Enable
#define RXCIE 7
// TX Complete Interrupt Enable
#define TXCIE 6
// USAER Data Register Empty Interrupt Enable
#define UDRIE 5
// Reciever Enable
#define RXEN 4
// Transmitter Enable
#define TXEN 3
// Character Size
#define UCSZ2 2
// Receive Data Bit8
#define RXB8 1
// Transmit Data Bit8
#define TXB8 0

#define UBRRL (*(volatile uint8_t *)0x29)

#define ADMUX (*(volatile uint8_t *)0x27)
#define REFS0 6
#define ADLAR 5
#define MUX0 0

#define ADCSRA (*(volatile uint8_t *)0x26)
#define ADEN 7
#define ADCS 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS0 0

#define ADCH (*(volatile uint8_t *)0x25)
#define ADCL (*(volatile uint8_t *)0x24)
#define ADCLH (*(volatile uint16_t *)0x24)

#define TWDR (*(volatile uint8_t *)0x23)

#define TWAR (*(volatile uint8_t *)0x22)
// TWI General Call Recognition Enable Bit
#define TWGCE 0

#define TWSR (*(volatile uint8_t *)0x21)
// TWI Prescaler Bit1
#define TWPS1 1
// TWI Prescaler Bit0
#define TWPS0 0

#define TWBR (*(volatile uint8_t *)0x20)

/**************ISR**********************/
// Enable global interrupt using Assembly instructions
#define sei() __asm__ __volatile__("sei" ::)
// disable global interrupt using Assembly instructions
#define cli() __asm__ __volatile__("cli" ::)
#define ISR_NOBLOCK __attribute__((interrupt))
#define ISR_NAKED __attribute__((naked))
#define ISR_ALIASOF(v) __attribute__((alias(__STRINGIFY(v))))

#define ISR(vector, ...)                                   \
    void vector(void) __attribute__((signal)) __VA_ARGS__; \
    void vector(void)
/**************************************/

/*************Vector Table*************/

#define EXTI0_VECT __vector_1
#define EXTI1_VECT __vector_2
#define EXTI2_VECT __vector_3
#define TIMER2_CTC_VECT __vector_4
#define TIMER2_OVF_VECT __vector_5
#define TIMER1_CAPT_VECT __vector_6
#define TIMER1_COMA_VECT __vector_7
#define TIMER1_COMB_VECT __vector_8
#define TIMER1_OVF_VECT __vector_9
#define TIMER0_CTC_VECT __vector_10
#define TIMER0_OVF_VECT __vector_11
#define SPI_VECT __vector_12
#define USART_RXC_VECT __vector_13
#define USART_UDRE_VECT __vector_14
#define USART_TXC_VECT __vector_15
#define ADC_VECT __vector_16
#define EE_RDY_VECT __vector_17
#define TWI_VECT __vector_19

/**************************************/

#endif
