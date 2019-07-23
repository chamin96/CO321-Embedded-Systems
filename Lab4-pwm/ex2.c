#include <avr/io.h>


void fade(int value){
	TCNT0 = 0;

    OCR0A = value; // set PWM  duty cycle
    TCCR0A |= (1 << COM0A1); // set none-inverting mode
    TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast PWM Mode
    TCCR0B |= (1 << CS00) | (1 << CS01); // set prescaler to 64 and starts PWM
}

void delay_func(){
	TCNT1 = 0; // for 512 micro sec at 16 MHz
	TCCR1A = 0x00; // Timer1 normal mode
    TCCR1B = 0x02; // Timer1 with 1:8 prescaler

    while ((TIFR1&0x01)==0);

    TCCR1A = 0x00;                  // Reset Timer0 setings
    TCCR1B = 0x00;

    TIFR1 = 0x01;                   // Clear flag bit
}


int main()
{
	DDRD = DDRD | (1<<6); //set pin 6 for output
	
	int fade_value = 5;
	int brightness = 0;



	while(1){

		fade(brightness);
		brightness += fade_value;
		if (brightness == 0 || brightness == 255)
		{
			fade_value = -fade_value;
		}
		delay_func();
		
	}

	return 0;
}