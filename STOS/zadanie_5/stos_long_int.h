#ifndef stos_long_int_h
#define stos_long_int_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_long_int_t stack_long_int_t;

struct stack_long_int_t{
int size;
int howMuch;
long int value;
stack_long_int_t* prevStack;
};

stack_long_int_t* stack_long_int_create(int size);
void stack_long_int_push(stack_long_int_t* pstack, long int value);
bool stack_long_int_try_push(stack_long_int_t* pstack, long int value);
int stack_long_int_pop(stack_long_int_t* pstack);
bool stack_long_int_try_pop(stack_long_int_t* pstack);
bool stack_long_int_empty(const stack_long_int_t* pstack);
void stack_long_int_free(stack_long_int_t* pstack);
void stack_long_int_print(const stack_long_int_t* pstack);
void remove_all_long_int(stack_long_int_t** pstack);
void save_stack_long_int(const char* path, stack_long_int_t* pstack);
stack_long_int_t* load_stack_long_int(const char* path);

#endif
