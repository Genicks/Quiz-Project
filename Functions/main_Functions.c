#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "formatting_Functions.c"
#include "support_Functions.c"
#include "validation_Functions.c"
#include "question_Functions.c"

//! This function outputs every level of the game
int gameLevel(level x, int i, int array[5][2], int *fullScore, int *totalScore, int (*highScore)[1][2])
{
    if (i != 1)
        printf("\n\n");
    underScoreDivider();
    printf("---------------- LEVEL .%d ----------------\n", i);
    underScoreDivider();
    int score = questionScores(x, array, fullScore);
    *totalScore += score;

    if ((*highScore)[0][0] < *totalScore)
    {
        (*highScore)[0][0] = *totalScore;
        (*highScore)[0][1] = *fullScore;
    }
    printf("Current Score: %d/%d", *totalScore, *fullScore);

    return score;
}

//!  The following functions update and display the top 5 highest scores achieved throughout the game.
int highScoreModifier(int (*highScores)[2], int currentScore[1][2])
{
    if (currentScore[0][0] > highScores[4][0])
    {
        int i = 4;
        while (i >= 0 && currentScore[0][1] > highScores[i][0])
        {
            if (i < 4)
            {
                highScores[i + 1][0] = highScores[i][0];
                highScores[i + 1][1] = highScores[i][1];
            }
            highScores[i][0] = currentScore[0][0];
            highScores[i][1] = currentScore[0][1];
            i--;
        }
    }

    printf("\nHighest Scores\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d - %d/%d\n", i + 1, highScores[i][0], highScores[i][1]);
    }
    currentScore[0][0] = 0;
    currentScore[0][1] = 0;

    return 0;
}

//!  The following functions update and display the top 5 most recent scores achieved throughout the game.
int recentScoreModifier(int (*recentScores)[2], int currentScore[1][2])
{
    for (int i = 3; i >= 0; i--)
    {
        recentScores[i + 1][0] = recentScores[i][0];
        recentScores[i + 1][1] = recentScores[i][1];
    }
    recentScores[0][0] = currentScore[0][0];
    recentScores[0][1] = currentScore[0][1];

    printf("\nRecent Scores\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d - %d/%d\n", i + 1, recentScores[i][0], recentScores[i][1]);
    }
    currentScore[0][0] = 0;
    currentScore[0][1] = 0;

    return 0;
}
