#include "stos.h"

int main(){

stack_t* stack = stack_create(6);
stack_push(stack,3);
stack_push(stack,4);
stack_push(stack,10);
stack_push(stack,1);
stack_push(stack,12);

stack_print(stack);

printf("Zdjety element ze stosu: %d\n",stack_pop(stack));
stack_print(stack);

stack_free(stack);

  return 0;
}
