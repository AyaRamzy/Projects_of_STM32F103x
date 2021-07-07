/*
 * main.c
 *
 *  Created on: Sep 20, 2020
 *      Author: Aya Ramzy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "HLEDMAT_interface.h"


void main (void)
{
	u8 DataArray[8]={0,124,18,18,18,124,0,0};
	/* RCC init and enable*/
	RCC_voidDisableClock();
	RCC_voidEnableClock(RCC_APB2,2);//GPIO A
	RCC_voidEnableClock(RCC_APB2,3);//GPIO B

	/* Init Systick */
	MSTK_voidInit();

	/* INIT LED Matrix */
	HLEDMAT_voidInit();

	HLEDMRX_voidDisplay(DataArray);


}






