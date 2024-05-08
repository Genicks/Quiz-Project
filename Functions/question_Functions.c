#include "../Question_Levels/level_3.c"
#include "../Question_Levels/level_2.c"
#include "../Question_Levels/level_1.c"

//! Generates a random question from a specified topic as defined by a structure
void QuestionGenerator(level x, int randSubject, int randNum)
{
    printf("\n%s\n", x.subjects[randSubject].questions.question[randNum]);
    for (int i = (randNum * 4); i <= ((randNum * 4) + 3); i++)
    {
        printf("\t%s\n", x.subjects[randSubject].questions.option[i]);
    }
}

//! Ask a question, wait for a response, and return 1 if correct, 0 otherwise.
int askQuestion(level x, int y, int z)
{
    char input;
    char answer = (x.subjects[y].questions.answer[z]);

    QuestionGenerator(x, (y), (z));

    printf("Input: ");
    scanf(" %c", &input);
    // input = answer; //*For testing purposes
    // printf("\n"); //*For Formatting during test
    dashDivider();
    sleep(1);// Allows Readability of content
    printf("Answer: %c\n", answer);
    sleep(1);// Allows player to know the correct Answer
    
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
        int score = (askQuestion(x, (array[i][0]), (array[i][1])));
        totalScore += score;
        printf("\tScore: %d/%d\n", totalScore, 5);
        sleep(1);// Allows scores to be read
        if (i == 4)
        {
            dashDivider();
        }
    }
    return totalScore;
}
