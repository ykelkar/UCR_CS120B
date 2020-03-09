/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: This program simulates a button that increments the value on PORTC and a button that decrements the value
 *						  on PORT C. PORTC is initially 7. When the value is 9, it cannot be incremented any further and when the 
 *						  value is 0 is cannot be decremented any further. When both buttons are pressed at the same time, the value of 
 *						  PORTC resets back to 0.
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States {Init, Changer, Increment, Decrement, Reset} state;
	
unsigned char C = 0x07;

void Tick() {
	unsigned char A = ~PINA & 0x03;
	
	switch(state) { //Transitions
		case Init:
			state = Changer;
			break;
			
		case Changer:
			if (A == 0x01)
			{
				if (C < 9)
				{
					state = Increment;
				}
			}
			else if (A == 0x02)
			{
				if (C > 0)
				{
					state = Decrement;	
				}
			}
			else if (A == 0x03)
			{
				state = Reset;
			}
			else 
			{
				state = Changer;
			}
			break;
			
		case Increment:
			state = Changer;
			break;
			
		case Decrement: 
			state = Changer;
			break;
			
		case Reset:
			state = Changer;
			break;
		
		default:
			break;
	}
	switch(state) { //State Actions
		case Init:
			C = 0x07;
			PORTC = C;
			break;
				
		case Changer:
			break;
				
		case Increment:
			C = C + 1;
			PORTC = C;
			break;
				
		case Decrement:
			C = C - 1;
			PORTC = C;
			break;
		
		case Reset:
			C = 0x00;
			PORTC = C;
			break;
			
		default:
			break;
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x07;
	
	state = Init;
	while(1)
	{	
		Tick();
	}
	return 0;
}
