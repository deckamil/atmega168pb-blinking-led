/*
 *	FILENAME:       ioport.h
 *
 *	DESCRIPTION:
 *		This header file contains prototypes of functions, which allow for configuration
 *		and reading of IO ports for AVR ATmega168PB.
 *
 *	AUTHOR:         Copyright (C) 2021 Kamil Deć github.com/deckamil
 *	DATE:           9 MAY 2021
 *
 *	LICENSE:
 *		This file is part of ioport module for AVR ATmega168PB.
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

#ifndef IOPORT_H_
#define IOPORT_H_

#include <stdint.h>

// Definition of port type for ioport module functions
typedef enum{
	PORTB_SEL,
	PORTC_SEL,
	PORTD_SEL,
	PORTE_SEL
} ioport_port_type;

// Definition of pin level type for ioport module functions
typedef enum{
	PIN_LOW,
	PIN_HIGH,
	INVALID_CONF	
} ioport_pin_level_type;

// Prototypes of ioport module functions
void set_port_pin_as_input(ioport_port_type port, uint8_t pin);
void set_port_pin_as_output(ioport_port_type port, uint8_t pin);
void set_port_pin_high(ioport_port_type port, uint8_t pin);
void set_port_pin_low(ioport_port_type port, uint8_t pin);
ioport_pin_level_type get_port_pin_level(ioport_port_type port, uint8_t pin);

#endif /* IOPORT_H_ */