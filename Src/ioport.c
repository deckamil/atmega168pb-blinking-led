/*
 *	FILENAME:       ioport.c
 *
 *	DESCRIPTION:
 *		This file contains definitions of functions, which allow for configuration
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

#include <avr/io.h>
#include "ioport.h"


/*
 *	The set_port_pin_as_input() function allows to configure selected port pin as input.
 *	The function takes:
 *			- port, which defines port number from B to E
 *			- pin, which defines pin number from 0 to 7
 */
void set_port_pin_as_input(ioport_port_type port, uint8_t pin){
	
	// Check correctness of pin selection for PORTB
	if(port == PORTB_SEL && pin >= PINB0 && pin <= PINB7){
			
		// Set selected pin of PORTB as input
		DDRB = DDRB & ~_BV(pin);
			
	}
	// Check correctness of pin selection for PORTC
	else if(port == PORTC_SEL && pin >= PINC0 && pin <= PINC6){
			
		//Set selected pin of PORTC as input
		DDRC = DDRC & ~_BV(pin);
			
	}
	// Check correctness of pin selection for PORTD
	else if(port == PORTD_SEL && pin >= PIND0 && pin <= PIND7){
			
		//Set selected pin of PORTD as input
		DDRD = DDRD & ~_BV(pin);
			
	}
	// Check correctness of pin selection for PORTE
	else if(port == PORTE_SEL && pin >= PINE0 && pin <= PINE3){
			
		//Set selected pin of PORTE as input
		DDRE = DDRE & ~_BV(pin);
			
	}
}


/*
 *	The set_port_pin_as_output() function allows to configure selected port pin as output.
 *	The function takes:
 *			- port, which defines port number from B to E
 *			- pin, which defines pin number from 0 to 7
 */
void set_port_pin_as_output(ioport_port_type port, uint8_t pin){
	
	// Check correctness of pin selection for PORTB
	if(port == PORTB_SEL && pin >= PINB0 && pin <= PINB7){
		
		// Set selected pin of PORTB as output
		DDRB = DDRB | _BV(pin);
		
	}
	// Check correctness of pin selection for PORTC
	else if(port == PORTC_SEL && pin >= PINC0 && pin <= PINC6){
		
		//Set selected pin of PORTC as output
		DDRC = DDRC | _BV(pin);
		
	}
	// Check correctness of pin selection for PORTD
	else if(port == PORTD_SEL && pin >= PIND0 && pin <= PIND7){
		
		//Set selected pin of PORTD as output
		DDRD = DDRD | _BV(pin);
		
	}
	// Check correctness of pin selection for PORTE
	else if(port == PORTE_SEL && pin >= PINE0 && pin <= PINE3){
		
		//Set selected pin of PORTE as output
		DDRE = DDRE | _BV(pin);
		
	}
}


/*
 *	The set_port_pin_high() function allows to set port pin to high state.
 *	The function takes:
 *			- port, which defines port number from B to E
 *			- pin, which defines pin number from 0 to 7
 */
void set_port_pin_high(ioport_port_type port, uint8_t pin){
	
	// Check correctness of pin selection for PORTB
	if(port == PORTB_SEL && pin >= PINB0 && pin <= PINB7){
			
		// Check if selected pin of PORTB is configured as output
		if((DDRB & _BV(pin)) == _BV(pin)){
			
			// Set selected pin of PORTB to high state
			PORTB = PORTB | _BV(pin);
		}
		
	}
	// Check correctness of pin selection for PORTC
	else if(port == PORTC_SEL && pin >= PINC0 && pin <= PINC6){
			
		// Check if selected pin of PORTC is configured as output
		if((DDRC & _BV(pin)) == _BV(pin)){
			
			// Set selected pin of PORTC to high state
			PORTC = PORTC | _BV(pin);
		}
		
	}
	// Check correctness of pin selection for PORTD
	else if(port == PORTD_SEL && pin >= PIND0 && pin <= PIND7){
			
		// Check if selected pin of PORTD is configured as output
		if((DDRD & _BV(pin)) == _BV(pin)){
			
			// Set selected pin of PORTD to high state
			PORTD = PORTD | _BV(pin);
		}
		
	}
	// Check correctness of pin selection for PORTE
	else if(port == PORTE_SEL && pin >= PINE0 && pin <= PINE3){
			
		// Check if selected pin of PORTE is configured as output
		if((DDRE & _BV(pin)) == _BV(pin)){
			
			// Set selected pin of PORTE to high state
			PORTE = PORTE | _BV(pin);
		}
		
	}
}


/*
 *	The set_port_pin_low() function allows to set port pin to low state.
 *	The function takes:
 *			- port, which defines port number from B to E
 *			- pin, which defines pin number from 0 to 7
 */
void set_port_pin_low(ioport_port_type port, uint8_t pin){
	
	// Check correctness of pin selection for PORTB
	if(port == PORTB_SEL && pin >= PINB0 && pin <= PINB7){
			
		// Check if selected pin of PORTB is configured as output
		if((DDRB & _BV(pin)) == _BV(pin)){
				
			// Set selected pin of PORTB to low state
			PORTB = PORTB & ~_BV(pin);
		}
			
	}
	// Check correctness of pin selection for PORTC
	else if(port == PORTC_SEL && pin >= PINC0 && pin <= PINC6){
			
		// Check if selected pin of PORTC is configured as output
		if((DDRC & _BV(pin)) == _BV(pin)){
				
			// Set selected pin of PORTC to low state
			PORTC = PORTC & ~_BV(pin);
		}
			
	}
	// Check correctness of pin selection for PORTD
	else if(port == PORTD_SEL && pin >= PIND0 && pin <= PIND7){
			
		// Check if selected pin of PORTD is configured as output
		if((DDRD & _BV(pin)) == _BV(pin)){
				
			// Set selected pin of PORTD to low state
			PORTD = PORTD & ~_BV(pin);
		}
			
	}
	// Check correctness of pin selection for PORTE
	else if(port == PORTE_SEL && pin >= PINE0 && pin <= PINE3){
			
		// Check if selected pin of PORTE is configured as output
		if((DDRE & _BV(pin)) == _BV(pin)){
				
			// Set selected pin of PORTE to low state
			PORTE = PORTE & ~_BV(pin);
		}
			
	}
}


/*
 *	The get_port_pin_level() function allows to read whether port pin is high or low.
 *	The function takes:
 *			- port, which defines port number from B to E
 *			- pin, which defines pin number from 0 to 7
 *	The function returns:
 *			- PIN_LOW, when port pin is low
 *			- PIN_HIGH, when port pin is high
 *			- INVALID_CONF, when wrong port or pin is selected
 */
ioport_pin_level_type get_port_pin_level(ioport_port_type port, uint8_t pin){
	
	// Result of the function
	ioport_pin_level_type result = INVALID_CONF;
	
	// Check correctness of pin selection for PORTB
	if(port == PORTB_SEL && pin >= PINB0 && pin <= PINB7){
			
		// Check status of selected pin of PORTB
		if((PINB & _BV(pin)) == _BV(pin)){
			
			// Pin is high
			result = PIN_HIGH;
		}
		else{
			
			// Pin is low
			result = PIN_LOW;
		}
			
	}
	// Check correctness of pin selection for PORTC
	else if(port == PORTC_SEL && pin >= PINC0 && pin <= PINC6){
			
		// Check status of selected pin of PORTC
		if((PINC & _BV(pin)) == _BV(pin)){
			
			// Pin is high
			result = PIN_HIGH;
		}
		else{
			
			// Pin is low
			result = PIN_LOW;
		}
			
	}
	// Check correctness of pin selection for PORTD
	else if(port == PORTD_SEL && pin >= PIND0 && pin <= PIND7){
			
		// Check status of selected pin of PORTD
		if((PIND & _BV(pin)) == _BV(pin)){
			
			// Pin is high
			result = PIN_HIGH;
		}
		else{
			
			// Pin is low
			result = PIN_LOW;
		}
			
	}
	// Check correctness of pin selection for PORTE
	else if(port == PORTE_SEL && pin >= PINE0 && pin <= PINE3){
			
		// Check status of selected pin of PORTE
		if((PINE & _BV(pin)) == _BV(pin)){
			
			// Pin is high
			result = PIN_HIGH;
		}
		else{
			
			// Pin is low
			result = PIN_LOW;
		}
			
	}
	
	// Return results
	return result;
}
