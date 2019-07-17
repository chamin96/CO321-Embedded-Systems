#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

// Timer1 overflow interrupt service routine
ISR(TIMER1_OVF_vect){
    PORTB = PORTB ^ (1<<5); // toggle LED
    TCNT1 = 3036;           // reset Timer 1
}

int main (void) {
	int i;

    DDRB = DDRB | (31<<1); /* configure pin 5,4,3,2,1 of PORTB for output including LED pin 5*/

	TIMSK = 0b00000100;    // enable Timer 1 overflow interrupt
	TCCR1A = 0x00; 	       // normal mode
	TCCR1B = 0x10; 	       // 256 prescaler

	TCNT1 = 3036; 	       // reset Timer 1
	sei(); 		           // enable interrupt subsystem globally

    while (1);

	// elapse_time = n * 65536/16 + (uint32_t) TCNT1; // elapsed time in microseconds
	cli(); // disable interrupt subsystem globally
	return 0;
}
