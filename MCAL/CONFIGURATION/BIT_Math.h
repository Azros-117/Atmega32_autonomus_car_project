/*
 * BIT_Math.h
 *
 * Created: 03/02/2025 17:38:24
 *  Author: andre
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* ------------------------->Bit Math              */
#define set_bit(reg,bit) reg|=(1<<bit)
#define clr_bit(reg,bit) reg&=~(1<<bit)
#define tgl_bit(reg,bit) reg^=(1<<bit)
#define get_bit(reg,bit) ((reg>>bit)&0x01)

#endif /* BIT_MATH_H_ */