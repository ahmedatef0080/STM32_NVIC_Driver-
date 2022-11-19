#include <MGPIO/MGPIO_Interface.h>
#include <MGPIO/MGPIO_Private.h>
#include "STD_Type.h"
#include "BIT_math.h" 


//#define CRLl (*(volatile u32*)0x40010800)
void SET_PIN_DIRECTION(u8 port ,u8 pin,u8 mode)
{
	switch (port)
	{	
		case MGPIOA:
			if(pin<=7)
			{
				MGPIO_A ->CRL &= ~(0b1111<<(pin*4));
				MGPIO_A ->CRL |=(mode<<( pin *4));
			}
			else if ((pin>7)&&(pin<=15))
			{
				pin-=8;
				MGPIO_A ->CRH &= ~(0b1111<<(pin*4));
				MGPIO_A ->CRH |=(mode<<( pin *4));
			}
		break;
			case MGPIOB:
			if(pin<=7)
			{
				MGPIO_B ->CRL &= ~(0b1111<<(pin*4));
				MGPIO_B ->CRL |=(mode<<( pin *4));
			}
			else if ((pin>7)&&(pin<=15))
			{
				pin-=8;
				MGPIO_B ->CRH &= ~(0b1111<<(pin*4));
				MGPIO_B ->CRH |=(mode<<( pin *4));
			}
		break;
			case MGPIOC:
			if(pin<=7)
			{
				MGPIO_C ->CRL &= ~(0b1111<<(pin*4));
				MGPIO_C ->CRL |=(mode<<( pin *4));
			}
			else if ((pin>7)&&(pin<=15))
			{
				pin-=8;
				MGPIO_C ->CRH &= ~(0b1111<<(pin*4));
				MGPIO_C ->CRH |=(mode<<( pin *4));
			}
		break;
		default:
		break;	
}
	}
//#define ODRR (*(volatile u32*)0x4001080C)
void SET_PIN_VALUE(u8 port , u8 pin , u8 Value)
{
	if (Value == MGPIO_PIN_HIGH)
	{
				switch(port)
				{
					case MGPIOA:
					set_bit(MGPIO_A->ODR,pin);
					break;
					case MGPIOB:
					set_bit(MGPIO_B ->ODR,pin);
					break;
					case MGPIOC:
						set_bit(MGPIO_C -> ODR,pin);
					break;
					default:
					break;
				}

			
			}
	else if (Value == MGPIO_PIN_LOW)
	{
			switch(port)
			{
				case MGPIOA:
					clear_bit(MGPIO_A ->ODR,pin);
				break;
				case MGPIOB:
					clear_bit(MGPIO_B ->ODR,pin);
				break;
				case MGPIOC:
					clear_bit(MGPIO_C -> ODR,pin);
				break;
				
			}
		
	}
}

u8 Read_PIN(u8 port , u8 pin)
{
	u8 LOC_Var=0;
	switch(port)
	{

	case(MGPIOA):	LOC_Var=read_bit(MGPIO_A->IDR,pin);break;
	case(MGPIOB):	LOC_Var=read_bit(MGPIO_B->IDR,pin);break;
	case(MGPIOC):	LOC_Var=read_bit(MGPIO_C->IDR,pin);break;
	}
	return LOC_Var;
}
void BSRR_SET_RESET_PIN_OUTPUT(u8 port ,u8 pin, u8 mode)
{
	if(mode == MGPIO_PIN_HIGH)
	{
	switch (port)
	{	
	case  MGPIOA:
		MGPIO_A -> BSRR =(1<<pin);
		break;
	case MGPIOB:
		MGPIO_B -> BSRR =(1<<pin);
		break;
	case MGPIOC:
		MGPIO_C -> BSRR =(1<<pin);
		break;
	default:
		break;
	}
}
	else if (mode == MGPIO_PIN_LOW)
	{
		switch (port)
		{	
	case  MGPIOA:
		MGPIO_A -> BSRR =(1<<(pin+16));
		break;
	case MGPIOB:
		MGPIO_B -> BSRR =(1<<(pin+16));
		break;
	case MGPIOC:
		MGPIO_C -> BSRR =(1<<(pin+16));
		break;
	default:
		break;
	}	
}
	

}
void BRR_RESET_PIN_OUTPUT(u8 port ,u8 pin)
{
	switch(port)
	{
		case MGPIOA:
			MGPIO_A ->BRR =(1<<pin);
			break;
		case MGPIOB:
			MGPIO_B ->BRR =(1<<pin);
			break;	
		case MGPIOC:
			MGPIO_C ->BRR =(1<<pin);
			break;
		default:
			break;	
	}
}
