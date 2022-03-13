CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic --std=c++11
SFMLFLAGS= -lsfml-system

all: ED
ED: main.o ED.o
	$(CC)  main.o ED.o  -o ED $(SFMLFLAGS)
main.o: main.cpp ED.hpp
	$(CC) -c main.cpp ED.hpp 
ED.o: ED.cpp  ED.hpp
	$(CC) -c ED.cpp ED.hpp  $(CFLAGS)

clean:
	rm *.o
	rm ED

