#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      printf("Please give one input file to read from.\n");
      return EXIT_FAILURE;
    }
  
  char *buffer = NULL;
  size_t buffSize = 0;
  ssize_t lineSize;
  int count = 0;
  FILE *txt = fopen(argv[1], "r");

  if (!txt)
    {
      fprintf(stderr, "File Error");
      return EXIT_FAILURE;
    }

  lineSize = getline(&buffer, &buffSize, txt);
  while(lineSize >= 0)
    {
      count ++;
      lineSize = getline(&buffer, &buffSize, txt);
    }
  fclose(txt);

  int arr[count];
  txt = fopen(argv[1], "r");
  lineSize = getline(&buffer, &buffSize, txt);
  for (int i = 0; i < count; i ++)
    {
      arr[i] = atoi(buffer);
      lineSize = getline(&buffer, &buffSize, txt);
    }
  fclose(txt);

  printf("Given array: [");
  for (int i = 0; i < count; i ++)
    {
      if (i == count - 1)
	{
	  printf("%d]\n", arr[i]);
	}
      else
	{
	  printf("%d, ", arr[i]);
	}
    }

  for (int i = 0; i < count; i ++)
    {
      if (arr[i] == i)
	{
	  printf("Index match: X[%d] = %d\n", arr[i], i);
	}
    }
  return EXIT_SUCCESS;
}
