#ifndef _MGPIO_Private_H_
#define _MGPIO_Private_H_
#include "STD_Type.h"
typedef struct 
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
	
	
}GPIO;


#define MGPIO_A ((volatile GPIO*)0x40010800)
#define MGPIO_B ((volatile GPIO*)0x40010C00)
#define MGPIO_C ((volatile GPIO*)0x40011000)



#endif 
