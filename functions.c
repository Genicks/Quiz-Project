#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "data_QuestionLevel1.c"

//! Creates a 2D Array with random values for the second column
void arrayRandomize(int array[5][2])
{
    srand(time(0));
    for (int i = 0; i < 5; ++i)
    {
        array[i][0] = i;
        array[i][1] = (rand() % 5);
    }
}

//! Generates a random question from a random topic as defined by a structure
void QuestionGenerator(level x, int randSubject, int randNum)
{
    printf("\n%s\n", x.subjects[randSubject].questions.question[randNum]);
    for (int i = (randNum * 4); i <= ((randNum * 4) + 3); i++)
    {
        printf("\t%s\n", x.subjects[randSubject].questions.option[i]);
    }
}

//! Simple divider this has a stylistic purpose
void dashDivider()
{
    printf("------------------------------------\n");
}
void underScoreDivider()
{
    printf("__________________________________________\n");
}

//! This function compares the user input with answer and return 1 if correct, 0 otherwise.
int answerCheck(char answer, char input)
{
    if (answer == toupper(input))
    {
        printf("Status: Correct  ");
        // sleep(1);
        return 1;
    }
    else
    {
        printf("Status: Incorrect");
        // sleep(1);
        return 0;
    }
}

//! Ask a question, wait for a response, and return 1 if correct, 0 otherwise.
int askQuestion(level x, int y, int z)
{
    char input;
    char answer = (x.subjects[y].questions.answer[z]);
    QuestionGenerator(x, (y), (z));
    printf("Input: ");
    // scanf(" %c", &input);
    input = answer;
    printf("\n");
    dashDivider();
    // sleep(1);// Allows Readability of content
    printf("Answer: %c\n", answer);
    // sleep(1);// Allows player to know the correct Answer
    return answerCheck(answer, input);
}

//! This function calculates the score for a level of questions and increments the full score by 5.
int questionScores(level x, int array[5][2], int *fullScore)
{
    *fullScore += 5;
    int totalScore = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("\nQuestion %d", i + 1);
        int score = (askQuestion(one, (array[i][0]), (array[i][1])));
        totalScore += score;
        printf("\tScore: %d/%d\n", totalScore, 5);
        // sleep(1);// Allows scores to be read
        if (i == 4)
        {
            dashDivider();
        }
    }
    return totalScore;
}

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

//! This functions checks if the score is == 5 returns true or false based on that condition
bool levelPassedCheck(int score, int i)
{
    // if ((4 >= score) || (score <= 5))
    if ((score == 5) || (score == 4))
    {
        printf("\tLevel .%d: Passed\n", i);
        return true;
    }
    else
        printf("\tLevel .%d Failed\n", i);
    return false;
}

//!  This function verifies that the player wants to try again after loosing a level
void playAgainAsk(bool *playAgainCheck)
{
    char input;
    bool notValid = true;

    while (notValid)
    {
        printf("\nDo you want to play again(y/n)? ");
        scanf(" %c", &input);
        if (toupper(input) == 'Y')
        {
            *playAgainCheck = true;
            notValid = false;
        }
        else if (toupper(input) == 'N')
        {
            *playAgainCheck = false;
            notValid = false;
        }
        else
        {
            notValid = true;
        }
    }
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

//!  The following functions update and display the top 5 highest scores achieved throughout the game.

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
    return 0;
}
