sfind: sfind.o search.o
	gcc -g -Wall -o sfind sfind.o search.o

sfind.o: sfind.c search.c
	gcc -c -Wall sfind.c search.c

search.o: search.c search.h
	gcc -c -Wall search.c search.h

clean:
	rm -f *.o sfind
