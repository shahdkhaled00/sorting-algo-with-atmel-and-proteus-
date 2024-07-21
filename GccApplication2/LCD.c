/*
 * LCD.c
 *
 * * Created: 5/9/2024 12:22:55 AM
 *  Author: DELL
 */


#include "LCD.h"
#define SET_CURSOR_LOCATION (0X80)

void LCD_Init (void){
	LCD_Data_Dir |= 0b00010111;
	LCD_Command_Dir |= (1<< RS) | (1<< EN);
	
	_delay_ms(15);
	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
	LCD_Command(0x80);
}

void LCD_Command(unsigned char cmd)
{
	PORTB &= 0b11101000;
	PORTB |= (((((cmd&0xF0) >> 4) & 0b00001000) << 1) | (((cmd&0xF0) >> 4) & 0b00000111));
	CLR_BIT(LCD_Command_Port , RS);
	SET_BIT(LCD_Command_Port , EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port , EN);
	_delay_ms(2);
	
	PORTB &= 0b11101000;
	PORTB |= ((((cmd & 0x0F) & 0b00001000) << 1) | ((cmd & 0x0F) & 0b00000111));
	SET_BIT(LCD_Command_Port , EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port , EN);
	_delay_ms(2);
}

void LCD_Char (unsigned char char_data){
	PORTB &= 0b11101000;
	PORTB |= (((((char_data & 0xF0) >> 4) & 0b00001000) << 1) | (((char_data & 0xF0) >> 4) & 0b00000111));
	SET_BIT(LCD_Command_Port , RS);
	SET_BIT(LCD_Command_Port , EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port , EN);
	_delay_us(100);
	
	PORTB &= 0b11101000;
	PORTB |= ((((char_data & 0x0F) & 0b00001000) << 1) | ((char_data & 0x0F) & 0b00000111));
    SET_BIT(LCD_Command_Port , EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port , EN);
	_delay_us(100);	
}

void LCD_String (char *str){
	int i;
	for (i=0;str[i]!=0;i++){
		LCD_Char(str[i]);
	}
}

void LCD_goToRowCol(unsigned char row , unsigned char col){
	unsigned char Address =0;
	switch(row){
		case 0:
			Address = col;
			break;
		case 1:
			Address = col+0x40;
			break;
		case 2:
			Address = col+0x14;
			break;
		case 3:
			Address = col+0x54;
			break;
	}
	LCD_Command(Address | SET_CURSOR_LOCATION);
}

void LCD_Clear(void)
{
	LCD_Command(0x01);
}
