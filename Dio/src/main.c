/*
 * main.c
 *
 *  Created on: Aug 16, 2020
 *      Author: Aya Ramzy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

int  main(void)
{
	RCC_voidInitSysClock();

	/* Enable RCC for GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);

	/* Enable RCC for GPIOB */
    RCC_voidEnableClock(RCC_APB2,3);

	/* Enable RCC for GPIOC */
	RCC_voidEnableClock(RCC_APB2,4);

	/*PINA0 output push pull 10 MHz*/
	MGPIO_voidSetPinDirection(GPIOA , PIN0 ,INPUT_PULLUP_DOWN);
	/* FOR PULL UP*/
	MGPIO_voidSetPinValue(GPIOA , PIN0 ,GPIO_HIGH);
	MGPIO_voidSetPinDirection(GPIOA , PIN1 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN2 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN3 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN4 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN5 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN6 ,OUTPUT_SPEED_10MHZ_PP);

   // u16 w =500 ;
	while(1)
	{
		if(MGPIO_u8GetPinValue(GPIOA,PIN0)==0)
		{
			MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_HIGH);

		}
		else
		{
			MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_LOW);
		}
		/*MGPIO_voidSetPinValue(GPIOA , PIN0 , GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA , PIN1 , GPIO_HIGH);
		MGPIO_voidSetPinValue(GPIOA , PIN2 , GPIO_HIGH);
		MGPIO_voidSetPinValue(GPIOA , PIN3 , GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA , PIN4 , GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA , PIN5 , GPIO_LOW);
		MGPIO_voidSetPinValue(GPIOA , PIN6 , GPIO_LOW);*/

	}


	return 0;
}

/*
 * for(u16 i=0 ; i<w ; i++)
		{
			for(u16 j=0 ; j<w ; j++)
			{
				asm("NOP");
			}
		}

		MGPIO_voidSetPinDirection(GPIOA , PIN0 , GPIO_LOW);
		for(u16 i=0 ; i<w ; i++)
		{
			for(u16 j=0 ; j<w ; j++)
			{
				asm("NOP");
			}
		}
 *
 * */


