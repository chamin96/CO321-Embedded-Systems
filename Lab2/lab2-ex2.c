#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



int main()
{

  DDRB |= (1<<0);        /* configure PB0 of PORTB for output*/
  DDRD = DDRD & ~(1<<2);    //Makes pin2 (INT0) of PORTD as Input

  EICRA |= (1<<ISC01);  //set for FALLING EDGE detection
  EICRA |= (0<<ISC00);  //set for FALLING EDGE detection


  sei(); //enable GLOBAL interrupts

  EIMSK |= (1<<INT0);   //enable external interrupt for INT0

  while(1){

  }
  return 0;

}

ISR(INT0_vect)
{
  PORTB ^= (1<<0);  //TOGGLE (XOR gate)
}
