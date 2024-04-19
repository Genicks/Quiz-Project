#include "functions.c"
#include <stdbool.h>

int gameLevel(level x, int i, int array[5][2], int *totalScore, int *fullScore)
{
  underScoreDivider();
  printf("---------------- LEVEL .%d ----------------\n", i);
  underScoreDivider();
  int score = questionScores(x, array, fullScore);
  *totalScore += score;

  printf("Overall Score: %d/%d", *totalScore, *fullScore);
  return score;
}

bool levelPassedCheck(int score, int i)
{
  if (score > 4)
  {
    printf("\tLevel .%d: Passed\n\n", i);
    return true;
  }
  else
    printf("\tLevel .%d Failed\n\n", i);
  return false;
}


int main()
{
  int array[5][2];
  arrayRandomize(array);
  int totalScore = 0;
  int fullScore = 0;

  for (int i = 0; i < 6; i++)
  {
    if (i == 0)
    {
      int score = gameLevel(one, i + 1, array, &totalScore, &fullScore);
      if (!levelPassedCheck(score, i + 1))
      {
        break;
      }
    }
    else if (i == 1)
    {
      int score = gameLevel(one, i + 1, array, &totalScore, &fullScore);
      if (!levelPassedCheck(score, i + 1))
      {
        break;
      }
    }
    else if (i == 2)
    {
      int score = gameLevel(one, i + 1, array, &totalScore, &fullScore);
      if (!levelPassedCheck(score, i + 1))
      {
        break;
      }
    }
    else if (i == 3)
    {
      int score = gameLevel(one, i + 1, array, &totalScore, &fullScore);
      if (!levelPassedCheck(score, i + 1))
      {
        break;
      }
    }
    else if (i == 4)
    {
      int score = gameLevel(one, i + 1, array, &totalScore, &fullScore);
      if (!levelPassedCheck(score, i + 1))
      {
        break;
      }
    }
    else if (i == 5)
    {
      int score = gameLevel(one, i + 1, array, &totalScore, &fullScore);
      if (!levelPassedCheck(score, i + 1))
      {
        break;
      }
    }
  }
}
