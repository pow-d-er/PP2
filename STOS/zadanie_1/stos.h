#ifndef stos_h
#define stos_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_t stack_t;

struct stack_t{
int size;
int howMuch;
int value;
stack_t* prevStack;
};

stack_t* stack_create(int size);
void stack_push(stack_t* pstack, int value);
int stack_pop(stack_t* pstack);
bool stack_empty(const stack_t* pstack);
void stack_free(stack_t* pstack);
void stack_print(const stack_t* pstack);

#endif
