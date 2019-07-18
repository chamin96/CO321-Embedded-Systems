#include <avr/io.h>

void delay_timer(){

    TCNT0 = 131;                    // Set initial value

    TCCR0A = 0x00;                  // Timer0 normal mode
    TCCR0B = 0x04;                  // Timer0 with 1:256 prescaler

    while ((TIFR0&0x01)==0);

    TCCR0A = 0x00;                  // Reset Timer0 setings
    TCCR0B = 0x00;

    TIFR0 = 0x01;                   // Clear flag bit

}

int main(void) {
	DDRB = DDRB | (1<<5);  			// set pin 5 of port B for output

	while (1){

        int i;
        PORTB = PORTB | (1<<5);     // Turn ON LED

        for (i = 0; i < 250; i++) { // Delay for 500ms
            delay_timer();
        }

        PORTB = PORTB & ~(1<<5);    // Turn OFF LED

        for (i = 0; i < 250; i++) { // Delay for 500ms
            delay_timer();
        }

    }

	return 0;
}
