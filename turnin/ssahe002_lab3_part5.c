/*	Author: Sherwin Sahebi
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise #4
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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
	
	unsigned short weight = 0x0000;
	unsigned char tmp = 0x00;
	unsigned char out = 0x01;
    while(1)
    {
        weight = (PIND << 1);
	tmp = PINB & 0x01;
	
	weight = weight | tmp;
	
//	out = (weight >= 70) ? 0x02 : out = (weight > 5 && weight < 70) ? 0x04 : 0x00;

	if (weight >= 0x0046) {
		out = 0x02;
	}
	else if ((weight < 0x0046) && (weight > 0x0055)) {
		out = 0x04;
	}


	PORTB = out;
	out = 0x01;
	weight = 0x0000;
	}	
return 1;
}



