/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #3  Exercise #1 
 *	Exercise Description: This program implements a button that affects two LEDs, PB0 and PB1. PB0 is initially on and PB1 
 *						  is initially off. Pressing the button, inverses the values on the LEDs. For example, if one is on
 *						  and the other is off, pressing the button will switch them.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States {Init, Off_Release, On_Press, On_Release, Off_Press} state;
	
void Tick() {
	unsigned char A0 = PINA & 0x01;
	
	switch(state) { //Transitions
		case Init:
			state = Off_Release;
			break;
			
		case Off_Release:
			if (!A0)
			{
				state = Off_Release;
			}
			else 
			{
				state = On_Press;
			}
			break;
			
		case On_Press:
			if (A0)
			{
				state = On_Press;
			}
			else 
			{
				state = On_Release;
			}
			break;
			
		case On_Release:
			if (!A0)
			{
				state = On_Release;
			}
			else 
			{
				state = Off_Press;
			}
			break;
			
		case Off_Press: 
			if (A0)
			{
				state = Off_Press;
			}
			else
			{
				state = Off_Release;
			}
			break;
	}
	switch(state) { //State Actions
		case Init:
			PORTB = 0x00;
			break;
				
		case Off_Release:
			PORTB = 0x01;
			break;
				
		case On_Press:
			PORTB = 0x02;
			break;
				
		case On_Release:
			break;
				
		case Off_Press:
			PORTB = 0x01;
			break;
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
	state = Init;
	while(1)
	{	
		Tick();
	}
	return 0;
}
