/*
 * SERVO_Configuration.h
 *
 * Created: 03/02/2025 17:34:11
 *  Author: andre
 */ 


#ifndef SERVO_CONFIGURATION_H_
#define SERVO_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "PERIPHERAL_LIBRARY.h"

typedef enum
{
	Angle_N90 = 16, // -90 degrees RIGHT POSITION
	Angle_0   = 23, // 0 degrees   STRAIGHT POSITION
	Angle_P90 = 35  // +90 degrees LEFT POSITION 
}servo_angle;

typedef enum
{
	SERVO_0 = 0,
	SERVO_1 = 1,
	SERVO_2 = 2,
	SERVO_3 = 3,
	SERVO_4 = 4,
	SERVO_5 = 5,
	SERVO_6 = 6,
	SERVO_7 = 7,
}servo;

#define SERVO_DDR  DDRB

#define SERVO_PORT PORTD
#define SERVO_LOW  DIO_LOW
#endif /* SERVO_CONFIGURATION_H_ */