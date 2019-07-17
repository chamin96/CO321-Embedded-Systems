#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

  DDRB = DDRB | 0b00111111;        /* configure pins PORTB for output*/
  DDRD = DDRD & ~(1<<PD7);    //Makes pin of PORTD as Input
  int count = 0;

  while(1) //infinite loop
  {

    if (PIND & (1<<7)) //If switch is pressed
    {
      count++;
    }
    PORTB = (count); //Turns ON LED
    _delay_ms(200);

  }
}
