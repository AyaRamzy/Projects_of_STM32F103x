/*
 * main.c
 *
 *  Created on: Oct 2, 2020
 *      Author: asss5
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "UART_interface.h"

#include "ESP_interface.h"



void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , IOPA_EN);
	RCC_voidEnableClock(RCC_APB2 , 14);

	DIO_voidSetDirection(GPIOA , 9 , OUTPUT_PP_50MHZ);  // TX
	DIO_voidSetDirection(GPIOA , 10 , INPUT_FLOATING);  // RX
	DIO_voidSetDirection(GPIOA , 0 ,OUTPUT_PP_2MHZ);

	MUSART1_voidInit();
    HESP_voidInit();

    HESP_voidWifiConnect("Orange-Ahmed","ahmed9643*@*#");
    HESP_voidWifiServerUrlTCP("162.253.155.226","80");

    volatile u8 X;
	while(1)
	{
		X = HESP_u8SendReceiveData(48,"http://webseeka.freevar.com/status.txt");  // 42 -> Length of URL  + 6 -> Length of "GET " + "\r\n"

				if(X == '1')
				{
					DIO_voidSetValue(GPIOA,0,GPIO_HIGH);
				}
				else if( X == '0')
				{
					DIO_voidSetValue(GPIOA,0,GPIO_LOW);
				}

				HESP_voidWifiServerUrlTCP("162.253.155.226","80");
	}
}

