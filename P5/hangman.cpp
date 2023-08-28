#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>  
#include <cstdio>
#include <vector>
#include "helper.h"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc == 1)
    {
      cout << "No .txt file detected. Please enter a .txt for the game to pull words from. Exiting..." << endl;
      return 0;
    }
  int finished = 1;
  while (finished == 1)
    {
      prompt();
      makeList(argv[1]);
      finished = playGame();
    }
  return finished;
}
