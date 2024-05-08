#include "Functions/main_Functions.c"
#include <stdbool.h>
#include <ctype.h>

int main()
{
  int array[5][2];
  int highScore[1][2] = {{0, 0}};
  bool playAgainCheck = false;
  int highScores[5][2] = {0};
  int recentScores[5][2] = {0};

  do
  {
    int currentScore[1][2] = {0};
    arrayRandomize(array);

    for (int i = 0; i < 3; i++)
    {
      if (i == 0)
      {
        int score = gameLevel(one, i + 1, array, &currentScore[0][0], &currentScore[0][1], &highScore);
        if (!levelPassedCheck(score, i + 1))
        {
          recentScoreModifier(highScores, highScore);
          break;
        }
        recentScoreModifier(highScores, highScore);
      }
      else if (i == 1)
      {
        int score = gameLevel(two, i + 1, array, &currentScore[0][0], &currentScore[0][1], &highScore);
        if (!levelPassedCheck(score, i + 1))
        {
          recentScoreModifier(highScores, highScore);
          break;
        }
        recentScoreModifier(highScores, highScore);
      }
      else if (i == 2)
      {
        int score = gameLevel(three, i + 1, array, &currentScore[0][0], &currentScore[0][1], &highScore);
        if (!levelPassedCheck(score, i + 1))
        {
          recentScoreModifier(highScores, highScore);
          break;
        }
        recentScoreModifier(highScores, highScore);
      }
    }

    highScoreModifier(highScores, highScore);
    playAgainAsk(&playAgainCheck);
  } while (playAgainCheck);
}
