/*
 * main.c
 *
 *  Created on: Sep 5, 2020
 *      Author: Aya Ramzy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void ahmed (void)
{
	/*Pin A2 High			*/
	MGPIO_voidSetPinValue(GPIOA , PIN2 ,GPIO_HIGH );
	/*Delay for 1 Sec		*/
	MSTK_voidSetBusyWait( 1000000 );

	/*Pin A2 Low			*/
	MGPIO_voidSetPinValue(GPIOA , PIN2 , GPIO_LOW );
	/*Delay for 1 Sec		*/
	MSTK_voidSetBusyWait( 1000000 );

}
void atia (void)
{
	/*Pin A2 High			*/
	MGPIO_voidSetPinValue(GPIOA , PIN3 , GPIO_HIGH );
	/*Delay for 1 Sec		*/
	MSTK_voidSetBusyWait( 1000000 );

	/*Pin A2 Low			*/
	MGPIO_voidSetPinValue(GPIOA , PIN3 , GPIO_LOW );
	/*Delay for 1 Sec		*/
	MSTK_voidSetBusyWait( 1000000 );

}

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2  , 0);
	RCC_voidEnableClock(RCC_APB2  , GPIOA);

	MEXTI_voidSetCallBack(ahmed);
	MEXTI_voidSetCallBack(atia);
	/**		GPIO Direction	**/
		/*		A0 = input =====> PULL UP Resistor	*/
		MGPIO_voidSetPinDirection(GPIOA , PIN0 , INPUT_PULLUP_DOWN);
		MGPIO_voidSetPinValue(GPIOA , PIN0 ,GPIO_HIGH );

		MGPIO_voidSetPinDirection(GPIOA , PIN1 , INPUT_PULLUP_DOWN);
		MGPIO_voidSetPinValue(GPIOA , PIN1 ,GPIO_HIGH );
		/**	A2 ======> OUTPUT  SPEED 2MHZ PUSH PULL 	*/
		MGPIO_voidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN3 , OUTPUT_SPEED_2MHZ_PP);

		MEXTI_voidInit();
		MEXTI_voidSetSignalLatch(LINE0 , FALLING);
		MEXTI_voidSetSignalLatch(LINE1 , FALLING);

		MNVIC_voidSetPriority(6 , 2);
		MNVIC_voidSetPriority(7 , 1);
		MNVIC_voidEnableInterrupt(6);
		MNVIC_voidEnableInterrupt(7);
		//MNVIC_voidSetPendingFlag(6);

		while(1);

		return ;
	}








