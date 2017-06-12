#include "stos.h"

int main(){

stack_int_t* stos1 = stack_int_create(32);
stack_int_t* stos2 = stack_int_create(32);
stack_float_t* stos3 = stack_float_create(123);

stack_int_try_push(stos1,5);
stack_int_try_push(stos1,10);
stack_int_try_push(stos1,17);

stack_int_print(stos1);

stack_float_try_push(stos3,5.17);
stack_float_try_push(stos3,10.32);
stack_float_try_push(stos3,17.48);
stack_float_print(stos3);
  return 0;
}
