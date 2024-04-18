#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  srand(time(0));
  int array[5][2];

  for (int i = 0; i < 5; ++i)
  {
    array[i][0] = i;
    array[i][1] = (rand() % 5);
  }

  for (int i = 0; i < 5; ++i)
  {
    printf("(%d, %d)\n", array[i][0], array[i][1]);
  }
  return 0;
}