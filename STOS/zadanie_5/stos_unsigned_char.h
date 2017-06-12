#ifndef stos_unsigned_char_h
#define stos_unsigned_char_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_unsigned_char_t stack_unsigned_char_t;

struct stack_unsigned_char_t{
int size;
int howMuch;
unsigned char value;
stack_unsigned_char_t* prevStack;
};

stack_unsigned_char_t* stack_unsigned_char_create(int size);
void stack_unsigned_char_push(stack_unsigned_char_t* pstack, unsigned char value);
bool stack_unsigned_char_try_push(stack_unsigned_char_t* pstack, unsigned char value);
int stack_unsigned_char_pop(stack_unsigned_char_t* pstack);
bool stack_unsigned_char_try_pop(stack_unsigned_char_t* pstack);
bool stack_unsigned_char_empty(const stack_unsigned_char_t* pstack);
void stack_unsigned_char_free(stack_unsigned_char_t* pstack);
void stack_unsigned_char_print(const stack_unsigned_char_t* pstack);
void remove_all_unsigned_char(stack_unsigned_char_t** pstack);
void save_stack_unsigned_char(const char* path, stack_unsigned_char_t* pstack);
stack_unsigned_char_t* load_stack_unsigned_char(const char* path);

#endif
