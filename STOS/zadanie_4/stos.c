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

bool stack_try_push(stack_t* pstack, int value){
    if(pstack->howMuch == pstack->size){
      printf("Stos pełny, nie można dodać już do niego żadnego elementu.\n");
      return false;
    }else{
      stack_push(pstack, value);
      return true;
    }

};

int stack_pop(stack_t* pstack){
  int value = pstack->value;
  *pstack = *pstack->prevStack;
  return value;
};

bool stack_try_pop(stack_t* pstack){
  if(stack_empty(pstack)){
    printf("Stos jest pusty, więc nie można zdjąć z niego żadnego elementu\n");
    return false;
  }else{
    printf("Zdjety element ze stosu: %d\n",stack_pop(pstack));
    return true;
  }
};

bool stack_empty(const stack_t* pstack){
  if(pstack->howMuch == 0) return true;
  else return false;
};

void stack_free(stack_t* pstack){
  stack_t* current_stack = malloc(sizeof(stack_t));
  while((current_stack = pstack) != NULL){
    pstack = pstack->prevStack;
    free(current_stack);
  }
};

void stack_print(const stack_t* pstack){
  if(stack_empty(pstack)) printf("Stos jest pusty\n");
  else{
  printf("\nZawartość stosu: \n");
  stack_t *stack = malloc(sizeof(stack_t));
  stack->value = pstack->value;
  stack->prevStack = pstack->prevStack;
  while(stack->prevStack != NULL){
    printf("%d\n",stack->value);
    stack = stack->prevStack;
  }
}
};

void remove_all(stack_t** pstack){
  stack_t* current_stack = malloc(sizeof(stack_t*));
  while((current_stack = (*pstack)->prevStack) != NULL){
    *pstack = (*pstack)->prevStack;
    current_stack = NULL;
  }
};

void save_stack(const char* path, stack_t* pstack){
  FILE *fp = fopen(path,"wb");
  if(fp){

    fwrite(pstack,sizeof(stack_t),1,fp);

  }else printf("Błąd odczytu pliku");

  fclose(fp);
};


stack_t* load_stack(const char* path){
  FILE* fp = fopen(path,"rb");
stack_t* loaded_stack = malloc(sizeof(stack_t));
  if(fp){
  fread(loaded_stack,sizeof(stack_t),1,fp);
  }else printf("Błąd odczytu pliku");
  fclose(fp);

  return loaded_stack;
};
