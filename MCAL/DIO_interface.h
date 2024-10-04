/*
* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
* Author : Hadeer Adel Hassan
* Layer  : MCAL
* SWC    : DIO/GPIO
*
*/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_






void DIO_voidSetPinDir (u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8dir);
void DIO_voidSetPinVal (u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8val);
u8   DIO_u8GetPinVal   (u8 Copy_u8port, u8 Copy_u8pin               );
void DIO_voidTogPinVal (u8 Copy_u8port, u8 Copy_u8pin               );
void DIO_voidSetPortDir(u8 Copy_u8port, u8 Copy_u8dir               );
void DIO_voidSetPortVal(u8 Copy_u8port, u8 Copy_u8val               );
u8   DIO_u8GetPortVal  (u8 Copy_u8port                              );
void DIO_voidTogPortVal(u8 Copy_u8port                              );
void DIO_voidWriteLowNibbles(u8 Copy_u8port, u8 Copy_u8val          );
void DIO_voidWriteHighNibbles(u8 Copy_u8port, u8 Copy_u8val         );
void DIO_voidEnablePullUp(u8 Copy_u8port, u8 Copy_u8pin             );
void DIO_voidDisableInternalPullUp(void                             );


#define DIO_PIN_OUTPUT  1
#define DIO_PIN_INPUT   0

#define DIO_PIN_HIGH    1
#define DIO_PIN_LOW     0

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0

#define DIO_PORT_HIGH   0xff
#define DIO_PORT_LOW    0

#define DIO_PORTA       0
#define DIO_PORTB       1
#define DIO_PORTC       2
#define DIO_PORTD       3

#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7

#define PUD             2

#endif
