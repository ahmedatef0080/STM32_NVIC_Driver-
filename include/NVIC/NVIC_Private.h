#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "STD_Type.h"

typedef struct
{
	u32 NVIC_ISER[32];
	u32 NVIC_ICER[32];
	u32 NVIC_ISPR[32];
	u32 NVIC_ICPR[32];
	u32 NVIC_IABR[32];
	u32 NVIC_Res[32] ;
	u8 NVIC_IPR[128];
	
}NVIC_Type;
typedef struct
{
	u32 SCB_CPUID;
	u32 SCB_ICSR;
	u32 SCB_VTOR;
	u32 SCB_AIRCR;
	u32 SCB_SCR;
	u32 SCB_CCR;
	u32 SCB_SHPR1;
	u32 SCB_SHPR2;
	u32 SCB_SHPR3;
	u32 SCB_SHCRS;
	u32 SCB_HFSR;
	u32 SCB_MMAR;
	u32 SCB_BFAR;
	
	
}SCB_Type;

#define NVIC               ((volatile NVIC_Type*)0xE000E100)
#define NVIC_STIR          (*((volatile u32*)0xE000EE00))
#define SCB                ((volatile SCB_Type*)0xE000E008)

#endif
