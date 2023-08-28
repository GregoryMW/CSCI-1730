// only include declaration once, by defining prepprocessor 'dummy variable'
#ifndef STATISTICS_H   
#define STATISTICS_H


extern double running_average( int add_number );

extern double numbers_sum(int numSum);

extern double numbers_average(int numAvg);

extern double numbers_squares(int numSquares);

extern double numbers_variance(int numVar);

extern int numbers_min(int numMin);

extern int numbers_max(int numMax);

#endif

