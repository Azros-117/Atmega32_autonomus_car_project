/*
 * Timer0_Configuration.h
 *
 * Created: 04/02/2025 17:03:01
 *  Author: andre
 */ 


#ifndef TIMER1_CONFIGURATION_H_
#define TIMER1_CONFIGURATION_H_

#include "Timer1_Address.h"
#define F_CPU				 16000000UL // Define your CPU frequency
#define _T1_OVF_BITS         65536
#define _T1_OVF_PRESCALER    64
#define _T1_OVF_FREQUENCY    (F_CPU / _T1_OVF_PRESCALER) // Calculate the actual frequency
#define _T1_OVF_MICROSECOND  1000000UL

typedef enum
{
	_T1_FAST_PWM_Pin_Disconnected   = 0,
	_T1_FAST_PWM_Pin_Inverting      = 1,
	_T1_FAST_PWM_Pin_Non_inverting  = 2
}_t1_fast_pwm_pin;


#endif /* TIMER0_CONFIGURATION_H_ */