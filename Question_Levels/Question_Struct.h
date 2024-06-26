#ifndef QUIZ_STRUCTS_H
#define QUIZ_STRUCTS_H

typedef struct 
{
    char question[5][200];
    char option[20][50];
    char answer[5];
} QA;

typedef struct 
{
    char name[20];
    QA questions;
} subject;

typedef struct 
{
    subject subjects[5];
} level;

#endif 
