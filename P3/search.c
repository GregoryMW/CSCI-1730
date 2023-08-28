#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

void searchdir(char *dirname, char *findme, char type)
{
  struct dirent *myfile = NULL;
  DIR *mydir;
  struct stat mystat;
  char *location;

  // These three if statements take in the name of the directory to search through, checks to see if it is null, sets the DIR pointer mydir to that directory,
  // and changes to that directory to begin sfind's task.
  if (dirname == NULL)
    {
      perror("dirname");
      return;
    }

  mydir = opendir(dirname);
  if(mydir == NULL)
    {
      perror("opendir");
      return;
    }

  if (chdir(dirname) != 0)
    {
      perror("chdir");
      return;
    }


  // This while loop serves as the main search function throughout searchdir(). It will iterate through each file in the directory and print out its complete working path
  // if it passes all of the criteria set by searchdir()'s parameters.
  while ((myfile = readdir(mydir)) != NULL)
    {
      if (lstat(myfile->d_name, &mystat) < 0)
	{
	  return;
	}

      // If searchdir() encounters a directory, it will then recursively call searchdir() again using said directory. When it is finished in that directory,
      // it will return to the parent directory of that which was called.
      if (mystat.st_mode & S_IFDIR)
	{
	  // This will skip through printing the parent directory, stopping any potential infinite loops
	  location = myfile->d_name;
	  if (strcmp(location, ".") == 0 || strcmp(location, "..") == 0)
	    {
	      continue;
	    }
	  // If the type flag was "d" or blank it will print out the file's path before going into the next searchdir() call if it passes all parameter checks.
	  if (strstr(location, findme))
	    {
	      if (type == '\0')
		{
		  printf("%s\n", realpath(location, NULL));
		}
	      else if (type == 'd')
		{
		  printf("%s\n", realpath(location, NULL));
		}
	    }
	  // This is the recursive call if a directory is encountered during the search.
	  searchdir(location, findme, type);
	  
	  // Returns to the parent directory after it is done searching the current one.
	  if (chdir("..") != 0)
	    {
	      perror("chdir");
	      return;
	    }
	}
      else
	{
	  // First checks to see if any portion of the file name contains the command line argument given in the main method.
	  if (strstr(myfile->d_name, findme))
	    {
	      // If it does, it will move on the type flag checks. If no flag was given, than all the files will be printed out.
	      if (type == '\0')
		{
		  printf("%s\n", realpath(myfile->d_name, NULL));
		}
	      // If the flag was given, this will go through each possible flag call according to lstat()'s manual page and check to see if
	      // the command line argument matches any of the possible options. If not, it will print out an error statement that a
	      // possible argument must be used when calling the "-t" flag.
	      else
		{
		  if (type == 'f')
		    {
		      if (mystat.st_mode & S_IFREG)
			printf("%s\n", realpath(myfile->d_name, NULL));
		    }
		  else if (type == 'd')
		    {
		      if (mystat.st_mode & S_IFDIR)
			printf("%s\n", realpath(myfile->d_name, NULL));
		    }
		  else if (type == 'c')
		    {
		      if (mystat.st_mode & S_IFCHR)
			printf("%s\n", realpath(myfile->d_name, NULL));
		    }
		  else if (type == 'b')
		    {
		      if (mystat.st_mode & S_IFBLK)
			printf("%s\n", realpath(myfile->d_name, NULL));
		    }
		  else if (type == 'p')
		    {
		      if (mystat.st_mode & S_IFIFO)
			printf("%s\n", realpath(myfile->d_name, NULL));
		    }
		  else if (type == 'l')
		    {
		      if (mystat.st_mode & S_IFLNK)
			printf("%s\n", realpath(myfile->d_name, NULL));
		    }
		  else if (type == 's')
		    {
		      if (mystat.st_mode & S_IFSOCK)
			printf("%s\n", realpath(myfile->d_name, NULL));
		    }
		  else
		    {
		      printf("Must be a valid type flag.\n");
		      return;
		    }
		}
	    }
	}
    }
  // Closes the directory once it is finished searching it to prevent any memory overflow that might occur from
  // searching any deep directories.
  closedir(mydir);
}

int isdirectory(char * filename)
{
  int err;
  struct stat mystat;

  err = lstat(filename, &mystat);

  if(-1 == err) 
    {
      if(ENOENT == errno)
	{
	  /* does not exist */
	  return 0;
	} 
      else 
	{
	  perror("stat");
	  exit(1);
	}
    } 
  else  // no error 
    {
      if(S_ISDIR(mystat.st_mode)) 
	{
	  /* it's a dir */
	  return 1;
	} 
      else 
	{
	  /* exists but is not a directory */
	  printf("ls: %s: No such file or directory", filename);
	  return 0;
	}
    }
}
