#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
#include "STD_Type.h"

void MNVIC_VoidINIT(void);

void MNVIC_Piriorty_Set(s8 INT_ID, u8 Group, u8 Sub_Group);

 

void MNVIC_Perhiral_Enable(u8 INT_ID);



void MNVIC_Perhiral_Disable(u8 INT_ID);


void MNVIC_Set_Pending(u8 INT_ID);



void MNVIC_clear_Pending(u8 INT_ID);



u8 MNVIC_GetActive(u8 INT_ID);



#endif
