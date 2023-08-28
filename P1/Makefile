playCraps: playCraps.o wager.o
	gcc -g -Wall -o playCraps playCraps.o wager.o

playCraps.o: playCraps.c wager.c
	gcc -c -Wall playCraps.c wager.c

wager.o: wager.c wager.h
	gcc -c -Wall wager.c wager.h

clean:
	rm -f *.o playCraps
