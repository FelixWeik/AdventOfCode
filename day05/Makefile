CC = g++
CFLAGS = -c -Wall
OBJECTS = day05.o

all: day05

day05: $(OBJECTS)
	$(CC) $(OBJECTS) -o day05

day05.o: day05.cpp day05.hpp
	$(CC) $(CFLAGS) day05.cpp -o day05.o

clean:
	rm -rf *.o day05
