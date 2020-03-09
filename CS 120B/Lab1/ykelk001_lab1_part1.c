/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #1  Exercise #1 
 *	Exercise Description: This program lights up an LED or sets the output to 1 if bit 0 on PORTA is 
 *						  1 and bit 1 on PORTA is 0;
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
   	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs,
   	// initialize to 0s
   	unsigned A0 = 0x00;
	unsigned A1 = 0x00;

	while(1)
	{
		A0 = PINA & 0x01;
		A1 = PINA & 0x02;	
		
		if ((A0 == 0x01) && (A1 == 0x00))
		{
			PORTB = 0x01;
		}
		else 
		{
			PORTB = 0x00;
		} 
	}
	return 0;
}



