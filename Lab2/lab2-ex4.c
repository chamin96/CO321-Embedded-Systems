#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int i = 0;

int main()
{

  DDRB |= 0b00111111;        /* configure PB0-6 of PORTB for output*/
  DDRD = DDRD & ~(1<<2);    //Makes pin2 (INT0) of PORTD as Input
  DDRD = DDRD & ~(1<<3);    //Makes pin2 (INT0) of PORTD as Input

  EICRA |= (1<<ISC01);  //set for FALLING EDGE detection
  EICRA |= (1<<ISC00);  //set for FALLING EDGE detection

  EICRA |= (1<<ISC11);  //set for FALLING EDGE detection
  EICRA |= (0<<ISC10);  //set for FALLING EDGE detection


  sei(); //enable GLOBAL interrupts

  EIMSK |= (1<<INT0);   //enable external interrupt for INT0
  EIMSK |= (1<<INT1);   //enable external interrupt for INT1

  while(1){

  }
  return 0;

}

ISR(INT0_vect)
{
  PORTB |= (1<<i);
  _delay_ms(500);
  i++;
}

ISR(INT1_vect){
  PORTB = PORTB & ~(1<<i);
  _delay_ms(500);
  i++;
}
