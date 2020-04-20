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

enum States {Start, INCREMENT, DECREMENT, ZERO}state;
void Tick();

void Tick(){
	switch(state){ //Transitions
		case Start:
			state = ZERO;
			PORTC = 0x07;
			break;
			
		case INCREMENT:

			if((PINA & 0x0F) == 0x03) {	//increment
				state = ZERO;
		       		PORTC = 0;
			}

			else if((PINA & 0x0F) == 0x01) {	//decrement
				state = INCREMENT;
			}
	
			else if((PINA & 0x0F) == 0x00) {	//reset
				state = ZERO; 
			}
	
			else {
				PORTC = PORTC; 
			}
			break;
		
		case DECREMENT:
			if ((PINA & 0x0F) == 0x03) {
				state = ZERO;
				PORTC = 0;
			}
			else if ((PINA & 0x0F) == 0x02) {
				state = DECREMENT;
			}
			else if ((PINA & 0x0F) == 0x00) {
				state = ZERO;
			}
			else {
				PORTC = PORTC;
			}
			break;

		default:
			PORTC = 0x07;
			state = Start;
			break;

		case ZERO:
			if ((PINA & 0x0F) == 0x03) {
				state = ZERO;
				PORTC = 0;
			}

			else if ((PINA & 0x0F) == 0x01) {
				state = INCREMENT;
				if (PORTC < 9) {
					PORTC++;
				}
			}

			else if ((PINA & 0x0F) == 0x02) {
				state = DECREMENT;
				if (PORTC > 0) {
					PORTC--;
				}
			}
			else {
				PORTC = PORTC;
			}
			break;
	}
}
	int main(void) {

		DDRA = 0x00; PORTA = 0xFF;
		DDRC = 0xFF; PORTC = 0x00;
		state = Start;
	
		while(1) {
			Tick();
		}
		return 0;
	}

