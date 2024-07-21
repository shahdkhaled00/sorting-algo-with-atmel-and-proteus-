#include "functions.h"

/*
 * functions.c
 *
 * Created: 13/05/2024 11:15:54 م
 *  Author: Admin
 */ 
uint8 tick=0;
uint8 is_sorted=0;
uint16 arr2[10]={0};
uint8 num=0;
uint8 counter_num=0;

uint8 get_ascii_of_number(uint8 num)
{
	return (uint8) (num + '0');
}                          // 22 27  500 ---------->

void DisplaySortedNum(uint16 arr[], uint8 n) {
	uint16 arr2[n][4];
	
	for (uint16 i = 0; i < n; ++i) {
		for (uint16 j = 0; j < 4; ++j) {
			arr2[i][j] = 10;
		}
	}
	
	
	for (uint16 i = 0;i<n;i++) {
		uint16 curr = arr[i];
		uint16 dig = 0;
		uint16 idx = 0;
		
		while (curr > 0) {
			dig = curr % 10;
			curr /= 10;
			arr2[i][idx] = dig;
			idx++;
		}
	}
	
	const uint8 charsize=n*4;
	uint8 charArr[charsize];
	uint16 idx = 0;
	for (uint16 i = 0; i < n; ++i) {
		for (uint16 j = 3; j <=3; --j) {
			if(arr2[i][j] != 10){
				charArr[idx] = (uint8*)(arr2[i][j] + '0');
				idx++;
			}
		}
		charArr[idx] = '-';

		idx++;
	}
	
	charArr[idx-1] = '\0';
	LCD_String(charArr);

	
}


void selection_sort(uint16 arr[], uint8 n) {
	
		uint8 i, j, min_idx;
		
		// One by one move boundary of unsorted subarray
		for (i = 0; i < n - 1; i++) {
			// Find the minimum element in unsorted array
			min_idx = i;
			for (j = i + 1; j < n; j++)
			{
				if (arr[j] < arr[min_idx])
				{
					min_idx = j;
				}
			}
			// Swap the found minimum element with the first element
			uint16 temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
	}
		


void DisplaySortSSD(){
	tick++;
	if(tick==NUMBER_OF_OVERFLOW && is_sorted==1){
		
		LCD_Clear();
		if(counter_num >= 0){
			disply_number(arr2[num]);
			num++;
			tick=0;
			counter_num--;
		}
	}
	
}
	
void processKeypadInput(void)
{
	uint8 counter_digit = 0;
	uint16 digit = 0;
	uint16 temp_num = 0;
	uint8 value;

	while (1) {
		CLR_SEV_SEG();
		value = keypad_get_value();
		if (value != INVALID_KEYPAD_PRESS) {
			if (counter_digit < 4 && value != 12 && value != 14 && value != 15) {
			
				switch (value) {
					case 0:
					digit = 7;
					++counter_digit;
					break;
					case 1:
					digit = 8;
					++counter_digit;
					break;
					case 2:
					digit = 9;
					++counter_digit;
					break;
					case 4:
					digit = 4;
					++counter_digit;
					break;
					case 5:
					digit = 5;
					++counter_digit;
					break;
					case 6:
					digit = 6;
					++counter_digit;
					break;
					case 8:
					digit = 1;
					++counter_digit;
					break;
					case 9:
					digit = 2;
					++counter_digit;
					break;
					case 10:
					digit = 3;
					++counter_digit;
					break;
					case 13:
					digit = 0;
					++counter_digit;
					break;
				}
				switch (counter_digit) {
					case 1:
					temp_num += digit;
					break;
					case 2:
					temp_num *= 10;
					temp_num += digit;
					break;
					case 3:
					temp_num *= 10;
					temp_num += digit;
					break;
					case 4:
					temp_num *= 10;
					temp_num += digit;
					break;
				}

				LCD_Char(get_ascii_of_number(digit));
				}
				else if (value == 15) {  // +
				//LCD_Clear();
				
				LCD_Char(' ');
				counter_digit = 0;
				
				arr2[counter_num] = temp_num;
				temp_num = 0;
				counter_num++;
				}
				
				else if (value == 14) {  // =
				LCD_Clear();
				selection_sort(arr2, counter_num); //show on lcd 
				DisplaySortedNum(arr2, counter_num);    //display on lcd 
				is_sorted = 1;
				tick = 25;
				}
				
				else if (value == 12) {  // on/c
				LCD_Clear();
				counter_digit = 0;
				arr2[counter_num] = temp_num;
				temp_num = 0;
				counter_num++;
			}
		}
		 _delay_ms(280);
	}
			}
		


