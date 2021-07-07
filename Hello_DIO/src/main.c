/*
 * main.c

 *
 *  Created on: Aug 15, 2020
 *      Author: Aya Ramzy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#define PORT_CRL  *((u32*)0x40010800)
#define PORT_ODR  *((u32*)0x4001080C)


void main(void)
{
	/*Initialize clock system */
	RCC_voidInitSysClock();

	/*Enable peripherals 2 on APB2 bus (GPIOA) */
	RCC_voidEnableClock(RCC_APB2 , 2);

	/* Configure A0 as output Push Pull */
	PORT_CRL = 0x00000002;
	/* Set A0 output high */
	PORT_ODR = 0x00000001;





	while(1)
	{
	}

}



