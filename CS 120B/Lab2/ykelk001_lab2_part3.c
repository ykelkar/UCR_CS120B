/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #2  Exercise #3 
 *	Exercise Description: This program extends the previous lab activity. If PA4 is 1 if a key is in the ignition, 
 *						  PA5 is 1 if a driver is seated, and PA6 is 1 if the driver's seatbelt is fastened. PC7 
 *						  should light a "Fasten seatbelt" icon if a key is in the ignition, the driver is seated, 
 *						  but the belt is not fastened.
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
		
		if ((A & 0x0F) == 0x01 || (A & 0x0F) == 0x02)
		{
			C = 0x20;
		}
		else if ((A & 0x0F) == 0x03 || (A & 0x0F) == 0x04)
		{
			C = 0x30;
		}
		else if ((A & 0x0F) == 0x05 || (A & 0x0F) == 0x06)
		{
			C = 0x38;
		}
		else if ((A & 0x0F) >= 0x07 && (A & 0x0F) <= 0x09)
		{
			C = 0x3C;
		}
		else if ((A & 0x0F) >= 0x0A && (A & 0x0F) <= 0x0C)
		{
			C = 0x3E;
		}
		else if ((A & 0x0F) >= 0x0D && (A & 0x0F) <= 0x0F)
		{
			C = 0x3F;
		}
		if ((A & 0x0F) <= 0x04)
		{
			C = C | 0x40;
		}
		else 
		{
			C = C & 0xBF;
		}
		if ((A & 0x70) == 0x30)
		{
			C = C | 0x80;
		}
		else 
		{
			C = C & 0x7F;
		}
		PORTC = C;
	}
	return 0;
}
