#define F_CPU 16000000UL
#include <util/delay.h>
#include"ATmega32_Rrgiosters.h"
#include "functions.h"

/* 0 1 2 3            7 8 9 %                      
 * 4 5 6 7            4 5 6 x
 * 8 9 10 11          1 2 3 -
 * 12 13 14 15        c 0 = +
 */


int main(void)
{
	uint8 tick=0;
	uint8 is_sorted=0;
	uint16 arr2[10]={0};
	uint8 num=0;
	uint8 counter_num=0;

	keypad_init();  //inatilaize keypad
	LCD_Init ();    //initailze lcd 
	SEVENSEG_init();  // int segma
	timer0_init();    //int timer 
	timer0_setCallBack(&DisplaySortSSD);
	LCD_String("     HELLO !!!!");    
	LCD_goToRowCol(2 , 1);   // ????    ??? 
	LCD_String("  ENTER YOUR LIST");
	
	//calling the core functions 
	processKeypadInput();
	selection_sort(arr2, counter_num);
	
	uint8 ascii_num = get_ascii_of_number(num);

	DisplaySortedNum(arr2, counter_num);
	//_delay_ms(5000);
	DisplaySortSSD();

    while(1){
		
	}
}
