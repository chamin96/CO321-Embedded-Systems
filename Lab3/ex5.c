#include <avr/io.h>
#include <avr/interrupt.h>

void delayTimer0()
{
	TCNT0 = 0;	 // load timer counter register
	TCCR0A = 0x00; // Timer0 normal mode with 1:1024 prescaler
	TCCR0B = 0x05;
	while ((TIFR0 & 0x01) == 0); /*wait till timer overflow bit (T0V0) is set*/
	TCCR0A = 0x00;
	TCCR0B = 0x00;
	TIFR0 = 0x01;
}

int main()
{

	DDRB = DDRB | (1 << 5);  // configure pin 5 of PORTB
	DDRD = DDRD | (15 << 4); // set pin 7,6,5,4 of PORTD for output

	TCNT1 = 3036; // Set Timer1 initial value
	TCCR1A = 0x00; // Timer1 normal mode
	TCCR1B = 0x04; // Timer1 with 256 prescler
	TIMSK1 = 0x01; // Enable timer1 overflow interrupt(TOIE1)

	sei(); // Enable global interrupts by setting global interrupt enable bit in SREG

	while (1)
	{

		int i = 7;
		while (i > 3)
		{
			PORTD = PORTD | (1 << i); /* set pin 5 high to turn led on */
			delayTimer0();
			delayTimer0();
			delayTimer0();
			delayTimer0();
			PORTD = PORTD & ~(1 << i); /* set pin 5 low to turn led off */
			delayTimer0();
			delayTimer0();
			delayTimer0();
			delayTimer0();
			i--;
		}
		i = 4;
		while (i < 8)
		{
			PORTD = PORTD | (1 << i); /* set pin 5 high to turn led on */
			delayTimer0();
			delayTimer0();
			delayTimer0();
			delayTimer0();
			PORTD = PORTD & ~(1 << i); /* set pin 5 low to turn led off */
			delayTimer0();
			delayTimer0();
			delayTimer0();
			delayTimer0();
			i++;
		}
	}
}

ISR(TIMER1_OVF_vect)
{
	PORTB = PORTB ^ (1 << 5); // toggle LED
	// TCNT1 = 3036;			  // Reset Timer1
}
