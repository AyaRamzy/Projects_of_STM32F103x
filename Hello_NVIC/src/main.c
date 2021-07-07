/*

 * main.c
 *
 *  Created on: Aug 30, 2020
 *      Author: Aya Ramzy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"

void main(void)
{
	/* initialize clock */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA clock */

	/* Pin Modes */
	MGPIO_voidSetPinDirection(GPIOA ,PIN0 ,0b0010); // A0 output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA ,PIN1 ,0b0010); // A1 output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA ,PIN2 ,0b0010); // A2 output PP 2MHz */

	/* Initialize NVIC*/
	MNVIC_voidInit();

	MNVIC_voidSetPriority(6,0b01000000); /* EXTI 0 Group 1 Sub 0 */
	MNVIC_voidSetPriority(7,0b00110000); /* EXTI 1 Group 0 Sub 3 */

	/* Enable EXTI0 interrupt from */
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);
	MNVIC_voidSetPendingFlag(6);

	while(1)
	{

	}

}


void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA , PIN0 ,GPIO_HIGH);
	MNVIC_voidSetPendingFlag(7);
	MGPIO_voidSetPinValue(GPIOA , PIN1 ,GPIO_HIGH);

}
void EXTI1_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA , PIN2 ,GPIO_HIGH);

}

