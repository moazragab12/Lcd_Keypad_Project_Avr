// LCD.c
#include "LCD.h"

void LCD_data(char c) {
	LCD_PORT = c;
	LCD_CTRL_PORT |= (1 << RS);
	LCD_CTRL_PORT |= (1 << EN);
	_delay_us(10);
	LCD_CTRL_PORT &= ~(1 << EN);
	_delay_us(1000);
}

void LCD_cmd(uint8_t command) {
	LCD_PORT = command;
	LCD_CTRL_PORT &= ~(1 << RS);
	LCD_CTRL_PORT |= (1 << EN);
	_delay_us(10);
	LCD_CTRL_PORT &= ~(1 << EN);
	_delay_ms(20);
}

void LCD_init(void) {
	LCD_DDR = 0xFF;
	LCD_CTRL_DDR |= (1 << EN) | (1 << RS);

	_delay_ms(150);
	LCD_cmd(0x38);
	LCD_cmd(0x0C);
	LCD_cmd(0x06);
	LCD_cmd(0x01);
}

void LCD_setCursor(uint8_t x, uint8_t y) {
	uint8_t row_offsets[] = {0x00, 0x40};
	LCD_cmd(0x80 | (row_offsets[y] + x));
}

void LCD_clr(void) {
	LCD_cmd(0x01);
	_delay_ms(20);
}

void LCD_clrScnd(void) {
	LCD_setCursor(0, 1);
	LCD_writeStr("                ");
	LCD_setCursor(0, 1);
}

void LCD_writeStr(char *a) {
	for (uint8_t i = 0; a[i] != '\0'; i++) {
		LCD_data(a[i]);
	}
}
