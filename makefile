# avr-g++ arguments

AVR_DEVICE = atmega328p
AVR_SOURCE = main.cpp 
AVR_TARGET = main.hex

# avrdude arguments

AVRDUDE_PORT = /dev/ttyUSB0
AVRDUDE_BAUD = 57600
AVRDUDE_PROGRAMMER = arduino 

######################################################################
######################################################################



# Tune the lines below only if you know what you are doing:

AVRDUDE = avrdude \
	-p$(AVR_DEVICE) \
	-P$(AVRDUDE_PORT) \
	-b$(AVRDUDE_BAUD) \
	-c$(AVRDUDE_PROGRAMMER)
AVR_GPP = avr-g++ -Wall -Wextra -std=c++11 -O3 \
	-mmcu=$(AVR_DEVICE) 

# symbolic targets:
all:	$(AVR_TARGET)

flash:	all
	$(AVRDUDE) -U flash:w:$(AVR_TARGET):i
	rm -f $(AVR_TARGET) main.elf

clean:
	rm -f $(AVR_TARGET) main.elf

# file targets:
main.elf: $(AVR_SOURCE)
	$(AVR_GPP) -o $@ $^

$(AVR_TARGET): main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf $(AVR_TARGET)

# Board Options