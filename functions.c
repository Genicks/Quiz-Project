#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "data_QuestionLevel1.c"

// !Creates a 5x2 Array with random values
void arrayRandomize(int array[5][2])
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            array[i][j] = rand() % 5;
        }
    }
}

// !Ensures that their are no duplicate value pairs by comparing each row
void uniqueRandPairArray(int array[5][2])
{
    printf("Ensuring Uniqueness...\n\n");
    srand(time(0));
    arrayRandomize(array); // Creates the first instants of the random array
    int numTests = 0;
    bool hasDuplicates = false;

    do // Test uniqueness
    {
        for (int i = 0; i < 4 && !hasDuplicates; ++i)
        {
            for (int j = i + 1; j < 5 && !hasDuplicates; ++j)
            {
                if (array[i][0] == array[j][0] && array[i][1] == array[j][1])
                {
                    hasDuplicates = true;
                    arrayRandomize(array); // If not unique create a new instants of the random array
                }
            }
        }
        numTests++;
    } while (hasDuplicates);
    printf("Uniqueness Achieved after %d tries\n\n", numTests);
}

// !Generates a random question from a random topic as defined by a structure
void QuestionGenerator(level x, int randSubject, int randNum)
{
    printf("\n%s\n", x.subjects[randSubject].questions.question[randNum]);
    for (int i = (randNum * 4); i <= ((randNum * 4) + 3); i++)
    {
        printf("%s\n", x.subjects[randSubject].questions.option[i]);
    }
}
