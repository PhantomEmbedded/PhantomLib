SOURCES := ${wildcard *.cpp}
OBJECTS := ${SOURCES:.cpp=.o} 

%.o: %.cpp
	avr-g++ -c -o $@ $< -Wall -Wextra -std=c++14 -O3 -I. -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -L./std/ -lstd -I./std/

all: $(OBJECTS)
	make -fMakefile --directory=std/
	@avr-ar rcs libphantom.a $^ std/libstd.a
