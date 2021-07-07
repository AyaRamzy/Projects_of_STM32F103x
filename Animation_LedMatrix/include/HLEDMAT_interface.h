/***********************************************************************/
/* Author      : Aya Ramzy                                             */
/* Date        : 31 August 2020                                        */
/* Version     : V01                                                   */
/***********************************************************************/

#ifndef HLEDMAT_INTERFACE_H
#define HLEDMAT_INTERFACE_H

void HLEDMAT_voidInit(void);
void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame);
void HLEDMRX_voidDisplay (u8 *Copy_u8Data);
void HLEDMRX_voidDisplayMotion	(u8	* Copy_u8DataLarge ,u32 speed);

#endif
