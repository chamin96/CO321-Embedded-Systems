#include <avr/io.h>

void delay_timer(){

    TCNT0 = 131;

    TCCR0A = 0x00;
    TCCR0B = 0x04;

    while ((TIFR0&0x01)==0);

    TCCR0A = 0x00;
    TCCR0B = 0x00;

    TIFR0 = 0x01;

}

int main(void) {
	DDRB = DDRB | (1<<5);  			// set pin 5 of port B for output

	while (1){

        PORTB = PORTB ^ (1<<5);
        delay_timer();

    }

	return 0;
}
