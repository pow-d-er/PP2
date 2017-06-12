#ifndef stos_unsigned_short_h
#define stos_unsigned_short_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_unsigned_short_t stack_unsigned_short_t;

struct stack_unsigned_short_t{
int size;
int howMuch;
unsigned short value;
stack_unsigned_short_t* prevStack;
};

stack_unsigned_short_t* stack_unsigned_short_create(int size);
void stack_unsigned_short_push(stack_unsigned_short_t* pstack, unsigned short value);
bool stack_unsigned_short_try_push(stack_unsigned_short_t* pstack, unsigned short value);
int stack_unsigned_short_pop(stack_unsigned_short_t* pstack);
bool stack_unsigned_short_try_pop(stack_unsigned_short_t* pstack);
bool stack_unsigned_short_empty(const stack_unsigned_short_t* pstack);
void stack_unsigned_short_free(stack_unsigned_short_t* pstack);
void stack_unsigned_short_print(const stack_unsigned_short_t* pstack);
void remove_all_unsigned_short(stack_unsigned_short_t** pstack);
void save_stack_unsigned_short(const char* path, stack_unsigned_short_t* pstack);
stack_unsigned_short_t* load_stack_unsigned_short(const char* path);

#endif
