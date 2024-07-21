/*
 * Seven_seg.h
 *
 * Created: 5/9/2024 12:29:04 AM
 *  Author: DELL
 */ 

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
#include "std_types.h"
#define F_CPU (16000000UL)
#include <util/delay.h>

void SEVENSEG_init();
void SEVENSEG_display(int number);
void disply_number(int numbers);
void CLR_SEV_SEG();



#endif /* SEVEN_SEG_H_ */
