#include "stos.h"

stack_t* stack_create(int size){
stack_t* new = malloc(sizeof(stack_t));
new->size = size;
new->howMuch = 0;
new->prevStack = NULL;
new->value = 0;
};

void stack_push(stack_t* pstack, int value){

  stack_t* next = malloc(sizeof(stack_t));
  next->prevStack = malloc(sizeof(stack_t));
  next->value = value;
  *next->prevStack = *pstack;
  next->howMuch = pstack->howMuch+1;
  next->size = pstack->size;
*pstack = *next;

};

int stack_pop(stack_t* pstack){
  int value = pstack->value;
  *pstack = *pstack->prevStack;
  return value;
};

bool stack_empty(const stack_t* pstack){
  if(pstack->prevStack == NULL) return true;
  else return false;
};

void stack_free(stack_t* pstack){
  stack_t* current_stack = malloc(sizeof(stack_t));
  while((current_stack = pstack) != NULL){
    pstack = pstack->prevStack;
    free(pstack);
  }
};

void stack_print(const stack_t* pstack){
  printf("\nZawartość stosu: \n");
  stack_t *stack = malloc(sizeof(stack_t));
  stack->value = pstack->value;
  stack->prevStack = pstack->prevStack;
  while(stack->prevStack != NULL){
    printf("%d\n",stack->value);
    stack = stack->prevStack;
  }
};
