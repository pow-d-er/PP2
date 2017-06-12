#ifndef stos_double_h
#define stos_double_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_double_t stack_double_t;

struct stack_double_t{
int size;
int howMuch;
double value;
stack_double_t* prevStack;
};

stack_double_t* stack_double_create(int size);
void stack_double_push(stack_double_t* pstack, double value);
bool stack_double_try_push(stack_double_t* pstack, double value);
int stack_double_pop(stack_double_t* pstack);
bool stack_double_try_pop(stack_double_t* pstack);
bool stack_double_empty(const stack_double_t* pstack);
void stack_double_free(stack_double_t* pstack);
void stack_double_print(const stack_double_t* pstack);
void remove_all_double(stack_double_t** pstack);
void save_stack_double(const char* path, stack_double_t* pstack);
stack_double_t* load_stack_double(const char* path);

#endif
