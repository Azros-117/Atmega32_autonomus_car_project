/*
 * ULTRA_Program.c
 *
 * Created: 03/02/2025 19:46:02
 *  Author: andre
 */ 
#include "ULTRA_Interface.h"

static volatile uint16t capture1, capture2;
static volatile uint8t flag = 0;
static volatile uint16t ov, ovf;

void ULTRA_Initialize(void) {
	DIO_SetPinDirection(ULTRA_TRIGGER_PORT, ULTRA_TRIGGER, ULTRA_OUTPUT);
	DIO_SetPinDirection(ULTRA_ECHO_PORT, ULTRA_ECHO, ULTRA_INPUT);
	
	Global_Interrupt_Disable();
	Timer1_Initialize(NORMAL_ICP);
	Timer1_EnableInterrupts();
	Timer1_SetInputCaptureEdge(RISING_EDGE);
	Timer1_Start(NORMAL_ICP);
	Global_Interrupt_Enable();
}

void ULTRA_Distance(uint16t *dist) {
	uint32t count;
	uint16t distance;

	// Generate 10µs Trigger Pulse
	DIO_SetPinValue(ULTRA_TRIGGER_PORT, ULTRA_TRIGGER, ULTRA_HIGH);
	_delay_us(10);
	DIO_SetPinValue(ULTRA_TRIGGER_PORT, ULTRA_TRIGGER, ULTRA_LOW);
// Add a delay to allow the sensor to stabilize
_delay_us(60000);
	if (flag == 2) {
		flag = 0;
		count = ((uint32t)capture2 + ((uint32t)ovf * 65536UL)) - (uint32t)capture1;

		// Updated distance calculation
		distance = (double)((count * 8645UL) / 1000000UL);

		if (distance >= 2 && distance <= 400) {
			*dist = distance;
			} else {
			*dist = 0;  // Invalid distance
		}

		// Reset overflow counts
		ovf = 0;
		ov = 0;

		Timer1_EnableInterrupts();
		Timer1_SetInputCaptureEdge(RISING_EDGE);
	}
	}

void ULTRA_STOP(void) {
	Timer1_Stop();
	Timer1_DisableInterrupts();
	Global_Interrupt_Disable();
}

// Timer1 Overflow Interrupt (Increment overflow count)
void __vector_9(void) {
	ov++;
}

// Timer1 Capture Interrupt (Handle rising and falling edges)
void __vector_6(void) {
	if (flag == 0) {
	capture1 = ICR1;
	Timer1_SetInputCaptureEdge(FALLING_EDGE);
	ov = 0;  // Reset overflow count
	flag = 1;
	} else if (flag == 1) {
	capture2 = ICR1;
	ovf = ov;  // Store overflow count
	flag = 2;  // Set flag to 2 to indicate completion
	Timer1_SetInputCaptureEdge(RISING_EDGE);
	}
}