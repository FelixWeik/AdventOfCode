CC = g++
CFLAGS = -c -Wall
OBJECTS = day10.o

all: day10

day10: $(OBJECTS)
	$(CC) $(OBJECTS) -o day10

day10.o: day10.cpp day10.hpp
	$(CC) $(CFLAGS) day10.cpp -o day10.o

clean:
	rm -rf *.o day10
