/*
 * SERVO_Interface.h
 *
 * Created: 03/02/2025 17:34:49
 *  Author: andre
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#include "Servo_Private.h"

void ServoMotor_Initialize(void);
void ServoMotor_Rotate(uint8t angle);

void SERVO_DIO_Initialize(void);
void Servo_DIO_AngleRotation(void);

void Servo_stop(void);

#endif /* SERVO_INTERFACE_H_ */