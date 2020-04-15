/*	Author: Sherwin Sahebi
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0x05;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0x00;

while(1) {
	tmpA = PINA & 0x0F;

	if (tmpA == 0x00) {
		PORTC = 0x40;
	}
	
	else if (tmpA == 1) {
		PORTC = 0x60;
		}

	else if (tmpA == 2) {
		PORTC = 0x60;
		}
	
	else if (tmpA == 3) {
	      	PORTC = 0x70;
		}

	else if	(tmpA == 4) {
		PORTC = 0x70;
		}
	
	else if (tmpA == 5) {
		PORTC = 0x38;
	       	}

	else if	(tmpA == 6) {
		PORTC = 0x38;
		}
	
	else if ((tmpA >= 7) && (tmpA <= 9)) {
		PORTC = 0x3C;
		}
	
	else if ((tmpA >= 10) && (tmpA <= 12)) {
		PORTC = 0x3E;
		}
	
	else if ((tmpA >= 13) && (tmpA <= 15)) {
		PORTC = 0x3F;
		}
	}
	return 1;
}



