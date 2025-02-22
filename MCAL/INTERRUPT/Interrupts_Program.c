/*
 * Interrupts_Program.h
 *
 * Created: 03/02/2025 18:07:51
 *  Author: andre
 */ 


#include "Interrupts_Interface.h"
void Global_Interrupt_Enable(void){
	set_bit(_INTERRUPT_SREG,INT1);
}
void Global_Interrupt_Disable(void){
	clr_bit(_INTERRUPT_SREG,INT1);
}
void External_Interrupt_Initialization(interruptPin intrrupt, interruptSense sense)
{
	cli();//Disable global interrupt clear bit 7 in SREG (Apartment door)
	switch (intrrupt)
	{
		case EXT_INT0:
		clr_bit(DDRD, INT0);//Define direction for interrupt pin as input
		set_bit(GICR, INT0);//Enable peripheral interrupt (Room door)
		switch (sense)
		{
			case EXT_INTERRUPT_SENSE_LOW:
			clr_bit(_INTERRUPT_MCUCR, ISC01); clr_bit(_INTERRUPT_MCUCR, ISC00);// 0       0
			break;
			case EXT_INTERRUPT_SENSE_HIGH:
			clr_bit(_INTERRUPT_MCUCR, ISC01); set_bit(_INTERRUPT_MCUCR, ISC00);// 0       1
			break;
			case EXT_INTERRUPT_SENSE_FALLING:
			set_bit(_INTERRUPT_MCUCR, ISC01); clr_bit(_INTERRUPT_MCUCR, ISC00);// 1       0
			break;
			case EXT_INTERRUPT_SENSE_RISING:
			set_bit(_INTERRUPT_MCUCR, ISC01); set_bit(_INTERRUPT_MCUCR, ISC00);// 1       1
			break;
		}
		break;
		case EXT_INT1:
		clr_bit(DDRD, INT1);//Define direction for interrupt pin as input
		set_bit(GICR, INT1);//Enable peripheral interrupt (Room door)
		switch (sense)
		{
			case EXT_INTERRUPT_SENSE_LOW:
			clr_bit(_INTERRUPT_MCUCR, ISC11); clr_bit(_INTERRUPT_MCUCR, ISC10);// 0       0
			break;
			case EXT_INTERRUPT_SENSE_HIGH:
			clr_bit(_INTERRUPT_MCUCR, ISC11); set_bit(_INTERRUPT_MCUCR, ISC10);// 0       1
			break;
			case EXT_INTERRUPT_SENSE_FALLING:
			set_bit(_INTERRUPT_MCUCR, ISC11); clr_bit(_INTERRUPT_MCUCR, ISC10);// 1       0
			break;
			case EXT_INTERRUPT_SENSE_RISING:
			set_bit(_INTERRUPT_MCUCR, ISC11); set_bit(_INTERRUPT_MCUCR, ISC10);// 1       1
			break;
		}
		break;
		case EXT_INT2:
		break;
	}
	sei();//Enable global interrupt set bit 7 in SREG (Apartment door)
}