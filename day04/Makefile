CC = g++
CFLAGS = -c -Wall
OBJECTS = day04.o

all: day04

day04: $(OBJECTS)
	$(CC) $(OBJECTS) -o day04

day04.o: day04.cpp day04.hpp
	$(CC) $(CFLAGS) day04.cpp -o day04.o

clean:
	rm -rf *.o day04
