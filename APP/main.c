/*
 * Voting.c
 *
 * Created: 23/09/2024 11:50:12 م
 * Author : Admin
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "SW_interface.h"

u8 counter1=0;
u8 counter2=0;
u8 counter3=0;
u8 counter4=0;


int main(void)
{
	CLCD_voidIntilal();
	SW sw1={DIO_PORTB,DIO_PIN3,SW_EXT_PULL_DOWN};
	SW sw2={DIO_PORTB,DIO_PIN4,SW_EXT_PULL_DOWN};
	SW sw3={DIO_PORTB,DIO_PIN5,SW_EXT_PULL_DOWN};
	SW sw4={DIO_PORTB,DIO_PIN6,SW_EXT_PULL_DOWN};
	SW sw5={DIO_PORTB,DIO_PIN7,SW_EXT_PULL_DOWN};				
	SW_voidInit(sw1);
	SW_voidInit(sw2);
	SW_voidInit(sw3);
	SW_voidInit(sw4);
	SW_voidInit(sw5);
	
	CLCD_voidSetPostion(1,1);
	_delay_ms(2);
	CLCD_voidSendString("A=0");
	CLCD_voidSetPostion(1,12);
	CLCD_voidSendString("B=0");
	CLCD_voidSetPostion(2,1);
	CLCD_voidSendString("C=0");
	CLCD_voidSetPostion(2,12);
	CLCD_voidSendString("D=0");
	
    while (1) 
    {
		if(SW_u8GetPressed(sw1) == SW_PRESSED)
		{
			counter1++;
			CLCD_voidSetPostion(1,3);
			if (counter1<10)
			{
				CLCD_voidSendData(counter1+48);
			}
			else if (counter1<100)
			{
				CLCD_voidSendData(counter1/10+48);
				CLCD_voidSendData(counter1%10+48);
			}
			else if (counter1<1000)
			{
				CLCD_voidSendData(counter1/100+48);
				CLCD_voidSendData((counter1/10)%10+48);
				CLCD_voidSendData(counter1%10+48);
			}
		}
		
		else if(SW_u8GetPressed(sw2) == SW_PRESSED)
		{
			counter2++;
			CLCD_voidSetPostion(1,14);
			if (counter2<10)
			{
				CLCD_voidSendData(counter2+48);
			}
			else if (counter2<100)
			{
				CLCD_voidSendData(counter2/10+48);
				CLCD_voidSendData(counter2%10+48);
			}
			else if (counter2<1000)
			{
				CLCD_voidSendData(counter2/100+48);
				CLCD_voidSendData((counter2/10)%10+48);
				CLCD_voidSendData(counter2%10+48);
			}
		}
		
		else if(SW_u8GetPressed(sw3) == SW_PRESSED)
		{
			counter3++;
			CLCD_voidSetPostion(2,3);
			if (counter3<10)
			{
				CLCD_voidSendData(counter3+48);
			}
			else if (counter3<100)
			{
				CLCD_voidSendData(counter3/10+48);
				CLCD_voidSendData(counter3%10+48);
			}
			else if (counter3<1000)
			{
				CLCD_voidSendData(counter3/100+48);
				CLCD_voidSendData((counter3/10)%10+48);
				CLCD_voidSendData(counter3%10+48);
			}
		}
		
		else if(SW_u8GetPressed(sw4) == SW_PRESSED)
		{
			counter4++;
			CLCD_voidSetPostion(2,14);
			if (counter4<10)
			{
				CLCD_voidSendData(counter4+48);
			}
			else if (counter4<100)
			{
				CLCD_voidSendData(counter4/10+48);
				CLCD_voidSendData(counter4%10+48);
			}
			else if (counter4<1000)
			{
				CLCD_voidSendData(counter4/100+48);
				CLCD_voidSendData((counter4/10)%10+48);
				CLCD_voidSendData(counter4%10+48);
			}
		}
		
		else if(SW_u8GetPressed(sw5) == SW_PRESSED)
		{
			counter1=counter2=counter3=counter4=0;
			CLCD_voidSetPostion(1,1);
			CLCD_voidSendString("A=0  ");
			CLCD_voidSetPostion(1,12);
			CLCD_voidSendString("B=0  ");
			CLCD_voidSetPostion(2,1);
			CLCD_voidSendString("C=0  ");
			CLCD_voidSetPostion(2,12);
			CLCD_voidSendString("D=0  ");
			CLCD_voidSetPostion(1,1);	
		}
		_delay_ms(200);
    }
}

