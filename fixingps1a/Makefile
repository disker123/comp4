CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
Boost= -lboost_unit_test_framework
all:
	make test
ps1a: FibLFSR.cpp
	$(CC) FibLFSR.cpp -c -o FibLFSR.o $(CFLAGS)
test: test.cpp FibLFSR.o
	$(CC) test.cpp FibLFSR.o $(CFLAGS) $(Boost) -o test

clean:
	rm *.o *.out test
