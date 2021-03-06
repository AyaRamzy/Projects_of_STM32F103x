/*
 * main.c
 *
 *  Created on: Sep 23, 2020
 *      Author: Aya Ramzy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "IR_interface.h"

#define  FramesNum  11

u8 Frames[FramesNum][8] ={
		{24, 203, 63, 75 , 88 , 32, 0, 0},
		{24, 203, 63, 75 , 152, 16, 0, 0},
		{0,  219, 63, 219, 0  , 8 , 0, 0},
		{0,  219, 63, 219, 0  , 4 , 0, 0},
		{0,  219, 63, 219, 0  , 2 , 0, 0},
		{0,  219, 63, 219, 0  , 1 , 0, 0},
		{0,  219, 63, 219, 0  , 2 , 0, 0},
		{0,  219, 63, 219, 0  , 4 , 0, 0},
		{0,  219, 63, 219, 0  , 8 , 0, 0},
		{24, 203, 63, 75 , 152, 16, 0, 0},
		{24, 203, 63, 75 , 88 , 32, 0, 0}
};




void main (void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);

	/* INIT STK*/
		MSTK_voidInit();

		/*INIT LED MATRIX */
		HLEDMRX_voidInit();
	    /* send data to matrix*/

	while(1){
		HLEDMRX_voidAnimateFrames(Frames, FramesNum);
	}

}


