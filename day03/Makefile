CC = g++
CFLAGS = -c -Wall
OBJECTS = day03.o

all: day03

day03: $(OBJECTS)
	$(CC) $(OBJECTS) -o day03

day03.o: day03.cpp day03.hpp
	$(CC) $(CFLAGS) day03.cpp -o day03.o

clean:
	rm -rf *.o day03
