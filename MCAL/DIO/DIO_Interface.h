/*
 * DIO_Interface.h
 *
 * Created: 03/02/2025 17:52:14
 *  Author: andre
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Private.h"
// MicroController pin direction
void DIO_SetPinDirection(dioPort port, dioPin pin, dioState state);
// Pin-Output
void DIO_SetPinValue(dioPort port, dioPin pin, dioStatus status);
void DIO_TogglePinDirection(dioPort port, dioPin pin);
// Pin-Input
uint8_t DIO_ReadPinValue(dioPort port, dioPin pin);
void DIO_SetPinPullUp(dioPort port, dioPin pin);



#endif /* DIO_INTERFACE_H_ */