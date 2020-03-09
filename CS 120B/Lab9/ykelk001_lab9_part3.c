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

unsigned char i = 0x00;
unsigned char button = 0x00;
//double note[] = {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88, 523.25}; //C4 D4 E4 F4 G4 A4 B4 C5
unsigned char time_held[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
unsigned char time_btwn[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
double star_wars[] = {392.00, 392.00, 392.00, 261.63, 392.00, 349.23, 329.63, 293.66, 523.25, 392.00, 349.23, 329.63, 293.66, 523.25, 392.00, 349.23, 329.63, 349.23, 293.66} //G G G C4 G F E D C5 G F E D C5 G F E F D

enum States {Init1, Wait_On, On_Press, Play, Finished} state;

void ON_Tick()
{
	switch(state)
	{
		case Init1:
		state = Wait_On;
		break;
		
		case Wait_On:
		if (button == 0x04)
		{
			state = On_Press;
		}
		else if (button == 0x00)
		{
			state = Wait_On;
		}
		break;
		
		case On_Press:
		if (button == 0x04)
		{
			state = Play;
		}
		break;
		
		
		case Play:
		if (i == 19)
		{
			state = Finished;
		}
		break;
		
		case Finished:
		case = Init1;
		break;
		
		default:
		break;
	}
	
	switch(state)
	{
		case Init1:
		set_PWM(0);
		break;
		
		case Wait_On:
		set_PWM(0);
		break;
		
		case On_Press:
		break;
		
		case Play:
		i++;
		set_PWM(star_wars[i]);
		break;
		
		case Finished:
		break;
		
		default:
		break;
	}
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	scale_state = Init;
	state = Init1;
	
	TimerSet(1);
	TimerOn();
	
	PWM_on();
	
	while (1)
	{
		Scale_Tick();
		ON_Tick();
		while (!TimerFlag);
		TimerFlag = 0;
	}
}