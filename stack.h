#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stdio.h>
struct stack
{
    union
    {
        int i;
        float f;
        char c;
        char *s;
    } *values;
};
struct stack stack;
int len = sizeof(stack.values) / sizeof(int);
int vals[] = {};
#endif