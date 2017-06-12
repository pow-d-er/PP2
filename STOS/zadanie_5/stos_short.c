#include "stos_short.h"

stack_short_t* stack_short_create(int size){
stack_short_t* new = malloc(sizeof(stack_short_t));
new->size = size;
new->howMuch = 0;
new->prevStack = NULL;
new->value = 0;
};

void stack_short_push(stack_short_t* pstack, short value){

  stack_short_t* next = malloc(sizeof(stack_short_t));
  next->prevStack = malloc(sizeof(stack_short_t));
  next->value = value;
  *next->prevStack = *pstack;
  next->howMuch = pstack->howMuch+1;
  next->size = pstack->size;
*pstack = *next;

};

bool stack_short_try_push(stack_short_t* pstack, short value){
    if(pstack->howMuch == pstack->size){
      printf("Stos pełny, nie można dodać już do niego żadnego elementu.\n");
      return false;
    }else{
      stack_short_push(pstack, value);
      return true;
    }

};

int stack_short_pop(stack_short_t* pstack){
  short value = pstack->value;
  *pstack = *pstack->prevStack;
  return value;
};

bool stack_short_empty(const stack_short_t* pstack){
  if(pstack->howMuch == 0) return true;
  else return false;
};

bool stack_short_try_pop(stack_short_t* pstack){
  if(stack_short_empty(pstack)){
    printf("Stos jest pusty, więc nie można zdjąć z niego żadnego elementu\n");
    return false;
  }else{
    printf("Zdjety element ze stosu: %d\n",stack_short_pop(pstack));
    return true;
  }
};



void stack_short_free(stack_short_t* pstack){
  stack_short_t* current_stack = malloc(sizeof(stack_short_t));
  while((current_stack = pstack) != NULL){
    pstack = pstack->prevStack;
    free(current_stack);
  }
};

void stack_short_print(const stack_short_t* pstack){
  if(stack_short_empty(pstack)) printf("Stos jest pusty\n");
  else{
  printf("\nZawartość stosu: \n");
  stack_short_t *stack = malloc(sizeof(stack_short_t));
  stack->value = pstack->value;
  stack->prevStack = pstack->prevStack;
  while(stack->prevStack != NULL){
    printf("%d\n",stack->value);
    stack = stack->prevStack;
  }
}
};

void remove_all_short(stack_short_t** pstack){
  stack_short_t* current_stack = malloc(sizeof(stack_short_t*));
  while((current_stack = (*pstack)->prevStack) != NULL){
    *pstack = (*pstack)->prevStack;
    current_stack = NULL;
  }
};

void save_stack_short(const char* path, stack_short_t* pstack){
  FILE *fp = fopen(path,"wb");
  if(fp){

    fwrite(pstack,sizeof(stack_short_t),1,fp);

  }else printf("Błąd odczytu pliku");

  fclose(fp);
};


stack_short_t* load_stack_short(const char* path){
  FILE* fp = fopen(path,"rb");
stack_short_t* loaded_stack = malloc(sizeof(stack_short_t));
  if(fp){
  fread(loaded_stack,sizeof(stack_short_t),1,fp);
  }else printf("Błąd odczytu pliku");
  fclose(fp);

  return loaded_stack;
};
