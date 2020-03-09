/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #1  Exercise #4
 *	Exercise Description: This program sets PD0 to 1 if the cart's total passenger weight exceeds the 
 *						  maximum of 140 kg. PD1 is also set to 1 if the difference between PORTA and PORTC 
 *						  exceeds 80 kg. Lastly, the remaining bits on PORTD represent the approximate weight on the cart.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRA = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
   	// initialize to 0s
	unsigned char A = 0x00;
	unsigned char B = 0x00;
	unsigned char C = 0x00;
	unsigned char D = 0x00;
	unsigned char temp = 0x00;
	while(1)
	{
		A = PINA;
		B = PINB;
		C = PINC;
		temp = A + B + C;
		
		if (temp > 0x8C)
		{
			D = D | 0x01;
		}
		
		if (((A - C) > 0x50) || ((C - A) > 0x50))
		{
			D = D | 0x02;
		}
		
		PORTD = D | temp;
		
		PORTD = 0x00;
		temp = 0;
	}
	return 0;
}



