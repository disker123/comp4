CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
all:	ps1b

ps1b:	PhotoMagic.o
	$(CC) PhotoMagic.o
	
PhotoMagic.o:	PhotoMagic.cpp
	$(CC) -c PhotoMagic.cpp $(LIBS) 

clean:
	rm *.o
	rm *.out
#		rm ps1a