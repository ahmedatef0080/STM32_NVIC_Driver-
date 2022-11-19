#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_



#define  set_bit(reg,bit)      (reg|=(1<<bit))
#define clear_bit(reg,bit)  reg &= ~(1<<bit)
#define Toggle_bit(reg,bit)  reg ^=(1<<bit)
#define Read_bit(reg,bit)    ((reg>>bit)&1)

#endif
