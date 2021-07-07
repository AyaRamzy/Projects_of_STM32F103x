/*
 * main.c
 *
 *  Created on: Sep 21, 2020
 *      Author: Aya Ramzy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"

u8 DataArray[8]={0, 124, 18, 18, 18, 124, 0, 0};
void main (void)
{

	/* Init RCC and Enable */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);

	/* INIT STK*/
	MSTK_voidInit();

	/*INIT LED MATRIX */
	HLEDMAT_voidInit();
    /* send data to matrix*/
	HLEDMRX_voidDisplay(DataArray);


}




