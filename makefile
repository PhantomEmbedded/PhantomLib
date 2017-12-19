# avr-g++ arguments

AVR_DEVICE = atmega328p

# avrdude arguments

AVRDUDE_PORT = /dev/ttyUSB*
AVRDUDE_BAUD = 115200
AVRDUDE_PROGRAMMER = usbasp 

# board include

BOARDFILE = ./Boards/ArduinoUno.h


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

clean:
	rm -f main.hex main.elf

# file targets:
%.o : %.cpp
	$(AVR_GPP) -o main.elf $<

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

# Board Options

ArduinoUno:	AVR_PROCESSOR = atmega328p
ArduinoUno: BOARDFILE = ./Boards/ArduinoUno.h
ArduinoUno: flash
