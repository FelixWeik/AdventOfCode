CC = g++
CFLAGS = -c -Wall
OBJECTS = day06.o

all: day06

day06: $(OBJECTS)
	$(CC) $(OBJECTS) -o day06

day06.o: day06.cpp day06.hpp
	$(CC) $(CFLAGS) day06.cpp -o day06.o

clean:
	rm -rf *.o day06
