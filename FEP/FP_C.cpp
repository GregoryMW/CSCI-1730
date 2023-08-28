#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream txt;
  string temp;
  int end = 0;

  cout << "Please enter which challenge you would like to demonstrate(1 or 2): ";
  int chalNum;
  cin >> chalNum;
  while (chalNum != 1 && chalNum != 2)
    {
      cout << "Please enter the challenge number you wish to demonstrate(1 or 2): ";
      cin >> chalNum;
    }

  while (end == 0)
    {
      int given;
      int answer;
      int possible = 0;
      int runFile = 1;
      int ownNum = 0;
      while (chalNum == 1)
	{
	  possible = 0;
	  if (runFile)
	    {
	      txt.open(argv[1]);
	      if (!txt)
		{
		  cerr << "Please give one input file to read from." << endl;
		  return EXIT_FAILURE;
		}
	      while (temp != "Challenge C-1")
		{
		  getline(txt,temp);
		}
	      getline(txt,temp);
	      given = stoi(temp);
	    }
	  
	  if (ownNum)
	    {
	      cout << "Please enter a positive integer: ";
	      cin >> given;
	      while (given < 1)
		{
		  cout << "Given number must be a positive integer: ";
		  cin >> given;
		}
	    }
	  
	  for (int i = 100; i < 1000; i ++)
	    {
	      if (((i/100) * ((i%100)/10) * ((i%100)%10) == given))
		{
		  answer = i;
		  possible = 1;
		  break;
		}
	    }
	  if (runFile)
	    txt.close();
	  if (possible == 0)
	    {
	      cout << "There is no 3-digit number in which the product of its digits equal " << given << "." << endl;
	    }
	  else
	    {
	      cout << "The product of " << answer << "'s digits equal " << given << "." << endl;
	    }
	  
	  cout << "What would you like to do now?\n1. Run the test file again\n2. Try your own number\n3. Run Challenge 2\n4. Exit" << endl;
	  int choice;
	  cin >> choice;
	  switch (choice)
	    {
	    case 1:
	      cout << "\n";
	      runFile = 1;
	      ownNum = 0;
	      break;
	    case 2:
	      cout << "\n";
	      runFile = 0;
	      ownNum = 1;
	      break;
	    case 3:
	      cout << "\n";
	      chalNum = 2;
	      break;
	    case 4:
	      cout << "Exiting.." << endl;
	      return EXIT_SUCCESS;
	    default:
	      while (choice < 1 || choice > 4)
		{
		  cout << "Please enter a valid input(1-4): ";
		  cin >> choice;
		}
	    }
	}
      while (chalNum == 2)
	{
	  int arr1count = 0;
	  int arr2count = 0;
	  txt.open(argv[1]);
	  if (!txt)
	    {
	      cerr << "Please give one input file to read from." << endl;
	      return EXIT_FAILURE;
	    }
      
	  while (temp != "Array 1")
	    {
	      getline(txt, temp);
	    }
	  getline(txt, temp);
	  while (temp != "Array 2")
	    {
	      arr1count ++;
	      getline(txt, temp);
	    }
	  while (getline(txt, temp))
	    {
	      arr2count ++;
	    }
	  txt.close();

	  int arr1[arr1count];
	  int arr2[arr2count];
	  txt.open(argv[1]);
	  while (temp != "Array 1")
	    {
	      getline(txt, temp);
	    }
	  for (int i = 0; i < arr1count; i ++)
	    {
	      getline(txt, temp);
	      arr1[i] = stoi(temp);
	    }
	  while (temp != "Array 2")
	    {
	      getline(txt, temp);
	    }
	  for (int i = 0; i < arr2count; i ++)
	    {
	      getline(txt, temp);
	      arr2[i] = stoi(temp);
	    }
	  txt.close();

	  int match = 0;
	  int extraCount = 0;
	  int extra1;
	  int extra2;
	  for (int i = 0; i < arr2count; i ++)
	    {
	      match = 0;
	      for (int j = 0; j < arr1count; j ++)
		{
		  if (arr2[i] == arr1[j])
		    {
		      match = 1;
		    }
		}
	      if (match == 0)
		{
		  if (extraCount == 0)
		    {
		      extra1 = arr2[i];
		      extraCount ++;
		    }
		  else
		    extra2 = arr2[i];
		}
	    }
	  cout << "Array 1: [";
	  for (int i = 0; i < arr1count; i ++)
	    {
	      if (i == arr1count - 1)
		cout << arr1[i] << "]" << endl;
	      else
		cout << arr1[i] << ", ";
	    }
	  cout << "Array 2: [";
	  for (int i = 0; i < arr2count; i ++)
	    {
	      if (i == arr2count - 1)
		cout << arr2[i] << "]" << endl;
	      else
		cout << arr2[i] << ", ";
	    }
	  cout << "Extra integers: " << extra1 << ", " << extra2 << endl;
	  cout << "What would you like to do now?\n1. Run the test file again\n2. Run Challenge 1\n3. Exit" << endl;
	  int choice2;
	  cin >> choice2;
	  switch (choice2)
	    {
	    case 1:
	      cout << "\n";
	      break;
	    case 2:
	      cout << "\n";
	      chalNum = 1;
	      runFile = 1;
	      ownNum = 0;
	      break;
	    case 3:
	      cout << "Exiting.." << endl;
	      return EXIT_SUCCESS;
	    default:
	      while (choice2 < 1 || choice2 > 3)
		{
		  cout << "Please enter a valid input(1-3): ";
		  cin >> choice2;
		}
	    }
	}
    }
  return EXIT_SUCCESS;
}
