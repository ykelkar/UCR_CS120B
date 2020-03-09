#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void shift_mario()
{
	// 	for (unsigned char k = 0; k < 38; k++)
	// 	{
	// 		if (k == count)
	// 		{
	//
	// 		}
	// 	}
	if (((time_counter) % 1500 == 0) && (flag == 1) &&(ending < 6))
	{
		row[1] = row[1] >> 1; //Second_Col
		row[2] = row[2] >> 1; //Third_Col
		row[3] = row[3] >> 1; //Fourth_Col
		row[4] = row[4] >> 1; //Fifth_Col
		row[5] = row[5] >> 1; //Sixth
		row[6] = row[6] >> 1;
		
		if (count == 0)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 1)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 2)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 3)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 4)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 5)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 6)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 7)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 8)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x04 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x10 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x20 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x40 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> count))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 9)
		{
			if ((col[14] == 0xBF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 10)
		{
			if ((col[14] == 0xBF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 11)
		{
			if ((col[14] == 0xF7) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 12)
		{
			if ((col[14] == 0xEF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 13)
		{
			if ((col[14] == 0xDF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 14)
		{
			if ((col[14] == 0xEF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 15)
		{
			if ((col[14] == 0xEF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 16)
		{
			if ((col[14] == 0xF7) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 17)
		{
			if ((col[14] == 0xF7) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 18)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 19)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 20)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 21)
		{
			if ((col[14] == 0xFD) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 22)
		{
			if ((col[14] == 0xFD) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 23)
		{
			if ((col[14] == 0xFD) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 24)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 25)
		{
			if ((col[14] == 0xFD) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 26)
		{
			if ((col[14] == 0xFD) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFD) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 27)
		{
			if ((col[14] == 0xFD) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 28)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xFB) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 29)
		{
			if ((col[14] == 0xFB) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 30)
		{
			if ((col[14] == 0xF7) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 31)
		{
			if ((col[14] == 0xF7) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 1))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 32)
		{
			if ((col[14] == 0xBF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 2))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 33)
		{
			if ((col[14] == 0xBF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 3))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 34)
		{
			if ((col[14] == 0xEF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 4))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 35)
		{
			if ((col[14] == 0xEF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xBF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 5))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 36)
		{
			if ((col[14] == 0xBF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xDF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xEF) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 6))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 37)
		{
			if ((col[14] == 0xF7) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
			else if ((col[14] == 0xF7) && (row[14] == 0x80 >> 7))
			{
				row[14] = row[14] >> 1;
			}
		}
		else if (count == 38)
		{
			if ((col[14] == 0xF7) && (row[14] == 0x80 >> 8))
			{
				row[14] = row[14] >> 1;
			}
		}
		if (count > 2) //Seventh_Col
		{
			row[7] = row[7] >> 1;
		}
		if (count > 3) //Eigth_Col
		{
			row[8] = row[8] >> 1;
		}
		if (count > 4) //Ninth_Col
		{
			row[9] = row[9] >> 1;
		}
		if (count > 7) //Tenth_Col
		{
			row[10] = row[10] >> 1;
		}
		if (count > 9) //Eleventh_Col
		{
			row[11] = row[11] >> 1;
		}
		if (count > 10) //Twelfth_Col
		{
			row[12] = row[12] >> 1;
		}
		if (count > 12)
		{
			row[13] = row[13] >> 1;
		}
		if (count > 13)
		{
			row[15] = row[15] >> 1;
		}
		if (count > 14)
		{
			row[16] = row[16] >> 1;
		}
		if (count > 16)
		{
			row[17] = row[17] >> 1;
		}
		if (count > 17)
		{
			row[18] = row[18] >> 1;
		}
		if (count > 18)
		{
			row[19] = row[19] >> 1;
		}
		if (count > 20)
		{
			row[20] = row[20] >> 1;
		}
		if (count > 21)
		{
			row[21] = row[21] >> 1;
		}
		if (count > 23)
		{
			row[22] = row[22] >> 1;
		}
		if (count > 26)
		{
			row[23] = row[23] >> 1;
		}
		if (count > 27)
		{
			row[24] = row[24] >> 1;
		}
		if (count > 29)
		{
			row[25] = row[25] >> 1;
		}
		if (count > 30)
		{
			row[26] = row[26] >> 1;
		}
		if (count > 33)
		{
			row[27] = row[27] >> 1;
			ending++;
		}
		if (count > 34)
		{
			row[28] = row[28] >> 1;
		}
		if (count > 35)
		{
			row[29] = row[29] >> 1;
		}
		if (count > 36)
		{
			row[30] = row[30] >> 1;
		}
		if (count > 37)
		{
			row[31] = row[31] >> 1;
		}
		if (count > 38)
		{
			row[32] = row[32] >> 1;
		}
		count++;
	}
}