#include "stos_double.h"

stack_double_t* stack_double_create(int size){
stack_double_t* new = malloc(sizeof(stack_double_t));
new->size = size;
new->howMuch = 0;
new->prevStack = NULL;
new->value = 0;
};

void stack_double_push(stack_double_t* pstack, double value){

  stack_double_t* next = malloc(sizeof(stack_double_t));
  next->prevStack = malloc(sizeof(stack_double_t));
  next->value = value;
  *next->prevStack = *pstack;
  next->howMuch = pstack->howMuch+1;
  next->size = pstack->size;
*pstack = *next;

};

bool stack_double_try_push(stack_double_t* pstack, double value){
    if(pstack->howMuch == pstack->size){
      printf("Stos pełny, nie można dodać już do niego żadnego elementu.\n");
      return false;
    }else{
      stack_double_push(pstack, value);
      return true;
    }

};

int stack_double_pop(stack_double_t* pstack){
  double value = pstack->value;
  *pstack = *pstack->prevStack;
  return value;
};

bool stack_double_empty(const stack_double_t* pstack){
  if(pstack->howMuch == 0) return true;
  else return false;
};

bool stack_double_try_pop(stack_double_t* pstack){
  if(stack_double_empty(pstack)){
    printf("Stos jest pusty, więc nie można zdjąć z niego żadnego elementu\n");
    return false;
  }else{
    printf("Zdjety element ze stosu: %d\n",stack_double_pop(pstack));
    return true;
  }
};



void stack_double_free(stack_double_t* pstack){
  stack_double_t* current_stack = malloc(sizeof(stack_double_t));
  while((current_stack = pstack) != NULL){
    pstack = pstack->prevStack;
    free(current_stack);
  }
};

void stack_double_print(const stack_double_t* pstack){
  if(stack_double_empty(pstack)) printf("Stos jest pusty\n");
  else{
  printf("\nZawartość stosu: \n");
  stack_double_t *stack = malloc(sizeof(stack_double_t));
  stack->value = pstack->value;
  stack->prevStack = pstack->prevStack;
  while(stack->prevStack != NULL){
    printf("%lf\n",stack->value);
    stack = stack->prevStack;
  }
}
};

void remove_all_double(stack_double_t** pstack){
  stack_double_t* current_stack = malloc(sizeof(stack_double_t*));
  while((current_stack = (*pstack)->prevStack) != NULL){
    *pstack = (*pstack)->prevStack;
    current_stack = NULL;
  }
};

void save_stack_double(const char* path, stack_double_t* pstack){
  FILE *fp = fopen(path,"wb");
  if(fp){

    fwrite(pstack,sizeof(stack_double_t),1,fp);

  }else printf("Błąd odczytu pliku");

  fclose(fp);
};


stack_double_t* load_stack_double(const char* path){
  FILE* fp = fopen(path,"rb");
stack_double_t* loaded_stack = malloc(sizeof(stack_double_t));
  if(fp){
  fread(loaded_stack,sizeof(stack_double_t),1,fp);
  }else printf("Błąd odczytu pliku");
  fclose(fp);

  return loaded_stack;
};
