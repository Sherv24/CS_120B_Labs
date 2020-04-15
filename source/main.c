/*	Author: Sherwin Sahebi
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise #1
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

	unsigned char totA = 0x00;
	unsigned char totB = 0x00;
	unsigned char numA = 0x00;
	unsigned char numB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char loop = 0x00;

	while(1) {
		tmpA = PINA;
		tmpB = PINB;
		totA = 0x00;
		totB = 0x00;
		for (loop; loop <= 0x08; loop = loop + 0x01) {
			numA = (tmpA >> loop) & 0x01;
			numB = (tmpB >> loop) & 0x01; //does bit shift, then uses '&' bitwise operator to get resulting value
			totA = (numA == 0x01) ? totA + 1 : totA;
			totB = (numB == 0x01) ? totB + 1 : totB;	
		}
		PORTC = totA + totB;
		loop = 0x00;
	}
	return 1;
}
