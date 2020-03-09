/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #3  Exercise #4 
 *	Exercise Description: This program implements a lock system that is initially locked. The sequence to unlock it is 
 *						  to press and release '#' and then the press Y. This sequence can also be used to lock it as well. Also
 *						  when ulocked the keypad can be locked by pressing a button connected to PA7.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States {Init, Locked, Hashtag_Press, Hashtag_Release, Y_Press, Y_Release, X_Press, X_Release, Unlocked} state;
	
void Tick() {
	unsigned char button_X = PINA & 0x01;
	unsigned char button_Y = PINA & 0x02; //Y button connected to PA1
	unsigned char button_hashtag = PINA & 0x04; //# button connected to PA2
	unsigned char button_lock = PINA & 0x80; //button connected to PA7 to lock 

	switch(state) { //Transitions
		case Init:
			state = Locked;
			break;
			
		case Locked:
			if (button_hashtag == 0x04)
			{
				state = Hashtag_Press;
			}
			else if (button_Y == 0x02)
			{
				state = Y_Press;
			}
			else if (button_X == 0x01)
			{
				state = X_Press;
			}
			else
			{
				state = Locked;
			}
			break;
			
		case Hashtag_Press:
			if (button_hashtag == 0x00)
			{
				state = Hashtag_Release;
			}
			else if (button_Y == 0x02)
			{
				state = Y_Press;
			}
			else if (button_X == 0x01)
			{
				state = X_Press;
			}
			else if (button_lock == 0x80)
			{
				state = Locked;
			}
			else 
			{
				state = Hashtag_Press;
			}
			break;
			
		case Hashtag_Release:
			if (button_Y == 0x02)
			{
				state = Unlocked;
			}
			else if (button_hashtag == 0x04)
			{
				state = Hashtag_Press;
			}
			else if (button_X == 0x01)
			{
				state = X_Press;
			}
			else if (button_lock == 0x80)
			{
				state = Locked;
			}
			else
			{
				state = Hashtag_Release;
			}
			break;
			
		case Y_Press:
			if (button_Y == 0x00)
			{
				state = Y_Release;
			}
			else if (button_hashtag == 0x04)
			{
				state = Hashtag_Press;
			}
			else if (button_X == 0x01)
			{
				state = X_Press;
			}
			else if (button_lock == 0x80)
			{
				state = Locked;
			}
			else 
			{
				state = Y_Press;
			}
			break;
		
		case Y_Release:
			if (button_Y == 0x02)
			{
				state = Y_Press;
			}
			else if (button_hashtag == 0x04)
			{
				state = Hashtag_Press;
			}
			else if (button_X == 0x01)
			{
				state = X_Press;
			}
			else if (button_lock == 0x80)
			{
				state = Locked;
			}
			else
			{
				state = Y_Release;
			}
			break;
		
		case X_Press:
			if (button_X == 0x00)
			{
				state = X_Release;
			}
			else if (button_hashtag == 0x04)
			{
				state = Hashtag_Press;
			}
			else if (button_Y == 0x02)
			{
				state = Y_Press;
			}
			else if (button_lock == 0x80)
			{
				state = Locked;
			}
			else 
			{
				state = X_Press;
			}
			break;
			
		case X_Release:
			if (button_X == 0x01)
			{
				state = X_Press;
			}
			else if (button_hashtag == 0x04)
			{
				state = Hashtag_Press;
			}
			else if (button_Y == 0x02)
			{
				state = Y_Press;
			}
			else if (button_lock == 0x80)
			{
				state = Locked;
			}
			else
			{
				state = X_Release;
			}
			break;
			
		case Unlocked:
			if (button_lock == 0x80)
			{
				state = Locked;
			}
			else if (button_Y == 0x00)
			{
				state = Y_Release;
			}
			else if (button_hashtag == 0x04)
			{
				state = Hashtag_Press;
			}
			else if (button_X == 0x01)
			{
				state = X_Press;
			}
			else
			{
				state = Unlocked;
			}
			
		default:
			break;
	}
	switch(state) { //State Actions
		case Init:
			PORTB = 0x00;
			PORTC = 0x00;
			break;
				
		case Locked:
			PORTB = 0x00;
			PORTC = 0x01;
			break;
				
		case Hashtag_Press:
			PORTC = 0x02;
			break;
				
		case Hashtag_Release:
			PORTC = 0x03;
			break;
		
		case Y_Press:
			PORTC = 0x04;
			break;
		
		case Y_Release:
			PORTC = 0x05;
			break;
			
		case X_Press:
			PORTC = 0x06;
			break;
			
		case X_Release:
			PORTC = 0x07;
			break;
			
		case Unlocked:
			PORTC = 0x08;
			if (PORTB == 0x00)
			{
				PORTB = 0x01;
			}
			else if (PORTB == 0x01)
			{
				PORTB = 0x00;
			}
			break;
			
		default:
			break;
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	state = Init;
	while(1)
	{	
		Tick();
	}
	return 0;
}
