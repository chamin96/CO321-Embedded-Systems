#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "lcd.h"
#include <ctype.h>

const unsigned int addr = 0;

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

unsigned int getKey()
{
    unsigned int key;
    EEPROMread(addr);
}

void stKey(unsigned int newKey)
{
    EEPROMwrite(addr, newKey);
}

unsigned char caesar(unsigned char p)
{ //Caesar cipher
    unsigned char c;
    unsigned int k = getKey();
    if (p < 91 && p > 64) //p is capital
    {
        c = (((p - 65) + 3) % 26) + 97;
    }
    else //p is simple
    {
        c = (((p - 97) + 3) % 26) + 97;
    }

    return c;
}

int main(void)
{
    /* initialize display, cursor off */
    lcd_init(LCD_DISP_ON);

    return 0;
}
