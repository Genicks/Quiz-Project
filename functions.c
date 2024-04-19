#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "data_QuestionLevel1.c"

// !Creates a 2D Array with random values for the second column
void arrayRandomize(int array[5][2])
{
    srand(time(0));
    for (int i = 0; i < 5; ++i)
    {
        array[i][0] = i;
        array[i][1] = (rand() % 5);
    }
}

// !Generates a random question from a random topic as defined by a structure
void QuestionGenerator(level x, int randSubject, int randNum)
{
    printf("\n%s\n", x.subjects[randSubject].questions.question[randNum]);
    for (int i = (randNum * 4); i <= ((randNum * 4) + 3); i++)
    {
        printf("\t%s\n", x.subjects[randSubject].questions.option[i]);
    }
}

// !Simple divider this has a stylistic purpose
void dashDivider()
{
    printf("------------------------------------\n");
}
void underScoreDivider()
{
    printf("__________________________________________\n");
}

// !This function compares the user input with answer and return 1 if correct, 0 otherwise.
int answerCheck(char answer, char input)
{
    if (answer == toupper(input))
    {
        printf("Status: Correct");
        return 1;
    }
    else
    {
        printf("Status: Incorrect");
        return 0;
    }
}

// !Ask a question, wait for a response, and return 1 if correct, 0 otherwise.
int askQuestion(level x, int y, int z)
{
    char input;
    char answer = (x.subjects[y].questions.answer[z]);
    QuestionGenerator(x, (y), (z));
    printf("Input: ");
    // scanf(" %c", &input);
    // printf("\n");
    input = answer;
    dashDivider();
    printf("Answer: %c\n", answer);
    return answerCheck(answer, input);
}

// !This function calculates the score for a level of questions and increments the full score by 5.
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
        if (i == 4)
        {
            dashDivider();
        }

        // sleep(2);
    }
    return totalScore;
}