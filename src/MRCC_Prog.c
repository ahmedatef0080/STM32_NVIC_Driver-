#include <MRCC/MRCC_Confg.h>
#include <MRCC/MRCC_Interface.h>
#include <MRCC/MRCC_Private.h>
#include "BIT_math.h"
#include "STD_Type.h"

//#define CFGR (*(volatile u32*)0x40021004)
void Set_Clock_Type(void)
{
	#if MRCC_TYPE_CLK == RCC_CLK_HSE_Crystal
	//enable
		MRCC->RCC_CR=0;
		MRCC->RCC_CR=0x00010080;
	//set HSE
		MRCC->RCC_CFGR=0x00000001;


	//wait until HSE Enable 	
	while ((Read_bit(MRCC -> RCC_CR,17))==0);
	
	#endif	
	
	#if MRCC_TYPE_CLK == RCC_CLK_HSE_RC
	//set HSE
		MRCC->RCC_CFGR=0x00000001;
	//enable	
		MRCC->RCC_CR.HSEON=0x0010080;//0x0001
	// bypass RC 	
		MRCC -> RCC_CR=0x00050080;
		
	//wait until HSE Enable 	
	while (Read_bit(MRCC ->RCC_CR,17)==0);
	
	#endif
	
	#if MRCC_TYPE_CLK == RCC_CLK_HSI
		//Enable HSI 
		MRCC -> RCC_CR=0x00000081;
		while (Read_bit(MRCC -> RCC_CR,1)==0);
		//set HSI 
		MRCC->RCC_CFGR=0x00000000;
		
	

	#endif
	
	
	
	#if MRCC_TYPE_CLK == RCC_CLK_PLL
		MRCC->RCC_CFGR=0x00000000;//set HSI
		MRCC -> RCC_CR=0x00000081;//enable HSI 
		MRCC->RCC_CFGR=0x00000002; // SET PLL
		//MRCC -> RCC_CR=0x00010080; // enable HSE 
		#if(MRCC_MULTI_FACTOR >=PLL_MULT_Factor_2 && MRCC_MULTI_FACTOR <= PLL_MULT_Factor_16)
			MRCC ->RCC_CFGR &= ~(0b111<<18);
			MRCC ->RCC_CFGR |= (MRCC_MULTI_FACTOR<<18);
		#endif
		
			
		#if MRCC_TYPE_CLK == PLL_HSI_2
		
			clear_bit( MRCC -> RCC_CFGR,16); // HSI/2 Enable 
			
		#elif MRCC_TYPE_CLK == PLL_HSE_2
			set_bit(MRCC -> RCC_CR,16); // HSE Enable 
			set_bit( MRCC -> RCC_CFGR,16);//HSE CLK as PLL
			set_bit(MRCC -> RCC_CFGR,17); //HSE/2
		#else
			set_bit(MRCC -> RCC_CR,16); // HSE Enable 
			set_bit( MRCC -> RCC_CFGR,16);//HSE CLK as PLL
			clear_bit(MRCC -> RCC_CFGR,17); //HSE/2
		
		#endif
		set_bit(MRCC -> RCC_CR , 24); // PLL Enable 
		
		while((Read_bit(MRCC -> RCC_CR,25))==0);
	
	#endif


	#if MRCC_CS_SYS== RCC_CS_Enable
		set_bit(MRCC -> RCC_CR,19);
	
	#else
		clear_bit(MRCC -> RCC_CR,19)=0;
	
	#endif
	

	
	
	
}
//#define RCC_APB2 (*(volatile u32 *)0x40021018)
void Set_clock_For_Perhphiral(u8 Bus,u8 Perphiral)
{
	switch(Bus)
	{
		case AHB_Bus:
			set_bit(MRCC -> RCC_AHBENR, Perphiral);
			break;
		case APB1_Bus :
			set_bit(MRCC -> RCC_APB1ENR, Perphiral);

			break;
		case APB2_Bus :
			set_bit(MRCC ->RCC_APB2ENR , Perphiral);
			break;
	}
}

















/*
		start up code by default by5osh y3ml switch mn HSI to PLL 
		fa kda ana msh h3rf 23ml edit fe config bt3t el PLL
		fa kda h3ml switch 3la el (CLK sys tani ) ex:HSI 3shan 23rf 23ml edi l el PLL w b3d kda arg3 23ml enable l el PLL 
		
		


*/
