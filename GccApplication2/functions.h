/*
 * functions.h
 *
 * Created: 13/05/2024 11:15:33 م
 *  Author: Admin
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include"ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "std_types.h"
#include "Keypad.h"
#include "LCD.h"
#include "Seven_seg.h"
#include "Timer.h"
#include "Keypad.h"

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_



void DisplaySortedNum(uint16 arr[], uint8 n);

void selection_sort(uint16 arr[], uint8 n) ;

void DisplaySortSSD(void);

uint8 get_ascii_of_number(uint8 num);

void processKeypadInput(void);






#endif /* FUNCTIONS_H_ */