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
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States {Start, TMP, LOCK, UNLOCK, FAIL, PRESS, RELEASE}state;
void Tick();
unsigned char x = 0;

void Tick(){
	switch(state){ //Transitions
		case Start:
			state = LOCK;
			PORTB = 0x00;
			break;
		
		case TMP:
			if ((PINA & 0x0F) == 0x02) {
				PORTB = 0x01;
				state = UNLOCK;
			}
			else if ((PINA & 0x0F) == 0x04) {
				state = TMP;
			}
			else {
				state = LOCK;
			}
			break;

		case LOCK:
			state = ((PINA & 0x0F) == 0x04) ? TMP : LOCK;
			break;

		case UNLOCK:
			if ((PINA & 0xF0) == 0x80) {
			       	PORTB = 0x00;
				state = LOCK;
			}
	 		else {
				state = UNLOCK;
			}
			break;

		case FAIL:
			state = LOCK;

		case PRESS:
			if (PINA == 0x00) {
				state = RELEASE;
			}
			else if (PINA == 0x04) {
				state = PRESS;
			}
			else {
				state = FAIL;
			}
			break;

		case RELEASE:
			if ((PINA == 0x01) && (x == 0x07)) {
				x = 0x00;
				PORTB = 0x01;
				state = UNLOCK;
			}
			else if (PINA == 0x00) {
				state = RELEASE;
			}
			else if ((PINA == 0x01) && (x == 0x01)) {
				state = RELEASE;
				x = 0x03;
			}
			else if ((PINA == 0x02) && (x == 0x03)) { 
				state = RELEASE;
				x = 0x07;
			}
			else {
				x = 0x00;
				state = FAIL;
			}
			break;


		default:
			state = Start;
			break;

		break;
	}
	switch(state) {
		case Start:
		case TMP:
		case LOCK:
		case UNLOCK:
		case PRESS:
		case RELEASE:
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0xFF; PORTB = 0x00; 

	state = Start;

	while(1) {
		Tick();
	}
	return 0;
}



