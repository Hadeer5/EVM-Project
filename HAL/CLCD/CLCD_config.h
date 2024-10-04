/***************************************************************************************************/
/**************************************Layer : MCAL****************************************/
/**************************************Ver : 01****************************************/
/**************************************Component : CLCD****************************************/
/**************************************Auter : Hadeer Adel****************************************/
/******************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*OPTIONS
*DIO_PORTA
*DIO_PORTB
*DIO_PORTC
*DIO_PORTD
*/
#define CLCD_DATA_PORT       DIO_PORTA
// RS,RW,EN
#define CLCD_CONTRIL_PORT    DIO_PORTB


/*OPTIONS
*DIO_PIN0
*DIO_PIN1
*DIO_PIN2
*DIO_PIN3
*DIO_PIN4
*DIO_PIN5
*DIO_PIN6
*DIO_PIN7
*/
#define RS           DIO_PIN1
#define RW           DIO_PIN2
#define EN           DIO_PIN0



#endif