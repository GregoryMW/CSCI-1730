CSCI 1730 Project 3

Name of program: sfind.c

This program replicates a portion of the UNIX command "find"'s functionality. The user has the option to include a directory to search and two flags, -n and -t. Any string the user enters in
the command line after "sfind" will be used as the directory the user wants to search through. If no directory is given, the program will default to the current working directory. The program will check
to see if the directory is valid, continuing if it is and printing out an error and exiting if it is not. -n requires the user to input a string that will serve as what the program will search for in the
name of each file in the given directory sfind is searching through. -t requires one of the type flags as defined by lstat()'s manual page, and will find all files in the searched directory that match the
file type given in the command line argument. The user can use any combination of these two options: both, one, or neither and the program will search the specified directory and print the complete file
path of the files that match any parameters given in the command line argument(s).

CODER: Gregory Woolsey

CREDIT/Contributions: isdirectory() function originally found in CSCI 1730's Lab7 on praciticing the usage of stat()

How to compile:
    gcc -g -Wall -o sfind sfind.c search.c

OR use the included Makefile
   make

How to run:
    sfind <directory-where to start looking> -n substring-criteria -t <filetype>
    *All arguments for sfind are optional
