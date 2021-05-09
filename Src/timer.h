/*
 *	FILENAME:       timer.h
 *
 *	DESCRIPTION:
 *		This header file contains prototypes of functions, which use AVR ATmega168PB timer
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

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

// Prototypes of timer module functions
void wait_10ms_multiplicity(uint16_t number_of_10ms_cycles);

#endif /* TIMER_H_ */