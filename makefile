CC=avr-g++

DEPS = ./Boards/ArduinoUno.h ./Boards/BoardBase.h Phantom.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< -mmcu=atmega328p -Wall -Wextra -std=c++11 -O3 -I.

all: main.o DigitalOutput.o Pin.o
	$(CC) -o $@ $^ -mmcu=atmega328p -Wall -Wextra -std=c++11 -O3 -I.

clean:
	rm *.o