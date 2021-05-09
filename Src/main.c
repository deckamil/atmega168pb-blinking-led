/*
 *	FILENAME:       main.c
 *
 *	DESCRIPTION:
 *		This is main file of Blinking-Led program for AVR ATmega168PB Xplained Mini development board.
 *		The dev board has one led light and one button. The program turns on and off the led light in
 *		sequence after pressing the button.
 *
 *	AUTHOR:         Copyright (C) 2021 Kamil Deć github.com/deckamil
 *	DATE:           9 MAY 2021
 *
 *	LICENSE:
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program. If not, see <https://www.gnu.org/licenses/>.
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include "ioport.h"
#include "timer.h"

// Prototypes of main module functions
void ioport_initialization();
void turn_on_led();
void turn_off_led();
bool button_is_pressed();


int main(void)
{
    
	// Initialize input/output ports
	ioport_initialization();
	
	while(1){
		
		// If button is pressed
		if(button_is_pressed() == true){
			
			// Turn on led and wait 10 sec
			turn_on_led();
			wait_10ms_multiplicity(1000);
			
			// Turn off led and wait 10 sec
			turn_off_led();
			wait_10ms_multiplicity(1000);
			
			// Turn on led and wait 10 sec
			turn_on_led();
			wait_10ms_multiplicity(1000);
			
		}
		else{
			
			// Turn off led
			turn_off_led();
		}
	}
}


/*
 *	The ioport_initialization() function configures AVR ATmega168PB PORTB pins
 *	connected with Xplained Mini led light and button.
 */
void ioport_initialization(){
	
	// The Xplained Mini led light is connected with Pin 5 of PORTB,
	// therefore this pin need to be configured as output.
	set_port_pin_as_output(PORTB_SEL, PB5);
	
	// The Xplained Mini button is connected with Pin 7 of PORTB,
	// therefore this pin need to be configured as input.
	set_port_pin_as_input(PORTB_SEL, PB7);
}


/*
 *	The turn_on_led() function turns on Xplained Mini led light.
 */
void turn_on_led(){
	
	// The Xplained Mini led light is connected with Pin 5 of PORTB,
	// therefore this pin need to be set to high state.
	set_port_pin_high(PORTB_SEL, PB5);
}


/*
 *	The turn_off_led() function turns off Xplained Mini led light.
 */
void turn_off_led(){
	
	// The Xplained Mini led light is connected with Pin 5 of PORTB,
	// therefore this pin need to be set to low state.
	set_port_pin_low(PORTB_SEL, PB5);
}


/*
 *	The button_is_pressed() function returns information if Xplained Mini board
 *	button is pressed or not.
 *	The function returns:
 *			- false, when button is not pressed
 *			- true, when button is pressed
 */
bool button_is_pressed(){
	
	// Result of the function
	bool result = false;
	
	// When Xplained Mini button is pressed, then Pin 7 of PORTB
	// is set to low state
	if(get_port_pin_level(PORTB_SEL, PB7) == PIN_LOW){
		
		// Button is pressed
		result = true;
	}
	else{
		
		//Button is not pressed
		result = false;
	}
	
	// Return results
	return result;
}
