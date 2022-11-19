#include <NVIC/NVIC_CONF.h>
#include <NVIC/NVIC_Interface.h>
#include <NVIC/NVIC_Private.h>

#include <MRCC/MRCC_Confg.h>
#include <MRCC/MRCC_Interface.h>
#include <MRCC/MRCC_Private.h>

#include <MGPIO/MGPIO_Interface.h>

#include "STD_Type.h"


void EXTI0_IRQHandler(void)
{
	SET_PIN_VALUE(MGPIOC,MGPIO_PIN13,MGPIO_PIN_HIGH);
}

int main()
{
	Set_Clock_Type();
	Set_clock_For_Perhphiral(APB2_Bus,GPIO_C_EN);

	SET_PIN_DIRECTION(MGPIOC,MGPIO_PIN13,OUT_PUT_PUSH_PULL_MODE_2_MHZ);
	SET_PIN_VALUE(MGPIOC,MGPIO_PIN13,MGPIO_PIN_LOW);





	MNVIC_Perhiral_Enable(EXTI0);
	MNVIC_Set_Pending(EXTI0);


	MNVIC_Perhiral_Enable(EXTI1);
	MNVIC_Set_Pending(EXTI1);





	while (1)
	{

	}
}
