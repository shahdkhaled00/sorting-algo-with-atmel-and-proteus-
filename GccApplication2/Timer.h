/*
 * Timer.h
 *
 * Created: 5/9/2024 12:31:27 AM
 *  Author: DELL
 */ 

#ifndef TIMER_H_
#define TIMER_H_
#define  NUMBER_OF_OVERFLOW 62
#define  NULL_PTR  ((void*)0)

void timer0_init(void);
void timer0_setCallBack(void(*a_ptr)(void));

#endif /* TIMER_H_ */
