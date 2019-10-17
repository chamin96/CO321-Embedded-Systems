#include <avr/io.h>
#include <ctype.h>

void usart_init()
{
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);   //enable transmitter & receiver
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); //8-bit data, no parity, 1 stop bit
    UBRR0L = 0x67;                          //baud rate=9600
}

void usart_send(unsigned char a)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ; //if the buffer is empty
    UDR0 = a;
}

unsigned char usart_receive()
{
    while (!(UCSR0A & (1 << RXC0)))
        ; //wait until recieve
    return UDR0;
}

void EEPROMwrite(unsigned int address, char data)
{
    //wait for completion of previous write
    while (EECR & (1 << EEPE))
        ;

    //set up address and data regs
    EEAR = address;
    EEDR = data;

    //write logical 1 to EEMPE
    EECR |= (1 << EEMPE);

    //start eeprom write
    EECR |= (1 << EEPE);
}

char EEPROMread(unsigned int address)
{
    //wait for completion of writes
    while (EECR & (1 << EEPE))
        ;

    //set up address
    EEAR = address;

    //start eeprom read
    EECR |= (1 << EERE);

    //return data
    return EEDR;
}

int main()
{

    while (1)
    {
        static unsigned int addr = 0;

        usart_init();
        unsigned char inTxt = usart_receive();

        // write to eeprom
        EEPROMwrite(addr++, inTxt);
    }

    return 0;
}