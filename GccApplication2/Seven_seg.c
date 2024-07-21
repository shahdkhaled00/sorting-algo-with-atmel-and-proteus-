/*
 * Seven_seg.c
 *
 * * Created: 5/9/2024 12:22:55 AM
 *  Author: DELL
 */

#include "Seven_seg.h"
#include "LCD.h"
#include"ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "std_types.h"
#include <util/delay.h>

void SEVENSEG_init()
{
	SET_BIT(DDRB,0);
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,2);
	SET_BIT(DDRB,4);
	PORTB &= 0b11101000;


	SET_BIT(DDRB,6);
	SET_BIT(DDRB,5);
	SET_BIT(DDRA,2);
	SET_BIT(DDRA,3);


}



void SEVENSEG_display(int num)
{

	PORTB &= 0b11101000;
	PORTB |= (((num & 0b00001000)<<1)|(num & 0b00000111));


}
void disply_number(int number)
{
	int digit4 = ( number / 1000) % 10;
	int digit3 = ( number / 100) % 10;
	int digit2 = ( number / 10) % 10;
	int digit1 =  (number/ 1 ) % 10;

	// Display the digits on the four-digit seven-segment display
	uint16_t start_time = 0;
	while (start_time < 1000) // Delay for 1 seconds
	{

		SEVENSEG_display(digit4);
		_delay_ms(2);
		TOGGLE_BIT(PORTB,6);
		SEVENSEG_display(digit3);
		_delay_ms(2);
		TOGGLE_BIT(PORTB,5);
		SEVENSEG_display(digit2);
		_delay_ms(2);
		TOGGLE_BIT(PORTA,2);
		SEVENSEG_display(digit1);
		_delay_ms(2);
		TOGGLE_BIT(PORTA,3);

		start_time += 5;


	}
	
}
void CLR_SEV_SEG()
{
	SET_BIT(PORTB,6);
	SET_BIT(PORTB,5);
	SET_BIT(PORTA,2);
	SET_BIT(PORTA,3);

}
