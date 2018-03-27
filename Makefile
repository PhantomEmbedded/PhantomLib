SOURCES := ${wildcard *.cpp}
OBJECTS := ${SOURCES:.cpp=.o} 

%.o: %.cpp
	avr-g++ -v -c -o $@ $< -Wall -Wextra -std=c++14 -O3 -I. -mmcu=atmega328p -DF_CPU=16000000 -L./std/ -lstd -I./std/

all: $(OBJECTS)
	make -fMakefile --directory=std/
	@echo "Building library"
	avr-ar rcsv libphantom.a $^

clean:
	@rm *.o
