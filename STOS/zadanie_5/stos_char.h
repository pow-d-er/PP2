#ifndef stos_char_h
#define stos_char_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_char_t stack_char_t;

struct stack_char_t{
int size;
int howMuch;
char value;
stack_char_t* prevStack;
};

stack_char_t* stack_char_create(int size);
void stack_char_push(stack_char_t* pstack, char value);
bool stack_char_try_push(stack_char_t* pstack, char value);
int stack_char_pop(stack_char_t* pstack);
bool stack_char_try_pop(stack_char_t* pstack);
bool stack_char_empty(const stack_char_t* pstack);
void stack_char_free(stack_char_t* pstack);
void stack_char_print(const stack_char_t* pstack);
void remove_all_char(stack_char_t** pstack);
void save_stack_char(const char* path, stack_char_t* pstack);
stack_char_t* load_stack_char(const char* path);

#endif
