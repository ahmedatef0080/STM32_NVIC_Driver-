#include <NVIC/NVIC_CONF.h>
#include <NVIC/NVIC_Interface.h>
#include <NVIC/NVIC_Private.h>
#include "STD_Type.h"


/*
	16_Group_0_Sub 
	8_Group_2_Sub  
	4_Group_4_Sub  
	2_Group_8Sub   
	0_Group_16_Sub  
*/

void MNVIC_VoidINIT(void)
{
	SCB-> SCB_AIRCR = Confg_Group_Sub_Group;
}

void MNVIC_Piriorty_Set(s8 INT_ID, u8 Group, u8 Sub_Group)
{
	u8 Loc_u8_Piriority = (Group) |( Sub_Group<<Confg_Group_Sub_Group -0x05FA030/*Base Address *//256 );
	
	
	if (INT_ID>=0)
	{
	NVIC ->NVIC_IPR[INT_ID]= Loc_u8_Piriority<<4;
	}
	else if ((INT_ID ==  UsageFault)||(INT_ID ==  BusFault)|| (INT_ID ==  MemManage))
	{
		INT_ID+=3;
		SCB->SCB_SHPR1= Loc_u8_Piriority <<((8*INT_ID+4));
		
	}
	else if (INT_ID ==  SVCall)
	{
		INT_ID+=7;
		SCB -> SCB_SHPR2 = Loc_u8_Piriority << (8*INT_ID+4) /*28*/ ; 
	}
	else if ((INT_ID ==PendSV)||(INT_ID == SysTick))
	{
		INT_ID+=8;
		SCB ->SCB_SHPR3 = Loc_u8_Piriority<<(8*INT_ID+4);
		
	}
		
}


void MNVIC_Perhiral_Enable(u8 INT_ID)
{
	NVIC->NVIC_ISER[INT_ID/32]=(1<<(INT_ID%32));
}



void MNVIC_Perhiral_Disable(u8 INT_ID)
{
	NVIC->NVIC_ICER[INT_ID/32]=(1<<(INT_ID%32));
}


void MNVIC_Set_Pending(u8 INT_ID)
{
	
	NVIC->NVIC_ISPR[INT_ID/32]=(1<<(INT_ID%32));
}



void MNVIC_clear_Pending(u8 INT_ID)
{
	NVIC->NVIC_ICPR[INT_ID/32]=(1<<(INT_ID%32));
}



u8 MNVIC_GetActive(u8 INT_ID)
{
	u8 Loc_Var=0;
	Loc_Var=read_bit(NVIC->NVIC_IABR[INT_ID/32],INT_ID%32);
	return Loc_Var;
}
