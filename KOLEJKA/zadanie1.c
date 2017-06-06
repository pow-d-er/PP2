#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{

  int* tab;
  int index;
  int howMuch;
  int size;
}queue_t;

bool queue_create(queue_t *q, int size){
  q->tab = (int*) malloc(sizeof(int)*size);
  if(q->tab == NULL)  return false;

  q->size = size;
  q->howMuch = 0;
  q->index = 0;
  return true;
}

void queue_push(queue_t * q, int value){
  q->tab[q->howMuch + q->index] = value;
  q->howMuch++;
    if(q->howMuch + q->index > q->size-1){
        q->tab = (int*)realloc(q->tab, sizeof(int)*q->size*2);
        q->size = q->size*2;
}
}

int queue_pop(queue_t * q){
  int value = q->tab[q->index];
  q->index++;
  q->howMuch--;
  return value;
}

bool queue_empty(const queue_t * q){
    if(q->howMuch == 0) return true;
    else return false;
}

int queue_size(const queue_t * q){
  return q->howMuch;
}

void queue_print(const queue_t * q ){
  queue_t q2;
  q2 = *q;
  for(int i=q2.index; i<q2.howMuch+q2.index; i++)
  printf("%d\n",q2.tab[i]);
}

int main(){

queue_t *q = malloc(sizeof(queue_t));
queue_create(q,10);
queue_push(q,5);
queue_push(q,6);
queue_push(q,7);
queue_push(q,8);
queue_push(q,9);
queue_push(q,10);
queue_push(q,11);
queue_push(q,12);
queue_push(q,13);
queue_push(q,14);
queue_push(q,15);
queue_push(q,16);
printf("%d\n",queue_pop(q));
printf("%d\n",queue_pop(q));
printf("%d\n",queue_pop(q));
printf("%d\n",queue_pop(q));
queue_print(q);


  return 0;
}
