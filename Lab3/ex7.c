#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t counter = 0;

ISR(TIMER0_OVF_vect)
{ 
    counter++;
    TCNT0 = 131; // Reset Timer0
}

ISR(TIMER1_OVF_vect)
{                             // Timer1 ISR
    TCNT1 = 34286;            // for 1 sec at 16 MHz
    PORTB = PORTB ^ (1 << 5); // toggle LED
}

int main()
{

    sei(); // Enable global interrupts by setting global interrupt enable bit in SREG

    DDRB = DDRB | (1 << 5); // set pin 5 of port B for output
    DDRD = DDRD | (1 << 7); // set pin 7 of port D for output

    TCNT0 = 131;   // for 50 milli sec at 16 MHz
    TCNT1 = 34286; // for 500 milli sec at 16 MHz

    TCCR0A = 0x00; // Timer0 normal mode
    TCCR0B = 0x04; // Timer0 with 1:8 prescaler

    TCCR1A = 0x00; // Timer1 normal mode
    TCCR1B = 0x04; // Timer1 with 1:256 prescaler

    TIMSK0 = 0b00000001; // Enable timer0 overflow interrupt(TOIE0)
    TIMSK1 = 0b00000001; // Enable timer1 overflow interrupt(TOIE1)

    while (1)
    {

        if (counter == 25)
        {
            PORTD = PORTD ^ (1 << 7); // toggle LED
            counter = 0;
        }
    }
}
