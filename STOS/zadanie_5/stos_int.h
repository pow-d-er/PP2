#ifndef stos_int_h
#define stos_int_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_int_t stack_int_t;

struct stack_int_t{
int size;
int howMuch;
int value;
stack_int_t* prevStack;
};

stack_int_t* stack_int_create(int size);
void stack_int_push(stack_int_t* pstack, int value);
bool stack_int_try_push(stack_int_t* pstack, int value);
int stack_int_pop(stack_int_t* pstack);
bool stack_int_try_pop(stack_int_t* pstack);
bool stack_int_empty(const stack_int_t* pstack);
void stack_int_free(stack_int_t* pstack);
void stack_int_print(const stack_int_t* pstack);
void remove_all_int(stack_int_t** pstack);
void save_stack_int(const char* path, stack_int_t* pstack);
stack_int_t* load_stack_int(const char* path);

#endif
