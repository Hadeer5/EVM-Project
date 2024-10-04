/*
* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
* Author : Hadeer Adel Hassan
* Layer  : MCAL
* SWC    : DIO/GPIO
*
*/


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"






void DIO_voidSetPinDir(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8dir)
{
	if(Copy_u8dir == DIO_PIN_OUTPUT)
	{
		switch(Copy_u8port)
		{
			case DIO_PORTA:SET_BIT(DDRA,Copy_u8pin);break;
			case DIO_PORTB:SET_BIT(DDRB,Copy_u8pin);break;
			case DIO_PORTC:SET_BIT(DDRC,Copy_u8pin);break;
			case DIO_PORTD:SET_BIT(DDRD,Copy_u8pin);break;
		}
	}
	else if(Copy_u8dir == DIO_PIN_INPUT)
	{
		switch(Copy_u8port)
		{
			case DIO_PORTA:CLR_BIT(DDRA,Copy_u8pin);break;
			case DIO_PORTB:CLR_BIT(DDRB,Copy_u8pin);break;
			case DIO_PORTC:CLR_BIT(DDRC,Copy_u8pin);break;
			case DIO_PORTD:CLR_BIT(DDRD,Copy_u8pin);break;
		}
	}
}
void DIO_voidSetPinVal(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8val)
{
	if(Copy_u8val == DIO_PIN_HIGH)
	{
		switch(Copy_u8port)
		{
			case DIO_PORTA:SET_BIT(PORTA,Copy_u8pin);break;
			case DIO_PORTB:SET_BIT(PORTB,Copy_u8pin);break;
			case DIO_PORTC:SET_BIT(PORTC,Copy_u8pin);break;
			case DIO_PORTD:SET_BIT(PORTD,Copy_u8pin);break;
		}
	}
	else if(Copy_u8val == DIO_PIN_LOW)
	{
		switch(Copy_u8port)
		{
			case DIO_PORTA:CLR_BIT(PORTA,Copy_u8pin);break;
			case DIO_PORTB:CLR_BIT(PORTB,Copy_u8pin);break;
			case DIO_PORTC:CLR_BIT(PORTC,Copy_u8pin);break;
			case DIO_PORTD:CLR_BIT(PORTD,Copy_u8pin);break;
		}
	}
}
u8   DIO_u8GetPinVal  (u8 Copy_u8port, u8 Copy_u8pin               )
{
	u8 Local_u8Val = 0; 
	switch(Copy_u8port)
		{
			case DIO_PORTA:Local_u8Val=GET_BIT(PINA,Copy_u8pin);break;
			case DIO_PORTB:Local_u8Val=GET_BIT(PINB,Copy_u8pin);break;
			case DIO_PORTC:Local_u8Val=GET_BIT(PINC,Copy_u8pin);break;
			case DIO_PORTD:Local_u8Val=GET_BIT(PIND,Copy_u8pin);break;
		}
		
		return Local_u8Val;
}
void DIO_voidTogPinVal(u8 Copy_u8port, u8 Copy_u8pin               )
{
	switch(Copy_u8port)
		{
			case DIO_PORTA:TOG_BIT(PINA,Copy_u8pin);break;
			case DIO_PORTB:TOG_BIT(PINB,Copy_u8pin);break;
			case DIO_PORTC:TOG_BIT(PINC,Copy_u8pin);break;
			case DIO_PORTD:TOG_BIT(PIND,Copy_u8pin);break;
		}
}

void DIO_voidSetPortDir(u8 Copy_u8port, u8 Copy_u8dir               )
{
	switch(Copy_u8port)
		{
			case DIO_PORTA:DDRA=Copy_u8dir;break;
			case DIO_PORTB:DDRB=Copy_u8dir;break;
			case DIO_PORTC:DDRC=Copy_u8dir;break;
			case DIO_PORTD:DDRD=Copy_u8dir;break;
		}
}
void DIO_voidSetPortVal(u8 Copy_u8port, u8 Copy_u8val               )
{
	switch(Copy_u8port)
		{
			case DIO_PORTA:PORTA=Copy_u8val;break;
			case DIO_PORTB:PORTB=Copy_u8val;break;
			case DIO_PORTC:PORTC=Copy_u8val;break;
			case DIO_PORTD:PORTD=Copy_u8val;break;
		}
}
u8   DIO_u8GetPortVal  (u8 Copy_u8port                              )
{
	u8 Local_u8Val = 0; 
	switch(Copy_u8port)
		{
			case DIO_PORTA:Local_u8Val=PINA;break;
			case DIO_PORTB:Local_u8Val=PINB;break;
			case DIO_PORTC:Local_u8Val=PINC;break;
			case DIO_PORTD:Local_u8Val=PIND;break;
		}
		
		return Local_u8Val;
}
void DIO_voidTogPortVal(u8 Copy_u8port                              )
{
	switch(Copy_u8port)
		{
			case DIO_PORTA:PORTA=~PORTA;break;
			case DIO_PORTB:PORTB=~PORTB;break;
			case DIO_PORTC:PORTC=~PORTC;break;
			case DIO_PORTD:PORTD=~PORTD;break;
		}
}


void DIO_voidWriteLowNibbles(u8 Copy_u8port, u8 Copy_u8val          )
{
	Copy_u8val&=0x0f;
	switch (Copy_u8port)
	{
		
		case DIO_PORTA:
		PORTA&=0xf0;
		PORTA|=Copy_u8val;
		break;
		case DIO_PORTB:
		PORTB&=0xf0;
		PORTB|=Copy_u8val;
		break;
		case DIO_PORTC:
		PORTC&=0xf0;
		PORTC|=Copy_u8val;
		break;
		case DIO_PORTD:
		PORTD&=0xf0;
		PORTD|=Copy_u8val;
		break;

	}
}
void DIO_voidWriteHighNibbles(u8 Copy_u8port, u8 Copy_u8val         )
{
	Copy_u8val<<=4;
	switch (Copy_u8port)
	{
		
		case DIO_PORTA:
		PORTA&=0x0f;
		PORTA|=Copy_u8val;
		break;
		case DIO_PORTB:
		PORTB&=0x0f;
		PORTB|=Copy_u8val;
		break;
		case DIO_PORTC:
		PORTC&=0x0f;
		PORTC|=Copy_u8val;
		break;
		case DIO_PORTD:
		PORTD&=0x0f;
		PORTD|=Copy_u8val;
		break;

	}
}

void DIO_voidEnablePullUp(u8 Copy_u8port,u8 Copy_u8pin              )
{
	DIO_voidSetPinDir(Copy_u8port,Copy_u8pin,DIO_PIN_INPUT);
	switch(Copy_u8port)
	{
		case DIO_PORTA:SET_BIT(PORTA,Copy_u8pin);break;
		case DIO_PORTB:SET_BIT(PORTB,Copy_u8pin);break;
		case DIO_PORTC:SET_BIT(PORTC,Copy_u8pin);break;
		case DIO_PORTD:SET_BIT(PORTD,Copy_u8pin);break;
	}
}

void DIO_voidDisableInternalPullUp(void                             )
{
	SET_BIT(SFIOR,2);
}