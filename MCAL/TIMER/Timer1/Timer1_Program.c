/*
 * Timer0_Program.c
 *
 * Created: 04/02/2025 17:03:54
 *  Author: andre
 */ 
#include "Timer1_Interface.h"

void Timer1_Initialize(uint8t mode) {
    switch(mode) {
        case NORMAL_ICP: // Select Normal Mode
            _T1_OVF_TCCR1A &= ~((1 << WGM11) | (1 << WGM10));
            _T1_OVF_TCCR1B &= ~((1 << WGM13) | (1 << WGM12));
            // Clear Counter
            _T1_OVF_TCNT1 = 0;
            break;
        case PWM: // Select Fast PWM Mode 14
            _T1_OVF_TCCR1A |= (1 << WGM11);
            _T1_OVF_TCCR1A &= ~(1 << WGM10);
            _T1_OVF_TCCR1B |= (1 << WGM13) | (1 << WGM12);
            // Set PWM Mode (Non-Inverting)
            _T1_OVF_TCCR1A |= (1 << COM1A1);
            _T1_OVF_TCCR1A &= ~(1 << COM1A0); // Non-inverting Mode
            break;
    }
}

void Timer1_EnableInterrupts(void) {
    // Enable Timer1 Overflow Interrupt
    _T1_OVF_TIMSK |= (1 << TOIE1);
    // Enable Input Capture Interrupt
    _T1_OVF_TIMSK |= (1 << TICIE1);
}

void Timer1_SetInputCaptureEdge(uint8_t edge) {
    switch(edge) {
        case RISING_EDGE:
            _T1_OVF_TCCR1B |= (1 << ICES1);
            break;
        case FALLING_EDGE:
            _T1_OVF_TCCR1B &= ~(1 << ICES1);
            break;
    }
}

void Timer1_DisableInterrupts(void) {
    // Disable Timer1 Overflow & Input Capture Interrupts
    _T1_OVF_TIMSK &= ~((1 << TICIE1) | (1 <<TOIE1));
}

void Timer1_Start(uint8t mode) {
    switch(mode) {
        case NORMAL_ICP: // Set Clock Prescaler to 1 (No Prescaler)
            _T1_OVF_TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
            // Set prescaler to 8
            _T1_OVF_TCCR1B |= (1 << CS11);  // CS11 = 1
            break;
        case PWM:
            // Set Clock Prescaler to 64 (Matches `_T1_FAST_PWM_PRESCALER`)
            _T1_OVF_TCCR1B &= ~(1 << CS12);
            _T1_OVF_TCCR1B |= (1 << CS11) | (1 << CS10);
            break;
    }
}

void Timer1_SetCompareMatchA(uint16_t compareValue) {
    _T1_OVF_OCR1A = compareValue;
}

void Timer1_SetPWM_Mode14(uint16_t freq_Hz, float duty) {
    if (duty <= 100) {
        // Use `_T1_FAST_PWM_MICROSECOND` for time calculation
        _T1_OVF_ICR1 = ((_T1_OVF_MICROSECOND * freq_Hz) / 4) - 1;
        // Set OCR1A based on duty cycle
        _T1_OVF_OCR1A = ((duty * (_T1_OVF_ICR1 + 1)) / 100) - 1;
    }
}

void Timer1_Stop(void) {
    // Clear Clock (Stops Timer)
    _T1_OVF_TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
}