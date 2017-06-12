#include "stos.h"

int main(){

stack_t *stack = stack_create(20);

for(int i=0; i<20; i++)
stack_try_push(stack,i*5);

stack_print(stack);

remove_all(&stack);

stack_print(stack);

for(int i=0; i<20; i++)
stack_try_push(stack,i*5);

save_stack("stos.bin",stack);
printf("\nWczytany stos: \n");
stack_print(load_stack("stos.bin"));




  return 0;
}
