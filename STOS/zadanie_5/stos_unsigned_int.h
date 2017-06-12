#ifndef stos_unsigned_int_h
#define stos_unsigned_int_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_unsigned_int_t stack_unsigned_int_t;

struct stack_unsigned_int_t{
int size;
int howMuch;
unsigned int value;
stack_unsigned_int_t* prevStack;
};

stack_unsigned_int_t* stack_unsigned_int_create(int size);
void stack_unsigned_int_push(stack_unsigned_int_t* pstack, unsigned int value);
bool stack_unsigned_int_try_push(stack_unsigned_int_t* pstack, unsigned int value);
int stack_unsigned_int_pop(stack_unsigned_int_t* pstack);
bool stack_unsigned_int_try_pop(stack_unsigned_int_t* pstack);
bool stack_unsigned_int_empty(const stack_unsigned_int_t* pstack);
void stack_unsigned_int_free(stack_unsigned_int_t* pstack);
void stack_unsigned_int_print(const stack_unsigned_int_t* pstack);
void remove_all_unsigned_int(stack_unsigned_int_t** pstack);
void save_stack_unsigned_int(const char* path, stack_unsigned_int_t* pstack);
stack_unsigned_int_t* load_stack_unsigned_int(const char* path);

#endif
