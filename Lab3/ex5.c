#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS  200

ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	PORTB = PORTB ^ (1<<5); // toggle LED
	TCNT1 = 3036;   // for 1 sec at 16 MHz
}

int main()
{
	DDRB = DDRB | (31<<1); /* configure pin 5,4,3,2,1 of PORTB for output including LED pin 5*/

	TCNT1 = 3036;   // for 1 sec at 16 MHz

	TCCR1A = 0x00;
	TCCR1B = 0x04;  // Timer mode with 256 prescler
	TIMSK1 = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG

	while(1)
	{
    int i = 4;
    		while(i>0){
    			PORTB = PORTB | (1<<i); /* set pin 5 high to turn led on */
    			_delay_ms(BLINK_DELAY_MS);
    			PORTB = PORTB &~(1<<i); /* set pin 5 low to turn led off */
    			_delay_ms(BLINK_DELAY_MS);
    			i--;
    		}
    		i = 2;
    		while(i<4){
    			PORTB = PORTB | (1<<i); /* set pin 5 high to turn led on */
    			_delay_ms(BLINK_DELAY_MS);
    			PORTB = PORTB &~(1<<i); /* set pin 5 low to turn led off */
    			_delay_ms(BLINK_DELAY_MS);
    			i++;
    		}
	}
}
