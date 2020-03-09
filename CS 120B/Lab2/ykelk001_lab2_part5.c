/*
 * GccApplication1.c
 *
 * Created: 4/5/2017 2:53:18 PM
 * Author : Yash 
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
