#include <avr/io.h>

int main()
{
	DDRD = DDRD | (1<<6); //set pin 6 for output
	DDRB = DDRB | (1<<5); //set pin 5
	

	TCNT0 = 0;
    OCR0A = 127; // set PWM for 50% duty cycle
    TCCR0A |= (1 << COM0A1); // set none-inverting mode
    TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast PWM Mode
    TCCR0B |= (1 << CS00) | (1 << CS01); // set prescaler to 64 and starts PWM

	while(1){
		PORTB = (1<<5);
	}

	return 0;
}