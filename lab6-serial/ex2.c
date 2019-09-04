#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

#define DELAY_TIME  1000

	void usart_init(){
		UCSR0B = (1<<TXEN0) | (1<<RXEN0);	//enable transmitter & receiver
		UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);	//8-bit data, no parity, 1 stop bit
		UBRR0L = 0x67;	//baud rate=9600
	}

	void usart_send(unsigned char a){
		while(!(UCSR0A & (1<<UDRE0)));	//if the buffer is empty
		UDR0 = a;
	}

	unsigned char usart_receive(){
		while(!(UCSR0A & (1<<RXC0)));	//wait until recieve
		return UDR0;
	}

int main()
{
    unsigned char * str = "E15142-Ganindu\nE15154-Chamin\nE15187-Devin\n";
    unsigned char strlength = strlen(str);
    unsigned char i = 0;
    usart_init();

    while(1){
        usart_send(str[i++]);
        if (i >= strlength){
            i=0;
            _delay_ms(DELAY_TIME);
        }       
    }


	return 0;
}