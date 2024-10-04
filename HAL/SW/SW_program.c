/*
* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
* Author : Hadeer Adel Hassan
* Layer  : HAL
* SWC    : SW
*
*/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"



void SW_voidInit     (SW SW_config)
{
	DIO_voidSetPinDir(SW_config.port, SW_config.pin, DIO_PIN_INPUT);
	if(SW_config.pull_state == SW_INT_PULL_UP)
	{
		DIO_voidSetPinVal(SW_config.port, SW_config.pin, DIO_PIN_HIGH);
	}
}


u8 SW_u8GetPressed      ( SW SW_Config )
{	
		u8 LOC_u8Result = SW_NOT_PRESSED ;
		u8 LOC_u8PinVal = SW_NOT_PRESSED ;
		
		if ( (SW_Config.pull_state == SW_INT_PULL_UP) || (SW_Config.pull_state == SW_EXT_PULL_UP) )
		{
			LOC_u8PinVal = DIO_u8GetPinVal( SW_Config.port , SW_Config.pin );
			
			if (LOC_u8PinVal==0)
			{
				LOC_u8Result = SW_PRESSED ;
			}
			else if (LOC_u8PinVal==1)
			{
				LOC_u8Result = SW_NOT_PRESSED ;
			}

		}
		else if (SW_Config.pull_state == SW_EXT_PULL_DOWN)
		{
			LOC_u8PinVal = DIO_u8GetPinVal( SW_Config.port , SW_Config.pin  );
			
			if (LOC_u8PinVal==0)
			{
				LOC_u8Result = SW_NOT_PRESSED ;
			}
			else if (LOC_u8PinVal==1)
			{
				LOC_u8Result = SW_PRESSED ;
			}
		}
		
		return LOC_u8Result ;
}
