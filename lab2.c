#include <avr/io.h>
#include <util/delay.h>


int main (void){
    for (int i = 0; i < 6; ++i)
    {
    	DDRB = DDRB | (1<<i);
    }
    DDRD = DDRD &~ (1<<7);

    while(1){
    	int count = 0;
    	while(count<63){
    	if (PORTD & (1<<7) == 1)
    	{
    		count++;
    	}
        PORTB = count;
    }
    }
    
}