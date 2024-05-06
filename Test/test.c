#include <time.h>
#include <stdio.h>
#include <stdio.h>

int highScoreModifier(int highScores[5][2], int currentScore[2])
{
    if (currentScore[0] > highScores[4][0])
    {
        int i = 4;
        while (i >= 0 && currentScore[0] >= highScores[i][0])
        {
            if (i < 4)
            {
                highScores[i + 1][0] = highScores[i][0];
                highScores[i + 1][1] = highScores[i][1];
            }
            highScores[i][0] = currentScore[0];
            highScores[i][1] = currentScore[1];
            i--;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d Highest: %d/%d\n", i, highScores[i][0], highScores[i][1]);
    }

    return 0; // Assuming 0 indicates successful completion
}

int main()
{
    int highScores[5][2] = {0};
    int current[2] = {0, 0};

    while (1)
    {
        printf("\nEnter Score: ");
        scanf("%d/%d", &current[0], &current[1]);
        printf("Current: %d/%d\n\n", current[0], current[1]);
        highScoreModifier(highScores, current);
    }

    //   while (current != 1)
    //   {
    //     printf("\nEnter Score: ");
    //     scanf("%d", &current);
    //     printf("Current: %d\n\n", current);

    //     for (int i = 4; i > 0; i--)
    //     {
    //       recentScores[i] = recentScores[i - 1];
    //     }

    //     recentScores[0] = current;

    //     printf("Recent Scores:\n");
    //     for (int i = 0; i < 5; i++)
    //     {
    //       printf("%d\n", recentScores[i]);
    //     }
    //   }

    // return 0;
}
