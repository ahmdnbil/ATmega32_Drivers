#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(register,bitNo) (register |= (1<<bitNo))
#define CLR_BIT(register,bitNo) (register &= ~(1<<bitNo))
#define GET_BIT(register,bitNo) ((register & ( ~(1<<bitNo) ) ) != register)

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#define NULL 0
#endif
