/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #2  Exercise #1 
 *	Exercise Description: This program counts the number of 1s on ports A and B and output that number on port C. 
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
   	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as outputs,
   	DDRC = 0xFF; PORTC = 0x00;
	// initialize to 0s
   	unsigned A = 0x00;
	unsigned B = 0x00;
	unsigned C = 0x00;
	unsigned num_ones = 0x00;
	unsigned bit_check = 0x00;;
	unsigned char i = 0x00;
	

	while(1)
	{	
		num_ones = 0x00;
		bit_check = 0x01;
		A = PINA;
		B = PINB;
		for (i = 0; i < 8; ++i)
		{
			
			if ((A & bit_check) == bit_check)
			{
				num_ones++;
			}
			if ((B & bit_check) == bit_check)
			{
				num_ones++;
			}
			bit_check = bit_check << 1;
		
			C = num_ones;
		}
		
		PORTC = C;
	}
	return 0;
}






