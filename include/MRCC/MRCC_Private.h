#ifndef  _MRCC_Private_H_
#define  _MRCC_Private_H_

#include "STD_Type.h"

/*
typedef struct
{
	volatile u8 HSION:1;//HSI ON/OFF
	volatile u8 RES:1;
	volatile u8 HSIRDY:1;// read only b3d el settling bt2olk 2no tmm yb2a hyrf3 flag 1 
	volatile u8 HSITRIM:5;// btbd2 mn 16 m3ak 32 27tmal 3shan hya 4 bit kol step bt2ll 40khz 2w btzwd 40khz
	volatile u8 HSICAL:8;// Read only lw RC mgbsh el requried Frequancy by3ml hna clibration ll frequancy 
	volatile u8 HSEON:1;// HSE Oscillator 1 ON (Enable External clock )
	volatile u8 HSERDY:1;// Read only set when settling time finished to get the stable CLK 
	volatile u8 HSEBYP:1;// External Clock 0 Crystal 1 RC
	volatile u8 CSSON:1;// CSS Enable/Disable ( this bit check my clock if my clock (HSE) Reduced (Fire interrupt ) turn off HSE and turn on HSI )
	volatile u8 RES_1:4;
	volatile u8 PLLON:1;//PLL Enable if 1 E else 0 =D
	volatile u8 PLLRDY:1;//PLL clock  ready flag (Settling time when it 1 settling time is finished and PLL ready to work) 
	volatile u8 RES_2:6;
	
	
}CR;
*/
/*
typedef struct
{
	volatile u8 SW:2; // set the type of the CLK (00-HSI 01-HSE 10-PLL 11-No allawed)
	volatile u8 SWS:2; //read the status of the CLK 
	volatile u8 HPRE:4; // set the Prescaler for the AHB Bus (MAX 72MHZ)
	volatile u8 PPRE1:3; // set and clear the prescaler (NOTE: MAX 36MHZ for APB1)
	volatile u8 PPRE2:3; // set and clear the precaler (NOTE MAX 72MHZ for APB2)
	volatile u8 ADCPRE:2; // ADC Prescaler 
	volatile u8 PLLSRC:1; //set and clear the PLL entry CLK source if 0 HSI/2 if 1 HSE
	volatile u8 PLLXTRE:1; // first of all i cannot edit in this bit except when PLL is disable  0: HSE clock not divided 1: HSE Clock divided by 2
	volatile u8 PLLMUL:4; // PLL Multiplication factor can be written only when PLL is disabled
	volatile u8 USBPRE:1 // generate 48MHZ USB clock 0 PLL clock is divided by 1.5 1 PLL clk not divided 
	volatile u8 MCO:3;   // Microcontroller clock output (mmkn n3ml share l clk l micro tani b5tar ya 2ma el sysclk ya 2ma el HSE ya 2ma el HSI ya 2ma el PLL)
	volatile u8 RES1:5;
	
	
}CFGR;
*/


typedef struct 
{
	volatile u32 RCC_CR;  // 0x00
	volatile u32 RCC_CFGR; //0x04
	volatile u32 RCC_CIR;  //0x08
	volatile u32 RCC_APB2RSTR; //0x0C
	volatile u32 RCC_APB1RSTR; //0x10
	volatile u32 RCC_AHBENR;   //0x14
	volatile u32 RCC_APB2ENR;   //0x18
	volatile u32 RCC_APB1ENR;  //0x1c
	volatile u32 RCC_BDCR;    //0x20
	
}RCC_Type;



//MRCC->RC.HSION=1;



#define MRCC ((volatile RCC_Type*)0x40021000)

#define RCC_CLK_HSE_Crystal    0
#define RCC_CLK_HSI            1
#define RCC_CLK_HSE_RC         2
#define RCC_CLK_PLL            3


#define PLL_HSI_2                  0
#define PLL_HSE_2                  1
#define PLL_HSE                    2

#define RCC_CS_Enable              1
#define RCC_CS_Disable             0



#define PLL_MULT_Factor_2           0
#define PLL_MULT_Factor_3           1
#define PLL_MULT_Factor_4           2
#define PLL_MULT_Factor_5           3
#define PLL_MULT_Factor_6           4
#define PLL_MULT_Factor_7           5
#define PLL_MULT_Factor_8           6
#define PLL_MULT_Factor_9           7
#define PLL_MULT_Factor_10          8
#define PLL_MULT_Factor_11          9
#define PLL_MULT_Factor_12          10
#define PLL_MULT_Factor_13          11
#define PLL_MULT_Factor_14          12
#define PLL_MULT_Factor_15          13
#define PLL_MULT_Factor_16          14


#endif
