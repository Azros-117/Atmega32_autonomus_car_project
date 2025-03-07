/*
 * DIO_Configuration.h
 *
 * Created: 03/02/2025 17:51:55
 *  Author: andre
 */ 


#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_

#include "DIO_Address.h"

// Renaming Ports
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}dioPort;
//Renaming Pins(Create new dataType)
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}dioPin;
//Renaming States(Create new dataType)
typedef enum
{
	DIO_INPUT  = 0,
	DIO_OUTPUT = 1
}dioState;
//Renaming Status(Create new dataType)
typedef enum
{
	DIO_LOW  = 0,
	DIO_HIGH = 1
}dioStatus;
//Renaming Return value(Create new dataType)
typedef enum
{
	DIO_FALSE  = 0,
	DIO_TRUE   = 1
}dioReturn;




#endif /* DIO_CONFIGURATION_H_ */