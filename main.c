//   main.c
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "KEYPAD.h"

int main() {
	uint8_t passcode[5];  // 4 digits + '\0'
	
	LCD_init();
	KeyPadInit();
	
	while (1) {
		LCD_clr();
		LCD_writeStr("Enter Passcode:");
		
		if (fillArr(passcode, 4)) {
			if (passcode[0] == '1' && passcode[1] == '2' && passcode[2] == '3' && passcode[3] == '4') {
				LCD_clrScnd();
				LCD_setCursor(0, 1);
				LCD_writeStr("Correct!");
				_delay_ms(1000); // Display "Correct!" for 1 second
				LCD_clrScnd();
				} else {
				LCD_clrScnd();
				LCD_setCursor(0, 1);
				LCD_writeStr("Try again");
				_delay_ms(1000); // Display "Try again" for 1 second
				LCD_clrScnd();
			}
			} else {
			// Handle the case when the user pressed back
			LCD_clrScnd();
		}
	}
	
	return 0;
}
