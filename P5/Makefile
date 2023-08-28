hangman: hangman.o helper.o
	g++ -g -Wall -o hangman hangman.o helper.o

hangman.o: hangman.cpp helper.cpp
	g++ -c -Wall hangman.cpp helper.cpp

helper.o: helper.cpp helper.h
	g++ -c -Wall helper.cpp helper.h

clean:
	rm -f *.o hangman
