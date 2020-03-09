/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #2  Exercise #2 
 *	Exercise Description: This program simulates a car fuel gauge. A car has a fuel-level sensor that sets PA3..PA0 to a 
 *						  value between 0 (empty) and 15 (full). A series of LEDs connected to PC5..PC0 should light to
 *						  graphically indicate the fuel level. If the fuel level is 1 or 2, PC5 lights. If the level is 3 or 
 *						  4, PC5 and PC4 light. Level 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights PC5..PC1. 13-15 
 *						  lights PC5..PC0. Also, PC6 connects to a "Low fuel" icon, which should light if the level is 4 or 
 *						  less.lights up an LED or sets the output to 1 if bit 0 on PORTA is 1 and bit 1 on PORTA is 0;
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
   	DDRC = 0xFF; PORTC = 0x00;
	// initialize to 0s
   	unsigned A = 0x00;	
	unsigned C = 0x00;

	while(1)
	{
		A = PINA;		
		if (A == 0x01 || A == 0x02)
		{
			C = 0x20;
		}
		else if (A == 0x03 || A == 0x04)
		{
			C = 0x30;
		}
		else if (A == 0x05 || A == 0x06)
		{
			C = 0x38;
		}
		else if (A >= 0x07 && A <= 0x09)
		{
			C = 0x3C;
		}
		else if (A >= 0x0A && A <= 0x0C)
		{
			C = 0x3E;
		}
		else if (A >= 0x0D && A <= 0x0F)
		{
			C = 0x3F;
		}
		if (A <= 0x04)
		{
			C = C | 0x40;
		}
		else 
		{
			C = C & 0xBF;
		}
		PORTC = C;
	}
	return 0;
}
