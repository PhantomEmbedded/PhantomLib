CC=avr-g++

CLASSES = \
	DigitalOutput.o \
	DigitalInput.o \
	Pin.o \
	AnalogInput.o


%.o: %.cpp
	@avr-g++ -c -o $@ $< -mmcu=atmega328p -Wall -Wextra -std=c++11 -O3 -I.

all: $(CLASSES)
	@echo "Building library"
	avr-ar rcsv libPhantom.a $^

clean:
	@rm *.o