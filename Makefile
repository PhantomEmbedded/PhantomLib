SOURCES := ${wildcard *.cpp}
OBJECTS := ${SOURCES:.cpp=.o}

%.o: %.cpp
	@avr-g++ -c -o $@ $< -Wall -Wextra -std=c++14 -O3 -I. -mmcu=atmega328p -DF_CPU=16000000

all: $(OBJECTS)
	@echo "Building library"
	avr-ar rcsv libphantom.a $^
	@rm *.o

clean:
	@rm *.o
