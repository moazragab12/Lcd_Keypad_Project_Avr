/*
 * LCD.h
 *
 * Created: 8/21/2023 11:31:31 AM
 *  Author:Moaz Ragab
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/delay.h>
#include <avr/io.h>
#include "KEYPAD.h"


#define LCD_PORT PORTA 
#define LCD_DDR DDRA
#define LCD_CTRL_DDR DDRB
#define LCD_CTRL_PORT PORTB
#define EN PB0
#define RS PB1

void LCD_data(char c);//sends a data (char) to the lcd to be displayed
void LCD_cmd(uint8_t command);//sends a command to the lcd
void LCD_init(void);//initiation of ports direction and initiation of lcd
void LCD_setCursor(uint8_t x,uint8_t y);//moves currsor to any position //x = col,y=row //// 0 ---> first row or first col
void LCD_clr(void);
void LCD_clrScnd(void);//clears the second line of the lcd only and set cursor to the beginning of the second line
void LCD_writeStr(char *a);//displays entire string on the lcd

#endif /* LCD_H_ */