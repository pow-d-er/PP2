#include "stos_float.h"

stack_float_t* stack_float_create(int size){
stack_float_t* new = malloc(sizeof(stack_float_t));
new->size = size;
new->howMuch = 0;
new->prevStack = NULL;
new->value = 0;
};

void stack_float_push(stack_float_t* pstack, float value){

  stack_float_t* next = malloc(sizeof(stack_float_t));
  next->prevStack = malloc(sizeof(stack_float_t));
  next->value = value;
  *next->prevStack = *pstack;
  next->howMuch = pstack->howMuch+1;
  next->size = pstack->size;
*pstack = *next;

};

bool stack_float_try_push(stack_float_t* pstack, float value){
    if(pstack->howMuch == pstack->size){
      printf("Stos pełny, nie można dodać już do niego żadnego elementu.\n");
      return false;
    }else{
      stack_float_push(pstack, value);
      return true;
    }

};

int stack_float_pop(stack_float_t* pstack){
  float value = pstack->value;
  *pstack = *pstack->prevStack;
  return value;
};

bool stack_float_empty(const stack_float_t* pstack){
  if(pstack->howMuch == 0) return true;
  else return false;
};

bool stack_float_try_pop(stack_float_t* pstack){
  if(stack_float_empty(pstack)){
    printf("Stos jest pusty, więc nie można zdjąć z niego żadnego elementu\n");
    return false;
  }else{
    printf("Zdjety element ze stosu: %d\n",stack_float_pop(pstack));
    return true;
  }
};



void stack_float_free(stack_float_t* pstack){
  stack_float_t* current_stack = malloc(sizeof(stack_float_t));
  while((current_stack = pstack) != NULL){
    pstack = pstack->prevStack;
    free(current_stack);
  }
};

void stack_float_print(const stack_float_t* pstack){
  if(stack_float_empty(pstack)) printf("Stos jest pusty\n");
  else{
  printf("\nZawartość stosu: \n");
  stack_float_t *stack = malloc(sizeof(stack_float_t));
  stack->value = pstack->value;
  stack->prevStack = pstack->prevStack;
  while(stack->prevStack != NULL){
    printf("%f\n",stack->value);
    stack = stack->prevStack;
  }
}
};

void remove_all_float(stack_float_t** pstack){
  stack_float_t* current_stack = malloc(sizeof(stack_float_t*));
  while((current_stack = (*pstack)->prevStack) != NULL){
    *pstack = (*pstack)->prevStack;
    current_stack = NULL;
  }
};

void save_stack_float(const char* path, stack_float_t* pstack){
  FILE *fp = fopen(path,"wb");
  if(fp){

    fwrite(pstack,sizeof(stack_float_t),1,fp);

  }else printf("Błąd odczytu pliku");

  fclose(fp);
};


stack_float_t* load_stack_float(const char* path){
  FILE* fp = fopen(path,"rb");
stack_float_t* loaded_stack = malloc(sizeof(stack_float_t));
  if(fp){
  fread(loaded_stack,sizeof(stack_float_t),1,fp);
  }else printf("Błąd odczytu pliku");
  fclose(fp);

  return loaded_stack;
};
