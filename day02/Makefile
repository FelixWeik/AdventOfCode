CC = g++
CFLAGS = -c -Wall
OBJECTS = day02.o

all: day02

day02: $(OBJECTS)
	$(CC) $(OBJECTS) -o day02

day02.o: day02.cpp day02.hpp
	$(CC) $(CFLAGS) day02.cpp -o day02.o

clean:
	rm -rf *.o day02
