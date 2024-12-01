CC = g++
CFLAGS = -c -Wall
OBJECTS = day01.o

all: day01

day01: $(OBJECTS)
	$(CC) $(OBJECTS) -o day01

day01.o: day01.cpp day01.hpp
	$(CC) $(CFLAGS) day01.cpp -o day01.o

clean:
	rm -rf *.o day01
