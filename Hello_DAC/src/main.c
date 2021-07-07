/*
 * main.c
 *
 *  Created on: Sep 27, 2020
 *      Author: Aya Ramzy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "DIO_private.h"

#include "file.h"
volatile u16 i=0;
void voidSetDAC(void)
{
	GPIOA_ODR = aya_raw[i];
	i++;
	if(i==39938)
	{
		i=0;

	}


}

void main(void)
{
	RCC_voidInitSysClock();/* Choose Clock System to HSE 8 MHZ*/
	RCC_voidEnableClock(RCC_APB2,2);/*Enable GPIOA Clock */

	MGPIO_voidSetPinDirection(GPIOA,0,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,1,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,2,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,3,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,4,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,5,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,6,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,7,0b0010);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);

	while(1)
	{

	}


}





