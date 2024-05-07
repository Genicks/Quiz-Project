#include <stdbool.h>

//! This function compares the user input with answer and return 1 if correct, 0 otherwise.
int answerCheck(char answer, char input)
{
    if (answer == toupper(input))
    {
        printf("Status: Correct  ");
        sleep(1);
        return 1;
    }
    else
    {
        printf("Status: Incorrect");
        sleep(1);
        return 0;
    }
}

//! This functions checks if the score is == 5 returns true or false based on that condition
bool levelPassedCheck(int score, int i)
{
    if ((score == 5) || (score == 4))
    {
        printf("\tLevel .%d: Passed\n", i);
        return true;
    }
    else
        printf("\tLevel .%d Failed\n", i);
    return false;
}
