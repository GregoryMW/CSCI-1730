#include <stdio.h>

#define MAX_LINE 80

// functions from statistics.c, prototype is in statistic.h
#include "statistics.h"


/* ---
 *  getIntegerLine() 
 * 	returns a positive integer from a line of input 
 * 	
 *      Assumption: assumes proper input.
*/
int getIntegerLine()
{
        char    line[MAX_LINE];
        int     return_user_int=-1;

        fgets( line, sizeof( line ), stdin );
        while( sscanf( line, "%d", &return_user_int ) != 1 )
        {
                // Not a positive integer - indicates end of input
		return -1; 
        }
        return return_user_int;
}


/* ---
 *      prompts user for input.
*/
void promptList()
{
	printf( "\nAssumes proper input \n\n" );
        printf( " Type a list of non-negative integers, below, one integer per line\n" );
        printf( " Indicate the END of input with any letter (a-z):\n\n"  );
}



void driver()
{
	int anumber = -1;
	int numbers = 0;
	double sum = -1;
	double avg = -1;
	double squares = -1;
	double variance = -1;
	int min = -1;
	int max = -1;

	promptList();

	while((anumber = getIntegerLine()) >= 0) 
	  {
	    numbers++;
	    sum = numbers_sum(anumber);
	    avg = numbers_average(anumber);
	    squares = numbers_squares(anumber);
	    min = numbers_min(anumber);
	    max = numbers_max(anumber);
	  }


	printf("            Sum: %.2f\n"
"        Average: %.2f\n"
" Sum of Squares: %.2f\n"
"Sample Variance: %.2f\n"
"        Minimum: %d\n"
"        Maximum: %d\n", sum, avg, squares, variance, min, max);

}

