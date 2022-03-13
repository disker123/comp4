CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic --std=c++11
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


NBody: NBody.o 
	$(CC) NBody.o -o NBody $(SFMLFLAGS)
NBody.o: universe.cpp  universe.hpp
	$(CC) -c universe.cpp -o NBody.o  $(CFLAGS)

clean:
	rm *.o
	rm NBody

