# CO321-Embedded-Systems
Lab Sessions

The commands thatweused tocompile and upload the file “led.c” are:


$ avr-gcc-Os -DF_CPU=16000000UL -mmcu=atmega328p -o ledled.c

$ avr-objcopy-O ihex -R .eeprom led led.hex

$ avrdude-F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex
