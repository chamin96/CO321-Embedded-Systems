#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS  200
int main (void){
	DDRB = DDRB | (31<<1); /* configure pin 5,4,3,2,1 of PORTB for output including LED pin 5*/
	while(1){
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
