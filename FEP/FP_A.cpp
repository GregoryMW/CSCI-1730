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
  int count = 0;
  int nonZero = 0;

  txt.open(argv[1]);
  if (!txt)
    {
      cerr << "Please give one input file to read from." << endl;
      return EXIT_FAILURE;
    }
    
  while (getline(txt, temp))
    {
      count ++;
    }
  txt.close();
  
  int arr[count];
  txt.open(argv[1]);
  for (int i = 0; i < count; i ++)
    {
      getline(txt, temp);
      arr[i] = stoi(temp);
      if (arr[i] != 0)
	nonZero ++;
    }
  txt.close();

  cout << "Given array: [";
  for (int i = 0; i < count; i ++)
    {
      if (i == count - 1)
	cout << arr[i] << "]" << endl;
      else
	cout << arr[i] << ", ";
    }

  for (int i = 1; i < count; i ++)
    {
      if (arr[i] != 0)
	{
	  int arrTemp = arr[i];
	  for (int j = i; j > 0; j --)
	    {
	      arr[j] = arr[j - 1];
	    }
	  arr[0] = arrTemp;
	}
    }
  
  cout << "Sorted array: [";
  for (int i = 0; i < count; i ++)
    {
      if (i == count - 1)
	cout << arr[i] << "]" << endl;
      else
	cout << arr[i] << ", ";
    }
  cout << "There are " << nonZero << " non-zero integers in the array" << endl;
  return EXIT_SUCCESS;
}
