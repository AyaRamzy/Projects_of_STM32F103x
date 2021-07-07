/***********************************************************************/
/* Author      : Aya Ramzy                                             */
/* Date        : 23 Sep 2020                                        */
/* Version     : V01                                                  */
/***********************************************************************/

#ifndef LEDM_INTERFACE_H
#define LEDM_INTERFACE_H
void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);
void HLEDMRX_voidAnimation(u8 *Copy_u8Data);
void HLEDMRX_voidAnimateFrames(u8 Copy_u8FramesVal[][8], u8 Copy_u8FramesNum);
void HLEDMRX_voidPauseAnimating(void);
void HLEDMRX_voidResumeAnimating(void);
void HLEDMRX_voidSpeedDown(void);
void HLEDMRX_voidSpeedUp(void);


#endif