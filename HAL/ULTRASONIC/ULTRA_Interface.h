/*
 * ULTRA_Interface.h
 *
 * Created: 03/02/2025 17:55:24
 *  Author: andre
 */ 


#ifndef ULTRA_INTERFACE_H_
#define ULTRA_INTERFACE_H_

#include "ULTRA_Private.h"

void ULTRA_Initialize(void);
void ULTRA_Distance(uint16t*distance);
void ULTRA_STOP(void);
void __vector_6(void)__attribute__((signal));
void __vector_9(void)__attribute__((signal));

#endif /* ULTRA_INTERFACE_H_ */