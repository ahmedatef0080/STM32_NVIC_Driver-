#ifndef     _MRCC_interface_H_
#define     _MRCC_interface_H_
#include "STD_Type.h"

#define AHB_Bus 	 0
#define APB1_Bus	 1
#define APB2_Bus	 2


#define GPIO_A_EN    2
#define GPIO_B_EN    3
#define GPIO_C_EN    4




void Set_Clock_Type(void);


void Set_clock_For_Perhphiral(u8 Bus,u8 Perhpiral);



#endif
