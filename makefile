# avr-g++ arguments

AVR_DEVICE = atmega328p
AVR_SOURCE = main.cpp

# avrdude arguments

AVRDUDE_PORT = /dev/ttyUSB*
AVRDUDE_BAUD = 115200
AVRDUDE_PROGRAMMER = usbasp 



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
all:	main.hex

flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i
	rm -f main.hex main.elf

# if you use a bootloader, change the command below appropriately:
load: all
	bootloadHID main.hex

clean:
	rm -f main.hex main.elf

# file targets:
main.elf: $(AVR_SOURCE)
	$(AVR_GPP) -o main.elf $(AVR_SOURCE)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

# Board Options