/*
 * Keypad.c
 *
 * * Created: 5/9/2024 12:22:55 AM
 *  Author: DELL
 */

#include "Keypad.h"

const unsigned char arr[4][4]={{0,1,2,3},
	                       	   {4,5,6,7},
                               {8,9,10,11},
							   {12,13,14,15}};


void keypad_init()
{
	CLR_BIT(DDRD,7);
	CLR_BIT(DDRD,6);
	CLR_BIT(DDRD,5);
	CLR_BIT(DDRD,3);

	SET_BIT(DDRC,5);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,2);

	SET_BIT(PORTD,7);
	SET_BIT(PORTD,6);
	SET_BIT(PORTD,5);
	SET_BIT(PORTD,3);

}

unsigned char keypad_get_value()
{
	unsigned char col,row,ans=INVALID_KEYPAD_PRESS;

 for(row=5;row>=2;row--){

     PORTC |= 0b00111100;
     CLR_BIT(PORTC,row);
     for(col=7;col>=3;col--){
      if(col==4)
      col--;
      if(GET_BIT(PIND,col)==0){
    	  _delay_ms(1000);
    	  if(GET_BIT(PIND,col)==0){
    		  if(col==3){
    			  ans=arr[5-row][7-col-1];
    			  break;
    		  }
    		  else{
    			  ans=arr[5-row][7-col];
    			   break;
    		  }
      }
     }
}
}
  _delay_ms(500);
return ans;
}
