#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wager.h"

void printGameRules()
{
  printf("Welcome to craps! This is a casino game that involves rolling two dice in attempts to get a particular desired number.\n"
	 "Two six-sided dice will be rolled, and the two upward-facing numbers will be added together.\n"
	 "If the sum is 7 or 11 on the first roll, the player wins!\n"
	 "If the sum is 2, 3, or 12 on the first roll, this is called 'craps', and the player loses.\n"
	 "If the sum is 4, 5, 6, 8, 9, or 10 on the first roll, then that number will be the players 'point'.\n"
	 "The player will continue to roll the two dice until they hit their 'point' (win), or they hit 7 (lose). Good luck!\n\n");
}

double getBankBalance()
{
  printf("Please enter an initial bank balance for your wagering: ");
  double balance = 0;
  scanf("%lf", &balance);
  while(getchar() != '\n');
  return balance;
}

int checkWager(double wager, double balance)
{
  if(wager <= balance)
    {
      return 1;
    }
  return 0;
}

double getWager()
{
  printf("Enter your wager for this roll: ");
  double wager = 0;
  scanf("%lf", &wager);
  while(getchar() != '\n');
  while (wager <= 0)
    {
      printf("Please wager a numerical amount greater than 0: ");
      scanf("%lf", &wager);
      while(getchar() != '\n');
    }
  return wager;
}

double adjustBalance(double bankBalance, double wageAmount, int addOrSubtractToBalance)
{
  bankBalance += (wageAmount * (double)addOrSubtractToBalance);
  return bankBalance;
}

int playGame()
{ 
  enum Status {CONTINUE, WON, LOST};
  
  int rollDice()
  {
    int die1;
    int die2;
    int workSum;

    die1 = 1 + (rand() % 6);
    die2 = 1 + (rand() % 6);
    workSum = die1 + die2;

    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
   
    return workSum;
  }

  int sum;
  int myPoint;

  enum Status gameStatus;
  
  srand(time(NULL));
  
  sum = rollDice();

  switch(sum) {
  case 7: 
  case 11:          
    gameStatus = WON;
    break;

  case 2: 
  case 3: 
  case 12:  
    gameStatus = LOST;
    break;

  default:                  
    gameStatus = CONTINUE;
    myPoint = sum;
    printf("Point is %d\n", myPoint);
    break;
  }

  while (gameStatus == CONTINUE) {    
    sum = rollDice();

    if (sum == myPoint)
      {
	gameStatus = WON;
      }
    else
      {
	  if (sum == 7)
	    {
	      gameStatus = LOST;
	    }  
	}
   }

   if (gameStatus == WON)
     {
       printf("Player wins\n");
       return 1;
     }
   else
     {
       printf("Player loses\n");
       return 0;
     }
}

int getYESorNO()
{
  printf("Would you like to play again?(y or n):\n");
  char ch;
  ch = getchar();
  while (getchar() != '\n');
  while (ch != 'y' && ch != 'n')
    {
      printf("Please enter a proper input.\n");
      ch = getchar();
      while (getchar() != '\n');
    }
  if (ch == 'y')
    {
      return 1;
    }
  return 0;
}

