#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(register,bitNo) (register |= (1<<bitNo))
#define CLR_BIT(register,bitNo) (register &= ~(1<<bitNo))
#define GET_BIT(register,bitNo) ((register & ( ~(1<<bitNo) ) ) != register)

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

/**************ISR**********************/
#define ISR_NOBLOCK __attribute__((interrupt))
#define ISR_NAKED __attribute__((naked))

#define ISR(vector,...) \
void vector (void) __attribute__((signal))__VA_ARGS__; \
void vector(void)
/**************************************/

/*************Vector Table*************/
#define EXTI0_VECT __vector_1
#define EXTI1_VECT __vector_2
#define EXTI2_VECT __vector_3
#define ADC_VECT __vector_16
#define TIMER0_CTC_VECT __vector_10
#define TIMER0_OVF_VECT __vector_11

/**************************************/

#define NULLPTR ((void *)0)
#define NULL 0

#endif
