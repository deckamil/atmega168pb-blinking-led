/*
 *	FILENAME:       timer.c
 *
 *	DESCRIPTION:
 *		This file contains definitions of functions, which use AVR ATmega168PB timer
 *		to introduce selected time delay.
 *
 *	AUTHOR:         Copyright (C) 2021 Kamil Deć github.com/deckamil
 *	DATE:           9 MAY 2021
 *
 *	LICENSE:
 *		This file is part of timer module for AVR ATmega168PB.
 *
 *		This module is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This module is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this module. If not, see <https://www.gnu.org/licenses/>.
 */ 

#include <avr/io.h>
#include "timer.h"

// Prototypes of timer module private functions
static void wait_10ms();


/*
 *	The wait_10ms() function introduces 10ms delay.
 */
static void wait_10ms(){
	
	// Set TC0 Control Registers A and B to normal mode, 1024 prescaler
	TCCR0A = 0x00;
	TCCR0B = 0x05;
	
	// Set TC0 Counter Value Register to 10ms delay
	//		Timer clock source frequency:     F_CPU/prescaler = 16000000Hz/1024 = 15625Hz
	//		Time of 1 cycle:                  1/15625Hz = 0.000064s
	//		Required number of cycles:        0.01s/0.000064s = 156 (approx)
	//		Value to load in TCNT0:           256 - 156 = 100, i.e. 0x64 in hex
	TCNT0 = 0x64;
	
	// Wait for TOV0 overflow flag to roll over
	while((TIFR0 & 0x01) == 0);
	
	// Clear TOV0 overflow flag
	TIFR0 = 0x01;
}


/*
 *	The wait_10ms_multiplicity() function introduces delay equal in total to given number of 10ms cycles.
 *	The function takes:
 *			- number_of_10ms_cycles, which defines number of 10ms cycles to wait
 *	Known limitations:
 *			- the function can wait up to 655.35 sec (limitation of uint16_t type range)
 */
void wait_10ms_multiplicity(uint16_t number_of_10ms_cycles){
	
	// Initialize cycle counter;
	uint16_t cycle = 0;
	
	// Wait required number of cycles
	do{
		
		// Wait 10 ms
		wait_10ms();
		
		// Increment cycle counter
		cycle++;
		
	}
	while (cycle < number_of_10ms_cycles);
}
