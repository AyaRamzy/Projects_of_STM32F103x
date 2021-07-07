/***********************************************************************/
/* Author      : Aya Ramzy                                             */
/* Date        : 19 August 2020                                        */
/* Version     : V01                                                   */
/***********************************************************************/

#ifndef   NVIC_INTERFACE_H
#define   NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt   (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag    (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag  (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag         (u8 Copy_u8IntNumber);
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority  (u8 Copy_u8PeripheralIdx,u8 Copy_u8Priority);
//void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8Sub_priority , u32 Copy_u32Group);

#define GROUP3   0x05FA0300  // 4 bits for group (IPR) => group
#define GROUP4   0x05FA0400  // 3 bits for group and 1 bit for sub 
#define GROUP5   0x05FA0500  // 2 bits for group and 2 bits for sub
#define GROUP6   0x05FA0600  // 1 bits for group and 3 bits for sub
#define GROUP7   0x05FA0700  // 0 bits for group and 4 bits for sub




#endif
