#ifndef stos_short_h
#define stos_short_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_short_t stack_short_t;

struct stack_short_t{
int size;
int howMuch;
short value;
stack_short_t* prevStack;
};

stack_short_t* stack_short_create(int size);
void stack_short_push(stack_short_t* pstack, short value);
bool stack_short_try_push(stack_short_t* pstack, short value);
int stack_short_pop(stack_short_t* pstack);
bool stack_short_try_pop(stack_short_t* pstack);
bool stack_short_empty(const stack_short_t* pstack);
void stack_short_free(stack_short_t* pstack);
void stack_short_print(const stack_short_t* pstack);
void remove_all_short(stack_short_t** pstack);
void save_stack_short(const char* path, stack_short_t* pstack);
stack_short_t* load_stack_short(const char* path);

#endif
