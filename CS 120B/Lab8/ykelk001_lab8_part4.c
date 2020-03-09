/* Name & E-mail: Yash Kelkar ykelk001@ucr.edu
* LathreeLEDsSection: 25
* Assignment: Lab 8 Exercise 4
* Exercise Description: This program a system, using a bank of eight LEDs, where the number of LEDs illuminated is a representation 
*						of how much light is detected. When more light is detected, more LEDs are illuminated. The LEDs
*						are illuminated in sequence from 0 to 7, based on the amount of light detected by the photoresistor. I use
*						the maximum ADC value observed from part 2 as the highest amount of light detectable by the photoresistor. 
*						Dividing that number by eight determines the thresholds for each LED.
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>
#include "io.c"
#include <avr/interrupt.h>

void ADC_init()
{
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	//        in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
}

int main()
{
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00; // Init port B to 0s
	
	unsigned char B = 0x00;
	unsigned short MAX = 0x00;
	unsigned short LED = 0x00;
	
	ADC_init();
	
	while(1)
	{
		unsigned short x = ADC;
		
		if (x > MAX)
		{
			MAX = x;
		}
		
		LED = MAX/8;
		
		if (x == LED)
		{
			B = 0x01;
		}
		else if (x == 2*LED)
		{
			B = 0x03;
		}
		else if (x == 3*LED)
		{
			B = 0x07;
		}
		else if (x == 4*LED)
		{
			B = 0x0F;
		}
		else if (x == 5*LED)
		{
			B = 0x1F;
		}
		else if (x == 6*LED)
		{
			B = 0x3F;
		}
		else if (x == 7*LED)
		{
			B = 0x7F;
		}
		else if (x == MAX)
		{
			B = 0xFF;
		}
		else if ((x >= 0) && (x < LED) )
		{
			B = 0x00;
		}
		
		PORTB = B;
	}
}