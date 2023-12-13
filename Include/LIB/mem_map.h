/**
 * @file mem_map.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _MEM_MAP_H_
#define _MEM_MAP_H_

// Output Compare Register
#define OCR0 (*(volatile u8 *)0x5C)

// General Interrupt Control Register
#define GICR (*(volatile u8 *)0x5B)

// General Interrupt Flag Register
#define GIFR (*(volatile u8 *)0x5A)

// Timer/Counter Interrupt Mask
#define TIMSK (*(volatile u8 *)0x59)

// Timer/Counter Interrupt Flag Register
#define TIFR (*(volatile u8 *)0x58)

// TWI Control Register
#define TWCR (*(volatile u8 *)0x56)

// MCU Control Register
#define MCUCR (*(volatile u8 *)0x55)

// MCU Control & Status Register
#define MCUCSR (*(volatile u8 *)0x54)

/* Timer/Counter Control Register */
#define TCCR0 (*(volatile u8 *)0x53)

// Timer/Counter Register
#define TCNT0 (*(volatile u8 *)0x52)

// Special FunctionIO Register
#define SFIOR (*(volatile u8 *)0x50)

// Timer/Counter1 Control Register A
#define TCCR1A (*(volatile u8 *)0x4F)

// Timer/Counter1 Control Register B
#define TCCR1B (*(volatile u8 *)0x4E)

#define TCNT1H (*(volatile u8 *)0x4D)

#define TCNT1L (*(volatile u8 *)0x4C)

#define TCNT1 (*(volatile u16 *)0x4C)

#define OCR1AH (*(volatile u8 *)0x4B)

#define OCR1AL (*(volatile u8 *)0x4A)

#define OCR1A (*(volatile u16 *)0x4A)

#define OCR1BH (*(volatile u8 *)0x49)

#define OCR1BL (*(volatile u8 *)0x48)

#define OCR1B (*(volatile u16 *)0x48)

#define ICR1H (*(volatile u8 *)0x47)

#define ICR1L (*(volatile u8 *)0x46)

#define ICR1 (*(volatile u16 *)0x46)

#define TCCR2 (*(volatile u8 *)0x45)

#define TCNT2 (*(volatile u8 *)0x44)

#define OCR2 (*(volatile u8 *)0x43)

// Asynchronous Status Register
#define ASSR (*(volatile u8 *)0x42)

// Watchdog Timer Control Register
#define WDTCR (*(volatile u8 *)0x41)

// USART Control and Status Register C
#define UCSRC (*(volatile u8 *)0x40)

// USART Baud Rate Register High
#define UBRRH (*(volatile u8 *)0x40)

// EEPROM Address Register High
#define EEARH (*(volatile u8 *)0x3F)

// EEPROM Address Register Low
#define EEARL (*(volatile u8 *)0x3E)

// EEPROM Data Register
#define EEDR (*(volatile u8 *)0x3D)

// EEPROM Control Register
#define EECR (*(volatile u8 *)0x3C)

#define PORTA_REG (*(volatile u8 *)0x3B)

#define DDRA_REG (*(volatile u8 *)0x3A)

#define PINA_REG (*(volatile u8 *)0x39)

#define PORTB_REG (*(volatile u8 *)0x38)

#define DDRB_REG (*(volatile u8 *)0x37)

#define PINB_REG (*(volatile u8 *)0x36)

#define PORTC_REG (*(volatile u8 *)0x35)

#define DDRC_REG (*(volatile u8 *)0x34)

#define PINC_REG (*(volatile u8 *)0x33)

#define PORTD_REG (*(volatile u8 *)0x32)

#define DDRD_REG (*(volatile u8 *)0x31)

#define PIND_REG (*(volatile u8 *)0x30)

// SPI Data Register
#define SPDR (*(volatile u8 *)0x2F)

// SPI Status Register
#define SPSR (*(volatile u8 *)0x2E)

// SPI Control Register
#define SPCR (*(volatile u8 *)0x2D)

// USART I/O Data Register
#define UDR (*(volatile u8 *)0x2C)

// USART Control and Status Register A
#define UCSRA (*(volatile u8 *)0x2B)

// USART Control and Status Register B
#define UCSRB (*(volatile u8 *)0x2A)

// USART Baud Rate Register LOW
#define UBRRL (*(volatile u8 *)0x29)

// ADC Multiplexer Selection Register
#define ADMUX (*(volatile u8 *)0x27)

// ADC Control Status Register A
#define ADCSRA (*(volatile u8 *)0x26)

// The ADC Data Register High
#define ADCH (*(volatile u8 *)0x25)

// The ADC Data Register Low
#define ADCL (*(volatile u8 *)0x24)

// TWI Data Register
#define TWDR (*(volatile u8 *)0x23)

// TWI Slave Address Register
#define TWAR (*(volatile u8 *)0x22)

// TWI Status Register
#define TWSR (*(volatile u8 *)0x21)

// TWI Bit Rate Register
#define TWBR (*(volatile u8 *)0x20)

#endif
