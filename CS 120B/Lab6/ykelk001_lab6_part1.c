/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab 6  Exercise 1
 *	Exercise Description: This program simulates a button that increments the value displayed on the LCD display by one and a button that decrements the value
 *						  on the LCD display by one. The value on LCD display is initially 0. When the value is 9, it cannot be incremented any further and when the 
 *						  value is 0 is cannot be decremented any further. When both buttons are pressed at the same time, the value of 
 *						  the LCD display value resets back to 0. When the increment button is held down, the numbers increase continuously until released. 
 *						  When the decrement button is held down, the numbers decrease continuously until released. 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 */

#include <avr/io.h>
#include "io.c"
#include <avr/interrupt.h>

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.

// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.
unsigned long _avr_timer_M = 1; // Start count from here, down to 0. Default 1 ms.
unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1ms ticks

void TimerOn() {
	// AVR timer/counter controller register TCCR1
	TCCR1B = 0x0B;// bit3 = 0: CTC mode (clear timer on compare)
	// bit2bit1bit0=011: pre-scaler /64
	// 00001011: 0x0B
	// SO, 8 MHz clock or 8,000,000 /64 = 125,000 ticks/s
	// Thus, TCNT1 register will count at 125,000 ticks/s
	// AVR output compare register OCR1A.
	OCR1A = 125; // Timer interrupt will be generated when TCNT1==OCR1A
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

void TimerOff() {
	TCCR1B = 0x00; // bit3bit1bit0=000: timer off
}

void TimerISR() {
	TimerFlag = 1;
}

// In our approach, the C programmer does not touch this ISR, but rather TimerISR()
ISR(TIMER1_COMPA_vect) {
	// CPU automatically calls when TCNT1 == OCR1 (every 1 ms per TimerOn settings)
	_avr_timer_cntcurr--; // Count down to 0 rather than up to TOP
	if (_avr_timer_cntcurr == 0) { // results in a more efficient compare
		TimerISR(); // Call the ISR that the user uses
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

// Set TimerISR() to tick every M ms
void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}
enum States {Init, Changer, Increment, Decrement, Wait} state;

unsigned char value = 0x00;
void Tick()
{
	unsigned char A = ~PINA & 0x03;
	switch(state)
	{ //Transitions
		
		case Init:
			state = Changer;
			break;
		
		case Changer:
			if (A == 0x01)
			{
				if (value < 9)
				{
					state = Increment;
				}
				else
				{
					state = Changer;
				}
			}
			else if (A == 0x02)
			{
				if (value > 0)
				{
					state = Decrement;
				}
				else
				{
					state = Changer;
				}
			}
			else if (A == 0x03)
			{
				state = Init;
			}
			else
			{
				state = Changer;
			}
			break;
		
		case Increment:
			state = Wait;
			break;
		
		case Decrement:
			state = Wait;
			break;
		
		case Wait:
			if (A == 0x03)
			{
				state = Init;
			}
			else if (A == 0x01)
			{
				if (value < 9)
				{
					state = Increment;
				}
			}
			else if (A == 0x02)
			{
				if (value > 0)
				{
					state = Decrement;
				}
			}
			else
			{
				state = Changer;
			}
			break;
		
		default:
			break;
	}
	switch(state) { //State Actions
		case Init:
			value = 0;
			LCD_Cursor(1);
			LCD_WriteData(value + '0');
			break;
			
		case Changer:
			break;
		
		case Increment:
			value++;
			LCD_Cursor(1);
			LCD_WriteData(value + '0');
			break;
		
		case Decrement:
			value--;
			LCD_Cursor(1);
			LCD_WriteData(value + '0');
			break;
		
		case Wait:
			break;
		
		default:
			break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00; // LCD data lines
	DDRD = 0xFF; PORTD = 0x00; // LCD control lines
	
	TimerSet(30);				// Sets timer
	TimerOn();					// Turns timer on
	
	// Initializes the LCD display
	LCD_init();
	LCD_Cursor(1);
	LCD_WriteData(value + '0');
	
	state = Init;
	
	while(1)
	{
		Tick();
		while (!TimerFlag);
		TimerFlag = 0;
	}
}
