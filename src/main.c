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
	uint16 targetDistance = 0;
	while (1)
	{
		targetDistance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 0);
		LCD_displayString("Distance=");
		LCD_moveCursor(0, 10);
		if (targetDistance >= 100)
		{
			LCD_intgerToString(targetDistance);
		}
		else
		{
			LCD_intgerToString(targetDistance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		LCD_moveCursor(0, 13);
		LCD_displayString("cm");
	}
}
