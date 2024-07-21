/*
 * LCD.h
 *
  * Created: 5/9/2024 12:22:55 AM
 *  Author: DELL
 */ 



#ifndef LCD_H_
#define LCD_H_

#include <util/delay.h>
#include"ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"

#define LCD_Data_Port    PORTB        // Define LCD data port
#define LCD_Data_Dir     DDRB         // Define LCD data port direction
#define LCD_Command_Port PORTA        // Define LCD data port
#define LCD_Command_Dir  DDRA         // Define LCD command port direction
#define RS 3                       // Define Register Select (data/command)
#define EN 2                       // Define Enable signal pin

void LCD_Init (void);
void LCD_Command(unsigned char cmd);
void LCD_Char (unsigned char char_data);
void LCD_String (char *str);
void LCD_goToRowCol(unsigned char row , unsigned char col);
void LCD_Clear(void);



#endif /* LCD_H_ */
