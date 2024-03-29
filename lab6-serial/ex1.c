#include <avr/io.h>

int main()
{
	void usart_init(){
		UCSR0B = (1<<TXEN0) | (1<<RXEN0);	//enable transmitter & receiver
		UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);	//8-bit data, no parity, 1 stop bit
		UBRR0L = 0x67;	//baud rate=9600
	}

	void usart_send(unsigned char a){
		while(!(UCSR0A & (1<<UDRE0)));	//if the buffer is empty
		UDR0 = a;
	}

	void usart_receive(){
		while(UCSR0A & (1<<RXC0));	//wait until recieve
		PORDB = UDR0;
	}

	return 0;
}