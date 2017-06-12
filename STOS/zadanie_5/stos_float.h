#ifndef stos_float_h
#define stos_float_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_float_t stack_float_t;

struct stack_float_t{
int size;
int howMuch;
float value;
stack_float_t* prevStack;
};

stack_float_t* stack_float_create(int size);
void stack_float_push(stack_float_t* pstack, float value);
bool stack_float_try_push(stack_float_t* pstack, float value);
int stack_float_pop(stack_float_t* pstack);
bool stack_float_try_pop(stack_float_t* pstack);
bool stack_float_empty(const stack_float_t* pstack);
void stack_float_free(stack_float_t* pstack);
void stack_float_print(const stack_float_t* pstack);
void remove_all_float(stack_float_t** pstack);
void save_stack_float(const char* path, stack_float_t* pstack);
stack_float_t* load_stack_float(const char* path);

#endif
