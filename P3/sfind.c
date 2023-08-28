#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#include "search.h"

int main(int argc, char* argv[])
{
  // If no arguments are given, the directory to search through will default to "." or the current working directory
  char *dirSearch = ".";
  char *nameSearch = "\0";
  char fileType;
  char *fileTemp;

  //int err;

  int i = 1;
  int hasType = 0;
  // Checking all of the command line arguments
  while (argv[i] != NULL)
    {
      // If the first argument after "sfind" is neither "-n" or "-t", it will be treated as the directory to search through
      if (i == 1 && strcmp(argv[i], "-n") != 0 && strcmp(argv[i], "-t") != 0)
	{
	  dirSearch = argv[i];
	}
      // If the argument is "-n", this will expect the nest argument to be a string to search for and assigns it as such
      if (strcmp(argv[i], "-n") == 0)
	{
	  nameSearch = argv[i + 1];
	}
      // If the argument is "-t", this will assign it as a type flag to search for and will set hasType to a setting that will choose
      // the searchdir() function the uses a type flag
      if (strcmp(argv[i], "-t") == 0)
	{
	  fileTemp = argv[i + 1];
	  fileType = fileTemp[0];
	  hasType = 1;
	}
      i ++;
    }

  if (!isdirectory(dirSearch))
    {
      printf("it is not a directory\n");
      return 1;
    }

  // If a type flag was given, it will run the first searchdir() function that takes in a type flag as a parameter, if no flag was given,
  // it will run the second function call that uses '\0' as its file type parameter
  if (hasType == 1)
    {
      searchdir(dirSearch, nameSearch, fileType);
    }
  else
    {
      searchdir(dirSearch, nameSearch, '\0');
    }
  return 0;
}
