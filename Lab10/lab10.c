#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int x;
static void handler(int signo)
{
  if (signo == SIGUSR1)
    {
      printf("Got my PARENT's signal of %d my PID = %d, parent's pid = %d\n", SIGUSR1, x, getpid());
    }
  else if (signo == SIGUSR2)
    {
       printf("Got my CHILD's signal of %d my PID = %d, child's pid = %d\n", SIGUSR2, getpid(), x);
    }
  else if (signo == SIGTERM)
    {
      printf("Got my PARENT's signal of %d my PID = %d, parent's pid = %d\n", SIGTERM, x, getpid());
    }
  else
    {
      fprintf(stderr, "ERROR: received signal %d\n", signo);
      perror("bad signal number\n");
      exit(1);
    }
  return;
}

int main(int argc, char* argv[])
{
  //signal (SIGUSR1, handler) * 3
  //fork()
  //*Child*
  //kill(SIGUSR2)
  //for() *sleep loop*
  //     sleep(1)
  //     printf(how long you slept, pid, ppid)
  //exit(0)
  //*Parent*
  //pause() -> waiting for SIGUSR2
  //kill(SIGUSR1)
  //kill(SIGTERM)
  //sleep(however long)
  //kill(SIGUSR1)
  //wait(NULL) -> child to finish
  //printf(*ending*)
  //return 0;

  int time = 10;
  int stopwhere = 20;
  char *c;

  if (argv[1] != NULL && argv[2] != NULL)
    {
      time = (int)strtol(argv[1], &c, 10);
      stopwhere = (int)strtol(argv[2], &c, 10);
    }

  signal (SIGUSR1, handler);
  signal (SIGUSR2, handler);
  signal (SIGTERM, handler);

  x = fork();
  int slept = 1;

  if (x == 0)
    {
      printf("Child sleeps for %d seconds\n\n", time);
      kill(getppid(), SIGUSR2);
      while (slept < time + 1)
	{
	  sleep(1);
	  printf("Child PID %d @ %d seconds %.2f%% complete\n", getpid(), slept, ((double)slept/time) * 100);
	  slept ++;
	}
      exit(0);
    }
  else
    {
      pause();
      kill(getpid(), SIGUSR1);
      kill(getpid(), SIGTERM);
      sleep(((double)stopwhere/100) * time + 1);
      kill(getpid(), SIGUSR1);
      wait(NULL);
      printf("Bye... Bye... I have harvested my children and peacefully leaving the world of UNIX...\n");
      return 0;
    }
}
