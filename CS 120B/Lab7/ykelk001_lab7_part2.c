/* Name & E-mail: Yash Kelkar ykelk001@ucr.edu
* Lab Section: 25
* Assignment: Lab 7 Exercise 2
* Exercise Description: This program connect LEDs to PB0, PB1, PB2, and PB3. In one state machine (Three LEDs), 
*						output to a shared variable (threeLEDs) the following behavior: set only bit 0 to 1, then 
*						only bit 1, then only bit 2 in sequence for 300 ms each. In a second state machine (Blinking LED), 
*						output to a shared variable (bilnkingLED) the following behavior: set bit 3 to 1 for 1 second, then 0 
*						for 1 second. In a third state machine (Combine LEDs), combine both shared variables and output to the PORTB. 
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

unsigned char time_counter = 0x00;
enum LED_States {Init, LED_1, LED_2, LED_3} LED_state;

unsigned char threeLEDs = 0x00;

void Tick_ThreeLEDS()
{
	switch(LED_state)
	{
		case Init:
			LED_state = LED_1;
			break;
		
		case LED_1:
			if (time_counter % 30 == 0)
			{
				LED_state = LED_2;
			}
			break;
		
		case LED_2:
			if (time_counter % 30 == 0)
			{
				LED_state = LED_3;
			}
			break;
		
		case LED_3:
			if (time_counter % 30 == 0)
			{
				LED_state = LED_1;
			}
			break;
		
		default:
			break;
	}
	
	switch(LED_state)
	{
		case Init:
			break;
		
		case LED_1:
			threeLEDs = threeLEDs & 0xF8; //frees bits 0-2 and sets them to 0
			threeLEDs = threeLEDs | 0x01;
			break;
		
		case LED_2:
			threeLEDs = threeLEDs & 0xF8; //frees bits 0-2 and sets them to 0
			threeLEDs = threeLEDs | 0x02;
			break;
		
		case LED_3:
			threeLEDs = threeLEDs & 0xF8; //frees bits 0-2 and sets them to 0
			threeLEDs = threeLEDs | 0x04;
			break;
		
		default:
			break;
	}
}

enum blink_State {Init1, Blink_On, Blink_Off} blink_state;

unsigned char blinkingLED = 0x00;

void Tick_BlinkingLED() 
{
	switch(blink_state)
	{
		case Init1:
			blink_state = Blink_On;
			break;
			
		case Blink_On:
			if (time_counter == 100)
			{
				blink_state = Blink_Off;

			}
			break;
			
		case Blink_Off:
			if (time_counter == 100)
			{
				blink_state = Blink_On;
			}
			break;
			
		default:
			break;	
	}
	switch(blink_state)
	{
		case Init1:
			break;
				
		case Blink_On:
			blinkingLED = blinkingLED | 0x08; //sets bit 3 to 1
			break;
				
		case Blink_Off:
			blinkingLED = blinkingLED & 0xF7; // sets bit 3 to 0
			break;
				
		default:
			break;
	}
}

void Tick_CombineLEDs() 
{
	PORTB = ((PORTB & 0xF0) | blinkingLED) | threeLEDs;

}

int main()
{
	DDRB = 0xFF; PORTB = 0x00; // Init port B to 0s
	
	LED_state = Init;

	TimerSet(1);
	TimerOn();
	
	while(1)
	{
		Tick_ThreeLEDS();
		Tick_BlinkingLED();
		Tick_CombineLEDs();
		while(!TimerFlag);
		TimerFlag = 0;
		time_counter++;
		if (time_counter > 100)
		{
			time_counter = 0;
		}
		
	}
}
