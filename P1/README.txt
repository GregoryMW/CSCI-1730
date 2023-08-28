Name of program: playCraps.c

This program plays the casino game craps where the user is prompted for an initial dollar amount to start with. Before each roll, the player is asked to bet an amount of money. This amount must be
greater than 0 and less than or equal to their current remaining balance. the game then rolls two dice in accordance with the rules of craps, and informs the player if they have won or lost.
If the player has won, their wager amount will be added to their total balance, and if they lost, their wager amount will  be subtracted. The user is then prompted if they would like
to play again, where they must enter 'y' for yes and 'n' for no. If yes, the game will continue playing craps using their current balance and if they say no, the game will print their final
balance and end the program.

CODER: Gregory Woolsey

CREDIT/Contributions:
Diesel and Deitel code craps.c

How to compile:
gcc -g -Wall -o playCraps playCraps.c wager.c

OR use the included makefile
make

How to run:
playCraps
