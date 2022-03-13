CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system


NBody: NBody.o 
	$(CC) NBody.o -o NBody $(SFMLFLAGS)

NBody.o: NBody.cpp 
	$(CC) -c NBody.cpp  $(CFLAGS)

clean:
	rm *.o
	rm NBody
