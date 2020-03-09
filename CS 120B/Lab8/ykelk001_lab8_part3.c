/* Name & E-mail: Yash Kelkar ykelk001@ucr.edu
* LathreeLEDsSection: 25
* Assignment: Lab 8 Exercise 3
* Exercise Description: This program is a system where an LED is illuminated if enough light is detected from the photo resistor. If
*						the result of the ADC is >= MAX/2, the LED is illuminated. If the result of the ADC is < MAX/2, the LED is 
*						turned off. MAX is the highest ADC value observed from part 2 of the lab.
*
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
	unsigned char D = 0X00;
	unsigned short MAX = 0x00;
	
	ADC_init();
	
	while(1)
	{
		unsigned short x = ADC;
		
		if (x > MAX)
		{
			MAX = x;
		}
		
		if (x >= (MAX/2))
		{
			B = 0x01;
		}
		else if (x < (MAX/2))
		{
			B = 0x00;
		}
		
		PORTB = B;
		PORTD = D;
	}
}