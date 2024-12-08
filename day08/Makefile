CC = g++
CFLAGS = -c -Wall
OBJECTS = day08.o

all: day08

day08: $(OBJECTS)
	$(CC) $(OBJECTS) -o day08

day08.o: day08.cpp day08.hpp
	$(CC) $(CFLAGS) day08.cpp -o day08.o

clean:
	rm -rf *.o day08
