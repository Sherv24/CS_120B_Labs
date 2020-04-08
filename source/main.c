/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	while(1) {
		// 1) Read input
		tmpA = PINA & 0x01;
		tmpB = PINA & 0x02;
		// 2) Perform computation
		// if PA0 is 1, set PB1PB0 = 01, else = 10
		if((tmpA == 0x01) && (tmpB == 0x00))
		{
			PORTB = 0x01;
		}
		else
		{
			PORTB = 0x00;
		}
	}
	return 0;
}
