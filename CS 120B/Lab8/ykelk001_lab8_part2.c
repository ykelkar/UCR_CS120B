/* Name & E-mail: Yash Kelkar ykelk001@ucr.edu
* LathreeLEDsSection: 25
* Assignment: Lab 8 Exercise 2
* Exercise Description: This program uses a photoresistor and a 330 ohm resistor to read the 10-bit ADC result from the ADC register,
*						and displays the result on a bank of 10 LEDs.
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00; // Init port B to 0s
	
	unsigned char B = 0x00;
	unsigned char D = 0X00;
	
	ADC_init();
	
	while(1)
	{
		unsigned short x = ADC;
		B = (char)x; //8 bits of x on PORTB [7:0]
		D = (char)(x >> 8); //last 2 bits of x on PORTD [1:0]
		
		PORTB = B;
		PORTD = D;
	}
}