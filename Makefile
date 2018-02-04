CC=avr-gcc
CPP=avr-g++

FILES = $(wildcard ./*.cpp)

%.o: %.cpp
	@avr-g++ -c -o $@ $< -Wall -Wextra -std=c++14 -O3 -I. -mmcu=atmega328p

all: $(FILES)
	@echo "Building library"
	avr-ar rcsv libphantom.a $^

clean:
	@rm *.o
