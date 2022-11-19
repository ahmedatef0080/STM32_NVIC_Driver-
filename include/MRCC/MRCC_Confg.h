#ifndef  _MRCC_Config_H_
#define  _MRCC_Config_H_
	

	/*
			RCC_CLK_HSE_Crystal    
		00	RCC_CLK_HSI            
		01	RCC_CLK_HSE_RC        
		10	RCC_CLK_PLL            
	
	*/



#define MRCC_TYPE_CLK      RCC_CLK_HSE_Crystal


#if MRCC_TYPE_CLK == RCC_CLK_PLL
	/*
		PLL_HSI_2                  0
		PLL_HSE_2                  1
		PLL_HSE                    2
	*/

	#define MRCC_PLL_CLK_TYPE  PLL_HSE
	
		/*
		PLL_MULT_Factor_2           0
		PLL_MULT_Factor_3           1
		PLL_MULT_Factor_4           2
		PLL_MULT_Factor_5           3
		PLL_MULT_Factor_6           4
		PLL_MULT_Factor_7           5
		PLL_MULT_Factor_8           6
		PLL_MULT_Factor_9           7
		PLL_MULT_Factor_10          8
		PLL_MULT_Factor_11          9
		PLL_MULT_Factor_12          10
		PLL_MULT_Factor_13          11
		PLL_MULT_Factor_14          12
		PLL_MULT_Factor_15          13
		PLL_MULT_Factor_16          14
		*/
	
	#define MRCC_MULTI_FACTOR PLL_MULT_Factor_2
		

#endif




#define MRCC_CS_SYS   RCC_CS_Enable

#endif


