/***********************************************************************/
/* Author      : Aya Ramzy                                             */
/* Date        : 31 August 2020                                        */
/* Version     : V01                                                   */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

void HLEDMAT_voidInit(void)
{
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_0,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_1,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_2,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_3,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_4,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_5,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_6,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_7,0b0010);
		  
		  
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_0,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_1,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_2,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_3,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_4,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_5,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_6,0b0010);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_7,0b0010);
}

void HLEDMRX_voidDisplay (u8 *Copy_u8Data)
{
	while(1)
	{
	/* column 0 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[0]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_0,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 1 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[1]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_1,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 2 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[2]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_2,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 3 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[3]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_3,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 4 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[4]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_4,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 5 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[5]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_5,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 6 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[6]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_6,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 7 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[7]);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_7,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);//2.5msec
	}
	
	
}   
static void DisableAllCols(void)
{
	MGPIO_VoidSetPinValue(HLEDMAT_COL_0,GPIO_HIGH);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_1,GPIO_HIGH);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_2,GPIO_HIGH);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_3,GPIO_HIGH);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_4,GPIO_HIGH);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_5,GPIO_HIGH);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_6,GPIO_HIGH);
	MGPIO_VoidSetPinValue(HLEDMAT_COL_7,GPIO_HIGH);
	
}	



static void SetRowsValue  (u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	Local_u8BIT==GET_BIT(Copy_u8Data[0],0);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_0,Copy_u8Value[0]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_1,Copy_u8Value[1]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_2,Copy_u8Value[2]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_3,Copy_u8Value[3]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_4,Copy_u8Value[4]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_5,Copy_u8Value[5]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_6,Copy_u8Value[6]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_7,Copy_u8Value[7]);
}

void ActivateColumn(u8 Copy_u8Col)
{
	/* Disable All */
	MGPIO_VidSetPinValue(HLEDMAT_COL_0,GPIO_HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_1,GPIO_HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_2,GPIO_HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_3,GPIO_HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_4,GPIO_HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_5,GPIO_HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_6,GPIO_HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_7,GPIO_HIGH);
	
	/* Enable the desired pin only */
	switch (Copy_u8Col)
	{
		case 0: MGPIO_VidSetPinValue(HLEDMAT_COL_0,GPIO_LOW ); break;
		case 1: MGPIO_VidSetPinValue(HLEDMAT_COL_1,GPIO_LOW ); break;
		case 2: MGPIO_VidSetPinValue(HLEDMAT_COL_2,GPIO_LOW ); break;
		case 3: MGPIO_VidSetPinValue(HLEDMAT_COL_3,GPIO_LOW ); break;
		case 4: MGPIO_VidSetPinValue(HLEDMAT_COL_4,GPIO_LOW ); break;
		case 5: MGPIO_VidSetPinValue(HLEDMAT_COL_5,GPIO_LOW ); break;
		case 6: MGPIO_VidSetPinValue(HLEDMAT_COL_6,GPIO_LOW ); break;
		case 7: MGPIO_VidSetPinValue(HLEDMAT_COL_7,GPIO_LOW ); break;
	}
}
