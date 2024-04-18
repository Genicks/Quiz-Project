// Define structure to hold questions, Option & answers Sheet
typedef struct 
{
    char question[5][100];
    char option[20][50];
    char answer[5];
} QA;

// Define structure to hold questions and answers for a subject
typedef struct 
{
    char name[20];
    QA questions;
    QA options;
    QA answers;
} subject;

// Define structure to represent levels containing subjects
typedef struct 
{
    subject subjects[5];
} level;
