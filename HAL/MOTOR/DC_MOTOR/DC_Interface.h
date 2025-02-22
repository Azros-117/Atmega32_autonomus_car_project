/*
 * DC_Interface.h
 *
 * Created: 03/02/2025 17:33:16
 *  Author: andre
 */ 


#ifndef DC_INTERFACE_H_
#define DC_INTERFACE_H_

#include "DC_Private.h"


void DC_Motor_Initialize(void);
void DC_Rotate(dcMotor motor, dcDirection direction);
void DC_Brake(dcMotor motor);



#endif /* DC_INTERFACE_H_ */