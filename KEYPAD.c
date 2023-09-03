#include "KEYPAD.h"

const char KEYPAD_KEYS[4][4] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

void KeyPadInit() {
	KEYPAD_DDR = 0xF0;
	KEYPAD_PORT = 0x0F;
	LCD_cmd(0x06);
}

char getChar() {
	while (1) {
		for (uint8_t col = 0; col < 4; col++) {
			KEYPAD_PORT = ~(0x10 << col);
			for (uint8_t row = 0; row < 4; row++) {
				if (!(KEYPAD_PIN & (1 << row))) {
					while (!(KEYPAD_PIN & (1 << row)));
					return KEYPAD_KEYS[row][col];
				}
			}
		}
	}
}

uint8_t fillArr(uint8_t *a, uint8_t max) {
	
	uint8_t index = 0;
	while (index < max) {
		char key = getChar();
		if (key == '#') {
			if (index > 0) {
				index--;
				a[index] = '\0';
				LCD_setCursor(index, 0);
				LCD_data(' ');
			}
			} else if (key >= '0' && key <= '9') {
			LCD_setCursor(index,1);
			a[index] = key;
			LCD_data(key);
			index++;
			
			if (index == max) {
				return 1; // Array filled successfully
			}
		}
	}
	return 0; // User pressed back before filling array
}