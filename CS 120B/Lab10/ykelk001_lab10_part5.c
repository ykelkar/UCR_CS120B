#include <avr/interrupt.h>
#include "io.c"
#include "timer.h"
#include "keypad.h"
#include <avr/io.h>

char* platform = "        *          *          *      ";
unsigned char col = 0;
unsigned char display[32];
unsigned char location[32];
unsigned char position = 0;
unsigned char start = 1;
unsigned char button = 0x00;
typedef struct Tasks {
	//Task's current state, period, and the time elapsed
	// since the last tick
	signed char state;
	unsigned long int period;
	unsigned long int elapsedTime;
	//Task tick function
	int (*TickFct)(int);
} task;


enum States{init} state;

int tick(int state){

	for (unsigned int j = 0; j < 32; j++){
		display[j] = platform[(col + j) % 36];
	}
	col = (col + 1) % 36;

	location[32] = 0;

	if (display[position] == '*'){
		LCD_DisplayString(1, "Oops You Lose");
		start = 0;
	}
	else{
		LCD_DisplayString(1, display);
	}

	if (!GetBit(PINB, 1)){
		pos = 1;
	}
	else if (!GetBit(PINB, 2)){
		pos = 17;
	}

	LCD_Cursor(position);


	return state;
}



int main(void)
{
	// PORTB set to output, outputs init 0s
	DDRD = 0xFF;
	PORTD = 0x00;
	// PC7..4 outputs init 0s, PC3..0 inputs init 1s
	DDRA = 0xFF;
	PORTA = 0x00;

	DDRB = 0x00;
	PORTB = 0xFF;

	button = ~PINB & 0x07;

	static task task1;

	task *tasks[] = {&task1};

	unsigned long int task_period = 50;
	unsigned long int task_tick = 50;
	const unsigned short numTasks = sizeof(task)/sizeof(task*);



	task1.state = -1;
	task1.period = task_period;
	task1.elapsedTime = task_tick;
	task1.TickFct = &tick;

	TimerSet(task_tick);
	TimerOn();
	LCD_init();

	while (1)
	{

		if (start){
			// Scheduler code
			for (unsigned short i = 0; i < numTasks; i++ ) {
				// Task is ready to tick
				if ( tasks[i]->elapsedTime == tasks[i]->period ) {
					// Setting next state for task
					tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
					// Reset elapsed time for next tick.
					tasks[i]->elapsedTime = 0;
				}
				tasks[i]->elapsedTime += 1;
			}
		}

		if (!GetBit(PINB, 0)){
			run = 1;
		}



		while(!TimerFlag){};
		TimerFlag = 0;


	}
}