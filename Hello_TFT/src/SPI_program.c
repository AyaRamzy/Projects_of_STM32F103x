/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 18 OCT 2020                            */
/* Version   : V01                                    */
/******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void (*CallBack)(u8);
void MSPI1_voidInit(void)
{
	/* CPOL=1 / CPHA =1 /Prescaller = CLK/2  MSB FIRST*/
	MSPI1->CR1 = 0x0347;
	
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DtaToTransmit, u8 * Copy_DataToReceive)
{
	/* CLR for slave select Pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_LOW);
	
	/* sent data */
	MSPI1 -> DR = Copy_u8DtaToTransmit;
	/* wait Busy flag to finish*/
	while(GET_BIT(MSPI1 -> SR ,7)==1);
	
    /* Return to the receive data */
    * Copy_DataToReceive= MSPI1 -> DR;
	
	/* set slave select pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_HIGH);
}



