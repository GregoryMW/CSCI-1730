#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include "helper.h"

using namespace std;

int length;
int numGuess;
vector<std::string> words;
vector<char> letters;
vector<char> currentWord;

void prompt()
{
  cout << "Welcome to hangman!\nPlease enter a word length between 3-12: ";
  cin >> length;
  while (length < 3 || length > 12)
    {
      cout << "Word length must be between 3-12 letters. Please enter a length: ";
      cin >> length;
    }

  cout << "Enter the number of guesses you would like: ";
  cin >> numGuess;
  while (numGuess < 1)
    {
      cout << "Number of guesses must be at least 1. Please enter the number of guesses you would like: ";
      cin >> numGuess;
    }
}

void makeList(char *wordList)
{
  ifstream txtFile;
  string temp;

  txtFile.open(wordList);
  while (getline(txtFile, temp))
    {
      if ((int)temp.length() == length)
	{
	  words.push_back(temp);
	}
    }

  if (words.size() == 0)
    {
      cout << "There are no words with this length. Please enter a new length: ";
      cin >> length;
      makeList(wordList);
    }

  for (int i = 0; i < length; i ++)
    {
      currentWord.push_back('-');
    }
}

int playGame()
{
  while (numGuess > 0)
    {
      cout << "\nGuesses left: " << numGuess << endl;
      cout << "Guesses so far: [";
      for (size_t i = 0, e = letters.size(); i != e; i++)
	cout << letters[i] << ", ";
      cout << "]" << endl;
  
      cout << "Current word: ";
      for (int i = 0; i < length; i++)
	cout << currentWord[i];
      cout << endl;

      cout << "Enter a letter: ";
      string guess;
      cin >> guess;
      while (guess.length() < 1 || guess.length() > 1 || !isalpha(guess[0]))
	{
	  cout << "Please enter only 1 letter: ";
	  cin >> guess;
	}
      for (size_t i = 0, e = letters.size(); i != e; i++)
	{
	  if (letters[i] == guess[0])
	    {
	      cout << "Please enter a letter that has not yet been used: ";
	      cin >> guess;
	      i = -1;
	    }
	}
      letters.push_back(guess[0]);

      multimap<int, string> map;
      int empty;
      string temp;
      for (size_t i = 0, e = words.size(); i != e; i++)
	{
	  empty = 1;
	  temp = words[i];
	  for (int j = 0; j < length; j ++)
	    {
	      if(temp[j] == guess[0])
		{
		  map.insert(pair<int, string>(j, temp));
		  empty = 0;
		  break;
		}
	    }
	  if (empty)
	    {
	      map.insert(pair<int, string>(-1, temp));
	    }
	}

      int most = map.count(-1);
      int mostMap = -1;
      for (int i = 0; i < length; i ++)
	{
	  if ((int)map.count(i) > most)
	    {
	      most = map.count(i);
	      mostMap = i;
	      i = -1;
	    }
	}
      words.clear();
      for (auto move = map.begin(); move != map.end(); move ++)
	{
	  if (move -> first == mostMap)
	    {
	      words.push_back(move -> second);
	      //Testing Code:
	      //cout << move -> second << endl;
	    }
	}

      /*
      //Testing code:
      for (int i = 0; i < length; i ++)
	{
	  cout << i << " letter " << map.count(i) << endl;
	}
      cout << "no letters " << map.count(-1) << endl;
      cout << "Map with most is " << mostMap << endl;
      */
      

      if (mostMap == -1)
	{
	  cout << "Sorry, there are no " << guess[0] << "'s" << endl;
	  numGuess --;
	}
      else
	{
	  for (string word : words)
	    {
	      for (int i = 0; i < length; i ++)
		{
		  if (word[i] == guess[0])
		    {
		      currentWord[i] = guess[0];
		    }
		}
	    }
	}

      int done = 1;
      for (char found : currentWord)
	{
	  if (found == '-')
	    {
	      done = 0;
	    }
	}
      if (done)
	{
	  cout << "Congratulations! You won! Would you like to play again? (y/n) ";
	  string status;
	  cin >> status;
	  while ((status[0] != 'y' && status[0] != 'n') || status.length() > 1)
	    {
	      cout << "Please enter 'y' or 'n' if you would like to play again or not.";
	      cin >> status;
	    }
	  if (status[0] == 'y')
	    {
	      words.clear();
	      letters.clear();
	      currentWord.clear();
	      return 1;
	    }
	  else
	    {
	      cout << "Thank you for playing!" << endl;
	      return 0;
	    }
	}
      cerr << words.size() << endl;
    }
  cout << "Sorry, You've run out of guesses! the word was: " << words[0] << endl;
  return 0;
}
