/*
 * Timer.c
 *
 * Created: 5/9/2024 12:21:47 AM
 *  Author: DELL
 */ 

#include "ATmega32_Rrgiosters.h"
#include "Timer.h"
#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "std_types.h"

#define I_BIT 7

void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER0_OVF_vect){
	if(g_callBackPtr != NULL_PTR){
		(*g_callBackPtr)();
	}
}

void timer0_init(void){
	TCNT0=0;
	SET_BIT(TIMSK,TOIE0);//ENABLE TIMER OVERFLOE FLAG
	TCCR0=(1<<FOC0)|(1<<CS02)|(1<<CS00);//chose timer0 normall mode
	SET_BIT(SREG,I_BIT);//ENABLE GLOBAL INT
}

void timer0_setCallBack(void(*a_ptr)(void)){
	g_callBackPtr = a_ptr;
}
