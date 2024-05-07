#include <stdbool.h>

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