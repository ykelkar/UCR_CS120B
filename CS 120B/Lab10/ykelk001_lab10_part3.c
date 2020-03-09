/*	Name & E-mail: Yash Kelkar		ykelk001@ucr.edu
 *	Lab Section: 25
 *	Assignment: Lab 10  Exercise 3
 *	Exercise Description: This program combines the functionality of the keypad and LCD so when keypad is pressed and released, 
 *						  the character of the button pressed is displayed on the LCD, and stays displayed until a different button 
 *						  press occurs. 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 */

#include <avr/io.h>
#include "bit.h"
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

////////////////////////////////////////////////////////////////////////////////

// Returns '\0' if no key pressed, else returns char '1', '2', ... '9', 'A', ...
// If multiple keys pressed, returns leftmost-topmost one
// Keypad must be connected to port C
// Keypad arrangement
//        Px4 Px5 Px6 Px7
//	  col 1   2   3   4
//  row  ______________
//Px0 1	| 1 | 2 | 3 | A
//Px1 2	| 4 | 5 | 6 | B
//Px2 3	| 7 | 8 | 9 | C
//Px3 4	| * | 0 | # | D

#include <bit.h>

// Keypad Setup Values
#define KEYPADPORT PORTC
#define KEYPADPIN  PINC
#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3
#define COL1 4
#define COL2 5
#define COL3 6
#define COL4 7

////////////////////////////////////////////////////////////////////////////////
//Functionality - Gets input from a keypad via time-multiplexing
//Parameter: None
//Returns: A keypad button press else '\0'
unsigned char GetKeypadKey() {

	// Check keys in col 1
	KEYPADPORT = SetBit(0xFF,COL1,0); // Set Px4 to 0; others 1
	asm("nop"); // add a delay to allow PORTx to stabilize before checking
	if ( GetBit(~KEYPADPIN,ROW1) ) { return '1'; }
	if ( GetBit(~KEYPADPIN,ROW2) ) { return '4'; }
	if ( GetBit(~KEYPADPIN,ROW3) ) { return '7'; }
	if ( GetBit(~KEYPADPIN,ROW4) ) { return '*'; }

	// Check keys in col 2
	KEYPADPORT = SetBit(0xFF,COL2,0); // Set Px5 to 0; others 1
	asm("nop"); // add a delay to allow PORTx to stabilize before checking
	if ( GetBit(~KEYPADPIN,ROW1) ) { return '2'; }
	if ( GetBit(~KEYPADPIN,ROW2) ) { return '5'; }
	if ( GetBit(~KEYPADPIN,ROW3) ) { return '8'; }
	if ( GetBit(~KEYPADPIN,ROW4) ) { return '0'; }

	// Check keys in col 3
	KEYPADPORT = SetBit(0xFF,COL3,0); // Set Px6 to 0; others 1
	asm("nop"); // add a delay to allow PORTx to stabilize before checking
	if ( GetBit(~KEYPADPIN,ROW1) ) { return '3'; }
	if ( GetBit(~KEYPADPIN,ROW2) ) { return '6'; }
	if ( GetBit(~KEYPADPIN,ROW3) ) { return '9'; }
	if ( GetBit(~KEYPADPIN,ROW4) ) { return '#'; }

	// Check keys in col 4
	KEYPADPORT = SetBit(0xFF,COL4,0); // Set Px7 to 0; others 1
	asm("nop"); // add a delay to allow PORTx to stabilize before checking
	if (GetBit(~KEYPADPIN,ROW1) ) { return 'A'; }
	if (GetBit(~KEYPADPIN,ROW2) ) { return 'B'; }
	if (GetBit(~KEYPADPIN,ROW3) ) { return 'C'; }
	if (GetBit(~KEYPADPIN,ROW4) ) { return 'D'; }
	
	return '\0';
}

typedef struct Tasks {
	//Task's current state, period, and the time elapsed
	// since the last tick
	signed char keypad_state;
	unsigned long int period;
	unsigned long int elapsedTime;
	//Task tick function
	int (*TickFct)(int);
} task;

enum Keypad_States{Init, Wait, Keypad_Press} keypad_state;

unsigned char x = 0x1F;
unsigned char num = 0x00;

int Keypad_Tick(int keypad_state)
{
	switch (keypad_state)
	{
		case Init:
		keypad_state = Wait;
		break;
		
		case Wait:
		if (x != 0x1F)
		{
			keypad_state = Keypad_Press;
		}
		else
		{
			keypad_state = Wait;
		}
		break;
		
		case Keypad_Press:
		if (x == 0x1F)
		{
			keypad_state = Wait;
		}
		else
		{
			keypad_state = Keypad_Press;
		}
		break;
		
		default:
		break;
	}
	
	switch(keypad_state)
	{
		case Init:
		break;
		
		case Wait:
		break;
		
		case Keypad_Press:
		x = GetKeypadKey();
		break;
		
		default:
		break;
	}
	
	return keypad_state;
}

int Keypad_Val_Tick(int keypad_state)
{

	x = GetKeypadKey();
	switch (x) {
		case '\0':
			PORTB = 0x1F;
			break; // All 5 LEDs on
		case '1':
			PORTB = 0x01;
			num = 1;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '2':
			PORTB = 0x02;
			num = 2;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '3':
			PORTB = 0x03;
			num = 3;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '4':
			PORTB = 0x04;
			num = 4;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '5':
			PORTB = 0x05;
			num = 5;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '6':
			PORTB = 0x06;
			num = 6;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '7':
			PORTB = 0x07;
			num = 7;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '8':
			PORTB = 0x08;
			num = 8;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '9':
			PORTB = 0x09;
			num = 9;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case 'A':
			PORTB = 0x0A;
			num = 17;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case 'B':
			PORTB = 0x0B;
			num = 18;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case 'C':
			PORTB = 0x0C;
			num = 19;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case 'D':
			PORTB = 0x0D;
			num = 20;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '*':
			PORTB = 0x0E;
			num = -6;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '0':
			PORTB = 0x00;
			num = 0;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		case '#':
			PORTB = 0x0F;
			num = -13;
			LCD_Cursor(1);
			LCD_WriteData(num + '0');
			break;
		default:
			PORTB = 0x1B;
			break; // Should never occur. Middle LED off.
	}
	return keypad_state;
}
int main(void)
{
	DDRB = 0xFF; PORTB = 0x00; // PORTB set to output, outputs init 0s
	DDRC = 0xF0; PORTC = 0x0F; // PC7..4 outputs init 0s, PC3..0 inputs init 1s
	DDRA = 0xFF; PORTA = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned long int keypad_period = 100;
	unsigned long int keypad_tick = 100;
	
	static task task1, task2;
	task *tasks[] = {&task1, &task2};
	
	const unsigned short numTasks = sizeof(task)/sizeof(task*);
	
	task1.keypad_state = -1;
	task1.period = keypad_period;
	task1.elapsedTime = keypad_period;
	task1.TickFct = &Keypad_Tick;
	
	task2.keypad_state = -1;
	task2.period = keypad_period;
	task2.elapsedTime = keypad_period;
	task2.TickFct = &Keypad_Val_Tick;
	
	TimerSet(keypad_tick);
	TimerOn();
	
	LCD_init();
	
	unsigned short i;
	while(1)
	{
		for (i = 0; i < numTasks; i++ )
		{
			if ( tasks[i]->elapsedTime == tasks[i]->period )
			{
				tasks[i]->keypad_state = tasks[i]->TickFct(tasks[i]->keypad_state);
				tasks[i]->elapsedTime = 0;
			}
			tasks[i]->elapsedTime += 1;
		}
		
		while(!TimerFlag);
		TimerFlag = 0;
	}
}
