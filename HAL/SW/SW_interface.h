/*
* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
* Author : Hadeer Adel Hassan
* Layer  : HAL
* SWC    : SW
*
*/

#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_

typedef struct
{
	u8 port;
	u8 pin;
	u8 pull_state;
}SW;

#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

#define SW_INT_PULL_UP     0
#define SW_EXT_PULL_UP     1
#define SW_EXT_PULL_DOWN   2
#define SW_FLOATING        3

void SW_voidInit     (SW SW_config);
u8   SW_u8GetPressed (SW SW_config);





#endif