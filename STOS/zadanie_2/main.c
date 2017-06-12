#include "stos.h"

int main(){

stack_t* stack = stack_create(3);

stack_try_push(stack,3);
stack_try_push(stack,4);
stack_try_push(stack,10);

stack_print(stack);

stack_try_push(stack,10);


stack_print(stack);
stack_try_pop(stack);

stack_print(stack);
stack_try_pop(stack);

stack_print(stack);
stack_try_pop(stack);

stack_print(stack);
stack_try_pop(stack);


  stack_free(stack);

  return 0;
}
