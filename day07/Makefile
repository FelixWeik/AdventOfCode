CC = g++
CFLAGS = -c -Wall
OBJECTS = day07.o

all: day07

day07: $(OBJECTS)
	$(CC) $(OBJECTS) -o day07

day07.o: day07.cpp day07.hpp
	$(CC) $(CFLAGS) day07.cpp -o day07.o

clean:
	rm -rf *.o day07
