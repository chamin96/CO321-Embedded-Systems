#include <avr/io.h>


void frequency_func(int value){
	TCNT0 = 0;
	OCR0A = value;
	TCCR0A |= (1 << COM0A1); // set none-inverting mode
    TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast PWM Mode
    TCCR0B |= (1 << CS00) | (1 << CS01); // set prescaler to 64 and starts PWM
}


void delay_func(){
	TCNT1 = 0; // for 65ms at 16 MHz
	TCCR1A = 0x00; // Timer1 normal mode
    TCCR1B = 0x05; // Timer1 with 1:1024 prescaler

    while ((TIFR1&0x01)==0);

    TCCR1A = 0x00;                  // Reset Timer0 setings
    TCCR1B = 0x00;

    TIFR1 = 0x01;                   // Clear flag bit
}


int main()
{
	DDRD = DDRD | (1<<6); //set pin 6 for output
	
	int frequency[4] = {2, 63, 191, 255};

    int i;

	
	for (i = 0; i < 4; ++i)
    {
        frequency_func(frequency[i]);
    	delay_func();
    }
    


    

	while(1){
	}

	return 0;
}