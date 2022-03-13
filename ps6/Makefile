CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic --std=c++11
#SFMLFLAGS= -lsfml-system
Boost= -lboost_unit_test_framework
all: test markov
markov: TextGenerator.o markov.o
	$(CC)  TextGenerator.o markov.o  -o markov 
test: test.cpp markov.o
	$(CC) test.cpp markov.o $(CFLAGS) $(Boost) -o test
TextGenerator.o: TextGenerator.cpp markov.h
	$(CC) -c TextGenerator.cpp markov.h
markov.o: markov.cpp  markov.h
	$(CC) -c markov.cpp markov.h  $(CFLAGS)
clean:
	rm *.o
	rm markov
	rm test

