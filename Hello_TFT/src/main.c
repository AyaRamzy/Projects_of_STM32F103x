/*
 * main.c
 *
 *  Created on: Oct 19, 2020
 *      Author: Aya Ramzy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"


#include "TFT_interface.h"
#include "image.h"

void main(void)
{
	/* RcC init*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); //GPIOA
	RCC_voidEnableClock(RCC_APB2,12);//SPI1

	/* Pin Initialization */
	MGPIO_voidSetPinDirection(GPIOA,PIN1,0b0010);  //A0
	MGPIO_voidSetPinDirection(GPIOA,PIN2,0b0010);  //Reset
	MGPIO_voidSetPinDirection(GPIOA,PIN5,0b1001);  //CLK
	MGPIO_voidSetPinDirection(GPIOA,PIN7,0b1001);  // MOsI

	/* Init STK*/
	MSTK_voidInit();

	/* SPI Init */
	MSPI1_voidInit();

	/* TFT INTI*/
	HTFT_voidInitialize();

	/* Display Image */
	//HTFT_voidDisplayImage(image);
	HTFT_voidFillColor ( 0xffff);
	HTFT_voidDrawRect ( 0,10,0,30,0);

	while(1);



}






