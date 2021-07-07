/***********************************************************************/
/* Author      : Aya Ramzy                                             */
/* Date        : 19 August 2020                                        */
/* Version     : V01                                                   */
/***********************************************************************/

// gaurd
#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

/* line and mode */
void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);
void MEXTI_voidSetCallBack(void (*ptr) (void));

#endif