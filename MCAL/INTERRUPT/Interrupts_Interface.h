/*
 * Interrupts_Interface.h
 *
 * Created: 03/02/2025 18:07:12
 *  Author: andre
 */ 


#ifndef INTERRUPTS_INTERFACE_H_
#define INTERRUPTS_INTERFACE_H_


#include "Interrupts_Private.h"

void Global_Interrupt_Enable(void);
void Global_Interrupt_Disable(void);
void External_Interrupt_Initialization(interruptPin intrrupt, interruptSense sense);


#endif /* INTERRUPTS_INTERFACE_H_ */