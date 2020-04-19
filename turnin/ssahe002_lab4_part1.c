/*	Author: Sherwin Sahebi
 *  Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
enum States {Start, Init, POWER_OFF, WAIT1, POWER_ON, WAIT2} state;
void Tick();

void Tick() {
	switch(state) { //state transitions
		case Start:
			PORTB = 0x01;
			state = Init;
			break;
		
		case Init:
			state = ((~PINA & 0x01) == 0x01) ? POWER_OFF : Init;
			break;

		case POWER_OFF:
			state = ((~PINA & 0x01) == 0x00) ? WAIT1 : POWER_OFF;
			break;

		case WAIT1:
			state = ((~PINA & 0x01) == 0x01) ? POWER_ON : WAIT1;
			break;

		case POWER_ON:
			state = ((~PINA & 0x01) == 0x00) ? WAIT2 : POWER_ON;
			break;

		case WAIT2:
			state = ((~PINA & 0x01) == 0x01) ? POWER_OFF : WAIT2;
			break;

		default:
			break;
	}

	switch(state) { //state actions
		case Start:
			break;

		case Init:
			PORTB = 0x01;
			break;

		case POWER_OFF:
			PORTB = 0x02;
			break;

		case WAIT1:
			break;

		case POWER_ON:
			PORTB = 0x01;
			break;

		case WAIT2:
			break;

		default:
			break;
	}
}

			
int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x01;
	state = Start;

	while (1) {
		Tick(); //starts  tick function call
	}
}



