#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"
#include <unistd.h>

int main()
{
  int array[5][2];

  uniqueRandPairArray(array);
  // for (int i = 0; i < 5; ++i)
  // {
  //   printf("(%d, %d)\n", array[i][0], array[i][1]);
  // }

  QuestionGenerator(one, (array[0][0]), (array[0][1]));
  // sleep(1);
  QuestionGenerator(one, (array[1][0]), (array[1][1]));
  // sleep(1);
  QuestionGenerator(one, (array[2][0]), (array[2][1]));
  // sleep(1);
  QuestionGenerator(one, (array[3][0]), (array[3][1]));
  // sleep(1);
  QuestionGenerator(one, (array[4][0]), (array[4][1]));
}


// !Notes
// Uniqueness Testing: Instead of continuously generating random arrays until a unique one is found, you might want to consider a more efficient algorithm. One approach could involve generating all possible combinations of pairs and shuffling them randomly to ensure uniqueness without repetition.

// Error Handling: Currently, if a unique array cannot be generated after a large number of attempts, the program could potentially enter an infinite loop. You might want to include error handling to limit the number of attempts or provide a fallback mechanism.

// Code Organization: It's good practice to organize your code into functions with clear responsibilities. Consider separating the logic for generating random arrays and ensuring uniqueness into distinct functions for better readability and maintainability.

// Documentation: Adding comments or documentation to explain the purpose and usage of each function can make your code more understandable for others and your future self.