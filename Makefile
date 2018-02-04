SOURCES := ${wildcard *.cpp}
OBJECTS := ${SOURCES:.cpp=.o}

%.o: %.cpp
	@avr-g++ -c -o $@ $< -Wall -Wextra -std=c++14 -O3 -I. -mmcu=atmega328p

all: $(OBJECTS)
	@echo "Building library"
	avr-ar rcsv libphantom.a $^
	@rm *.o

clean:
	@rm *.o
