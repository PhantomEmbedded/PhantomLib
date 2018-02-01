CC=avr-gcc
CPP=avr-g++
CPPFILES = $(wildcard ./*.cpp)

%.o: %.cpp
	@$(CPP) -c -o $@ $< -mmcu=atmega328p -Wall -Wextra -Werror -std=c++11 -O3 -I.

all: $(CPPFILES)
	@echo "Building library"
	@avr-ar rcsv libPhantom.a $^

clean:
	@rm *.o
