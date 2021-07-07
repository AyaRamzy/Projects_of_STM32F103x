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
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_0,0b0010);//PUSH PULL OUTPUT 2MHz
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_1,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_2,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_3,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_4,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_5,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_6,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_7,0b0010);
		  
		  
	MGPIO_voidSetPinDirection(HLEDMAT_COL_0,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_1,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_2,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_3,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_4,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_5,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_6,0b0010);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_7,0b0010);
}

void HLEDMRX_voidDisplay (u8 *Copy_u8Data)
{
	
	while(1)
	{
	/* column 0 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[0]);
	ActivateColumn(0);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 1 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[1]);
	ActivateColumn(1);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 2 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[2]);
	ActivateColumn(2);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 3 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[3]);
	ActivateColumn(3);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 4 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[4]);
	ActivateColumn(4);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 5 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[5]);
	ActivateColumn(5);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 6 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[6]);
	ActivateColumn(6);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	/* column 7 */
	DisableAllCols();
	SetRowValues(Copy_u8Data[7]);
	ActivateColumn(7);
	MSTK_voidSetBusyWait(2500);//2.5msec
	
	}
} 
static void	HLEDMRX_voidDisplayloop	(u8	* Copy_u8Data, u32 Copy_u32speed)
{
	for (u32 k = 0 ; k < Copy_u32speed ; k++)
	{
		/*	column	0*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 0	*/
		SetRowValues(Copy_u8Data[0]);
		ActivateColumn(0);
		MSTK_voidSetBusyWait(2500);

		/*	column	1*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 1	*/
		SetRowValues(Copy_u8Data[1]);
		ActivateColumn(1);
		MSTK_voidSetBusyWait(2500);

		/*	column	2*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 2	*/
		SetRowValues(Copy_u8Data[2]);
		ActivateColumn(2);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	3*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 3	*/
		SetRowValues(Copy_u8Data[3]);
		ActivateColumn(3);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	4*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 4	*/
		SetRowValues(Copy_u8Data[4]);
		ActivateColumn(4);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	5*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 5	*/
		SetRowValues(Copy_u8Data[5]);
		ActivateColumn(5);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	6*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 6	*/
		SetRowValues(Copy_u8Data[6]);
		ActivateColumn(6);
		MSTK_voidSetBusyWait(2500);
		
		/*	column	7*/
		/*	Disable all Columns	*/
		DisableAllCols ();
		/*	Enable COlumn 7	*/
		SetRowValues(Copy_u8Data[7]);
		ActivateColumn(7);
		MSTK_voidSetBusyWait(2500);
	}
}

void	HLEDMRX_voidDisplayMotion	(u8	* Copy_u8DataLarge ,u32 speed)
{
	u8 Copy_u8DataSmall[8];
	for(u8 i=0 ; i<25 ;i++)
	{
		for(u8 j=0 ; j<8 ;j++)
		{
			Copy_u8DataSmall[j]= Copy_u8DataLarge[i+j];
		}
		HLEDMRX_voidDisplayloop	(Copy_u8DataSmall,speed);
	}
}  
static void DisableAllCols(void)
{
	MGPIO_voidSetPinValue(HLEDMAT_COL_0,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_1,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_2,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_3,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_4,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_5,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_6,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_7,GPIO_HIGH);
	
}	


static void SetRowValues  (u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_0,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_1,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_2,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_3,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_4,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_5,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_6,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_7,Local_u8BIT);
	
}

void ActivateColumn(u8 Copy_u8Col)
{
	/* Disable All */
	MGPIO_voidSetPinValue(HLEDMAT_COL_0,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_1,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_2,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_3,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_4,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_5,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_6,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_7,GPIO_HIGH);
	
	/* Enable the desired pin only */
	switch (Copy_u8Col)
	{
		case 0: MGPIO_voidSetPinValue(HLEDMAT_COL_0,GPIO_LOW); break;
		case 1: MGPIO_voidSetPinValue(HLEDMAT_COL_1,GPIO_LOW); break;
		case 2: MGPIO_voidSetPinValue(HLEDMAT_COL_2,GPIO_LOW); break;
		case 3: MGPIO_voidSetPinValue(HLEDMAT_COL_3,GPIO_LOW); break;
		case 4: MGPIO_voidSetPinValue(HLEDMAT_COL_4,GPIO_LOW); break;
		case 5: MGPIO_voidSetPinValue(HLEDMAT_COL_5,GPIO_LOW); break;
		case 6: MGPIO_voidSetPinValue(HLEDMAT_COL_6,GPIO_LOW); break;
		case 7: MGPIO_voidSetPinValue(HLEDMAT_COL_7,GPIO_LOW); break;
	}
}
