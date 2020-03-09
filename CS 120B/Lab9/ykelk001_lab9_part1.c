/* Name & E-mail: Yash Kelkar ykelk001@ucr.edu
* LathreeLEDsSection: 25
* Assignment: Lab 9 Exercise 1
* Exercise Description: This program simulates a system that uses three buttons to select one of three tones to be generated on
*						the speaker. When a button is pressed, the tone mapped to it is generated on the speaker. Using the tones C4,
*						D4, and E4 from the table in the introduction section. When a button is pressed and held, the tone mapped to
*						it is generated on the speaker. When more than one button is pressed simultaneously, the speaker remains silent.
*						When no buttons are pressed, the speaker remains silent.
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>
#include "io.c"
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.

// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.
unsigned long _avr_timer_M = 1; // Init count from here, down to 0. Default 1 ms.
unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1ms ticks

void TimerOn()
{
	// AVR timer/counter controller register TCCR1
	TCCR1B = 0x0B;// bit3 = 0: CTC mode (clear timer on compare)
	// bit2bit1bit0=011: pre-scaler /64
	// 00001011: 0x0B
	// SO, 8 MHz clock or 8,000,000 /64 = 125,000 ticks/s
	// Thus, TCNT1 register will count at 125,000 ticks/s

	// AVR output compare register OCR1A.
	OCR1A = 125;	// Timer interrupt will be generated when TCNT1==OCR1A
	// We want a 1 ms tick. 0.001 s * 125,000 ticks/s = 125
	// So when TCNT1 register equals 125,
	// 1 ms has passed. Thus, we compare to 125.
	// AVR timer interrupt mask register
	TIMSK1 = 0x02; // bit1: OCIE1A -- enables compare match interrupt

	//Initialize avr counter
	TCNT1=0;

	_avr_timer_cntcurr = _avr_timer_M;
	// TimerISR will be called every _avr_timer_cntcurr milliseconds

	//Enable global interrupts
	SREG |= 0x80; // 0x80: 1000000
}

void TimerOff()
{
	TCCR1B = 0x00; // bit3bit1bit0=000: timer off
}

void TimerISR()
{
	TimerFlag = 1;
}

// In our approach, the C programmer does not touch this ISR, but rather TimerISR()
ISR(TIMER1_COMPA_vect)
{
	// CPU automatically calls when TCNT1 == OCR1 (every 1 ms per TimerOn settings)
	_avr_timer_cntcurr--; // Count down to 0 rather than up to TOP
	if (_avr_timer_cntcurr == 0)
	{ // results in a more efficient compare
		TimerISR(); // Call the ISR that the user uses
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

// Set TimerISR() to tick every M ms
void TimerSet(unsigned long M)
{
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}

// 0.954 hz is lowest frequency possible with this function,
// based on settings in PWM_on()
// Passing in 0 as the frequency will stop the speaker from generating sound
void set_PWM(double frequency) {
	static double current_frequency; // Keeps track of the currently set frequency
	// Will only update the registers when the frequency changes, otherwise allows
	// music to play uninterrupted.
	if (frequency != current_frequency) {
		if (!frequency) { TCCR3B &= 0x08; } //stops timer/counter
		else { TCCR3B |= 0x03; } // resumes/continues timer/counter
		
		// prevents OCR3A from overflowing, using prescaler 64
		// 0.954 is smallest frequency that will not result in overflow
		if (frequency < 0.954) { OCR3A = 0xFFFF; }
		
		// prevents OCR0A from underflowing, using prescaler 64					// 31250 is largest frequency that will not result in underflow
		else if (frequency > 31250) { OCR3A = 0x0000; }
		
		// set OCR3A based on desired frequency
		else { OCR3A = (short)(8000000 / (128 * frequency)) - 1; }

		TCNT3 = 0; // resets counter
		current_frequency = frequency; // Updates the current frequency
	}
}

void PWM_on() {
	TCCR3A = (1 << COM3A0);
	// COM3A0: Toggle PB3 on compare match between counter and OCR0A
	TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
	// WGM02: When counter (TCNT0) matches OCR0A, reset counter
	// CS01 & CS30: Set a prescaler of 64
	set_PWM(0);
}

void PWM_off()
{
	TCCR0A = 0x00;
	TCCR0B = 0x00;
}

enum Freq_States {Init, Wait , C4_Press, C4_Release, D4_Press, D4_Release, E4_Press, E4_Release } freq_state;

unsigned char button = 0x00;

void freq_Tick()
{
	button = ~PINA & 0x07;
	switch(freq_state)
	{
		case Init:
			freq_state = Wait;
			break;

		case Wait:
			if (button == 0x01)
			{
				freq_state = C4_Press;
			}
			else if (button == 0x02)
			{
				freq_state = D4_Press;
			}
			else if (button == 0x04)
			{
				freq_state = E4_Press;
			}
			else
			{
				freq_state = Wait;
			}
			break;

		case C4_Press:
			if (button == 0x01)
			{
				freq_state = C4_Press;
			}
			else
			{
				freq_state = C4_Release;
			}
			break;

		case C4_Release:
			freq_state = Wait;
			break;

		case D4_Press:
			if (button == 0x02)
			{
				freq_state = D4_Press;
			}
			else
			{
				freq_state = D4_Release;
			}
			break;

		case D4_Release:
			freq_state = Wait;
			break;

		case E4_Press:
			if (button == 0x04)
			{
				freq_state = E4_Press;
			}
			else
			{
				freq_state = E4_Release;
			}
			break;

		case E4_Release:
			freq_state = Wait;
			break;

		default:
			break;

	}
	switch(freq_state)
	{
		case Wait:
			set_PWM(0);
			break;

		case C4_Press:
			set_PWM(261.63);
			break;

		case C4_Release:
			set_PWM(0);
			break;

		case D4_Press:
			set_PWM(293.66);
			break;

		case D4_Release:
			set_PWM(0);
			break;

		case E4_Press:
			set_PWM(329.63);
			break;

		case E4_Release:
			set_PWM(0);
			break;

		default:
			break;
	}
}
int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	freq_state = Init;
	
	PWM_on();
	
	while (1)
	{
		freq_Tick();
	}
}