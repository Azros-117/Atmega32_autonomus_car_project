/*
 * SERVO_Program.c
 *
 * Created: 03/02/2025 19:46:32
 *  Author: andre
 */ 
#include "Servo_Interface.h"

void ServoMotor_Initialize(void)
{
	// Define direction of OC2 pin (PD7) to use timer 2 for servo movement
	DDRD |= (1 << PD7); // Set PD7 as output (OC2)

	// Choose Fast PWM mode (Mode 3)
	TCCR2 |= (1 << WGM21) | (1 << WGM20);

	// Choose non-inverting mode
	TCCR2 |= (1 << COM21);
	TCCR2 &= ~(1 << COM20);

	// Choose Prescaler of 1024 for ~61Hz PWM frequency
	TCCR2 |= (1 << CS22) | (1 << CS21) | (1 << CS20);

	// Set initial duty cycle to zero
	OCR2 = 0;
}
void ServoMotor_Rotate(uint8t angle)
{
	OCR2 = angle;
}

void Servo_stop(void){
	DIO_SetPinValue(SERVO_PORT,PD7,SERVO_LOW);
}