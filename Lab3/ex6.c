#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS  200

unsigned char counter = 0;

ISR (TIMER0_OVF_vect)    // Timer1 ISR
{
  counter++;
	TCNT0 = 6;   // for 1 sec at 16 MHz
}

int main()
{
	DDRB = DDRB | (1<<5);  // set pin 5 of port B for output

	TCNT0 = 6;   // for 1 sec at 16 MHz

	TCCR0A = 0x00;
	TCCR0B = 0x04;  // Timer mode with 256 prescler

	TIMSK0 = 0b00000100 ;   // Enable timer0 overflow interrupt(TOIE0)

	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG

	while(1)
	{
    if (counter == 25){
      PORTB = PORTB ^ (1<<5); // toggle LED
      counter = 0;
    }

	}
}
