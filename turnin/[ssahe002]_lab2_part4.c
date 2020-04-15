/*	Author: Sherwin Sahebi
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #2  Exercise #4
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
	DDRA = 0x00; PORTA = 0x01; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0x0A;
	DDRC = 0x00; PORTB = 0x08; // Configure port B's 8 pins as outputs, initial
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char total = 0x00;
	unsigned char wA = 0x00;
	unsigned char wB = 0x00;
	unsigned char wC = 0x00;
	unsigned char aD = 0x00;
	

	while(1) {
		wA = PINA;
		wB = PINB;
		wC = PINC;
		total = wA + wB + wC;
		
		aD = (total > 140) ? 0x01 : aD;
		aD = (abs(wA - wC) > 80) ? aD | 0x02 : aD;
		
		PORTD = total | aD;
		aD = 0x00;
	}
}
