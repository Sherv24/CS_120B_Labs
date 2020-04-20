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

enum States {Start, Init, INCREMENT, DECREMENT, WAIT, RESET}state;
void Tick();

void Tick(){
	switch(state){ //Transitions
		case Start:
			state = Init;
			break;
			
		case Init:
		if((~PINA & 0x03) == 0x01) {	//increment
			state = INCREMENT;
		       	break;
		}

		else if((~PINA & 0x03) == 0x02) {	//decrement
			state = DECREMENT; 
			break;
		}

		else if((~PINA & 0x03) == 0x03) {	//reset
			state = RESET; 
			break;
		}

		else {
			state = Init; 
			break;
		}
		
		case INCREMENT:
		state = WAIT;
		break;
		
		case DECREMENT:
		state = WAIT;
		break;
		
		case WAIT:
		if (((~PINA & 0x03) == 0x01) || ((~PINA & 0x03) == 0x02)) {
			state = WAIT; break;
		}
		else if((~PINA & 0x03) == 0x03)
		{
			state = RESET; break;
		}
		else
		{
			state = Init; break;
		}
		
		case RESET:
		state = (((~PINA & 0x03) == 0x01) || ((~PINA & 0x03) == 0x02)) ? RESET : Init;
		break;
	
		
		default:
		break;
	}

	switch(state){ //State actions
		case Start:
			PORTC = 0x07;
			break;
		
		case Init:
			break;
		
		case INCREMENT:
			PORTC = (PORTC >= 0x09) ? 0x09 : PORTC + 0x01;
			break;
		
		case DECREMENT:
			PORTC = (PORTC <= 0x00) ? 0x00 : PORTC - 0x01;
			break;
		
		case WAIT:
			break;
		
		case RESET:
			PORTC = 0x00; 
			break;
		}
}
int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x07;
	state = Start;
	while(1)
	{
		Tick();
	}
}


