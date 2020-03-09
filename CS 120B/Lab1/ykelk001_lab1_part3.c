/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab #1  Exercise #3
 *	Exercise Description: This program outputs the number of available parking spaces by decrementing 
 *						  a variable initially set to 4 when a spot is filled. If all spaces are filled, bit 7 on PORTB
 *						  will be set to 1 indicate so.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00;
   	// initialize to 0s
	unsigned char cntavail = 0x00;

	while(1)
	{
		cntavail = 0x04;
		
		if ((PINA & 0x01) == 0x01)
		{
			cntavail = cntavail - 1;
		}
		if ((PINA & 0x02) == 0x02)
		{
			cntavail = cntavail - 1;
		}
		if ((PINA & 0x04) == 0x04)
		{
			cntavail = cntavail - 1;
		}
		if ((PINA & 0x08) == 0x08)
		{
			cntavail = cntavail - 1;
		}
		
		if (cntavail == 0x00)
		{
			cntavail = cntavail | 0x80;
		}
		PORTC = cntavail;
	}
	return 0;
}



