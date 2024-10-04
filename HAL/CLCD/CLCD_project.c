#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define  F_CPU 8000000
#include "util/delay.h"
#include "DIO_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"


void CLCD_voidSendData(u8 Copy_u8Data)
{
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,RS,DIO_PIN_HIGH);
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,RW,DIO_PIN_LOW);
	DIO_voidSetPortVal(CLCD_DATA_PORT,Copy_u8Data);
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,EN,DIO_PIN_LOW);
	_delay_ms(1);
}

void CLCD_voidSendComm(u8 Copy_u8Comm)
{
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,RS,DIO_PIN_LOW);
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,RW,DIO_PIN_LOW);
	DIO_voidSetPortVal(CLCD_DATA_PORT,Copy_u8Comm);
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(CLCD_CONTRIL_PORT,EN,DIO_PIN_LOW);
	_delay_ms(1);
}

void CLCD_voidIntilal(void)
{
	_delay_ms(50);
	DIO_voidSetPortDir (CLCD_DATA_PORT , DIO_PORT_OUTPUT);
	DIO_voidSetPinDir  (CLCD_CONTRIL_PORT, RS , DIO_PIN_OUTPUT);
	DIO_voidSetPinDir  (CLCD_CONTRIL_PORT, RW , DIO_PIN_OUTPUT);
	DIO_voidSetPinDir  (CLCD_CONTRIL_PORT, EN , DIO_PIN_OUTPUT);
	
	CLCD_voidSendComm(0b00111011);
	_delay_ms(5);
	CLCD_voidSendComm(0b00001100);
	_delay_ms(5);
	CLCD_voidClearScrean();
	CLCD_voidSendComm(0b00000110);
	_delay_ms(2);
}

void CLCD_voidSendString (const u8 * Copy_u8PtrStr)
{
	u8 Loc_Iterator = 0;
	while(Copy_u8PtrStr[Loc_Iterator]!='\0')
	{
		CLCD_voidSendData(Copy_u8PtrStr[Loc_Iterator]);
		Loc_Iterator++;
	}
}

void CLCD_voidClearScrean(void)
{
	CLCD_voidSendComm(0b00000001);
	_delay_ms(10);
}

void CLCD_voidSetPostion(u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 LOC_u8data;
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)
	{
		LOC_u8data = lcd_SetCursor ; //first location
	}
	else if(Copy_u8Row == CLCD_ROW_1)
	{
		LOC_u8data = ( (lcd_SetCursor) + (Copy_u8Col-1) );
	}
	else if(Copy_u8Row == CLCD_ROW_2)
	{
		LOC_u8data = ( (lcd_SetCursor) + (64) + (Copy_u8Col-1) );
	}
	CLCD_voidSendComm(LOC_u8data);
	_delay_ms(1);
}

/*void CLCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 LOC_u8Iterator = 0;
	CLCD_voidSendComm(lcd_CGRAM);
	for(LOC_u8Iterator = 0;LOC_u8Iterator<sizeof(CLCD_u8ExtraChar)/sizeof(CLCD_u8ExtraChar[0]);LOC_u8Iterator++)
	{
		CLCD_voidSendData(CLCD_u8ExtraChar[LOC_u8Iterator]);
	}
	CLCD_voidSetPostion(Copy_u8Row,Copy_u8Col);
	for(LOC_u8Iterator = 0;LOC_u8Iterator < 8; LOC_u8Iterator++)
	{
		CLCD_voidSendData(LOC_u8Iterator);
	}
}*/
