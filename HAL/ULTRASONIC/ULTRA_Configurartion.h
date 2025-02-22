/*
 * ULTRA_Configurartion.h
 *
 * Created: 03/02/2025 17:54:54
 *  Author: andre
 */ 


#ifndef ULTRA_CONFIGURARTION_H_
#define ULTRA_CONFIGURARTION_H_

#include "CPU_Configuration.h"
#include "PERIPHERAL_LIBRARY.h"
//Define Trigger port BY TAKING ANY GIOP
#define ULTRA_TRIGGER_PORT  DIO_PORTD
#define ULTRA_TRIGGER       DIO_PIN0
//Define echo port for timer1 input capture mode pin
#define ULTRA_ECHO_PORT		DIO_PORTD
#define ULTRA_ECHO			DIO_PIN6
//Define states of ultrasonic sensor
#define ULTRA_LOW    DIO_LOW
#define ULTRA_HIGH   DIO_HIGH
//Define input and output for ultrasonic sensor
#define ULTRA_INPUT     DIO_INPUT
#define ULTRA_OUTPUT    DIO_OUTPUT

#endif /* ULTRA_CONFIGURARTION_H_ */