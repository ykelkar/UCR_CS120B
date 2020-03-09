/* Name & E-mail: Yash Kelkar ykelk001@ucr.edu
* Lab Section: 25
* Assignment: Lab 7 Exercise 5
* Exercise Description: In this program, buttons are connected to PA0 and PA1. Output PORTB drives a bank of 4 LEDs. 
*						Pressing PA0 increments a binary number displayed on the bank of LEDs (stopping at 9). Pressing 
*						PA1 decrements the binary number (stopping at 0). If both buttons are depressed (even if not initially 
*						simultaneously), the display resets to 0. If a button is held, then the display continues to increment 
*						(or decrement) at a rate of once per second. However, if the button is held for 3 seconds, the 
*						incrementing/decrementing occurs once per 400 ms.
*
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>
#include "io.c"
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.

// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.
unsigned long _avr_timer_M = 1; // Start count from here, down to 0. Default 1 ms.
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

enum States {Init, Changer, Inc_Press, Inc_Release, Dec_Press, Dec_Release, Faster_Inc, Faster_Dec} LED_state;

unsigned char value = 0x00;
unsigned char changer = 0x00;
unsigned char time_counter = 0x00;
unsigned char timer = 100;

void Tick()
{
	changer = ~PINA & 0x03;
	switch(LED_state)
	{
		case Init:
		LED_state = Changer;
		break;

		case Changer:
		if(changer == 0x01)
		{
			LED_state = Inc_Press;
		}
		else if (changer == 0x02)
		{
			LED_state = Dec_Press;
		}
		else if (changer == 0x03)
		{
			LED_state = Init;
		}
		break;

		case Inc_Press:
		if(changer == 0x01)
		{
			time_counter++;
			if (time_counter == 2 && value != 9)
			{
				LED_state = Faster_Inc;
			}
			else
			{
				LED_state = Inc_Press;
			}
		}
		else if(changer == 0x00)
		{
			LED_state = Inc_Release;
		}
		else if(changer == 0x03)
		{
			LED_state = Init;
		}
		break;

		case Inc_Release:
		LED_state = Changer;
		break;

		case Dec_Press:
		if(changer == 0x02)
		{
			time_counter++;
			if (time_counter == 2 && value != 0)
			{
				LED_state = Faster_Dec;
			}
			else
			{
				LED_state = Dec_Press;
			}
		}
		else if(changer == 0x00)
		{
			LED_state = Dec_Release;
		}
		else if(changer == 0x03)
		{
			LED_state = Init;
		}
		break;

		case Dec_Release:
		LED_state = Changer;
		break;

		case Faster_Inc:
		if (changer == 0x01)
		{
			LED_state = Faster_Inc;
		}
		else
		{
			LED_state = Changer;
		}
		break;
		
		case Faster_Dec:
		if (changer == 0x02)
		{
			LED_state = Faster_Dec;
		}
		else
		{
			LED_state = Changer;
		}
		break;
		
		default:
		break;
	}//LED_state TRANSITIONS


	switch(LED_state)
	{
		case Init:
		value = 0x00;
		PORTB = value;
		break;
		
		case Changer:
		timer = 100;
		break;
		
		case Inc_Press:
		if(value < 9)
		{
			value++;
		}
		PORTB = value;
		break;

		case Dec_Press:
		if(value > 0)
		{
			value--;

		}
		PORTB = value;
		break;

		case Faster_Inc:
		timer = 40;
		time_counter = 0;
		if (value < 9)
		{
			value++;
		}
		PORTB = value;
		break;
		
		case Faster_Dec:
		timer = 40;
		time_counter = 0;
		if (value > 0)
		{
			value--;
		}
		PORTB = value;
		break;
		
		default:
		break;
	}//LED_state actionss
}

int main()
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00; // Init port B to 0s
	
	TimerSet(timer);
	TimerOn();
	
	while(1)
	{
		Tick();
		while(!TimerFlag);
		TimerFlag = 0;
		TimerSet(timer);
	}
}
