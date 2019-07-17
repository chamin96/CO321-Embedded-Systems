#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS  2000
int main (void){
DDRB = DDRB|(15<<2); /* configure pin 5 of PORTB for output*/
while(1){
 PORTB = PORTB | (15<<2); /* set pin 5 high to turn led on */
 _delay_ms(BLINK_DELAY_MS);
 PORTB = PORTB &~(15<<2); /* set pin 5 low to turn led off */
 _delay_ms(BLINK_DELAY_MS);
}
}
