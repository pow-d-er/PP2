#include "stos_unsigned_long_long_int.h"

stack_unsigned_long_long_int_t* stack_unsigned_long_long_int_create(int size){
stack_unsigned_long_long_int_t* new = malloc(sizeof(stack_unsigned_long_long_int_t));
new->size = size;
new->howMuch = 0;
new->prevStack = NULL;
new->value = 0;
};

void stack_unsigned_long_long_int_push(stack_unsigned_long_long_int_t* pstack, unsigned long long int value){

  stack_unsigned_long_long_int_t* next = malloc(sizeof(stack_unsigned_long_long_int_t));
  next->prevStack = malloc(sizeof(stack_unsigned_long_long_int_t));
  next->value = value;
  *next->prevStack = *pstack;
  next->howMuch = pstack->howMuch+1;
  next->size = pstack->size;
*pstack = *next;

};

bool stack_unsigned_long_long_int_try_push(stack_unsigned_long_long_int_t* pstack, unsigned long long int value){
    if(pstack->howMuch == pstack->size){
      printf("Stos pełny, nie można dodać już do niego żadnego elementu.\n");
      return false;
    }else{
      stack_unsigned_long_long_int_push(pstack, value);
      return true;
    }

};

int stack_unsigned_long_long_int_pop(stack_unsigned_long_long_int_t* pstack){
  unsigned long long int value = pstack->value;
  *pstack = *pstack->prevStack;
  return value;
};

bool stack_unsigned_long_long_int_empty(const stack_unsigned_long_long_int_t* pstack){
  if(pstack->howMuch == 0) return true;
  else return false;
};

bool stack_unsigned_long_long_int_try_pop(stack_unsigned_long_long_int_t* pstack){
  if(stack_unsigned_long_long_int_empty(pstack)){
    printf("Stos jest pusty, więc nie można zdjąć z niego żadnego elementu\n");
    return false;
  }else{
    printf("Zdjety element ze stosu: %d\n",stack_unsigned_long_long_int_pop(pstack));
    return true;
  }
};



void stack_unsigned_long_long_int_free(stack_unsigned_long_long_int_t* pstack){
  stack_unsigned_long_long_int_t* current_stack = malloc(sizeof(stack_unsigned_long_long_int_t));
  while((current_stack = pstack) != NULL){
    pstack = pstack->prevStack;
    free(current_stack);
  }
};

void stack_unsigned_long_long_int_print(const stack_unsigned_long_long_int_t* pstack){
  if(stack_unsigned_long_long_int_empty(pstack)) printf("Stos jest pusty\n");
  else{
  printf("\nZawartość stosu: \n");
  stack_unsigned_long_long_int_t *stack = malloc(sizeof(stack_unsigned_long_long_int_t));
  stack->value = pstack->value;
  stack->prevStack = pstack->prevStack;
  while(stack->prevStack != NULL){
    printf("%llu\n",stack->value);
    stack = stack->prevStack;
  }
}
};

void remove_all_unsigned_long_long_int(stack_unsigned_long_long_int_t** pstack){
  stack_unsigned_long_long_int_t* current_stack = malloc(sizeof(stack_unsigned_long_long_int_t*));
  while((current_stack = (*pstack)->prevStack) != NULL){
    *pstack = (*pstack)->prevStack;
    current_stack = NULL;
  }
};

void save_stack_unsigned_long_long_int(const char* path, stack_unsigned_long_long_int_t* pstack){
  FILE *fp = fopen(path,"wb");
  if(fp){

    fwrite(pstack,sizeof(stack_unsigned_long_long_int_t),1,fp);

  }else printf("Błąd odczytu pliku");

  fclose(fp);
};


stack_unsigned_long_long_int_t* load_stack_unsigned_long_long_int(const char* path){
  FILE* fp = fopen(path,"rb");
stack_unsigned_long_long_int_t* loaded_stack = malloc(sizeof(stack_unsigned_long_long_int_t));
  if(fp){
  fread(loaded_stack,sizeof(stack_unsigned_long_long_int_t),1,fp);
  }else printf("Błąd odczytu pliku");
  fclose(fp);

  return loaded_stack;
};
