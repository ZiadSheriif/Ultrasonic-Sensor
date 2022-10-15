/*
 * main.c
 *
 *  Created on: Oct 15, 2022
 *      Author: Ziad
 */

#include "lcd.h"
#include "ultrasonic.h"
#include "icu.h"
#include "util/delay.h"
#include <avr/io.h>
#include "std_types.h"

int main(void)
{
	SREG |= (1 << 7);
	LCD_init();
	Ultrasonic_init();
	LCD_clearScreen();
	LCD_displayString("Distance=");
	_delay_ms(2000);
	uint16 targetDistance = 0;
	while (1)
	{
		LCD_moveCursor(0, 0);
		LCD_displayString("Distance=");
		LCD_moveCursor(0, 10);
		targetDistance = Ultrasonic_readDistance();
		LCD_intgerToString(targetDistance);
		LCD_moveCursor(0, 13);
		LCD_displayString("cm");
		_delay_ms(10);
	}
}
