//
// Created by loewi on 23.03.16.
//
#include "stack.h"
#define START_SIZE 15

stack_t *createStack(){
    stack_t *s;
    s = (stack_t *) malloc(sizeof(stack_t));
    s->error = 0;
    s->size = START_SIZE;
    s->insPos = 0;
    s->values = (float*) malloc(s->size * sizeof(float));
}


char isEmpty(stack_t *s) {
    return (char) (s->values == 0 ? 1 : 0);
};

void push(stack_t *s, float value) {
    if (s->insPos == s->size) {
        s->values = (float *) realloc(s->values, s->size * 2 * sizeof(float));
        s->size *= 2;
    }
    s->values[s->insPos++] = value;
}

float top(stack_t *s){
    if (s->insPos == 0) {
        s->error = 1;
        return (float) -1;
    }
    return s->values[s->insPos-1];
}

void pop(stack_t *s) {
    if (s->insPos > 0) {
        s->insPos -= 1;
        if (s->insPos < s->size / 2 && s->size  > START_SIZE * 2){
            s->values = (float *) realloc(s->values, s->size / 2 * sizeof(float));
            s->size /= 2;
        }
    }
    s->error = 1;
}

char getError(stack_t *s) {
    char tmp = s->error;
    if (s->error > 0)
        s->error = 0;
    return tmp;
}

void destroyStack(stack_t *s) {
    free(s->values);
    free(s);
}