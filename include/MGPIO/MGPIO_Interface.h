#ifndef _MGPIO_Interface_H_
#define _MGPIO_Interface_H_

#include "STD_Type.h"



#define MGPIOA 0
#define MGPIOB 1
#define MGPIOC 2



#define MGPIO_PIN0    0
#define MGPIO_PIN1    1
#define MGPIO_PIN2    2
#define MGPIO_PIN3    3
#define MGPIO_PIN4    4
#define MGPIO_PIN5    5
#define MGPIO_PIN6    6
#define MGPIO_PIN7    7
#define MGPIO_PIN8    8
#define MGPIO_PIN9    9
#define MGPIO_PIN10  10
#define MGPIO_PIN11  11
#define MGPIO_PIN12  12
#define MGPIO_PIN13  13
#define MGPIO_PIN14  14
#define MGPIO_PIN15  15


#define MGPIO_PIN_LOW  0
#define MGPIO_PIN_HIGH 1



#define INPUT_PIN_ANALOG_MODE      0b0000
#define INPUT_PIN_FLOATING_MODE    0b0100
#define INPUT_PIN_PUSH_PULL_MODE   0b1000



#define OUT_PUT_PUSH_PULL_MODE_2_MHZ      0b0010
#define OUT_PUT_OPEN_DRAIN_MODE_2_MHZ     0b0110
#define OUT_PUT_AF_PUSH_PULL_MODE_2_MHZ   0b1010
#define OUT_PUT_AF_OPEN_DRAIN_MODE_2_MHZ  0b1110

#define OUT_PUT_PUSH_PULL_MODE_10_MHZ      0b0001
#define OUT_PUT_OPEN_DRAIN_MODE_10_MHZ     0b0101
#define OUT_PUT_AF_PUSH_PULL_MODE_10_MHZ   0b1001
#define OUT_PUT_AF_OPEN_DRAIN_MODE_10_MHZ  0b1101

#define OUT_PUT_PUSH_PULL_MODE_50_MHZ      0b0011
#define OUT_PUT_OPEN_DRAIN_MODE_50_MHZ     0b0111
#define OUT_PUT_AF_PUSH_PULL_MODE_50_MHZ   0b1011
#define OUT_PUT_AF_OPEN_DRAIN_MODE_50_MHZ  0b1111


void SET_PIN_DIRECTION(u8 port ,u8 pin,u8 mode);

void SET_PIN_VALUE(u8 port , u8 pin , u8 Value);


u8 Read_PIN(u8 port , u8 pin);

void BSRR_SET_RESET_PIN_OUTPUT(u8 port ,u8 pin,u8 mode);


void BRR_RESET_PIN_OUTPUT(u8 port ,u8 pin);


#endif 
