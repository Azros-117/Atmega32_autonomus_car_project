/*
 * Timer0_Interface.h
 *
 * Created: 04/02/2025 17:03:18
 *  Author: andre
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define PWM            0
#define NORMAL_ICP     1

#define RISING_EDGE    0
#define FALLING_EDGE   1

#include "Timer1_Private.h"

void Timer1_Initialize(uint8t mode);
void Timer1_EnableInterrupts(void);
void Timer1_SetInputCaptureEdge(uint8_t edge);
void Timer1_DisableInterrupts(void);
void Timer1_Start(uint8t mode);
void Timer1_SetCompareMatchA(uint16_t compareValue);
void Timer1_SetPWM_Mode14(uint16_t freq_Hz, float duty);
void Timer1_Stop(void);
#endif /* TIMER0_INTERFACE_H_ */