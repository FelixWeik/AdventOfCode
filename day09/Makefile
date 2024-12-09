CC = g++
CFLAGS = -c -Wall
OBJECTS = day09.o

all: day09

day09: $(OBJECTS)
	$(CC) $(OBJECTS) -o day09

day09.o: day09.cpp day09.hpp
	$(CC) $(CFLAGS) day09.cpp -o day09.o

clean:
	rm -rf *.o day09
