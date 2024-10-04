/***************************************************************************************************/
/**************************************Layer : MCAL****************************************/
/**************************************Ver : 01****************************************/
/**************************************Component : CLCD****************************************/
/**************************************Auter : Hadeer Adel****************************************/
/******************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define lcd_SetCursor                 0x80
#define lcd_CGRAM                     0x40 

#define CLCD_ROW_1   1
#define CLCD_ROW_2   2

#define CLCD_COL_1   1
#define CLCD_COL_2   2
#define CLCD_COL_3   3
#define CLCD_COL_4   4
#define CLCD_COL_5   5
#define CLCD_COL_6   6
#define CLCD_COL_7   7
#define CLCD_COL_8   8
#define CLCD_COL_9   9
#define CLCD_COL_10  10
#define CLCD_COL_11  11
#define CLCD_COL_12  12
#define CLCD_COL_13  13
#define CLCD_COL_14  14
#define CLCD_COL_15  15
#define CLCD_COL_16  16


void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendComm(u8 Copy_u8Comm);
void CLCD_voidIntilal(void);
void CLCD_voidClearScrean(void);
void CLCD_voidSendString(const u8 * Copy_u8PtrStr);
void CLCD_voidSetPostion(u8 Copy_u8Row, u8 Copy_u8Col);
//void CLCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Col);



#endif