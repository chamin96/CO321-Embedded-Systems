#include <avr/io.h>
#include <ctype.h>

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

	unsigned char caesar(unsigned char p){	//Caesar cipher, key is 3
		unsigned char c;
		if (p < 91 && p > 64) 	//p is capital
		{
			c = (((p - 65) + 3)%26)+97;
		}
		else	//p is simple
		{
			c = (((p - 97) + 3)%26)+97;
		}	
		
		return c;
	}

int main()
{
    
	
    while(1){
		usart_init();
		unsigned char d = usart_receive();
		if (isalpha(d)){
			d = caesar(d);
		}
		usart_send(d);
    }

	return 0;
}