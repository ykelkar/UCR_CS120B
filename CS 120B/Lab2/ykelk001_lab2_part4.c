/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #1  Exercise #1 
 *	Exercise Description: Read an 8-bit value on PA7..PA0 and write that value on PB3..PB0PC7..PC4. That is to say,  
 *						  take the upper nibble of PINA and map it to the lower nibble of PORTB, likewise take the lower 
 *						  nibble of PINA and map it to the upper nibble of PORTC (PA7 -> PB3, PA6 -> PB2, � PA1 -> PC5, PA0 -> PC4).
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
	DDRB = 0xFF; PORTB = 0x00;
   	DDRC = 0xFF; PORTC = 0x00;
	// initialize to 0s

	while(1)
	{
		PORTB = PINA >> 4;
		PORTC = PINA << 4;
	}
	return 0;
}
