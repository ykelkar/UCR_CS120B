/* Name & E-mail: Yash Kelkar ykelk001@ucr.edu
* Lab Section: 25
* Assignment: Lab 4 Exercise 3
* Exercise Description: This program creates a festive lights display 
* using two buttons to alternated between two light sequences. The light sequences are 
* represented by two values that are stored into PORTC alternatively when 
* the different buttons are pressed. 
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>

unsigned char led_1 = 0x99; 	// Temporary variable to store the output
unsigned char led_2 = 0x66; 	// Temporary variable to store the output

enum LED_states {Init, Wait, Wait_A, Wait_B, LED_1, LED_2} LED_state;  	// Declaring the states

void Tick() 
{
	unsigned char button = ~PINA & 0x03;
	
	switch (LED_state) 
	{ //Transitions
		case Init:				// Initial state is set to LED_1
			LED_state = LED_1;
			break;
		
		case Wait:				// Wait checks if the button is pressed and if not continues to wait to be pressed
			if (button == 0x01) 
			{
				LED_state = Wait_B;
			}
			else
			{
				LED_state = Wait;
			}
			break;
		
		case Wait_A:			// Waits for the button to be released and switches back to Wait
			if (button != 0x00)
			{
				LED_state = Wait_A;
			}
			else
			{
				LED_state = Wait;
			}
			break;
		
		case Wait_B:			// If the button is pressed and released, determines which value to store into PORTC
			if (PORTC == led_1) 
			{		// If the value is LED_1, switches to LED_2
				LED_state = LED_2;
			}
			else if (PORTC == led_2) // If the value is LED_2, switches to LED_1
			{
					
				LED_state = LED_1;
			}
			else
			{
				LED_state = Wait_B;
			}
			break;
		
		case LED_1:						// Transitions to Wait_A 
			LED_state = Wait_A;
			break;
		
		case LED_2:						// Transitions to Wait_A 
			LED_state = Wait_A;
			break;

		default:
			LED_state = Init;
			break;
	}
	
	switch (LED_state) 
	{ 
		case Init:			// The output initially has the value of LED_1
			PORTC = led_1;
			break;
		
		case LED_1:			// Sets the output to the value of LED_1
			PORTC = led_1;
			break;
		
		case LED_2:			// Sets the output to the value of LED_2
			PORTC = led_2;
			break;
		
		default:
			break;
	}
}

int main()
{
	DDRA = 0x00; PORTA = 0xFF;  // Configure port A's 8 pin as inputs
	DDRC = 0xFF; PORTC = 0x00;  // Configure port C's 8 pin as outputs
	LED_state = Init;
	while (1)
	{
		Tick();					// Call Tick() function within while loop
	}
}