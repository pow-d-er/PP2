#include "kolejka.h"

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
  if(queue_empty(q)){
    printf("Ta kolejka jest pusta!");
    return 0;
  }
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

void queue_push_front(queue_t * q, int value){

    if(q->index-1<0){
      printf("Queue underflow\n");
    }else{
      q->index--;
    q->tab[q->index] = value;
    q->howMuch++;
  }
};

int queue_pop_back(queue_t * q){
    if(queue_empty(q)){
      printf("Ta kolejka jest pusta!");
      return 0;
    }
    int value = q->tab[q->howMuch];
    q->howMuch--;
    return value;
};
