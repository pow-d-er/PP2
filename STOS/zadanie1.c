#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct stack_t{

struct stack_t* prev;
int value;
}stack_t;



stack_t* stack_create(int size);
void stack_push(stack_t** pstack, int value);
int stack_pop(stack_t** pstack);
bool stack_empty(const stack_t* pstack);
void stack_free(stack_t* pstack);
void stack_print(const stack_t* pstack);


int main(){

stack_t *stos = stack_create(10);
stack_push(&stos, 10);
stack_push(&stos, 20);
stack_push(&stos, 30);
stack_print(stos);
printf("\n\npopped value: %d\n\n", stack_pop(&stos));
stack_print(stos);
  return 0;
}

stack_t* stack_create(int size){
  stack_t *root = malloc(sizeof(stack_t)*size);
  root->value = size;
  root->prev = NULL;

}

void stack_push(stack_t** pstack, int value){

stack_t *new;
new = malloc(sizeof(size_t)*value);

new->value = value;
new->prev = *pstack;

*pstack = new;
}

int stack_pop(stack_t** pstack){
  int  value = (*pstack)->value;
  *pstack = (*pstack)->prev;

  return value;
}

 bool stack_empty(const stack_t* pstack){
         if (pstack == NULL ) return true;

          return false;
 }

void stack_free(stack_t* pstack){
    while(stack_empty(pstack)){
            free(pstack);
            pstack = pstack->prev;
    }
}

 void stack_print(const stack_t* pstack){

              stack_t helper = *pstack;
              stack_t *phelper = &helper;

              while(!stack_empty(phelper)){
             printf("%d\n",phelper->value);
             phelper = phelper->prev;

           }
     }
