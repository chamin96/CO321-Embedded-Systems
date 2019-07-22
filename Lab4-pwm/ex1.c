#include <avr/io.h>

int main()
{
	DDRD = DDRD | (1<<3); //set pin 3 for output
	DDRB = DDRB | (1<<5); //set pin 5
	TCNT0 = 0;
	TCCR0A = 0x11; //timer0 fast pwm mode
	TCCR0B = 0x11; // 1:64 prescaler
	OCR0 = 127; // compare reg value

	while(1){
		PORTB = (1<<5);
	}

	return 0;
}