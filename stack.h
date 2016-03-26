//
// Created by loewi on 23.03.16.
//

#ifndef UE01_STACK_H
#define UE01_STACK_H

#include <stdlib.h>


typedef struct{
    int size, insPos;
    float *values;
    char error;
} stack_t;

stack_t *createStack();

char isEmpty(stack_t *s);

void push(stack_t *s, float value);

float top(stack_t *s);

void pop(stack_t *s);

char getError(stack_t *s);

void destroyStack(stack_t *s);

#endif //UE01_STACK_H
