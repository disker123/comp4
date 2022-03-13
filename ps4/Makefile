CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic --std=c++11
Boost= -lboost_unit_test_framework
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:
	make ps4
ps4: main.o StringSound.o RingBuffer.o 
	$(CC)  main.o StringSound.o RingBuffer.o  -o ps4 $(SFMLFLAGS)
main.o: main.cpp StringSound.hpp
	$(CC) -c main.cpp StringSound.hpp  $(CFLAGS)
RingBuffer.o: RingBuffer.cpp  RingBuffer.h
	$(CC) -c RingBuffer.cpp RingBuffer.h  $(CFLAGS)
StringSound.o: StringSound.cpp StringSound.hpp
	$(CC) -c StringSound.cpp StringSound.hpp  $(CFLAGS)
#test: test.cpp ps4a.o
#	$(CC) test.cpp ps4a.o $(CFLAGS) $(Boost) -o test

clean:
	rm *.o
	rm ps4
#	rm test

