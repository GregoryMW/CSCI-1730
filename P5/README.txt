Name of Program: hangman.cpp

This program plays an alternate game of traditional hangman in which an algorithm is used to change the word to guess each time the player chooses a letter.
The program will categorize every word by how many times the chosen letter appears in the entire list of given words, and then chooses the category with the most
words available. The player can play with words between 3-12 letters, and can have any number of guesses above 1.

CODER: Gregory Woolsey

How to compile: g++ -g -Wall -o hangman hangman.cpp helper.cpp

OR use the included makefile
make

How to run:
hangman
