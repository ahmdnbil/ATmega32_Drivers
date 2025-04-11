/**
 * @file BIT_MATH.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define CONC_BIT(b7, b6, b5, b4, b3, b2, b1, b0) Conc_help(b7, b6, b5, b4, b3, b2, b1, b0)
#define Conc_help(b7, b6, b5, b4, b3, b2, b1, b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#define SET_BIT(register,bitNo) (register |= (1<<bitNo))
#define CLR_BIT(register,bitNo) (register &= ~(1<<bitNo))
#define GET_BIT(register,bitNo) ((register & ( ~(1<<bitNo) ) ) != register)
#define TOG_BIT(register, bitNo) (register ^= (1 << bitNo))


#define NULLPTR ((void *)0)
#define NULL 0

#endif
