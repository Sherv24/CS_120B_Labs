/*	Author: Sherwin Sahebi
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #2  Exercise #3
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
	DDRC = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initial

	unsigned char cntavail = 0x00;
	unsigned char parkOne = 0x00;
	unsigned char parkTwo = 0x00;
	unsigned char parkThree = 0x00;
	unsigned char parkFour = 0x00;

	while(1) {
		parkOne = PINA & 0x01;
		parkTwo = PINA & 0x02;
		parkThree = PINA & 0x04;
		parkFour = PINA & 0x08;

		//parkOne wouldn't need shift
		parkTwo = parkTwo >> 1;
		parkThree = parkThree >> 2;
		parkFour = parkFour >> 3;

		cntavail = 0x04 - (parkFour + parkThree + parkTwo + parkOne);
		PORTC = (cntavail == 0x00) ? 0x00 : cntavail;
    }
}
